/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Game.hpp
*/

#pragma once

#include "../../CerealEngine/CerealEngine.hpp"

class Game {
    public:
        Game();
        ~Game() = default;

        void run(double deltaTime);
        void resetGame();

        std::string gameScene;

    private:
        void setupEntities();
        void setupKeys();
        void handleCollision();
        void handlePause();
        void createPipes();

        float velocityZ = 0.0f;
        float gravity = -45.8f;
        float jumpForce = 18.0f;
        float terminalVelocity = -50.0f;
        bool isRunning = true;
        bool gameAsStarted = false;
        bool resetScore = false;

        double pipeSpawnTimer = 0.0;
        int topPipeCount = 0;
        int bottomPipeCount = 0;
};
