/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Win.hpp
*/

#pragma once

#include "../NType.hpp"

class Win { // : public Cereal::Scene {
    public:
        Win();
        ~Win() = default;

        void run();

        std::string gameWinScene;

    private:
        void setupEntities();
        void handleInputs();
};
