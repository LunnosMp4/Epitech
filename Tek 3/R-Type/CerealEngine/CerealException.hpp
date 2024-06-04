/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** CerealException.hpp
*/

#pragma once

#include <stdexcept>
#include <string>

namespace Cereal {
    class CerealException : public std::exception {
    public:
        explicit CerealException(const std::string& message) : message_(message) {}

        const char* what() const noexcept override {
            return message_.c_str();
        }

    private:
        std::string message_;
    };

}
