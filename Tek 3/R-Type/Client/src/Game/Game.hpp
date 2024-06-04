/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Game.hpp
*/

#pragma once

#include "../NType.hpp"

class Game { // : public Cereal::Scene {
    public:
        Game(int level);
        ~Game() = default;

        static Game& getInstance();
        void run(double deltaTime, Cereal::Network::Client& client);
        void resetGame();

        bool isRunning = false;
        std::string gameScene;

        int bulletCount = 0;
        int enemyCount = 0;
        int planetCount = 0;
        int asteroidCount = 0;
        int bgAsteroidCount = 0;

    private:
        int currentLevel = 1;
        double enemySpawnTimer = 0.0;
        double bulletReloadTimer = 0.0;
        double planetSpawnTimer = 0.0;
        double asteroidSpawnTimer = 0.0;
        double bgAsteroidSpawnTimer = 0.0;
        bool bossSpawned = false;
        bool finalBossSpawned = false;

        std::vector<int> clientsIds = {};
        Cereal::Transform transform = {};
        std::string currentInput = "NONE";

        std::vector<std::string> enemyModels = {
            "assets/models/EnemyShips/Ennemy1.glb",
            "assets/models/EnemyShips/Ennemy2.glb",
            "assets/models/EnemyShips/LittleEnnemy1.glb",
            "assets/models/EnemyShips/LittleEnnemy2.glb",
            "assets/models/EnemyShips/LittleEnnemy3.glb",
            "assets/models/EnemyShips/LittleEnnemy4.glb",
            "assets/models/EnemyShips/LittleEnnemy5.glb"
        };

        void setupEntities();
        void CheckCurrentInput();
        void createPlayer(const int id);
        void updatePlayerTransform(const Cereal::Transform serverTransform, const int id);
        void handleInputs();
        void handleCollision();
        void setupKeys();
        void shotBullet();
        void createEnemy(Cereal::Stats enemyStats);
        void createMiniBoss(int bossToSpawn, Cereal::Stats bossStats, int posZ = 0);
        void createBigBoss(Cereal::Stats bossStats);
        void createPlanets();
        void createAsteroid();
        void createBgAsteroid();
        void createFriend();

        void level1(double deltaTime);
        void level2(double deltaTime);
        void level3(double deltaTime);
        void bossLevel(double deltaTime);
};
