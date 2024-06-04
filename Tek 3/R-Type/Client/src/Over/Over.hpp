/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Over.hpp
*/

#pragma once

#include "../NType.hpp"

class Over { // : public Cereal::Scene {
    public:
        Over();
        ~Over() = default;

        void run();

        std::string gameOverScene;

    private:
        void setupEntities();
        void handleInputs();
};
