/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Enemy.cpp
*/

#include "Game.hpp"

using namespace Cereal;

void AttackPlayer()
{
    auto player = GetEntityByName("Player");
    int damage = 10;
    auto playerStats = player.getComponent<Stats>();
    auto explosion = player.getComponentByTag<SoundAmbiant>("SoundExplosion");
    playerStats->health -= damage;

    GetEntityByName("Life").getComponent<Cereal::Text>()->text = "Life: " + std::to_string(playerStats->health).substr(0, 5);

    if (playerStats->health <= 0)
    {
        explosion->haveToPlay = true;
        for (auto &entity : GetEntitiesInCurrentScene())
        {
            if (entity.name == "Player")
            {
                entity.getComponent<Stats>()->health = 100;
                entity.getComponent<Inventory>()->items.clear();
                AddItem(*entity.getComponent<Inventory>(), "Missile", 3);
                GetEntityByName("Score").getComponent<Cereal::Text>()->text = "Score: 0";
                GetEntityByName("Life").getComponent<Cereal::Text>()->text = "Life: 100";
                GetEntityByName("Camera").getComponent<Cereal::Camera>()->camera.position.y = -40.0f;
                entity.getComponent<Cereal::Transform>()->position = {0, 0, 0};
                continue;
            }

            if (entity.tag == "Elementary" || entity.name == "Camera" || entity.name == "Light")
                continue;

            DestroyEntity(entity);
        }
        SetCurrentScene("GameOverScene");
    }
}

void bossAttackOne(Entity &enemy)
{
    auto enemyTransform = enemy.getComponent<Cereal::Transform>();
    static int bulletCount = 0;
    bulletCount++;
    const std::string bulletName = "BossBullet" + std::to_string(bulletCount);

    CreateEntity("GameScene", bulletName)
        .addComponent<Cereal::Transform>(Cereal::Transform({enemyTransform->position.x, enemyTransform->position.y, enemyTransform->position.z}, {0, 0, 0}, 0.01f))
        .addComponent<Model3D>(Model3D(BULLET, {0, 1, 0}, 90))
        .addComponent<Render>(Render(true))
        .addComponent<SoundAmbiant>(SoundAmbiant(SHOOT, true, 0.2f))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{10, 2, 2});

    AddLightShaderToModel(*GetEntityByName(bulletName).getComponent<Model3D>(), *GetLightComponentInScene("GameScene"));

    std::function<void()> bulletScript = [bulletName]()
    {
        auto bullet = GetEntityByName(bulletName);
        auto bulletTransform = bullet.getComponent<Cereal::Transform>();

        bulletTransform->position.x -= 0.30f;

        if (bulletTransform->position.x <= -100)
            DestroyEntity(bullet);

        if (CheckCollision(bullet, GetEntityByName("Player")))
        {
            DestroyEntity(bullet);
            AttackPlayer();
        }
    };
    GetEntityByName(bulletName).addComponent<Script>(Script(bulletScript));
}

