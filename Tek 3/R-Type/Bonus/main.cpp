/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** main.cpp
*/

#include "src/F-Plane.h"

using namespace Cereal;
using namespace std::chrono;

static void LogicScene(GameLoop& gameLoop, Game& game, double& deltaTime, std::chrono::high_resolution_clock::time_point& lastTime) {
    auto currentTime = high_resolution_clock::now();
    duration<double> elapsed = currentTime - lastTime;
    lastTime = currentTime;
    deltaTime += elapsed.count();

    while (deltaTime >= 1.0 / FPS) {
        gameLoop.update();
        if (GetCurrentScene() == "GameScene") {
            game.run(deltaTime);
        } else {
            throw std::runtime_error("No scene found");
        }
        deltaTime -= 1.0 / FPS;
    }
}

void loop(GameLoop& gameLoop, Game& game) {
    using namespace std::chrono;
    auto lastTime = high_resolution_clock::now();
    double deltaTime = 0.0;

    while (!gameLoop.WindowShouldClose()) {
        StartDrawing();
        gameLoop.render();
        LogicScene(gameLoop, game, deltaTime, lastTime);
        StopDrawing();
        gameLoop.audio();
    }
}

int main() {
    try {
        Engine engine(SCREEN_WIDTH, SCREEN_HEIGHT, "F-Plane", FPS, false);
        StartDrawing();
        Cereal::RenderText("Loading Game...", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, 30, BLACK);
        StopDrawing();
        Game game;

        /* Global entities  for all scenes */
        CreateGlobalCamera({0.0f, -40.0f, 0.01f}, {0, 0, 0}, {0, 1, 0});
        loop(engine.gameLoop, game);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}
