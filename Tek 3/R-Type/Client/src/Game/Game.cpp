/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Game.cpp
*/

#include "Game.hpp"

using namespace Cereal;

Game::Game(int level) {
    currentLevel = level;
    gameScene = CreateScene("GameScene");
    setupEntities();
    setupKeys();
}

Game& Game::getInstance() {
    static Game instance(1);
    return instance;
}

void Game::resetGame() {
    isRunning = false;
    currentLevel = 1;
    bossSpawned = false;
    finalBossSpawned = false;
    enemySpawnTimer = 0.0;
    bulletReloadTimer = 0.0;
    planetSpawnTimer = 0.0;
    asteroidSpawnTimer = 0.0;
    bgAsteroidSpawnTimer = 0.0;
    enemyCount = 0;
    bulletCount = 0;
    planetCount = 0;
    asteroidCount = 0;
    bgAsteroidCount = 0;
}

void Game::CheckCurrentInput() {
    const std::string actionDown = GetActionDown();

    if (actionDown == "MoveRight") {
        currentInput = "RIGHT";
    } else if (actionDown == "MoveLeft") {
	      currentInput = "LEFT";
    } else if (actionDown == "MoveUp") {
        currentInput = "UP";
    } else if (actionDown == "MoveDown") {
	      currentInput = "DOWN";
    } else {
        currentInput = "NONE";
    }
}

void Game::createPlayer(const int id) {
    std::cout << "Creating Player: " << "Player" + std::to_string(id) << std::endl;
    /* Player */
    CreateEntity(gameScene, "Player" + std::to_string(id))
        .addComponent<Cereal::Transform>(Cereal::Transform({0, 0, 0}, {0, 0, 0}, 0.01f))
        .addComponent<Stats>(Stats(100000, 20, 0.1f))
        .addComponent<Model3D>(Model3D(SHIP, {1, 1, 0}, 180))
        .addComponent<Render>(Render(true))
        .addComponent<Inventory>(Inventory())
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{9, 5, 6})
        .addComponent<SoundAmbiant>(SoundAmbiant(EXPLOSION, false, 1.0f)).addTag<SoundAmbiant>("SoundExplosion")
        .addTagToEntity("Elementary");

    AddItem(*GetEntityByNameInScene("Player" + std::to_string(id), gameScene).getComponent<Inventory>(), "Missile", 3);
}

void Game::updatePlayerTransform(const Cereal::Transform serverTransform, const int id) {
    GetEntityByNameInScene("Player" + std::to_string(id), gameScene).getComponent<Cereal::Transform>()->position = serverTransform.position;
    GetEntityByNameInScene("Player" + std::to_string(id), gameScene).getComponent<Cereal::Transform>()->rotation = serverTransform.rotation;
}

void Game::run(double deltaTime, Network::Client& client) {
    if (!isRunning)
        return;

    if (IsGamepadConnected(0)) {
        GetEntityByName("Notice").getComponent<Cereal::Text>()->text = "Press         to shoot";
        GetEntityByName("NoticeIcon").getComponent<Render>()->enabled = true;
    } else {
        GetEntityByName("Notice").getComponent<Cereal::Text>()->text = "Press Space to shoot";
        GetEntityByName("NoticeIcon").getComponent<Render>()->enabled = false;
    }

    int id = client.getEntityId(PacketType::UPDATE_ENTITY);
    auto serverTransform = client.getTransformComponent(PacketType::UPDATE_ENTITY);

    if (id == -1)
        GetEntityByName("Player").getComponent<Render>()->enabled = true;

    // Check if the list is empty and add the first ID
    if (clientsIds.empty() && id != -1) {
        clientsIds.push_back(id);
        std::cout << "First Id In Game: " << id << std::endl;
        createPlayer(id);
    } else if (id != -1) {
        bool idExists = false;
        // Check if the ID is already in the list
        for (const auto& clientId : clientsIds) {
            if (clientId == id) {
                idExists = true;
                break;
            }
        }
        // Add the ID if it's not already in the list
        if (!idExists) {
            clientsIds.push_back(id);
            std::cout << "New Id In Game: " << id << std::endl;
            createPlayer(id);
        }
    }

    CheckCurrentInput();
    if (id != -1) {
      updatePlayerTransform(serverTransform, id);
      client.sendInput(currentInput);
    }

    handleCollision();
    handleInputs();
    shotBullet();


    enemySpawnTimer += deltaTime;
    bulletReloadTimer += deltaTime;
    planetSpawnTimer += deltaTime;
    asteroidSpawnTimer += deltaTime;
    bgAsteroidSpawnTimer += deltaTime;

    if (planetSpawnTimer >= 25.0) {
        createPlanets();
        planetSpawnTimer = 0.0;
    }

    if (bgAsteroidSpawnTimer >= 1.0) {
        createBgAsteroid();
        bgAsteroidSpawnTimer = 0.0;
    }

    if (bulletReloadTimer >= 1) {
        bulletReloadTimer = 0.0;
        if (GetItemQuantity(*GetEntityByNameInScene("Player", gameScene).getComponent<Inventory>(), "Missile") < 3)
            AddItem(*GetEntityByNameInScene("Player", gameScene).getComponent<Inventory>(), "Missile", 1);
        GetEntityByName("Missile").getComponent<Text>()->text = "Missile: " + std::to_string(GetItemQuantity(*GetEntityByNameInScene("Player", gameScene).getComponent<Inventory>(), "Missile"));
    }

    if (asteroidSpawnTimer >= 5.0) {
        createAsteroid();
        asteroidSpawnTimer = 0.0;
    }

    /* Levels Manager */

    if (currentLevel == 1)
        level1(deltaTime);
    if (currentLevel == 2)
        level2(deltaTime);
    if (currentLevel == 3)
        level3(deltaTime);
    if (currentLevel == 4)
        bossLevel(deltaTime);
}

void Game::setupKeys() {
    MapKey("Action", Cereal::KeySpace, Cereal::InputType::Keyboard_T);
    MapKey("Action", Cereal::ButtonDown, Cereal::InputType::Gamepad_T);
    MapKey("Enter", Cereal::KeyEnter, Cereal::InputType::Keyboard_T);
    MapKey("Enter", Cereal::Start, Cereal::InputType::Gamepad_T);
}