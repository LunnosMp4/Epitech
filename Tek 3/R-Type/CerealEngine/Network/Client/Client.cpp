/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Client
*/

#include "Client.hpp"

using namespace Cereal::Network;

Client::Client(asio::io_context& io_context)
    : _io_context(io_context),
      _tcp_socket(io_context),
      _udp_socket(io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0)),
      _host(""),
      _tcp_port(8080),
      _udp_port(8081)
{}

void Client::start()
{
    _io_context.run();
}

void Client::stop()
{
    _io_context.stop();
}

void Client::configConnection(const std::string& host, const int tcp_port) {
    _host = host;
    _tcp_port = tcp_port;
}


bool Client::connectToServer()
{
    try {
        if (_host.empty()) {
            std::cerr << "Host is empty" << std::endl;
            return false;
        }

        std::cout << "Connecting to " << _host << ":" << _tcp_port << std::endl;
        asio::ip::tcp::resolver resolver(_io_context);
        asio::error_code ec;
        auto endpoints = resolver.resolve(_host, std::to_string(_tcp_port), ec);
        if (ec) {
            std::cerr << "Resolver error: " << ec.message() << std::endl;
            return false;
        }
        asio::async_connect(_tcp_socket, endpoints,
            [this](const asio::error_code& error, const asio::ip::tcp::endpoint& /*endpoint*/) {
                if (!error) {
                    receiveUdpPort(_host, _udp_port);
                } else {
                    std::cerr << "Error: " << error.message() << std::endl;
                }
            });
    } catch (const std::exception& e) {
        std::cerr << "Exception in connectToServer: " << e.what() << std::endl;
    }
    return true;
}

void Client::disconnectFromServer()
{
    _tcp_socket.close();
    _udp_socket.close();
    stop();
}

void Client::receiveUdpPort(const std::string& host, int udp_port)
{
    _tcp_socket.async_read_some(asio::buffer(_tcp_recv_buffer),
        [this](const asio::error_code& error, size_t bytes_transferred) {
            if (!error) {
                std::string message(_tcp_recv_buffer.data(), bytes_transferred);
                std::cout << "Received TCP message: " << message << std::endl;

                // Parse the message to extract the UDP port
                std::size_t pos = message.find("UDP_PORT: ");
                if (pos != std::string::npos) {
                    std::string udp_port_str = message.substr(pos + 10); // Extract the port number part
                    _udp_port = std::stoi(udp_port_str);

                    // Initialize UDP with the correct port
                    _udp_endpoint = asio::ip::udp::endpoint(asio::ip::address::from_string(_host), _udp_port);
                    sendPacketType(PacketType::JOIN_GAME);
                    receivePacket();
                }
            } else {
                std::cout << "Error: " << error.message() << std::endl;
            }
        });
}

void Client::receivePacket() {
    _udp_socket.async_receive_from(asio::buffer(_udp_recv_buffer), _udp_endpoint,
        [this](const asio::error_code& error, size_t bytes_transferred) {
            if (!error) {
                // std::cout << "Received UDP data, " << bytes_transferred << " bytes transferred." << std::endl;
                // Handle the received data
                Packet receivedPacket;
                std::memcpy(&receivedPacket.header, _udp_recv_buffer.data(), sizeof(PacketHeader));

                // Check if the full body has been received
                if (bytes_transferred - sizeof(PacketHeader) < receivedPacket.header.bodySize) {
                    // Incomplete packet, continue receiving
                    std::cout << "Incomplete packet, continue receiving" << std::endl;
                    receivePacket();
                    return;
                }

                // Deserialize the packet body into a Transform object
                receivedPacket.body.resize(receivedPacket.header.bodySize);
                std::memcpy(receivedPacket.body.data(), _udp_recv_buffer.data() + sizeof(PacketHeader), receivedPacket.header.bodySize);

                // Handle the received packet
                handlePacket(receivedPacket);

                // Continue receiving next packets
                receivePacket();
            } else {
                // Handle the error or incomplete data
                receivePacket();
            }
        });
}


// function get_TransformComponent(entityId)

Cereal::Transform Client::getTransformComponent(PacketType type)
{
    if (type == PacketType::UPDATE_ENTITY) {
        if (_updatePacket.header.entityId == -1) {
            std::cout << "No entity ID" << std::endl;
            return Cereal::Transform();
        }
        // if (std::strncmp(_updatePacket.header.entityName, "Player", sizeof(_updatePacket.header.entityName)) == 0 && _id == -1) {
        //     _id = _updatePacket.header.entityId;
        //     // std::cout << "Player ID: " << _id << std::endl;
        // }
        // std::cout << "Packet entity name: " << _updatePacket.header.entityName << std::endl;
        // std::cout << "Packet entity ID: " << _updatePacket.header.entityId << std::endl;
        // std::cout << "transform.x: " << _transform.position.x << std::endl;
        // std::cout << "transform.y: " << _transform.position.y << std::endl;
        return _transform;
    }
    return Cereal::Transform();
}

