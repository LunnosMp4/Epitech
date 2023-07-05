/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Update.cpp
*/

#include "Game.hpp"

using namespace Zappy;

static float cameraRotationAngle = 0.0f;

void Game::selectTile() {
    for (auto& tile : _tiles) {
        float x = tile.position.x;
        float y = tile.position.y;
        float z = tile.position.z;

        Ray ray = raylib->getMouseRay(raylib->getMousePosition(), _camera);
        BoundingBox box = {
            (Vector3){ x - tileSize / 2, y, z - tileSize / 2 },
            (Vector3){ x + tileSize / 2, y + tileSize, z + tileSize / 2 }
        };
        RayCollision collision = raylib->getRayCollisionBox(ray, box);

        if (collision.hit && tile.position.x != 0.0f && tile.position.z != 0.0f && tile.position.x != _mapSizeVector.x * tileSize - tileSize && tile.position.z != _mapSizeVector.y * tileSize - tileSize && _hoveredCharacter.position.x == 0.0f && _hoveredCharacter.position.z == 0.0f) {
            _hoveredTile = tile;
            if (raylib->isMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                PlaySound(_sounds["click"]);
                if (tile.position.x == _selectedTile.position.x && tile.position.z == _selectedTile.position.z)
                    _selectedTile = Tile(Vector3{0, 0, 0});
                else {
                    _selectedTile = tile;
                }
            }
            break;
        } else if (!collision.hit) {
            _hoveredTile = Tile(Vector3{0, 0, 0});
        }
    }
}

void Game::selectCharacter() {
    Vector2 mousePosition = raylib->getMousePosition();
    Ray ray = GetMouseRay(mousePosition, _camera);
    bool characterSelected = false;

    for (const auto& character : _characters) {
        BoundingBox box = {
            { character.currentPosition.x - 1.0f, character.currentPosition.y, character.currentPosition.z - 1.0f },
            { character.currentPosition.x + 1.0f, character.currentPosition.y + 2.0f, character.currentPosition.z + 1.0f }
        };

        RayCollision collision = GetRayCollisionBox(ray, box);

        if (collision.hit) {
            if (_cameraMode == ORBITAL) {
                _hoveredCharacter = character;
                _cursor = "cursor_select";
            }
            if (raylib->isMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                PlaySound(_sounds["click"]);
                _camera.fovy = 45.0f;
                _selectedCharacter = character;
                _cameraMode = PLAYER;
                _network->send("pin " + std::to_string(character.id) + "\n");
                _network->send("plv " + std::to_string(character.id) + "\n");
                characterSelected = true;
                break;
            }
        } else {
            _cursor = "cursor_normal";
            _hoveredCharacter = Character(Vector3{0, 0, 0});
            if (_selectedCharacter.isValid() && _cameraMode == PLAYER && raylib->isMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                _selectedCharacter = Character(Vector3{0, 0, 0});
                float cameraX = _mapSizeVector.x * 2.0f / 2.0f;
                float cameraY = _mapSizeVector.y * 2.0f / 2.0f;
                _camera.target = { cameraX, 0.0f, cameraY };
                _camera.position = { cameraX, cameraY * 2, cameraY * 3 };
                _cameraMode = ORBITAL;
            }
        }
        
        if (characterSelected)
            break;
    }
}

void Game::ToggleFullScreenWindow(int width, int height) {
}

