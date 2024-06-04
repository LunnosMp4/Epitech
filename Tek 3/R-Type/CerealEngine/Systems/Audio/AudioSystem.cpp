/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** AudioSystem.cpp
*/

#include "AudioSystem.hpp"

using namespace Cereal;

void AudioSystem::playSound(Cereal::SoundAmbiant* sound) {
    if (sound && sound->haveToPlay) {
        PlaySound(sound->sound);
        sound->haveToPlay = false;
    }
}

void AudioSystem::playMusic(MusicAmbiant* music) {
    if (music) {
        if (music->haveToPlay) {
            PlayMusicStream(music->music);
            music->haveToPlay = false;
        } else if (music->haveToStop) {
            StopMusicStream(music->music);
            music->haveToStop = false;
        }
        UpdateMusicStream(music->music);
    }
}

void AudioSystem::updateComponents() {
    for (auto& e : entityManager.getEntitiesOfCurrentScene()) {
        auto musics = e.getComponents<MusicAmbiant>();
        auto sounds = e.getComponents<Cereal::SoundAmbiant>();

        for (auto& music : musics)
            playMusic(music);
        for (auto& sound : sounds)
            playSound(sound);
    }
}