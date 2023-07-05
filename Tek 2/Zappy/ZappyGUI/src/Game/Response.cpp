/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Response.cpp
*/

#include "Game.hpp"

using namespace Zappy;

void Game::parseResponse() {
    if (_response.empty())
        return;

    std::cout << _response;

    std::istringstream iss(_response);
    std::string line;
    std::vector<std::string> tokens;
    while (std::getline(iss, line)) {
        std::istringstream lineIss(line);
        std::string token;
        while (lineIss >> token)
            tokens.push_back(token);
        if (tokens[0] == "msz") {
            _mapSizeVector.x = std::stoi(tokens[1]);
            _mapSizeVector.y = std::stoi(tokens[2]);
            _mapSizeVector.x += 2.0f;
            _mapSizeVector.y += 2.0f;
            createMap();
        }
        if (tokens[0] == "sgt" || tokens[0] == "sst") {
            _frequency = std::stoi(tokens[1]);
            _pause.setFrequency(_frequency);
        }
        if (tokens[0] == "bct") {
            int x = std::stoi(tokens[1]) + 1;
            int y = std::stoi(tokens[2]) + 1;
            int food = std::stoi(tokens[3]);
            int linemate = std::stoi(tokens[4]);
            int deraumere = std::stoi(tokens[5]);
            int sibur = std::stoi(tokens[6]);
            int mendiane = std::stoi(tokens[7]);
            int phiras = std::stoi(tokens[8]);
            int thystame = std::stoi(tokens[9]);
            for (auto& tile : _tiles) {
                if (tile.position.x / 2 == x && tile.position.z / 2 == y) {
                    tile.setResources(food, linemate, deraumere, sibur, mendiane, phiras, thystame);
                }
            }
        }
        if (tokens[0] == "pnw") {
            int id = std::stoi(tokens[1]);
            int x = std::stoi(tokens[2]);
            int y = std::stoi(tokens[3]);
            int orientation = std::stoi(tokens[4]);
            int level = std::stoi(tokens[5]);
            std::string team = tokens[6];
            for (auto& character : _characters) {
                if (character.id == id) {
                    character.position.x = x;
                    character.position.z = y;
                    character.orientation = orientation;
                    character.level = level;
                    character.team = team;
                    break;
                }
            }
            Character newCharacter((Vector3){ Cast(float, x), 0.5f, Cast(float, y) }, id, orientation, level, team);

            newCharacter.model = LoadModel("resources/character.glb");
            newCharacter.modelAnimations = LoadModelAnimations("resources/character.glb", &newCharacter.animsCount);
            for (int i = 0; i < newCharacter.model.materialCount; i++)
                newCharacter.model.materials[i].shader = _shader;
            _characters.push_back(newCharacter);;
        }
        if (tokens[0] == "pdi") {
            int id = std::stoi(tokens[1]);  
            if (_selectedCharacter.id == id) {
                _selectedCharacter = Character(Vector3{0, 0, 0});
                float cameraX = _mapSizeVector.x * 2.0f / 2.0f;
                float cameraY = _mapSizeVector.y * 2.0f / 2.0f;
                _camera.target = (Vector3){ cameraX, 0.0f, cameraY };
                _camera.position = (Vector3){ cameraX, cameraY * 2, cameraY * 3 };
                _cameraMode = ORBITAL;
            }
            for (auto it = _characters.begin(); it != _characters.end(); ) {
                if (it->id == id)
                    it = _characters.erase(it);
                else
                    ++it;
            }
        }
        if (tokens[0] == "pin") {
            int id = std::stoi(tokens[1]);
            int food = std::stoi(tokens[4]);
            int linemate = std::stoi(tokens[5]);
            int deraumere = std::stoi(tokens[6]);
            int sibur = std::stoi(tokens[7]);
            int mendiane = std::stoi(tokens[8]);
            int phiras = std::stoi(tokens[9]);
            int thystame = std::stoi(tokens[10]);
            for (auto& character : _characters) {
                if (character.id == id) {
                    character.setResources(food, linemate, deraumere, sibur, mendiane, phiras, thystame);
                    break;
                }
            }
        }
        if (tokens[0] == "plv") {
            int id = std::stoi(tokens[1]);
            int level = std::stoi(tokens[2]);
            for (auto& character : _characters) {
                if (character.id == id) {
                    character.level = level;
                    break;
                }
            }
        }
        if (tokens[0] == "ppo") {
            int id = std::stoi(tokens[1]);
            int x = std::stoi(tokens[2]);
            int y = std::stoi(tokens[3]);
            int orientation = std::stoi(tokens[4]);
            for (auto& character : _characters) {
                if (character.id == id) {
                    character.newPosition.x = x;
                    character.newPosition.z = y;
                    character.isMoving = true;
                    character.moveStartTime = GetTime();
                    character.moveDuration = 7.0f / _frequency - 0.1f;
                    if (character.orientation == orientation)
                        character.animType = AnimType::RUN;
                    character.orientation = orientation;
                    return;
                }
            }
        }
        if (tokens[0] == "pic") {
            int id = std::stoi(tokens[4]);
            for (auto& character : _characters) {
                if (character.id == id) {
                    PlaySound(_sounds["levelup"]);
                    character.isIncantating = true;
                    character.incantationStartTime = GetTime();
                    character.incantationStartTime = 300.0f / _frequency - 0.1f;
                    character.animType = AnimType::JUMP;
                    break;
                }
            }
        }
        if (tokens[0] == "pie") {}
        if (tokens[0] == "enw") {
            int eggId = std::stoi(tokens[1]);
            int id = std::stoi(tokens[2]);
            int x = std::stoi(tokens[3]);
            int y = std::stoi(tokens[4]);
            for (auto& egg : _eggs) {
                if (egg.id == eggId) {
                    egg.idParent = id;
                    egg.position.x = x;
                    egg.position.z = y;
                    return;
                }
            }

            Egg newEgg((Vector3){ Cast(float, x), 0.5f, Cast(float, y) }, eggId, id);
            newEgg.model = LoadModel("resources/egg.glb");
            for (int i = 0; i < newEgg.model.materialCount; i++)
                newEgg.model.materials[i].shader = _shader;
            _eggs.push_back(newEgg);
        }

        if (tokens[0] == "edi") {
            int eggId = std::stoi(tokens[1]);
            for (auto it = _eggs.begin(); it != _eggs.end(); ) {
                if (it->id == eggId)
                    it = _eggs.erase(it);
                else
                    ++it;
            }
        }
        if (tokens[0] == "pex") {
            int id = std::stoi(tokens[1]);
            for (auto& character : _characters) {
                if (character.id == id) {
                    character.animType = AnimType::JUMP;
                    character.isEjected = true;
                    character.ejectStartTime = GetTime();
                    character.ejectDuration = 7.0f / _frequency - 0.1f;
                    switch (character.orientation) {
                        case 1:
                            character.newPosition.z -= 1;
                            break;
                        case 2:
                            character.newPosition.x += 1;
                            break;
                        case 3:
                            character.newPosition.z += 1;
                            break;
                        case 4:
                            character.newPosition.x -= 1;
                            break;
                    }
                    break;
                }
            }
        }
        tokens.clear();
    }
}