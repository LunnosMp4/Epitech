/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Weapon.cpp
*/

#include "Game.hpp"

using namespace Cereal;

void AttackEnemy(Entity& player, Entity& enemy) {
    auto playerStats = player.getComponent<Stats>();
    auto enemyStats = enemy.getComponent<Stats>();
    auto inventory = player.getComponent<Inventory>();
    auto explosion = player.getComponentByTag<SoundAmbiant>("SoundExplosion");

    enemyStats->health -= playerStats->damage;

    if (enemyStats->health <= 0) {
        explosion->haveToPlay = true;
        AddItem(*inventory, "Score", 100);
        AddItem(*inventory, "Kills", 1);
        GetEntityByName("Score").getComponent<Cereal::Text>()->text = "Score: " + std::to_string(GetItemQuantity(*inventory, "Score"));
        DestroyEntity(enemy);
    }
}

void Game::shotBullet() {
    const std::string actionPressed = GetActionPressed();

    if (actionPressed == "Action" && HasItem(*GetEntityByName("Player").getComponent<Inventory>(), "Missile")) {
        RemoveItem(*GetEntityByName("Player").getComponent<Inventory>(), "Missile", 1);

        GetEntityByName("Missile").getComponent<Text>()->text = "Missile: " + std::to_string(GetItemQuantity(*GetEntityByName("Player").getComponent<Inventory>(), "Missile"));
        bulletCount++;
        const std::string bulletName = "Bullet" + std::to_string(bulletCount);

        CreateEntity(gameScene, bulletName)
            .addComponent<Cereal::Transform>(Cereal::Transform(GetEntityByName("Player").getComponent<Cereal::Transform>()->position, {0, 0, 0}, 0.01f))
            .addComponent<Model3D>(Model3D(BULLET, {0, 1, 0}, 270))
            .addComponent<Render>(Render(true))
            .addComponent<SoundAmbiant>(SoundAmbiant(SHOOT, true, 0.2f))
            .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{10, 2, 2});

        AddLightShaderToModel(*GetEntityByName(bulletName).getComponent<Model3D>(), *GetLightComponentInScene(gameScene));

        std::function<void()> bulletScript = [bulletName]() {
            auto bullet = GetEntityByName(bulletName);
            auto bulletTransform = bullet.getComponent<Cereal::Transform>();

            bulletTransform->position.x += 0.15f;

            if (bulletTransform->position.x > 100)
                DestroyEntity(bullet);

            for (auto& enemy : GetEntitiesWithTag("Enemy")) {
                if (CheckCollision(bullet, enemy)) {
                    DestroyEntity(bullet);
                    AttackEnemy(GetEntityByName("Player"), enemy);
                }
            }
        };
        GetEntityByName(bulletName).addComponent<Script>(Script(bulletScript));
    }
}