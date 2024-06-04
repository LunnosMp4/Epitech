/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** AudioSystem.hpp
*/

#pragma once

#include "../Entity/EntityManager.hpp"
#include "../../Components/MusicComponent.hpp"
#include "../../Components/SoundComponent.hpp"

namespace Cereal {
    class AudioSystem {
    public:
        EntityManager& entityManager;

        AudioSystem(EntityManager& entityManager) : entityManager(entityManager) {};

        // @brief Play a sound
        // @param sound The sound to play
        void playSound(Cereal::SoundAmbiant* sound);

        // @brief Play a music
        // @param music The music to play
        void playMusic(MusicAmbiant* music);
        
        // @brief Update all components
        void updateComponents();
    };
}