void Game::KeyEvents() {
    if (_cameraMode == ORBITAL) {
        if (raylib->isKeyDown(KEY_LEFT_ALT)) {
            _cursor = "cursor_move";
            float mouseDeltaX = Cast(float, GetMouseDelta().x);
            cameraRotationAngle += mouseDeltaX * 0.1f;
            float cameraX = _mapSizeVector.x * 2.0f / 2.0f;
            float cameraY = _mapSizeVector.y * 2.0f / 2.0f;
            _camera.position.x = cos(DEG2RAD * cameraRotationAngle) * cameraY * 2.0f + cameraX;
            _camera.position.z = sin(DEG2RAD * cameraRotationAngle) * cameraY * 2.0f + cameraY;
        }
        if (raylib->isKeyReleased(KEY_LEFT_ALT))
            _cursor = "cursor_normal";
        float mouseWheelDelta = Cast(float, GetMouseWheelMove());
        _camera.fovy -= mouseWheelDelta * 2.0f;
        _camera.fovy = std::clamp(_camera.fovy, 10.0f, 45.0f);
    }
    if (_cameraMode == PLAYER) {
        for (const auto& character : _characters) {
            if (character.id == _selectedCharacter.id) {
                _selectedCharacter = character;
                break;
            }
        }
        
        _camera.target = (Vector3){
            _selectedCharacter.currentPosition.x,
            _selectedCharacter.currentPosition.y + 2.0f,
            _selectedCharacter.currentPosition.z
        };

        float cameraDistance = 5.0f;

        switch (_selectedCharacter.orientation) {
            case 1:
                _camera.position = Vector3Subtract(_camera.target, { 0.0f, -2.0f, cameraDistance });
                break;
            case 2:
                _camera.position = Vector3Subtract(_camera.target, { cameraDistance, -2.0f, 0.0f });
                break;
            case 3:
                _camera.position = Vector3Add(_camera.target, { 0.0f, 2.0f, cameraDistance });
                break;
            case 4:
                _camera.position = Vector3Add(_camera.target, { cameraDistance, 2.0f, 0.0f });
                break;
        }
        _camera.up = { 0.0f, 5.0f, 0.0f };
    }
    if (_selectedCharacter.isValid()) {
        if (raylib->isKeyPressed(KEY_RIGHT)) {
            for (const auto& character : _characters) {
                if (character.id == _selectedCharacter.id + 1) {
                    _selectedCharacter = character;
                    _network->send("pin " + std::to_string(character.id) + "\n");
                    _network->send("plv " + std::to_string(character.id) + "\n");
                    break;
                }
            }
        }
        if (raylib->isKeyPressed(KEY_LEFT)) {
            for (const auto& character : _characters) {
                if (character.id == _selectedCharacter.id - 1) {
                    _selectedCharacter = character;
                    _network->send("pin " + std::to_string(character.id) + "\n");
                    _network->send("plv " + std::to_string(character.id) + "\n");
                    break;
                }
            }
        }
    }
    if (raylib->isKeyPressed(KEY_F1))
        _displayHelp = !_displayHelp;
    if (raylib->isKeyPressed(KEY_F2)) {
        _resourcesTotal.clear();
        for (const auto& tile : _tiles) {
            for (const auto& resource : tile.getResourcesMap()) {
                if (_resourcesTotal.find(resource.first) == _resourcesTotal.end()) {
                    _resourcesTotal[resource.first] = resource.second;
                } else {
                    _resourcesTotal[resource.first] = std::to_string(std::stoi(_resourcesTotal[resource.first]) + std::stoi(resource.second));
                }
            }
        }
        _displayResources = !_displayResources;        
    }
    if (raylib->isKeyPressed(KEY_F3))
        _displayTeams = !_displayTeams;
    if (raylib->isKeyPressed(KEY_ENTER) && (raylib->isKeyDown(KEY_LEFT_ALT) || raylib->isKeyDown(KEY_RIGHT_ALT))) {
        ToggleFullScreenWindow(800, 450);
    }
}

void Game::updateAnimations() {
    if (!_characters.empty()) {
        for (auto& character : _characters) {
            ModelAnimation anim;
            if (character.animType == AnimType::IDLE)
                anim = character.modelAnimations[AnimType::IDLE];
            else if (character.animType == AnimType::RUN)
                anim = character.modelAnimations[AnimType::RUN];
            else if (character.animType == AnimType::JUMP)
                anim = character.modelAnimations[AnimType::JUMP];

            character.animCurrentFrame = (character.animCurrentFrame + 1) % anim.frameCount;
            UpdateModelAnimation(character.model, anim, character.animCurrentFrame);
        }
    }
}

