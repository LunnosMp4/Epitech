/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** _Particles.hpp
*/

#pragma once

#include "ZappyGUI.h"

namespace Zappy {
    class Particles {
        public:
            Particles() {};
            ~Particles() {};

            void CreateParticle(const Vector3& position, const Vector3& velocity, const Color& color, float lifetime);
            void CreateVector2Particle(const Vector2& position, const Vector3& velocity, const Vector2& size, const Color& color, int numParticles, float lifetime);

            void UpdateParticles();
            void RenderParticles();

        private:
            struct Particle {
                Vector3 position;
                Vector3 velocity;
                Color color;
                float lifetime;

                Particle(const Vector3& pos, const Vector3& vel, const Color& col, float lt)
                    : position(pos), velocity(vel), color(col), lifetime(lt)
                {
                }
            };

            std::vector<Particle> _particles;
    };
}