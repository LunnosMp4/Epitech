/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Friend.cpp
*/

#include "Game.hpp"

using namespace Cereal;

void AttackEnemyFromFriend(Entity& player, Entity& enemy) {
    auto enemyStats = enemy.getComponent<Stats>();
    auto inventory = player.getComponent<Inventory>();
    auto explosion = player.getComponentByTag<SoundAmbiant>("SoundExplosion");

    enemyStats->health -= 10;

    if (enemyStats->health <= 0) {
        explosion->haveToPlay = true;
        AddItem(*inventory, "Score", 100);
        AddItem(*inventory, "Kills", 1);
        GetEntityByName("Score").getComponent<Cereal::Text>()->text = "Score: " + std::to_string(GetItemQuantity(*inventory, "Score"));
        DestroyEntity(enemy);
    }
}

void friendShotBullet(Entity& friendEntity) {
    auto friendTransform = friendEntity.getComponent<Cereal::Transform>();
    static int bulletCount = 0;
    bulletCount++;
    const std::string bulletName = "FriendBullet" + std::to_string(bulletCount);

    CreateEntity("GameScene", bulletName)
        .addComponent<Cereal::Transform>(Cereal::Transform(friendTransform->position, {0, 0, 0}, 0.02f))
        .addComponent<Model3D>(Model3D(BULLET_FRIEND, {0, 1, 0}, 270))
        .addComponent<Render>(Render(true))
        .addComponent<SoundAmbiant>(SoundAmbiant(PISTOL_SHOOT, true, 0.2f))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{5, 2, 2});

    AddLightShaderToModel(*GetEntityByName(bulletName).getComponent<Model3D>(), *GetLightComponentInScene("GameScene"));

    std::function<void()> bulletScript = [bulletName]() {
        auto bullet = GetEntityByName(bulletName);
        auto bulletTransform = bullet.getComponent<Cereal::Transform>();

        bulletTransform->position.x += 0.15f;

        if (bulletTransform->position.x > 100)
            DestroyEntity(bullet);

        for (auto& enemy : GetEntitiesWithTag("Enemy")) {
            if (CheckCollision(bullet, enemy)) {
                DestroyEntity(bullet);
                AttackEnemyFromFriend(GetEntityByName("Player"), enemy);
            }
        }
    };
    GetEntityByName(bulletName).addComponent<Script>(Script(bulletScript));
}

void Game::createFriend() {
    CreateEntity(gameScene, "Friend")
        .addComponent<Cereal::Transform>(Cereal::Transform({0, 0, 0}, {0, 0, 0}, 0.007f))
        .addComponent<Model3D>(Model3D(FRIEND, {1, 1, 0}, 180))
        .addComponent<Render>(Render(true))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{4, 5, 4})
        .addComponent<Timer>(Timer())
        .addTagToEntity("Elementary");

    std::function<void()> friendScript = []() {
        auto friendEntity = GetEntityByName("Friend");
        auto playerEntity = GetEntityByName("Player");
        auto friendTransform = friendEntity.getComponent<Cereal::Transform>();
        auto playerTransform = playerEntity.getComponent<Cereal::Transform>();
        auto friendTimer = friendEntity.getComponent<Timer>();

        static float radius = 5.0f;
        static float speed = 0.01f;
        static float angle = 0.0f;

        angle += speed;

        float x = playerTransform->position.x + radius * cos(angle);
        float z = playerTransform->position.z + radius * sin(angle);

        friendTransform->position = {x, friendTransform->position.y, z};


        auto currentTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime - friendTimer->time);

        if (duration.count() >= 2)
        {
            friendShotBullet(friendEntity);
            friendTimer->time = currentTime;
        }
    };

    GetEntityByNameInScene("Friend", gameScene).addComponent<Script>(Script(friendScript));
}