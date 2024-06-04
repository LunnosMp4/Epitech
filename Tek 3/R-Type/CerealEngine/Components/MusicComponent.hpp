/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** MusicComponent.hpp
*/

#pragma once

#include "../Systems/Resource/ResourceManager.hpp"
#include "../Systems/Component/Component.hpp"

namespace Cereal {
    class MusicAmbiant : public ComponentBase {
        public:
            Music music;
            bool haveToPlay;
            bool haveToStop = false;

            MusicAmbiant() = default;
            MusicAmbiant(const std::string& musicPath, bool haveToPlay = true, bool loop = true, float volume = 1) : haveToPlay(haveToPlay) {
                music = ResourceManager::getInstance().getMusic(musicPath, loop, volume);
            }
            ~MusicAmbiant() = default;
    };
}
