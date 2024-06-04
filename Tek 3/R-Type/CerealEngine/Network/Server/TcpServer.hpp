/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Tcp
*/

#pragma once

#include <asio.hpp>
#include <iostream>

namespace Cereal {
    namespace Network {
        class TcpConnection : public std::enable_shared_from_this<TcpConnection> {
            public:
                typedef std::shared_ptr<TcpConnection> pointer;

                static pointer create(asio::io_context& io_context, int udp_port) {
                    return pointer(new TcpConnection(io_context, udp_port));
                }

                asio::ip::tcp::socket& socket() {
                    return _socket;
                }

                void start() {
                    /* Send UDP port to the client */
                    std::string udpPortMessage = "UDP_PORT: " + std::to_string(_udp_port);
                    writeMessage(udpPortMessage);

                    readMessage();
                }

            private:
                TcpConnection(asio::io_context& io_context, int udp_port)
                    : _socket(io_context), _udp_port(udp_port) {}

                void readMessage() {
                    auto self(shared_from_this());
                    asio::async_read(_socket, asio::buffer(_read_msg, max_length),
                        [this, self](std::error_code ec, std::size_t length) {
                            if (!ec) {
                                handleMessage(std::string(_read_msg.data(), length));
                                readMessage();
                            }
                            /* Handle disconnection or errors here */
                            if (ec == asio::error::eof) {
                                std::cout << "Client disconnected" << std::endl;
                            } else if (ec) {
                                std::cerr << "Error: " << ec.message() << std::endl;
                            }
                        });
                }

                void handleMessage(const std::string& message) {
                    // Process the message
                    // For example, echo it back to the client
                    writeMessage(message);
                }

                void writeMessage(const std::string& message) {
                    auto self(shared_from_this()); // Keep the connection alive
                    asio::async_write(_socket, asio::buffer(message),
                        [this, self](std::error_code ec, std::size_t length) {
                            if (ec) {
                                std::cerr << "Failed to send message: " << ec.message() << std::endl;
                            } else {
                                std::cout << "Message sent successfully, " << length << " bytes" << std::endl;
                            }
                        });
                }

                int _udp_port;
                asio::ip::tcp::socket _socket;
                enum { max_length = 1024 };
                std::array<char, max_length> _read_msg;
        };

        class TcpServer {
            public:
                TcpServer(asio::io_context& io_context, int tcp_port, int udp_port)
                    : _io_context(io_context),
                      _acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), tcp_port)),
                      _udp_port(udp_port) {
                    startAccept();
                }

                void startAccept() {
                    auto new_connection = TcpConnection::create(_io_context, _udp_port);

                    _acceptor.async_accept(new_connection->socket(),
                        [this, new_connection](const asio::error_code& error) {
                            handleAccept(new_connection, error);
                        });
                }

                void handleAccept(std::shared_ptr<TcpConnection> new_connection, const asio::error_code& error) {
                    if (!error) {
                        std::cout << "New connection accepted" << std::endl;
                        new_connection->start();
                    }
                    startAccept();
                }

                // Method to send data over a TCP connection
                void sendTcpData(std::shared_ptr<asio::ip::tcp::socket> socket, const std::string &data) {
                    asio::async_write(*socket, asio::buffer(data),
                        [](const asio::error_code& error, std::size_t bytes_transferred) {
                            // Handle the completion of the send operation
                            // You can log the error or the number of bytes transferred
                        });
                }

            private:
                int _udp_port;
                asio::io_context& _io_context;
                asio::ip::tcp::acceptor _acceptor;
        };
    } // namespace Network
} // namespace Cereal