void bossAttackTwo(Entity &enemy)
{
    auto enemyTransform = enemy.getComponent<Cereal::Transform>();
    static int attackCount = 1;

    const std::string attack1 = "Enemyattack" + std::to_string(attackCount);
    attackCount++;
    const std::string attack2 = "Enemyattack" + std::to_string(attackCount);
    attackCount++;
    const std::string attack3 = "Enemyattack" + std::to_string(attackCount);
    attackCount++;

    CreateEntity("GameScene", attack1)
        .addComponent<Cereal::Transform>(Cereal::Transform({enemyTransform->position.x, enemyTransform->position.y, enemyTransform->position.z + 6}, {0, 0, 0}, 0.01f))
        .addComponent<Model3D>(Model3D(BULLET, {0, 1, 0}, 90))
        .addComponent<Render>(Render(true))
        .addComponent<SoundAmbiant>(SoundAmbiant(SHOOT, true, 0.2f))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{10, 2, 2});

    AddLightShaderToModel(*GetEntityByName(attack1).getComponent<Model3D>(), *GetLightComponentInScene("GameScene"));

    CreateEntity("GameScene", attack2)
        .addComponent<Cereal::Transform>(Cereal::Transform({enemyTransform->position.x, enemyTransform->position.y, enemyTransform->position.z}, {0, 0, 0}, 0.01f))
        .addComponent<Model3D>(Model3D(BULLET, {0, 1, 0}, 90))
        .addComponent<Render>(Render(true))
        .addComponent<SoundAmbiant>(SoundAmbiant(SHOOT, true, 0.2f))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{10, 2, 2});

    AddLightShaderToModel(*GetEntityByName(attack2).getComponent<Model3D>(), *GetLightComponentInScene("GameScene"));

    CreateEntity("GameScene", attack3)
        .addComponent<Cereal::Transform>(Cereal::Transform({enemyTransform->position.x, enemyTransform->position.y, enemyTransform->position.z - 6}, {0, 0, 0}, 0.01f))
        .addComponent<Model3D>(Model3D(BULLET, {0, 1, 0}, 90))
        .addComponent<Render>(Render(true))
        .addComponent<SoundAmbiant>(SoundAmbiant(SHOOT, true, 0.2f))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{10, 2, 2});

    AddLightShaderToModel(*GetEntityByName(attack3).getComponent<Model3D>(), *GetLightComponentInScene("GameScene"));

    std::function<void()> bulletScript1 = [attack1]()
    {
        auto Entity_attack1 = GetEntityByName(attack1);
        auto attack1Transform = Entity_attack1.getComponent<Cereal::Transform>();

        attack1Transform->position.x -= 0.15f;

        if (attack1Transform->position.x <= -100)
            DestroyEntity(Entity_attack1);

        if (CheckCollision(Entity_attack1, GetEntityByName("Player")))
        {
            DestroyEntity(Entity_attack1);
            AttackPlayer();
        }
    };
    std::function<void()> bulletScript2 = [attack2]()
    {
        auto Entity_attack2 = GetEntityByName(attack2);
        auto attack2Transform = Entity_attack2.getComponent<Cereal::Transform>();

        attack2Transform->position.x -= 0.15f;

        if (attack2Transform->position.x <= -100)
            DestroyEntity(Entity_attack2);

        if (CheckCollision(Entity_attack2, GetEntityByName("Player")))
        {
            DestroyEntity(Entity_attack2);
            AttackPlayer();
        }
    };
    std::function<void()> bulletScript3 = [attack3]()
    {
        auto Entity_attack3 = GetEntityByName(attack3);
        auto attack3Transform = Entity_attack3.getComponent<Cereal::Transform>();

        attack3Transform->position.x -= 0.15f;

        if (attack3Transform->position.x <= -100)
            DestroyEntity(Entity_attack3);

        if (CheckCollision(Entity_attack3, GetEntityByName("Player")))
        {
            DestroyEntity(Entity_attack3);
            AttackPlayer();
        }
    };
    GetEntityByName(attack1).addComponent<Script>(Script(bulletScript1));
    GetEntityByName(attack2).addComponent<Script>(Script(bulletScript2));
    GetEntityByName(attack3).addComponent<Script>(Script(bulletScript3));
}

