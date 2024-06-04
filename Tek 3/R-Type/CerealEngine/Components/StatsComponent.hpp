/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** StatsComponent.cpp
*/

#pragma once

#include "../Systems/Component/Component.hpp"

namespace Cereal {
    class Stats : public ComponentBase {
        public:
            float health;
            float damage;
            float velocity;

            Stats(float health = 0, float damage = 0, float velocity = 0): health(health), damage(damage), velocity(velocity) {}
    };
}
