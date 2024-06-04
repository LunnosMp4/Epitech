/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** UdpServer
*/

#include "UdpServer.hpp"

using namespace Cereal::Network;

UdpServer::UdpServer(asio::io_context& io_context, int port)
    : _socket(io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)) {
    startReceive();
}

void UdpServer::startReceive() {
    _socket.async_receive_from(
    asio::buffer(_recv_buffer), _remote_endpoint,
    [this](const asio::error_code& error, std::size_t bytes_transferred) {
        if (_clients.find(_remote_endpoint) == _clients.end()) {
            addClient(_remote_endpoint);
        }
        handleReceive(error, bytes_transferred);
    });
}

std::string UdpServer::getInputForEntity(int entityId) {
    // for (auto& [key, value] : _inputsByEntityId) {
    //     std::cout << "Entity ID: " << key << " Input: " << value << std::endl;
    // }

    auto it = _inputsByEntityId.find(entityId);
    if (it != _inputsByEntityId.end()) {
        return it->second;
    }
    return ""; // Return empty string if entity ID not found
}

void UdpServer::findInput(const Packet& packet)
{
    std::string deserializedInput = Deserialization::InputDeserializer::deserializeInput(packet.body);
    int entityId = packet.header.entityId;

    std::cout << "Received entity ID: " << entityId << std::endl;

    _inputsByEntityId[entityId] = deserializedInput;

    // for (auto& [key, value] : _inputsByEntityId) {
    //     std::cout << "Entity ID: " << key << " Input: " << value << std::endl;
    // }
    // Debug::debugInput(deserializedInput);
    // std::cout << "Packet entity name: " << packet.header.entityName << std::endl;
    // std::cout << "Packet entity ID: " << packet.header.entityId << std::endl;
    // std::cout << "Packet input: " << deserializedInput << std::endl;
}

/* Handle */
void UdpServer::handlePacket(const Packet& packet) {
    // Utilisez les informations du paquet pour traiter les données
    // par exemple, vous pouvez extraire l'ID de l'entité, le type de socket, etc.

    // Traitez le corps du paquet (les données du composant en bytecode)
    // ...

    // Répondez au client si nécessaire
    // ...
    std::string_view packetBody(reinterpret_cast<const char*>(packet.body.data()), packet.body.size());


    switch (packet.header.type) {
        case PacketType::UPDATE_ENTITY:
            // std::cout << "Received UPDATE_ENTITY packet: " << packetBody << std::endl;
            // std::cout << "Packet entity name: " << packet.header.entityName << std::endl;
            // std::cout << "Packet entity ID: " << packet.header.entityId << std::endl;
            break;
        case PacketType::INPUT:
            findInput(packet);
            break;
        case PacketType::JOIN_GAME:
            std::cout << "Received JOINED_GAME packet" << std::endl;
            joinedGame = true;
            break;
        case PacketType::START_GAME:
            std::cout << "Received START_GAME packet" << std::endl;
            startedGame = true;
            break;
        default:
            std::cout << "Received unknown packet" << std::endl;
            break;
    }
}

void UdpServer::handleReceive(const asio::error_code& error, std::size_t bytes_transferred) {
    if (!error) {
        if (bytes_transferred >= sizeof(PacketHeader)) {
            // Process received data (stored in _recv_buffer)
            Packet receivedPacket;
            std::memcpy(&receivedPacket.header, _recv_buffer.data(), sizeof(PacketHeader));

            // Check if the full body has been received
            if (bytes_transferred - sizeof(PacketHeader) < receivedPacket.header.bodySize) {
                // Incomplete packet, continue receiving
                startReceive();
                return;
            }

            if (_clients.empty()) {
                std::cout << "No clients connected" << std::endl;
                // return;
            } else {
                // for (const auto& endpoint : _clients) {
                //     std::cout << endpoint << std::endl;
                // }
            }

            // Deserialize the packet body into a Transform object
            receivedPacket.body.resize(receivedPacket.header.bodySize);
            std::memcpy(receivedPacket.body.data(), _recv_buffer.data() + sizeof(PacketHeader), receivedPacket.header.bodySize);

            // print the received packet
            // std::cout << "Received UDP packet, " << bytes_transferred << " bytes transferred." << std::endl;
            // std::cout << "Packet type: " << static_cast<int>(receivedPacket.header.type) << std::endl;
            // std::cout << "Packet body size: " << receivedPacket.header.bodySize << std::endl;
            // std::cout << "Packet entity ID: " << receivedPacket.header.entityId << std::endl;

            // Handle the received packet
            handlePacket(receivedPacket);

            // Continue receiving next packets
            startReceive();
        } else {
            std::cerr << "Received incomplete packet" << std::endl;
        }
    } else {
        // Handle the error during reception
        std::cerr << "Error receiving UDP data: " << error.message() << std::endl;
    }

    // Continue receiving next packets
    startReceive();
}

void UdpServer::sendPacket(const Packet& packet, const asio::ip::udp::endpoint& endpoint) {
    // Serialize the packet
    std::vector<std::byte> serializedPacket(sizeof(PacketHeader) + packet.header.bodySize);
    std::memcpy(serializedPacket.data(), &packet.header, sizeof(PacketHeader));
    std::memcpy(serializedPacket.data() + sizeof(PacketHeader), packet.body.data(), packet.header.bodySize);

    // Send the serialized packet
    _socket.async_send_to(
        asio::buffer(serializedPacket), endpoint,
        [this](const asio::error_code& ec, std::size_t bt) {
        if (ec) {
            // Gérer l'erreur d'envoi
            std::cerr << "Error sending UDP data: " << ec.message() << std::endl;
        } else {
            // Gérer le succès de l'envoi
            // std::cout << "Sent UDP data, " << bt << " bytes transferred." << std::endl;
        }
    });
}

void UdpServer::sendTransform(PacketType type, const Cereal::Transform& transform, const std::string& entityName, const int entityId) {
    std::vector<std::byte> serializedTransform = Serialization::TransformSerializer::serializeTransform(transform);

    Packet packet;
    packet.header.type = type;
    packet.header.bodySize = serializedTransform.size();

    // Ensure entityName is not longer than the size of entityName in PacketHeader
    std::strncpy(packet.header.entityName, entityName.c_str(), sizeof(packet.header.entityName) - 1);
    packet.header.entityName[sizeof(packet.header.entityName) - 1] = '\0'; // Null-terminate

    packet.header.entityId = entityId;
    packet.body = serializedTransform;

    if (_clients.empty()) {
          std::cout << "No clients connected" << std::endl;
          return;
    }
    for (const auto& endpoint : _clients) {
        sendPacket(packet, endpoint);
    }
}

void UdpServer::broadcastData(const Packet& packet) {
    if (_clients.empty()) {
          std::cout << "No clients connected" << std::endl;
          return;
    }
    for (const auto& endpoint : _clients) {
        sendPacket(packet, endpoint);
    }
}

std::set<asio::ip::udp::endpoint> UdpServer::getClients() {
    return _clients;
}

void UdpServer::addClient(const asio::ip::udp::endpoint& endpoint) {
    _clients.insert(endpoint);
}

void UdpServer::removeClient(const asio::ip::udp::endpoint& endpoint) {
    _clients.erase(endpoint);
}