void bigBossAttack(Entity &enemy)
{
    auto enemyTransform = enemy.getComponent<Cereal::Transform>();
    static int bigAttackCount = 0;

    std::cout << "bigboss attack !" << std::endl;

    const std::string bigAttack1 = "EnemybigAttack" + std::to_string(bigAttackCount);
    bigAttackCount++;
    const std::string bigAttack2 = "EnemybigAttack" + std::to_string(bigAttackCount);
    bigAttackCount++;
    const std::string bigAttack3 = "EnemybigAttack" + std::to_string(bigAttackCount);
    bigAttackCount++;

    CreateEntity("GameScene", bigAttack1)
        .addComponent<Cereal::Transform>(Cereal::Transform({enemyTransform->position.x, enemyTransform->position.y, enemyTransform->position.z - 5}, {0, 0, 0}, 0.01f))
        .addComponent<Model3D>(Model3D(BULLET, {0, 1, 0}, 90))
        .addComponent<Render>(Render(true))
        .addComponent<SoundAmbiant>(SoundAmbiant(SHOOT, true, 0.2f))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{10, 2, 2});

    AddLightShaderToModel(*GetEntityByName(bigAttack1).getComponent<Model3D>(), *GetLightComponentInScene("GameScene"));

    CreateEntity("GameScene", bigAttack2)
        .addComponent<Cereal::Transform>(Cereal::Transform({enemyTransform->position.x, enemyTransform->position.y, enemyTransform->position.z - 10}, {0, 0, 0}, 0.01f))
        .addComponent<Model3D>(Model3D(BULLET, {0, 1, 0}, 90))
        .addComponent<Render>(Render(true))
        .addComponent<SoundAmbiant>(SoundAmbiant(SHOOT, true, 0.2f))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{10, 2, 2});

    AddLightShaderToModel(*GetEntityByName(bigAttack2).getComponent<Model3D>(), *GetLightComponentInScene("GameScene"));

    CreateEntity("GameScene", bigAttack3)
        .addComponent<Cereal::Transform>(Cereal::Transform({enemyTransform->position.x, enemyTransform->position.y, enemyTransform->position.z - 10}, {0, 0, 0}, 0.01f))
        .addComponent<Model3D>(Model3D(BULLET, {0, 1, 0}, 90))
        .addComponent<Render>(Render(true))
        .addComponent<SoundAmbiant>(SoundAmbiant(SHOOT, true, 0.2f))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{10, 2, 2});

    AddLightShaderToModel(*GetEntityByName(bigAttack3).getComponent<Model3D>(), *GetLightComponentInScene("GameScene"));

    std::function<void()> bulletScript1 = [bigAttack1]()
    {
        auto Entity_bigAttack1 = GetEntityByName(bigAttack1);
        auto bigAttack1Transform = Entity_bigAttack1.getComponent<Cereal::Transform>();
        std::cout << "missile 1 !" << std::endl;

        bigAttack1Transform->position.x -= 0.20f;
        bigAttack1Transform->position.z -= 0.02f;

        if (bigAttack1Transform->position.x <= -100 || bigAttack1Transform->position.z >= 200) {
            std::cout << "missile 1 destroyed !" << std::endl;
            DestroyEntity(Entity_bigAttack1);
        }

        if (CheckCollision(Entity_bigAttack1, GetEntityByName("Player")))
        {
            DestroyEntity(Entity_bigAttack1);
            AttackPlayer();
        }
    };
    std::function<void()> bulletScript2 = [bigAttack2]()
    {
        auto Entity_bigAttack2 = GetEntityByName(bigAttack2);
        auto bigAttack2Transform = Entity_bigAttack2.getComponent<Cereal::Transform>();
        std::cout << "missile 2 !" << std::endl;

        bigAttack2Transform->position.x -= 0.20f;

        if (bigAttack2Transform->position.x <= -100) {
            std::cout << "missile 2 destroyed !" << std::endl;
            DestroyEntity(Entity_bigAttack2);
        }

        if (CheckCollision(Entity_bigAttack2, GetEntityByName("Player")))
        {
            DestroyEntity(Entity_bigAttack2);
            AttackPlayer();
        }
    };
    std::function<void()> bulletScript3 = [bigAttack3]()
    {
        auto Entity_bigAttack3 = GetEntityByName(bigAttack3);
        auto bigAttack3Transform = Entity_bigAttack3.getComponent<Cereal::Transform>();

        std::cout << "missile 3 !" << std::endl;

        bigAttack3Transform->position.x -= 0.20f;
        bigAttack3Transform->position.z -= 0.02f;

        if (bigAttack3Transform->position.x <= -100 || bigAttack3Transform->position.z <= -200) {
            std::cout << "missile 3 destroyed !" << std::endl;
            DestroyEntity(Entity_bigAttack3);
        }

        if (CheckCollision(Entity_bigAttack3, GetEntityByName("Player")))
        {
            DestroyEntity(Entity_bigAttack3);
            AttackPlayer();
        }
    };
    GetEntityByName(bigAttack1).addComponent<Script>(Script(bulletScript1));
    GetEntityByName(bigAttack2).addComponent<Script>(Script(bulletScript2));
    GetEntityByName(bigAttack3).addComponent<Script>(Script(bulletScript3));
}

void bossPaternOne(Entity &enemy)
{
    bossAttackOne(enemy);
}

void bossPaternTwo(Entity &enemy)
{
    bossAttackTwo(enemy);
}

