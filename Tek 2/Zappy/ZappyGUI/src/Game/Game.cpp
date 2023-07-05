/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Game.cpp
*/

#include "Game.hpp"

#define GLSL_VERSION    330

using namespace Zappy;

Game::Game(std::shared_ptr<Network> network) : _network(network) {
    _network->send("GRAPHIC\n");
    initWindow();
}

Game::~Game() {
    for (auto& modelPair : _models)
        raylib->unloadModel(modelPair.second);
    _models.clear();
    raylib->closeWindow();
    stopAudio();
}

void Game::initWindow() {
    _screenWidth = 1920;
    _screenHeight = 1080;

    raylib->setTraceLogLevel(LOG_NONE);
    raylib->setConfigFlags(FLAG_MSAA_4X_HINT);
    raylib->setConfigFlags(FLAG_WINDOW_RESIZABLE);
    raylib->initWindow(_screenWidth, _screenHeight, "Zappy");
    raylib->setTargetFPS(144);
    raylib->setExitKey(0);
    GuiLoadStyle("resources/jungle.rgs");
    _camera.position = (Vector3){ 12.0f, 20.0f, 40.0f };
    _camera.target = (Vector3){ 12.0f, -10.0f, 0.0f };
    _camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
}

void Game::createMap() {
    for (int i = 0; i < _mapSizeVector.x; i++) {
        for (int j = 0; j < _mapSizeVector.y; j++) {
            float x = i * tileSize;
            float y = 0.0f;
            float z = j * tileSize;

            Vector3 tilePosition = {x, y, z};
            Tile tile(tilePosition);
            _tiles.push_back(tile);
        }
    }
}

void Game::drawMouse() {
    if (_cursor == "cursor_normal")
        raylib->drawTextureEx(_textures2D[_cursor], (Vector2) {Cast(float, GetMouseX()), Cast(float, GetMouseY())}, 0, 0.4, WHITE);
    if (_cursor == "cursor_select")
        raylib->drawTextureEx(_textures2D[_cursor], (Vector2) {Cast(float, GetMouseX()), Cast(float, GetMouseY())}, 0, 0.5, WHITE);
    if (_cursor == "cursor_move")
        raylib->drawTextureEx(_textures2D[_cursor], (Vector2) {Cast(float, GetMouseX()), Cast(float, GetMouseY())}, 0, 0.5, WHITE);
}

void Game::run() {
    HideCursor();
    _response = _network->receiveLoop();
    parseResponse();

    float cameraX = _mapSizeVector.x * 2.0f / 2.0f;
    float cameraY = _mapSizeVector.y * 2.0f / 2.0f;
    _camera.target = (Vector3){ cameraX, 0.0f, cameraY };
    _camera.position = (Vector3){ cameraX, cameraY * 2, cameraY * 3 };

    loadShader();
    loadModels();
    loadLights();
    loadImages();
    initAudio();

    while (!raylib->windowShouldClose()) {
        try {
            _pause.update();
            if (!_pause.getPause())
                update();

            raylib->beginDrawing();
            if (_pause.getPause()) raylib->beginTextureMode(_bgShaderTarget);
            raylib->clearBackground(BLANK);
            raylib->beginMode3D(_camera);

                rlDisableBackfaceCulling();
                rlDisableDepthMask();
                    raylib->drawModel(_skybox, (Vector3){0, 0, 0}, 1.0f, WHITE);
                rlEnableBackfaceCulling();
                rlEnableDepthMask();

                drawMapTiles();
                drawCharacters();
                drawEggs();
                drawResources();
                _particles.RenderParticles();
            raylib->endMode3D();
            if (_pause.getPause()) {
                EndTextureMode();
                ClearBackground(RAYWHITE);
                raylib->beginShaderMode(_bgShader);
                    raylib->drawTextureRec(_bgShaderTarget.texture, (Rectangle){ 0, 0, (float)_bgShaderTarget.texture.width, (float)-_bgShaderTarget.texture.height }, (Vector2){ 0, 0 }, WHITE);
                raylib->endShaderMode();
            }

            if (!_pause.getPause())
                drawUI();
            else
                _pause.draw();
            drawMouse();
            raylib->endDrawing();
            raylib->updateMusicStream(_music); 
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