int Client::getEntityId(PacketType type)
{
    if (type == PacketType::UPDATE_ENTITY) {
        return _entityId;
    }
    return -1;
}

void Client::updateEntity(const Packet& packet)
{
    Cereal::Transform deserializedTransform = Deserialization::TransformDeserializer::deserializeTransform(packet.body);

    _updatePacket = packet;
    _transform = deserializedTransform;
    // std::cout << "transform.pos.x: " << _transform.position.x << std::endl;
    // std::cout << "transform.pos.y: " << _transform.position.y << std::endl;
    // if (_entityId == -1)
    //   _id = packet.header.entityId;
    _entityId = packet.header.entityId;
    // std::cout << "UPDATE Packet entity ID: " << packet.header.entityId << std::endl;
    // Debug::debugTransform(deserializedTransform);
}

void Client::handlePacket(const Packet& packet)
{
    std::string_view packetBody(reinterpret_cast<const char*>(packet.body.data()), packet.body.size());


    switch (packet.header.type) {
        case PacketType::UPDATE_ENTITY:
            // std::cout << "Received UPDATE_ENTITY packet: " << packetBody << std::endl;
            // std::cout << "Packet entity name: " << packet.header.entityName << std::endl;
            // std::cout << "Packet entity ID: " << packet.header.entityId << std::endl;
            // if (std::strncmp(packet.header.entityName, "Player", sizeof(packet.header.entityName)) == 0 && _id == -1) {
            //     _id = packet.header.entityId;
            //     std::cout << "Player ID: " << _id << std::endl;
            // }
            updateEntity(packet);
            break;
        case PacketType::DESTROY_ENTITY:
            std::cout << "Received DESTROY_ENTITY packet: " << packetBody << std::endl;
            break;
        case PacketType::GIVE_ID:
            if (_id == -1)
                _id = packet.header.entityId;
            std::cout << "Received ID: " << _id << std::endl;
            break;
        case PacketType::START_GAME:
            std::cout << "Received START_GAME packet" << std::endl;
            _startedGame = true;
            break;
        default:
            std::cout << "Received unknown packet type with body: " << packetBody << std::endl;
            break;
    }
}

void Client::sendUdpPacket(const Packet& packet)
{
    // Serialize the packet
    std::vector<std::byte> serializedPacket(sizeof(PacketHeader) + packet.header.bodySize);
    std::memcpy(serializedPacket.data(), &packet.header, sizeof(PacketHeader));
    std::memcpy(serializedPacket.data() + sizeof(PacketHeader), packet.body.data(), packet.header.bodySize);

    _udp_socket.async_send_to(asio::buffer(serializedPacket), _udp_endpoint,
    [](const asio::error_code& error, std::size_t bytes_transferred) {
        if (error) {
            std::cout << "Error sending UDP data: " << error.message() << std::endl;
        } else {
            // std::cout << "Sent UDP data, " << bytes_transferred << " bytes transferred." << std::endl;
        }
    });
}

void Client::sendInput(const std::string& input)
{
    std::vector<std::byte> inputBytes = Serialization::InputSerializer::serializeInput(input);

    Packet packet;
    packet.header.type = PacketType::INPUT;
    packet.header.bodySize = inputBytes.size();

    // Ensure entityName is not longer than the size of entityName in PacketHeader
    std::strncpy(packet.header.entityName, "", sizeof(packet.header.entityName) - 1);
    packet.header.entityName[sizeof(packet.header.entityName) - 1] = '\0'; // Null-terminate

    packet.header.entityId = _id;
    packet.body = inputBytes;

    sendUdpPacket(packet);
}

void Client::sendPacketType(PacketType type)
{
    Packet packet;
    packet.header.type = type;
    packet.header.bodySize = 0;

    // Ensure entityName is not longer than the size of entityName in PacketHeader
    std::strncpy(packet.header.entityName, "", sizeof(packet.header.entityName) - 1);
    packet.header.entityName[sizeof(packet.header.entityName) - 1] = '\0'; // Null-terminate

    packet.header.entityId = _id;

    sendUdpPacket(packet);
}

bool Client::getStartedGame()
{
    return _startedGame;
}