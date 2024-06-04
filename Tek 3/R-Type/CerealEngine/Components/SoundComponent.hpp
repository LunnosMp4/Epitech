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
    class SoundAmbiant : public ComponentBase {
        public:
            Sound sound;
            bool haveToPlay;

            SoundAmbiant() = default;
            SoundAmbiant(const std::string& soundPath, bool haveToPlay = true, float volume = 1) : haveToPlay(haveToPlay) {
                sound = ResourceManager::getInstance().getSound(soundPath, volume);
            }
            ~SoundAmbiant() = default;
    };
}
