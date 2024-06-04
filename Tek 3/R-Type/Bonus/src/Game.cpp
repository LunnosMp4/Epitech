/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Game.cpp
*/

#include "Game.hpp"

using namespace Cereal;

Game::Game() {
    gameScene = CreateScene("GameScene");
    setupEntities();
    setupKeys();
    SetCurrentScene(gameScene);
}

void Game::resetGame() {
    GetEntityByName("Player").getComponent<Cereal::Transform>()->position = {0, 0, 0};
    velocityZ = 0.0f;
    gravity = -45.8f;
    jumpForce = 18.0f;
    terminalVelocity = -50.0f;
    pipeSpawnTimer = 0.0;
    topPipeCount = 0;
    bottomPipeCount = 0;
    isRunning = true;
    resetScore = true;
}

void Game::run(double deltaTime) {
    if (!isRunning) {
        handlePause();
        return;
    }

    handleCollision();

    if (GetActionPressed() == "Action") {
        GetEntityByName("Player").getComponentByTag<SoundAmbiant>("Flap")->haveToPlay = true;
        gameAsStarted = true;
        velocityZ = jumpForce;
    }

    if (gameAsStarted) {
        if (resetScore) {
            GetEntityByName("Score").getComponent<Cereal::Text>()->text = "Score: 0";
            resetScore = false;
        }
        pipeSpawnTimer += deltaTime;

        auto transform = GetEntityByName("Player").getComponent<Cereal::Transform>();
        velocityZ += gravity * deltaTime;
        if (velocityZ < terminalVelocity)
            velocityZ = terminalVelocity;
        transform->position.z += velocityZ * deltaTime;        

        if (pipeSpawnTimer >= 2.5) {
            createPipes();
            pipeSpawnTimer = 0.0;
        }
    } else {
        RenderText("Press Space to start", Raylib::GetScreenWidth() / 2 - 120, Raylib::GetScreenHeight() / 2 + 50, 20, BLACK);
    }

}

void Game::createPipes() {
    topPipeCount++;
    bottomPipeCount++;

    std::string topPipeName = "TopPipe" + std::to_string(topPipeCount);
    std::string bottomPipeName = "BottomPipe" + std::to_string(bottomPipeCount);

    float gapY = static_cast<float>(rand() % 10 - 5);

    CreateEntity(gameScene, topPipeName)
        .addComponent<Cereal::Transform>(Cereal::Transform({30, 0, gapY + 12.5f}, {0, 0, 0}, 8.0f))
        .addComponent<Model3D>(Model3D("assets/models/pipe.glb", {1, 0, 0}, -90.0f))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{5, 5, 30})
        .addComponent<Render>(Render(true))
        .addTagToEntity("Pipe");

    AddLightShaderToModel(*GetEntityByNameInScene(topPipeName, gameScene).getComponent<Model3D>(), *GetLightComponentInScene(gameScene));

    CreateEntity(gameScene, bottomPipeName)
        .addComponent<Cereal::Transform>(Cereal::Transform({30, 0, gapY - 12.5f}, {0, 0, 0}, 8.0f))
        .addComponent<Model3D>(Model3D("assets/models/pipe.glb", {1, 0, 0}, 90.0f))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{5, 5, 30})
        .addComponent<Render>(Render(true))
        .addTagToEntity("Pipe");

    AddLightShaderToModel(*GetEntityByNameInScene(bottomPipeName, gameScene).getComponent<Model3D>(), *GetLightComponentInScene(gameScene));

    std::function<void()> pipeScript = [topPipeName, bottomPipeName]() {
        auto topPipe = GetEntityByName(topPipeName);
        auto bottomPipe = GetEntityByName(bottomPipeName);
        auto topPipeTransform = topPipe.getComponent<Cereal::Transform>();
        auto bottomPipeTransform = bottomPipe.getComponent<Cereal::Transform>();

        if (topPipeTransform->position.x <= -30) {
            DestroyEntity(topPipe);
            DestroyEntity(bottomPipe);
            GetEntityByName("Score").getComponent<Cereal::Text>()->text = "Score: " + std::to_string(std::stoi(GetEntityByName("Score").getComponent<Cereal::Text>()->text.substr(7)) + 1);
        }

        topPipeTransform->position.x -= (0.3f + (std::stoi(GetEntityByName("Score").getComponent<Cereal::Text>()->text.substr(7)) * 0.02));
        bottomPipeTransform->position.x -= (0.3f + (std::stoi(GetEntityByName("Score").getComponent<Cereal::Text>()->text.substr(7)) * 0.02));
    };

    GetEntityByNameInScene(topPipeName, gameScene).addComponent<Script>(Script(pipeScript));
}

