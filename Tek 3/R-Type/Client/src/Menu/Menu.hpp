/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Menu.hpp
*/

#pragma once

#include "../NType.hpp"

class Menu { // : public Cereal::Scene {
    public:
        Menu();
        ~Menu() = default;

        void run();

        std::string menuScene;
    private:
        void setupEntities();
        void handleInputs();
};
