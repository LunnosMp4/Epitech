/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Game.hpp
*/

#pragma once

#include "ZappyGUI.h"
#include "Raylib.hpp"
#include "Network.hpp"
#include "Tile.hpp"
#include "Character.hpp"
#include "Egg.hpp"
#include "Pause.hpp"
#include "Particles.hpp"

namespace Zappy
{

    class Game
    {
        public:
            Game(std::shared_ptr<Network> network);
            ~Game();

            void run();
            void update();

        private:
            void initWindow();
            void loadModels();
            void loadShader();
            void loadLights();
            void loadImages();
            void createMap();
            void parseResponse();
            void KeyEvents();
            void selectTile();
            void selectCharacter();
            void updateAnimations();
            void updatePositions();
            void ejectCharacter();
            void updateLevel();
            void drawMapTiles();
            void drawCharacters();
            void drawEggs();
            void drawResources();
            void drawUI();
            void drawMouse();
            void initAudio();
            void stopAudio();
            void ToggleFullScreenWindow(int width, int height);

        private:
            std::shared_ptr<Network> _network;
            std::shared_ptr<Raylib> raylib;

            int _screenWidth;
            int _screenHeight;

            Shader _shader;
            Shader _bgShader;
            RenderTexture2D _bgShaderTarget;
            Model _skybox;
            Vector2 _mapSizeVector;
            int _frequency;
            bool _displayHelp = false;
            bool _displayResources = false;
            bool _displayTeams = false;
            std::string _cursor = "cursor_normal";
            
            // Camera
            enum CameraMode {
                ORBITAL,
                PLAYER
            };
            CameraMode _cameraMode = ORBITAL;
            Camera3D _camera;

            Pause _pause;

            // Tiles
            std::vector<Tile> _tiles;
            Tile _hoveredTile = Tile(Vector3{0, 0, 0});
            Tile _selectedTile = Tile(Vector3{0, 0, 0});
            std::map<int, std::string> _resourcesTotal;

            // Characters
            std::vector<Character> _characters;
            Character _selectedCharacter = Character(Vector3{0, 0, 0});
            Character _hoveredCharacter = Character(Vector3{0, 0, 0});
            enum AnimType {
                ATTACK,
                CRINGE,
                IDLE,
                JUMP,
                RUN
            };

            // Egg
            std::vector<Egg> _eggs;

            // Particles
            Particles _particles;

            // Models
            std::map<std::string, Model> _models;

            // Images
            std::map<std::string, Image> _images;

            // Textures2D
            std::map<std::string, Texture2D> _textures2D;

            // Lights
            Light _light;

            // Network
            std::string _response;

            // Audio
            Music _music;
            std::map<std::string, Sound> _sounds;
    };
}