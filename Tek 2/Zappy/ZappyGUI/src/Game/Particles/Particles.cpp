/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Particles.cpp
*/

#include "Particles.hpp"

using namespace Zappy;

void Particles::CreateParticle(const Vector3& position, const Vector3& velocity, const Color& color, float lifetime) {
    _particles.emplace_back(position, velocity, color, lifetime);
}

void Particles::CreateVector2Particle(const Vector2& position, const Vector3& velocity, const Vector2& size, const Color& color, int numParticles, float lifetime) {
    _particles.reserve(_particles.size() + numParticles * numParticles);

    float halfWidth = size.x / 2.0f;
    float halfHeight = size.y / 2.0f;
    float spacingX = size.x / (numParticles - 1);
    float spacingY = size.y / (numParticles - 1);

    float height = (velocity.y < 0) ? -velocity.y : 0.0f;

    for (int i = 0; i < numParticles; ++i) {
        float posX = position.x - halfWidth + spacingX * i;

        for (int j = 0; j < numParticles; ++j) {
            float posY = position.y - halfHeight + spacingY * j;

            Vector3 particlePosition = { posX, 1.0f + height, posY };
            Color particleColor = color;
            _particles.emplace_back(particlePosition, velocity, particleColor, lifetime);
        }
    }
}

void Particles::UpdateParticles() {
    float frameTime = GetFrameTime();
    for (auto it = _particles.begin(); it != _particles.end(); ) {
        Particle& particle = *it;
        particle.position.x += particle.velocity.x * frameTime;
        particle.position.y += particle.velocity.y * frameTime;
        particle.position.z += particle.velocity.z * frameTime;
        particle.lifetime -= frameTime;

        if (particle.lifetime <= 0.0f) {
            it = _particles.erase(it);
        } else {
            ++it;
        }
    }
}

void Particles::RenderParticles() {
    for (const auto& particle : _particles) {
        DrawSphere(particle.position, 0.1f, particle.color);
    }
}