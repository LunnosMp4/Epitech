/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** RessourceManager.hpp
*/

#pragma once

#include <unordered_map>
namespace Raylib {
    #include <raylib.h>
}
using namespace Raylib;
#include <string>

namespace Cereal {
    class ResourceManager {
        public:
            // @brief Get the instance of the singleton
            // @return The instance
            static ResourceManager& getInstance();
            // @brief Clean up all the resources when the game is closed
            void cleanUp();


            // @brief Get a texture asked and create it if it doesn't exist
            // @param filePath The path of the texture
            // @return The texture
            Texture2D getTexture(const std::string& filePath);

            // @brief Get a model asked and create it if it doesn't exist
            // @param filePath The path of the model
            // @return The model
            Model getModel(const std::string& filePath);

            // @brief Get a music asked and create it if it doesn't exist
            // @param filePath The path of the music
            // @param loop If the music have to loop
            // @param volume The volume of the music
            // @return The music
            Music getMusic(const std::string& filePath, bool loop, float volume);

            // @brief Get a sound asked and create it if it doesn't exist
            // @param filePath The path of the sound
            // @param volume The volume of the sound
            // @return The sound
            Sound getSound(const std::string& filePath, float volume);

            // @brief Get a font asked and create it if it doesn't exist
            // @param filePath The path of the font
            // @return The font
            Font getFont(const std::string& filePath);

        private:
            ResourceManager() = default;
            ~ResourceManager() = default;

            std::unordered_map<std::string, Texture2D> _textures;
            std::unordered_map<std::string, Model> _models;
            std::unordered_map<std::string, Music> _musics;
            std::unordered_map<std::string, Sound> _sounds;
            std::unordered_map<std::string, Font> _fonts;
        };
}