void Game::updatePositions() {
    for (const auto& character : _characters) {
        character.currentPosition.x = character.position.x * tileSize + 2.0f;
        character.currentPosition.y = 1.0f;
        character.currentPosition.z = character.position.z * tileSize + 2.0f;

        if (character.isMoving) {
            float t = (float)(raylib->getTime() - character.moveStartTime) / character.moveDuration;
            if (abs(character.newPosition.x - character.position.x) > 5.0f || abs(character.newPosition.z - character.position.z) > 5.0f) {

                Vector2 particleSize = { 2.0f, 2.0f };
                Vector3 particleVelocityStart = { 0.0f, 3.0f, 0.0f };
                Vector3 particleVelocityEnd = { 0.0f, -3.0f, 0.0f };
                Color particleColor = WHITE;
                int numParticles = 4;
                _particles.CreateVector2Particle((Vector2) {character.newPosition.x * tileSize + 2.0f, character.newPosition.z * tileSize + 2.0f}, particleVelocityEnd, particleSize, particleColor, numParticles, character.moveDuration);
                _particles.CreateVector2Particle((Vector2) {character.position.x * tileSize + 2.0f, character.position.z * tileSize + 2.0f}, particleVelocityStart, particleSize, particleColor, numParticles, character.moveDuration);
                if (t >= 1.0f) {
                    character.position.x = character.newPosition.x;
                    character.position.z = character.newPosition.z;
                    character.currentPosition.x = character.position.x * tileSize + 2.0f;
                    character.currentPosition.z = character.position.z * tileSize + 2.0f;
                    character.isMoving = false;
                    character.animType = AnimType::IDLE;
                }
            } else if (t >= 1.0f) {
                character.position.x = character.newPosition.x;
                character.position.z = character.newPosition.z;
                character.currentPosition.x = character.position.x * tileSize + 2.0f;
                character.currentPosition.z = character.position.z * tileSize + 2.0f;
                character.isMoving = false;
                character.animType = AnimType::IDLE;
            } else {
                character.currentPosition.x = character.position.x * tileSize + 2.0f + (character.newPosition.x - character.position.x) * t * tileSize;
                character.currentPosition.z = character.position.z * tileSize + 2.0f + (character.newPosition.z - character.position.z) * t * tileSize;
            }
        }
    }
}

void Game::updateLevel() {
    for (const auto& character : _characters) {
        if (character.isIncantating) {
            float t = (float)(GetTime() - character.incantationStartTime) / character.incantationDuration;
            t = std::clamp(t, 0.0f, 1.0f);
            if (t >= 1.0f) {
                character.isIncantating = false;
                character.currentPosition.y = 1.0f;
            }
            float offset = sin(GetTime() * 10.0f) * 0.2f;
            character.currentPosition.y = character.position.y + offset + 0.5;
        }
    }
}

void Game::ejectCharacter() {
    for (const auto& character : _characters) {
        if (character.isEjected) {
            float t = (float)(GetTime() - character.ejectStartTime) / character.ejectDuration;
            t = std::clamp(t, 0.0f, 1.0f);
            if (t >= 1.0f) {
                character.isEjected = false;
                character.position.x = character.newPosition.x;
                character.position.z = character.newPosition.z;
                character.currentPosition.x = character.position.x * tileSize + 2.0f;
                character.currentPosition.z = character.position.z * tileSize + 2.0f;
            } else {
                character.currentPosition.x = character.position.x * tileSize + 2.0f + (character.newPosition.x - character.position.x) * t * tileSize;
                character.currentPosition.z = character.position.z * tileSize + 2.0f + (character.newPosition.z - character.position.z) * t * tileSize;
            }
        }
    }
}

void Game::update() {
    _response = _network->receive();
    parseResponse();
    if (!_displayHelp) {
        selectTile();
        selectCharacter();
    }

    KeyEvents();
    updateAnimations();
    updatePositions();
    updateLevel();
    _particles.UpdateParticles();

    if (_pause.getFrequency() != _frequency)
        _network->send("sst " + std::to_string((int) _pause.getFrequency()) + "\n");

    static float lightRotationAngle = 0.0f;

    _light.position.x = cos(DEG2RAD * lightRotationAngle) * 13;
    _light.position.z = sin(DEG2RAD * lightRotationAngle) * 13;
    lightRotationAngle += 0.1f;

    raylib->updateLightValues(_shader, _light);
    raylib->setShaderValue(_shader, _shader.locs[SHADER_LOC_VECTOR_VIEW], &_camera.position.x, SHADER_UNIFORM_VEC3);
}