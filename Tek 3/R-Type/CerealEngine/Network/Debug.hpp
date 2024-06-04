/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Debug
*/

#include <iostream>
#include <asio.hpp>
#include <set>
#include "../Components/TransformComponent.hpp"

#pragma once

namespace Cereal {
    namespace Network {
        class Debug {
            public:
                static void debugTransform(const Cereal::Transform& transform) {
                    std::cout
                      << "Position <" << transform.position.x << ", " << transform.position.y << ", " << transform.position.z << ">"
                      << " Rotation <" << transform.rotation.x << ", " << transform.rotation.y << ", " << transform.rotation.z << ">"
                      << " Scale <" << transform.scale << ">" << std::endl;
                }
                static void debugInput(const std::string& input) {
                    std::cout << "Input: " << input << std::endl;
                }

                static void debugEndpoint(const asio::ip::udp::endpoint& endpoint) {
                    std::cout << endpoint.address().to_string() << ":" << endpoint.port() << std::endl;
                }

                static void debugEndpoints(const std::set<asio::ip::udp::endpoint>& endpoints) {
                    for (auto& endpoint : endpoints) {
                        debugEndpoint(endpoint);
                    }
                }
        };
    }
}