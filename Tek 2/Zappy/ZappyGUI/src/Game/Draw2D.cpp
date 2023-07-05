/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Draw2D.cpp
*/

#include "Game.hpp"

using namespace Zappy;

void Game::drawUI() {
    if (_selectedTile.isValid()) {
        float x =_selectedTile.position.x / 2 - 1.0f;
        float z =_selectedTile.position.z / 2 - 1.0f;
        raylib->drawRectangleRounded((Rectangle) {0, Cast(float, raylib->getScreenHeight() - 95), 290, 110}, 0.25, 4, Fade(BLACK, 0.4));
        raylib->drawText(TextFormat("Tile x : %.1f y : %.1f", x, z), 10, raylib->getScreenHeight() - 85, 20, WHITE);

        raylib->drawTextureEx(_textures2D["food"], (Vector2) {10, Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.06, WHITE);
        raylib->drawTextureEx(_textures2D["gem1"], (Vector2) {48 + 2, Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.035, WHITE);
        raylib->drawTextureEx(_textures2D["gem2"], (Vector2) {87 + 5, Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.05, WHITE);
        raylib->drawTextureEx(_textures2D["gem3"], (Vector2) {125.5 + 3, Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.05, WHITE);
        raylib->drawTextureEx(_textures2D["gem4"], (Vector2) {161 + 5, Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.05, WHITE);
        raylib->drawTextureEx(_textures2D["gem5"], (Vector2) {199 + 5, Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.04, WHITE);
        raylib->drawTextureEx(_textures2D["gem6"], (Vector2) {237, Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.05, WHITE);

        raylib->drawText(TextFormat("%s", _selectedTile.getResourcesMap()[0].c_str()), 10 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedTile.getResourcesMap()[1].c_str()), 48 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedTile.getResourcesMap()[2].c_str()), 87 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedTile.getResourcesMap()[3].c_str()), 125.5 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedTile.getResourcesMap()[4].c_str()), 161 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedTile.getResourcesMap()[5].c_str()), 199 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedTile.getResourcesMap()[6].c_str()), 237 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
    }
    if (_selectedCharacter.isValid()) {
        float x =_selectedCharacter.position.x;
        float z =_selectedCharacter.position.z;
        raylib->drawRectangleRounded((Rectangle) {Cast(float, raylib->getScreenWidth() - 290), Cast(float, raylib->getScreenHeight() - 155), 290, 165}, 0.25, 4, Fade(BLACK, 0.4));
        raylib->drawText(TextFormat("Character x : %.1f y : %.1f", x, z), raylib->getScreenWidth() - 280, raylib->getScreenHeight() - 145, 20, WHITE);
        raylib->drawText(TextFormat("Level : %d", _selectedCharacter.level), raylib->getScreenWidth() - 280, raylib->getScreenHeight() - 115, 20, WHITE);
        raylib->drawText(TextFormat("Team : %s", _selectedCharacter.team.c_str()), raylib->getScreenWidth() - 280, raylib->getScreenHeight() - 85, 20, WHITE);

        raylib->drawTextureEx(_textures2D["food"], (Vector2) {Cast(float, raylib->getScreenWidth() - 280), Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.06, WHITE);
        raylib->drawTextureEx(_textures2D["gem1"], (Vector2) {Cast(float, raylib->getScreenWidth() - 242 + 1), Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.035, WHITE);
        raylib->drawTextureEx(_textures2D["gem2"], (Vector2) {Cast(float, raylib->getScreenWidth() - 203 + 5), Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.05, WHITE);
        raylib->drawTextureEx(_textures2D["gem3"], (Vector2) {Cast(float, raylib->getScreenWidth() - 165 + 4), Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.05, WHITE);
        raylib->drawTextureEx(_textures2D["gem4"], (Vector2) {Cast(float, raylib->getScreenWidth() - 129 + 5), Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.05, WHITE);
        raylib->drawTextureEx(_textures2D["gem5"], (Vector2) {Cast(float, raylib->getScreenWidth() - 91 + 6), Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.04, WHITE);
        raylib->drawTextureEx(_textures2D["gem6"], (Vector2) {Cast(float, raylib->getScreenWidth() - 53 + 4), Cast(float, raylib->getScreenHeight() - 30)}, 0, 0.05, WHITE);

        raylib->drawText(TextFormat("%s", _selectedCharacter.getResourcesMap()[0].c_str()), raylib->getScreenWidth() - 280 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedCharacter.getResourcesMap()[1].c_str()), raylib->getScreenWidth() - 242 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedCharacter.getResourcesMap()[2].c_str()), raylib->getScreenWidth() - 203 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedCharacter.getResourcesMap()[3].c_str()), raylib->getScreenWidth() - 165 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedCharacter.getResourcesMap()[4].c_str()), raylib->getScreenWidth() - 129 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedCharacter.getResourcesMap()[5].c_str()), raylib->getScreenWidth() - 91 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
        raylib->drawText(TextFormat("%s", _selectedCharacter.getResourcesMap()[6].c_str()), raylib->getScreenWidth() - 53 + 10, raylib->getScreenHeight() - 55, 20, WHITE);
    }

    raylib->drawText(TextFormat("Camera mode : %s", _cameraMode == ORBITAL ? "Orbital" : "Player"), 10, 10, 20, WHITE);
    raylib->drawFPS(10, 30);

    if (_displayTeams) {
        raylib->drawRectangleRounded((Rectangle) {Cast(float, raylib->getScreenWidth() / 2 - 300), Cast(float, raylib->getScreenHeight() / 2 - 200), 600, 400}, 0.25, 4, Fade(BLACK, 0.7));
        raylib->drawText("Teams", raylib->getScreenWidth() / 2 - 20, raylib->getScreenHeight() / 2 - 180, 20, WHITE);
        std::unordered_map<std::string, int> teamCounts;
        for (const auto& character : _characters) {
            teamCounts[character.team]++;
        }

        int y = raylib->getScreenHeight() / 2 - 150;
        for (const auto& [teamName, count] : teamCounts) {
            std::string text = teamName + ": ";
            for (const auto& character : _characters) {
                if (character.team == teamName) {
                    text += std::to_string(character.id) + " ";
                }
            }
            raylib->drawText(text.c_str(), raylib->getScreenWidth() / 2 - 280, y, 20, WHITE);
            y += 30;
        }
    }

    if (_displayResources) {
        raylib->drawRectangleRounded((Rectangle) {Cast(float, raylib->getScreenWidth() / 2 - 300), Cast(float, raylib->getScreenHeight() / 2 - 200), 600, 400}, 0.25, 4, Fade(BLACK, 0.7));
        raylib->drawText("Resources", raylib->getScreenWidth() / 2 - 20, raylib->getScreenHeight() / 2 - 180, 20, WHITE);
        int y = raylib->getScreenHeight() / 2 - 110;
        raylib->drawTextureEx(_textures2D["food"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280), Cast(float, y)}, 0, 0.05, WHITE);
        raylib->drawText("Food", raylib->getScreenWidth() / 2 - 240, y, 20, WHITE);
        raylib->drawText(TextFormat("%s", _resourcesTotal[0].c_str()), raylib->getScreenWidth() / 2 - 100, y, 20, WHITE);
        y += 30;
        raylib->drawTextureEx(_textures2D["gem1"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280), Cast(float, y)}, 0, 0.03, WHITE);
        raylib->drawText("Linemate", raylib->getScreenWidth() / 2 - 240, y, 20, WHITE);
        raylib->drawText(TextFormat("%s", _resourcesTotal[1].c_str()), raylib->getScreenWidth() / 2 - 100, y, 20, WHITE);
        y += 30;
        raylib->drawTextureEx(_textures2D["gem2"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280), Cast(float, y)}, 0, 0.05, WHITE);
        raylib->drawText("Deraumere", raylib->getScreenWidth() / 2 - 240, y, 20, WHITE);
        raylib->drawText(TextFormat("%s", _resourcesTotal[2].c_str()), raylib->getScreenWidth() / 2 - 100, y, 20, WHITE);
        y += 30;
        raylib->drawTextureEx(_textures2D["gem3"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280), Cast(float, y)}, 0, 0.05, WHITE);
        raylib->drawText("Sibur", raylib->getScreenWidth() / 2 - 240, y, 20, WHITE);
        raylib->drawText(TextFormat("%s", _resourcesTotal[3].c_str()), raylib->getScreenWidth() / 2 - 100, y, 20, WHITE);
        y += 30;
        raylib->drawTextureEx(_textures2D["gem4"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280), Cast(float, y)}, 0, 0.05, WHITE);
        raylib->drawText("Mendiane", raylib->getScreenWidth() / 2 - 240, y, 20, WHITE);
        raylib->drawText(TextFormat("%s", _resourcesTotal[4].c_str()), raylib->getScreenWidth() / 2 - 100, y, 20, WHITE);
        y += 30;
        raylib->drawTextureEx(_textures2D["gem5"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280), Cast(float, y)}, 0, 0.05, WHITE);
        raylib->drawText("Phiras", raylib->getScreenWidth() / 2 - 240, y, 20, WHITE);
        raylib->drawText(TextFormat("%s", _resourcesTotal[5].c_str()), raylib->getScreenWidth() / 2 - 100, y, 20, WHITE);
        y += 30;
        raylib->drawTextureEx(_textures2D["gem6"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280), Cast(float, y)}, 0, 0.05, WHITE);
        raylib->drawText("Thystame", raylib->getScreenWidth() / 2 - 240, y, 20, WHITE);
        raylib->drawText(TextFormat("%s", _resourcesTotal[6].c_str()), raylib->getScreenWidth() / 2 - 100, y, 20, WHITE);
        y = raylib->getScreenHeight() / 2 - 110;
        int Total = 0;
        for (int i = 0; i < 7; i++)
            Total += std::stoi(_resourcesTotal[i]);
        raylib->drawText(TextFormat("Total : %d", Total), raylib->getScreenWidth() / 2 + 100, y, 20, WHITE);
    }

    if (_displayHelp) {
        DrawRectangleRounded((Rectangle) {Cast(float, raylib->getScreenWidth() / 2 - 300), Cast(float, raylib->getScreenHeight() / 2 - 200), 600, 400}, 0.25, 4, Fade(BLACK, 0.7));
        raylib->drawText("Help", raylib->getScreenWidth() / 2 - 20, raylib->getScreenHeight() / 2 - 180, 20, WHITE);
        raylib->drawText("Move camera : Hold alt + drag mouse", raylib->getScreenWidth() / 2 - 280, raylib->getScreenHeight() / 2 - 150, 20, WHITE);
        raylib->drawText("Zoom camera : Scroll mouse", raylib->getScreenWidth() / 2 - 280, raylib->getScreenHeight() / 2 - 120, 20, WHITE);
        raylib->drawText("Select tile : Left click", raylib->getScreenWidth() / 2 - 280, raylib->getScreenHeight() / 2 - 90, 20, WHITE);
        raylib->drawText("Select character : Left click", raylib->getScreenWidth() / 2 - 280, raylib->getScreenHeight() / 2 - 60, 20, WHITE);
        raylib->drawText("Resources", raylib->getScreenWidth() / 2 - 50, raylib->getScreenHeight() / 2, 20, WHITE);
        
        raylib->drawTextureEx(_textures2D["food"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280), Cast(float, raylib->getScreenHeight() / 2 + 30)}, 0, 0.06, WHITE);
        raylib->drawTextureEx(_textures2D["gem1"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280), Cast(float, raylib->getScreenHeight() / 2 + 60)}, 0, 0.035, WHITE);
        raylib->drawTextureEx(_textures2D["gem2"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280), Cast(float, raylib->getScreenHeight() / 2 + 90)}, 0, 0.05, WHITE);
        raylib->drawTextureEx(_textures2D["gem3"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280), Cast(float, raylib->getScreenHeight() / 2 + 120)}, 0, 0.05, WHITE);
        raylib->drawText("Food", raylib->getScreenWidth() / 2 - 280 + 50, raylib->getScreenHeight() / 2 + 30, 20, WHITE);
        raylib->drawText("Linemate", raylib->getScreenWidth() / 2 - 280 + 50, raylib->getScreenHeight() / 2 + 60, 20, WHITE);
        raylib->drawText("Deraumere", raylib->getScreenWidth() / 2 - 280 + 50, raylib->getScreenHeight() / 2 + 90, 20, WHITE);
        raylib->drawText("Sibur", raylib->getScreenWidth() / 2 - 280 + 50, raylib->getScreenHeight() / 2 + 120, 20, WHITE);
        raylib->drawTextureEx(_textures2D["gem4"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280 + 200), Cast(float, raylib->getScreenHeight() / 2 + 30)}, 0, 0.05, WHITE);
        raylib->drawTextureEx(_textures2D["gem5"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280 + 200), Cast(float, raylib->getScreenHeight() / 2 + 60)}, 0, 0.04, WHITE);
        raylib->drawTextureEx(_textures2D["gem6"], (Vector2) {Cast(float, raylib->getScreenWidth() / 2 - 280 + 200), Cast(float, raylib->getScreenHeight() / 2 + 90)}, 0, 0.05, WHITE);
        raylib->drawText("Mendiane", raylib->getScreenWidth() / 2 - 280 + 200 + 50, raylib->getScreenHeight() / 2 + 30, 20, WHITE);
        raylib->drawText("Phiras", raylib->getScreenWidth() / 2 - 280 + 200 + 50, raylib->getScreenHeight() / 2 + 60, 20, WHITE);
        raylib->drawText("Thystame", raylib->getScreenWidth() / 2 - 280 + 200 + 50, raylib->getScreenHeight() / 2 + 90, 20, WHITE);
    }
}