void bigBossPatern(Entity &enemy)
{
    bigBossAttack(enemy);
}

void ennemyShotBullet(Entity &enemy)
{
    auto enemyTransform = enemy.getComponent<Cereal::Transform>();
    static int bulletCount = 0;
    bulletCount++;
    const std::string bulletName = "EnemyBullet" + std::to_string(bulletCount);

    CreateEntity("GameScene", bulletName)
        .addComponent<Cereal::Transform>(Cereal::Transform({enemyTransform->position.x, enemyTransform->position.y, enemyTransform->position.z}, {0, 0, 0}, 0.01f))
        .addComponent<Model3D>(Model3D(BULLET, {0, 1, 0}, 90))
        .addComponent<Render>(Render(true))
        .addComponent<SoundAmbiant>(SoundAmbiant(SHOOT, true, 0.2f))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{10, 2, 2});

    AddLightShaderToModel(*GetEntityByName(bulletName).getComponent<Model3D>(), *GetLightComponentInScene("GameScene"));

    std::function<void()> bulletScript = [bulletName]()
    {
        auto bullet = GetEntityByName(bulletName);
        auto bulletTransform = bullet.getComponent<Cereal::Transform>();

        bulletTransform->position.x -= 0.15f;

        if (bulletTransform->position.x <= -100)
            DestroyEntity(bullet);

        if (CheckCollision(bullet, GetEntityByName("Player")))
        {
            DestroyEntity(bullet);
            AttackPlayer();
        }
    };
    GetEntityByName(bulletName).addComponent<Script>(Script(bulletScript));
}

void Game::createEnemy(Cereal::Stats enemyStats)
{
    enemyCount++;
    const std::string enemyString = "Enemy" + std::to_string(enemyCount);

    int randomY = rand() % 20 - 10;

    std::cout << "Enemy created at position: " << randomY << std::endl;

    std::srand(static_cast<unsigned>(std::time(0)));
    int randomModelIndex = std::rand() % enemyModels.size();
    std::string selectedModel = enemyModels[randomModelIndex];

    CreateEntity(gameScene, enemyString)
        .addComponent<Cereal::Transform>(Cereal::Transform({35, 0, (float)randomY}, {0, 0, 0}, 0.01f))
        .addComponent<Stats>(enemyStats)
        .addComponent<Model3D>(Model3D(selectedModel, {-0.71f, 0.71f, 0.0f}, 180))
        .addComponent<Render>(Render(true))
        .addComponent<Inventory>(Inventory())
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{9, 5, 6})
        .addComponent<Timer>(Timer())
        .addTagToEntity("Enemy");

    AddLightShaderToModel(*GetEntityByName(enemyString).getComponent<Model3D>(), *GetLightComponentInScene(gameScene));

    std::function<void()> enemyScript = [enemyString]()
    {
        auto enemy = GetEntityByName(enemyString);
        auto enemyTransform = enemy.getComponent<Cereal::Transform>();
        auto enemyStats = enemy.getComponent<Stats>();
        auto enemyTimer = enemy.getComponent<Timer>();

        if (enemyTransform && enemyStats && enemyTimer)
        {
            if (enemyTransform->position.x <= -35)
                enemyTransform->position.x += 70;

            enemyTransform->position.x -= enemyStats->velocity;

            auto currentTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime - enemyTimer->time);

            if (duration.count() >= 3)
            {
                ennemyShotBullet(enemy);
                enemyTimer->time = currentTime;
            }
        }
    };

    GetEntityByName(enemyString).addComponent<Script>(Script(enemyScript));
}

