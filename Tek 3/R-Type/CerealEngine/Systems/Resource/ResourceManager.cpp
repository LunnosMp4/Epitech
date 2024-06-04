/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** RessourceManager.cpp
*/

#include "ResourceManager.hpp"

using namespace Cereal;

ResourceManager& ResourceManager::getInstance() {
    static ResourceManager instance;
    return instance;
}

void ResourceManager::cleanUp() {
//    auto& textures = getInstance()._textures;
//    for (auto& texture : textures) {
//        UnloadTexture(texture.second);
//    }
//    auto& models = getInstance()._models;
//    for (auto& model : models) {
//        UnloadModel(model.second);
//    }
//    auto& musics = getInstance()._musics;
//    for (auto& music : musics) {
//        UnloadMusicStream(music.second);
//    }
//    auto& sounds = getInstance()._sounds;
//    for (auto& sound : sounds) {
//        UnloadSound(sound.second);
//    }
}

Texture2D ResourceManager::getTexture(const std::string& filePath) {
    auto& textures = getInstance()._textures;
    if (textures.find(filePath) == textures.end()) {
        textures[filePath] = LoadTexture(filePath.c_str());
    }
    return textures[filePath];
}

Model ResourceManager::getModel(const std::string& filePath) {
    auto& models = getInstance()._models;
    if (models.find(filePath) == models.end()) {
        models[filePath] = LoadModel(filePath.c_str());
    }
    return models[filePath];
}

Music ResourceManager::getMusic(const std::string& filePath, bool loop, float volume) {
    auto& musics = getInstance()._musics;
    if (musics.find(filePath) == musics.end()) {
        musics[filePath].looping = loop;
        musics[filePath] = LoadMusicStream(filePath.c_str());
        SetMusicVolume(musics[filePath], volume);
    }
    return musics[filePath];
}

Sound ResourceManager::getSound(const std::string& filePath, float volume) {
    auto& sounds = getInstance()._sounds;
    if (sounds.find(filePath) == sounds.end()) {
        sounds[filePath] = LoadSound(filePath.c_str());
        SetSoundVolume(sounds[filePath], volume);
    }
    return sounds[filePath];
}

Font ResourceManager::getFont(const std::string& filePath) {
    auto& fonts = getInstance()._fonts;
    if (fonts.find(filePath) == fonts.end()) {
        fonts[filePath] = LoadFont(filePath.c_str());
    }
    return fonts[filePath];
}