void Game::handlePause() {

    for (auto& entity : GetEntitiesInCurrentScene()) {
        if (entity.tag == "Pipe")
            DestroyEntity(entity);
    }    

    gameAsStarted = false;
    const std::string actionDown = GetActionDown();

    RenderText("You Died", Raylib::GetScreenWidth() / 2 - 100, Raylib::GetScreenHeight() / 2 - 10, 50, BLACK);
    //score
    RenderText(("Score: " + GetEntityByName("Score").getComponent<Cereal::Text>()->text.substr(7)).c_str(), Raylib::GetScreenWidth() / 2 - 50, Raylib::GetScreenHeight() / 2 + 50, 20, BLACK);
    RenderText("Press Enter to restart", Raylib::GetScreenWidth() / 2 - 120, Raylib::GetScreenHeight() / 2 + 80, 20, BLACK);
    if (actionDown == "Enter")
        resetGame();
}

void Game::handleCollision() {
    if (CheckCollision(GetEntityByName("Player"), GetEntityByName("Floor") ) || CheckCollision(GetEntityByName("Player"), GetEntityByName("Roof"))) {
        isRunning = false;
    }

    for (auto& entity : GetEntitiesInCurrentScene()) {
        if (entity.tag == "Pipe") {
            if (CheckCollision(GetEntityByName("Player"), entity)) {
                isRunning = false;
            }
        }
    }
}

void Game::setupKeys() {
    MapKey("Action", Cereal::KeySpace, Cereal::InputType::Keyboard_T);
    // MapKey("Action", Cereal::ButtonDown, Cereal::InputType::Gamepad_T);
    MapKey("Enter", Cereal::KeyEnter, Cereal::InputType::Keyboard_T);
    MapKey("Enter", Cereal::Start, Cereal::InputType::Gamepad_T);
}

void Game::setupEntities() {
    CreateLight(gameScene, {0, -10, 300}, WHITE);

    CreateEntity(gameScene)
            .addComponent<MusicAmbiant>(MusicAmbiant("assets/musics/gamemusic.mp3", true, 1, 0.5f))
            .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 1.5f))
            .addComponent<Sprite>(Sprite("assets/textures/1.png", 0.01f, true))
            .addComponent<Render>(Render(true));

    CreateEntity(gameScene)
            .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 3.0f))
            .addComponent<Sprite>(Sprite("assets/textures/5.png", 0.003f, true))
            .addComponent<Render>(Render(true));

    CreateEntity(gameScene)
            .addComponent<Cereal::Transform>(Cereal::Transform({0, -20, 0}, {0, 0, 0}, 3.0f))
            .addComponent<Sprite>(Sprite("assets/textures/3.png", 0.025f, true))
            .addComponent<Render>(Render(true));

    /* Player */
    CreateEntity(gameScene, "Player")
            .addComponent<Cereal::Transform>(Cereal::Transform({0, 0, 0}, {0, 0, 0}, 1.0f))
            .addComponent<Stats>(Stats(100, 20, 0.1f))
            .addComponent<Model3D>(Model3D("assets/models/Plane.glb", {0.71, 0.71, 0}, 180.0f))
            .addComponent<Render>(Render(true))
            .addComponent<SoundAmbiant>(SoundAmbiant("assets/musics/flap.mp3", false, 2.0f)).addTag<SoundAmbiant>("Flap")
            .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{9, 5, 6});


    CreateEntity(gameScene, "Pipe") // Preload
            .addComponent<Model3D>(Model3D("assets/models/pipe.glb", {0, 0, 0}, 0.0f))
            .addComponent<Render>(Render(false))
            .addTagToEntity("Elementary");

    CreateEntity(gameScene, "Score")
            .addComponent<Cereal::Text>(Cereal::Text("Score: 0", {(float)Raylib::GetScreenWidth() / 2 - 50, 10}, 20, "assets/fonts/Chivo-Regular.ttf", BLACK))
            .addComponent<Cereal::Render>(Cereal::Render(true));

    CreateEntity(gameScene, "Roof")
            .addComponent<Cereal::Transform>(Cereal::Transform({0, 0, 18}, {0, 0, 0}, 0.01f))
            .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{100, 10, 10})
            .addComponent<Render>(Render(true));

    CreateEntity(gameScene, "Floor")
            .addComponent<Cereal::Transform>(Cereal::Transform({0, 0, -20}, {0, 0, 0}, 0.01f))
            .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{100, 10, 10})
            .addComponent<Render>(Render(true));

    AddLightToAllModelsInScene(GetLightComponentInScene(gameScene), gameScene);
}