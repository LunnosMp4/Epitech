/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** raylib->draw3D.cpp
*/

#include "Game.hpp"

using namespace Zappy;

static int calculateAngle(Vector2 mapSizeVector, int i, int j) {
    int angle = 0;
    if (i == 0 && j == 0)
        angle = 90;
    else if (i == 0 && j == (mapSizeVector.y * 2 - 2))
        angle = 180;
    else if (i == (mapSizeVector.x * 2 - 2) && j == 0)
        angle = 0;
    else if (i == (mapSizeVector.x * 2 - 2) && j == (mapSizeVector.y * 2 - 2))
        angle = -90;
    return angle;
}

static Vector3 calculateTreePos(Vector2 mapSizeVector, Vector3 posTree, int i, int j) {
    if (i == 0)
        posTree.x += 0.5f;
    else if (i == (mapSizeVector.x * 2 - 2))
        posTree.x -= 0.5f;
    else if (j == 0)
        posTree.z += 0.5f;
    else if (j == (mapSizeVector.y * 2 - 2))
        posTree.z -= 0.5f;
    posTree.y += 1.0f;
    return posTree;
}

void Game::drawMapTiles() {
    Model treeModels[] = {_models["treeA"], _models["treeB"], _models["treeC"]};
    srand(4);

    for (const auto& tile : _tiles) {
        float x = tile.position.x;
        float y = 0.0f;
        float z = tile.position.z;

        if (InvalidTile) {
            if ((tile.position.x == 0 && tile.position.z == 0) || (tile.position.x == 0 && tile.position.z == (_mapSizeVector.y * tileSize - tileSize)) || (tile.position.x == (_mapSizeVector.x * tileSize - tileSize) && tile.position.z == 0) || (tile.position.x == (_mapSizeVector.x * tileSize - tileSize) && tile.position.z == (_mapSizeVector.y * tileSize - tileSize))) {
                int angle = calculateAngle(_mapSizeVector, tile.position.x, tile.position.z);
                raylib->drawModelEx(_models["tileCorner"], (Vector3){ x, y, z }, (Vector3){ 0.0f, 1.0f, 0.0f }, angle, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
            } else {
                int angle = (tile.position.x == 0) ? 0 : (tile.position.x == (_mapSizeVector.x * tileSize - tileSize)) ? 180 : (tile.position.z == 0) ? -90 : 90;
                raylib->drawModelEx(_models["tileHalf"], (Vector3){ x, y, z }, (Vector3){ 0.0f, 1.0f, 0.0f }, angle, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);

                Vector3 posTree = calculateTreePos(_mapSizeVector, (Vector3){ x, y, z }, tile.position.x, tile.position.z);
                if (rand() % 2 == 0)
                    raylib->drawModelEx(treeModels[rand() % 3], posTree, (Vector3){ 0.0f, 1.0f, 0.0f }, rand() % 360, (Vector3){ 3.0f, 3.0f, 3.0f }, WHITE);
                else if (rand() % 2 == 0)
                    raylib->drawModelEx(_models["rock"], posTree, (Vector3){ 0.0f, 1.0f, 0.0f }, rand() % 360, (Vector3){ 1.2f, 1.2f, 1.2f }, WHITE);
            }
        } else {
            raylib->drawCubeWires((Vector3){ x, y, z }, tileSize, tileSize + 0.01f, tileSize, BLACK);
            raylib->drawModel(_models["tile"], (Vector3){ x, y, z }, 1.0f, WHITE);
        }
    }

    if (_hoveredTile.isValid()) {
        float x = _hoveredTile.position.x;
        float y = 0.0f;
        float z = _hoveredTile.position.z;

        raylib->drawCubeWires((Vector3){ x, y, z }, tileSize, tileSize + 0.01f, tileSize, WHITE);
    }

    if (_selectedTile.isValid()) {
        float x = _selectedTile.position.x;
        float y = 0.0f;
        float z = _selectedTile.position.z;

        raylib->drawModel(_models["tile"], (Vector3){ x, y, z }, 1.0f, BLACK); // TODO : Change opacity to 0.2
    }
}

void Game::drawCharacters() {
    for (const auto& character : _characters) {
        float rotation = 0;

        if (character.orientation == 1)
            rotation = 0;
        else if (character.orientation == 2)
            rotation = 90;
        else if (character.orientation == 3)
            rotation = 180;
        else if (character.orientation == 4)
            rotation = -90;

        raylib->drawModelEx(character.model, character.currentPosition, (Vector3){ 0.0f, 1.0f, 0.0f }, rotation, (Vector3){ 2.0f, 2.0f, 2.0f }, WHITE);
    }

    if (_hoveredCharacter.isValid()) {
        BoundingBox box = {
            (Vector3){ _hoveredCharacter.currentPosition.x - 1.0f, _hoveredCharacter.currentPosition.y, _hoveredCharacter.currentPosition.z - 1.0f },
            (Vector3){ _hoveredCharacter.currentPosition.x + 1.0f, _hoveredCharacter.currentPosition.y + 2.0f, _hoveredCharacter.currentPosition.z + 1.0f }
        };

        raylib->drawBoundingBox(box, WHITE);
    }
}

void Game::drawEggs() {
    for (const auto& egg : _eggs) {
        float x = egg.position.x * tileSize + 2.0f;
        float y = 1.0f;
        float z = egg.position.z * tileSize + 2.0f;

        raylib->drawModelEx(egg.model, (Vector3){ x, y, z }, (Vector3){ 1.0f, 0.0f, 0.0f }, -90, (Vector3){ 0.3f, 0.3f, 0.3f }, WHITE);
    }
}

void Game::drawResources() {
    for (auto& tile : _tiles) {
        if (InvalidTile)
            continue;
        tile.drawResources(_models);
    }
}
