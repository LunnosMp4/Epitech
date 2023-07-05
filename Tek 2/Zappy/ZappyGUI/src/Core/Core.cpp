/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Core.cpp
*/

#include "Core.hpp"
#include "raygui.h"

using namespace Zappy;

Core::Core(int ac, char **av) {
    if (ac == 1)
        initLauncher();
    else
        parseArgs(ac, av);
}

void Core::parseArgs(int ac, char **av) {
    if (ac == 2 && std::string(av[1]) == "-help") {
        printHelp();
        exit(0);
    }
    if (ac != 5) {
        std::cerr << "Invalid number of arguments" << std::endl;
        exit(84);
    }
    for (int i = 1; i < ac; i += 2) {
        std::string arg(av[i]);
        if (arg == "-p")
            _port = av[i + 1];
        else if (arg == "-h")
            _ip = av[i + 1];
        else {
            std::cerr << "Invalid arguments" << std::endl;
            exit(84);
        }
    }

    if (stoi(_port) < 0 || stoi(_port) > 65535) {
        std::cerr << "Invalid port number" << std::endl;
        exit(84);
    }
    if (_ip == "localhost")
        _ip = "127.0.0.1";
}

void Core::printHelp() const {
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

void Core::initLauncher() {
    useLauncher = true;
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib->setTraceLogLevel(LOG_NONE);
    raylib->setConfigFlags(FLAG_WINDOW_UNDECORATED);
    raylib->setConfigFlags(FLAG_MSAA_4X_HINT);
    raylib->initWindow(screenWidth, screenHeight, "Zappy Launcher");
    raylib->setTargetFPS(144);
    raylib->setExitKey(0);
    GuiLoadStyle("resources/jungle.rgs");

    _camera.offset = {screenWidth, screenHeight};
    _camera.target = {0.0f, 0.0f};
    _camera.rotation = 0.0f;
    _camera.zoom = 1.0f;

    _background = LoadTexture("resources/images/background.png");
}

void Core::updateLauncher() {
    if (raylib->checkCollisionPointRec(GetMousePosition(), {50, 140, 200, 40}) && raylib->isMouseButtonPressed(MOUSE_LEFT_BUTTON))
        _ipIsHovered = true;
    else if (raylib->isMouseButtonPressed(MOUSE_LEFT_BUTTON) && !raylib->checkCollisionPointRec(GetMousePosition(), {50, 140, 200, 40}))
        _ipIsHovered = false;

    if (raylib->checkCollisionPointRec(GetMousePosition(), {50, 220, 200, 40}) && raylib->isMouseButtonPressed(MOUSE_LEFT_BUTTON))
        _portIsHovered = true;
    else if (raylib->isMouseButtonPressed(MOUSE_LEFT_BUTTON) && !raylib->checkCollisionPointRec(GetMousePosition(), {50, 220, 200, 40}))
        _portIsHovered = false;

    if (IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
        exit(0);
    }

    Vector2 mousePos = GetMousePosition();
    if (CheckCollisionPointRec(mousePos, {0, 0, static_cast<float>(_background.width), static_cast<float>(_background.height)})) {
        float offsetX = mousePos.x / GetScreenWidth();
        float offsetY = mousePos.y / GetScreenHeight();
        float scaleFactor = 0.15;
        offsetX *= scaleFactor;
        offsetY *= scaleFactor;

        _backgroundPosition.x = -offsetX * (_background.width * 0.29 - GetScreenWidth());
        _backgroundPosition.y = -offsetY * (_background.height * 0.29 - GetScreenHeight());
    }
}

void Core::drawLauncher() {
    raylib->beginDrawing();
    raylib->clearBackground(RAYWHITE);
    raylib->drawTextureEx(_background, _backgroundPosition, 0, 0.29, WHITE);
    raylib->drawText("Game Launcher", 50, 50, 40, BLACK);
    raylib->drawText("Enter IP:", 50, 120, 20, BLACK);
    GuiTextBox({50, 140, 200, 40}, (char *) _ip.c_str(), 48, _ipIsHovered);
    raylib->drawText("Enter Port:", 50, 200, 20, BLACK);
    GuiTextBox({50, 220, 200, 40}, (char *) _port.c_str(), 48, _portIsHovered);
    if (GuiButton({500, 300, 200, 40}, "Launch Game")) {
        const char *ipC = _ip.c_str();
        const char *portC = _port.c_str();
        std::string ip(ipC);
        std::string port(portC);
        if (stoi(port) < 0 || stoi(port) > 65535) {
            std::cerr << "Invalid port number" << std::endl;
            exit(84);
        }
        if (ip == "localhost")
            ip = "127.0.0.1";
        _network = std::make_shared<Network>(ip, stoi(port));

        raylib->endDrawing();
        raylib->closeWindow();
        _game = std::make_shared<Game>(_network);

        _game->run();
    }
    if (GuiButton({710, 300, 50, 40}, "Exit"))
        exit(0);
    raylib->endDrawing();
}

void Core::run() {
    if (useLauncher) {
        while (!raylib->windowShouldClose()) {
            updateLauncher();
            drawLauncher();
        }
        raylib->closeWindow();
    } else {
        _network = std::make_shared<Network>(_ip, stoi(_port));
        _game = std::make_shared<Game>(_network);

        _game->run();
    }
}
