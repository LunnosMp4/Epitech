/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** main.cpp
*/

#include "src/NType.hpp"

using namespace Cereal;
using namespace std::chrono;

static void startClientConnection(Network::Client& client) {
    // Start network operations in a separate thread
    client.configConnection("127.0.0.1", 50000);
    client.connectToServer();

    std::thread clientThread([&client]() {
        client.start();
    });

    // Join the network thread after the game loop ends
    clientThread.detach();
}

static void LogicScene(GameLoop& gameLoop, Menu& menu, Game& game, Over& over, Win& win, double& deltaTime, std::chrono::high_resolution_clock::time_point& lastTime, Network::Client& client) {
    auto currentTime = high_resolution_clock::now();
    static bool isConnected = false;
    duration<double> elapsed = currentTime - lastTime;
    lastTime = currentTime;
    deltaTime += elapsed.count();

    while (deltaTime >= 1.0 / FPS) {
        gameLoop.update();
        if (!isConnected) {
            startClientConnection(client);
            isConnected = true;
        }
        if (client.getStartedGame() && GetCurrentScene() == "MenuScene") {
            SetCurrentScene("GameScene");
        }
        if (GetCurrentScene() == "GameScene") {
            game.isRunning = true;
            client.sendPacketType(PacketType::START_GAME);
            game.run(deltaTime, client);
        } else if (GetCurrentScene() == "MenuScene") {
            menu.run();
        } else if (GetCurrentScene() == "GameOverScene") {
            game.resetGame();
            over.run();
        } else if (GetCurrentScene() == "GameWinScene") {
            game.resetGame();
            win.run();
        } else {
            throw std::runtime_error("No scene found");
        }
        deltaTime -= 1.0 / FPS;
    }
}

void loop(GameLoop& gameLoop, Menu& menu, Game& game, Over& over, Win& win, Network::Client& client) {
    using namespace std::chrono;
    auto lastTime = high_resolution_clock::now();
    double deltaTime = 0.0;

    while (!gameLoop.WindowShouldClose()) {
        StartDrawing();
        gameLoop.render(false);
        LogicScene(gameLoop, menu, game, over, win, deltaTime, lastTime, client);
        StopDrawing();
        gameLoop.audio();
    }
}

Network::Client* globalClient = nullptr;

void cleanup() {
    // Perform any necessary cleanup before exiting the program
    // For example, disconnect the client, free resources, etc.
    if (globalClient) {
        globalClient->disconnectFromServer(); // Ensure the client is properly disconnected
    }
    // Additional cleanup tasks...
}

void signalHandler(int signum) {
    // std::cout << "Interrupt signal (" << signum << ") received.\n";
    cleanup();
    exit(signum);
}

int main() {
    try {
        /* Init Asio */
        asio::io_context io_context;
        Network::Client client(io_context);
        globalClient = &client; // Set global client pointer for signal handler

        Engine engine(SCREEN_WIDTH, SCREEN_HEIGHT, "R-Type", FPS, true);
        StartDrawing();
        Cereal::RenderText("Loading Game...", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, 30, BLACK);
        StopDrawing();

        Menu menu;
        Over over;
        Win win;
        Game game(1);

        /* Global entities  for all scenes */
        CreateGlobalCamera({0.0f, -40.0f, 0.01f}, {0, 0, 0}, {0, 1, 0});
        loop(engine.gameLoop, menu, game, over, win, client);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}