void Game::createMiniBoss(int bossToSpawn, Cereal::Stats bossStats, int PosZ)
{
    enemyCount++;
    const std::string miniBossString = "MiniBoss" + std::to_string(enemyCount);

    std::string selectedModel;
    if (bossToSpawn == 1)
        selectedModel = BOSS1;
    else if (bossToSpawn == 2)
        selectedModel = BOSS2;

    CreateEntity(gameScene, miniBossString)
        .addComponent<Cereal::Transform>(Cereal::Transform({55, 0, (float)PosZ}, {0, 0, 0}, 0.01f))
        .addComponent<Stats>(bossStats)
        .addComponent<Model3D>(Model3D(selectedModel, {-0.71f, 0.71f, 0.0f}, 180))
        .addComponent<Render>(Render(true))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{20, 10, 15})
        .addComponent<Timer>(Timer())
        .addTagToEntity("Enemy");

    AddLightShaderToModel(*GetEntityByName(miniBossString).getComponent<Model3D>(), *GetLightComponentInScene(gameScene));

    std::function<void()> miniBossScript = [bossToSpawn, miniBossString]()
    {
        auto miniBoss = GetEntityByName(miniBossString);
        auto miniBossTransform = miniBoss.getComponent<Cereal::Transform>();
        auto miniBossStats = miniBoss.getComponent<Stats>();
        auto miniBossTimer = miniBoss.getComponent<Timer>();
        static int miniBossUpDown = 0;

        if (miniBossTransform && miniBossStats)
        {
            if (miniBossTransform->position.x > 5)
                miniBossTransform->position.x -= miniBossStats->velocity;

            if (miniBossTransform->position.z <= 10 && miniBossUpDown == 0)
            {
                miniBossTransform->position.z += miniBossStats->velocity;
                if (miniBossTransform->position.z >= 10 && miniBossUpDown == 0)
                    miniBossUpDown = 1;
            }

            if (miniBossTransform->position.z >= -10 && miniBossUpDown == 1)
            {
                miniBossTransform->position.z -= miniBossStats->velocity;
                if (miniBossTransform->position.z <= -10 && miniBossUpDown == 1)
                    miniBossUpDown = 0;
            }

            auto currentTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime - miniBossTimer->time);

            if (duration.count() >= 2)
            {
                if (bossToSpawn == 2)
                    bossPaternOne(miniBoss);
                if (bossToSpawn == 1)
                    bossPaternTwo(miniBoss);
                miniBossTimer->time = currentTime;
            }
        }
        else
            return;
    };

    GetEntityByName(miniBossString).addComponent<Script>(Script(miniBossScript));
}

void Game::createBigBoss(Cereal::Stats bossStats)
{
    enemyCount++;
    const std::string bigBossString = "BigBoss";

    CreateEntity(gameScene, bigBossString)
        .addComponent<Cereal::Transform>(Cereal::Transform({500, 470, 0}, {0, 0, 0}, 0.01f))
        .addComponent<Stats>(bossStats)
        .addComponent<Model3D>(Model3D(BIGBOSS, {0, 0, 0}, 0))
        .addComponent<Render>(Render(true))
        .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{40, 10, 25})
        .addComponent<Timer>(Timer())
        .addTagToEntity("Enemy");

    AddLightShaderToModel(*GetEntityByName(bigBossString).getComponent<Model3D>(), *GetLightComponentInScene(gameScene));

    std::function<void()> bigBossScript = [bigBossString]()
    {
        auto bigBoss = GetEntityByName(bigBossString);
        auto bigBossTransform = bigBoss.getComponent<Cereal::Transform>();
        auto bigBossStats = bigBoss.getComponent<Stats>();
        auto bigBossTimer = bigBoss.getComponent<Timer>();

        if (bigBossTransform && bigBossStats)
        {
            Entity camera = GetEntityByName("Camera");
            if (camera.getComponent<Cereal::Camera>()->camera.position.y > -80.0f && bigBossTransform->position.x <= 29)
            {
                camera.getComponent<Cereal::Camera>()->camera.position.y -= 0.1f;
            }

            if (bigBossTransform->position.x > 30)
                bigBossTransform->position.x -= 0.6f;

            if (bigBossTransform->position.x > 29 && bigBossTransform->position.x <= 30)
                bigBossTransform->position.x -= 0.003f;

            if (bigBossTransform->position.y > 0)
                bigBossTransform->position.y -= 0.6f;

            auto currentTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime - bigBossTimer->time);

            if (duration.count() >= 4)
            {
                std::cout << "in coming !" << std::endl;
                bigBossPatern(bigBoss);
                bossPaternTwo(bigBoss);
                bigBossTimer->time = currentTime;
            }
        }
        else
            return;
    };

    GetEntityByName(bigBossString).addComponent<Script>(Script(bigBossScript));
}