/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** PhysicsSystem.cpp
*/

#include "PhysicsSystem.hpp"

using namespace Cereal;

bool PhysicsSystem::checkCollision(Entity& entityA, Entity& entityB) {
    auto colliderA = entityA.getComponent<BoxCollider>();
    auto colliderB = entityB.getComponent<BoxCollider>();
    auto transformA = entityA.getComponent<Transform>();
    auto transformB = entityB.getComponent<Transform>();

    if (!colliderA || !colliderB) {
        throw CerealException("PhysicsSystem: Entity does not have a BoxCollider component");
        return false;
    }

    if (!transformA || !transformB) {
        throw CerealException("PhysicsSystem: Entity does not have a Transform component");
        return false;
    }

    Raylib::BoundingBox boxA = {
        Raylib::Vector3{transformA->position.x - colliderA->box.max.x / 2, transformA->position.y - colliderA->box.max.y / 2, transformA->position.z - colliderA->box.max.z / 2},
        Raylib::Vector3{transformA->position.x + colliderA->box.max.x / 2, transformA->position.y + colliderA->box.max.y / 2, transformA->position.z + colliderA->box.max.z / 2}
    };

    Raylib::BoundingBox boxB = {
        Raylib::Vector3{transformB->position.x - colliderB->box.max.x / 2, transformB->position.y - colliderB->box.max.y / 2, transformB->position.z - colliderB->box.max.z / 2},
        Raylib::Vector3{transformB->position.x + colliderB->box.max.x / 2, transformB->position.y + colliderB->box.max.y / 2, transformB->position.z + colliderB->box.max.z / 2}
    };

    return CheckCollisionBoxes(boxA, boxB);
}

void PhysicsSystem::updateComponents() {
    return;
}

bool PhysicsSystem::checkHoverOnEntity(Entity& entity) {
    auto collider = entity.getComponent<BoxCollider>();
    auto transform = entity.getComponent<Transform>();
    auto render = entity.getComponent<Render>();

    if (!render || !render->enabled)
        return false;

    if (!collider) {
        throw CerealException("PhysicsSystem: Entity does not have a BoxCollider component");
        return false;
    }
    if (!transform) {
        throw CerealException("PhysicsSystem: Entity does not have a Transform component");
        return false;
    }

    Raylib::BoundingBox box = {
        Raylib::Vector3{transform->position.x - collider->box.max.x / 2, transform->position.y - collider->box.max.y / 2, transform->position.z - collider->box.max.z / 2},
        Raylib::Vector3{transform->position.x + collider->box.max.x / 2, transform->position.y + collider->box.max.y / 2, transform->position.z + collider->box.max.z / 2}
    };

    Raylib::Ray ray = GetMouseRay(GetMousePosition(), entityManager.getEntityByName("Camera").getComponent<Cereal::Camera>()->camera);
    Raylib::RayCollision collision = GetRayCollisionBox(ray, box);
    if (collision.hit)
        return true;
    return false;
}

Entity PhysicsSystem::getHoveredEntity() {
    for (auto& e : entityManager.getEntitiesOfCurrentScene()) {
        if (!e.hasComponent<BoxCollider>() || !e.hasComponent<Transform>() || !e.hasComponent<Render>() || !e.getComponent<Render>()->enabled)
            continue;

        if (checkHoverOnEntity(e))
            return e;
    }
    return Entity();
}