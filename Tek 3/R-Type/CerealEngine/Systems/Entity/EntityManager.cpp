/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** EntityManager.cpp
*/

#include "EntityManager.hpp"

using namespace Cereal;

Entity& EntityManager::createEntity(std::string SceneName, std::optional<std::string> name) {
    if (name && entityExistsInScene(*name, SceneName))
        throw CerealException("EntityManager: Entity already exists\nCurrent scene: " + currentScene + "\nEntity name: " + *name);

    Entity entity;
    entity.id = nextId++;
    entity.name = name;
    entity.sceneOwner = SceneName;
    entities[SceneName].push_back(entity);
    return entities[SceneName].back();
}

void EntityManager::destroyEntity(Entity& entity) {
    if (entityExistsInScene(*entity.name, entity.sceneOwner) == false)
        return;

    for (auto it = entities[entity.sceneOwner].begin(); it != entities[entity.sceneOwner].end(); ++it) {
        if (it->id == entity.id) {
            entities[entity.sceneOwner].erase(it);
            return;
        }
    }
    throw CerealException("EntityManager: Entity not found\nCurrent scene: " + currentScene + "\nEntity name: " + *entity.name);
}

Entity& EntityManager::getEntityByName(const std::string& name) {
    for (auto& e : entities[currentScene]) {
        if (e.name && *e.name == name) {
            return e;
        }
    }
    throw CerealException("EntityManager: Entity <" + name + "> not found\nCurrent scene: " + currentScene + "\nEntity name: " + name);
}

Entity& EntityManager::getEntityByNameInScene(const std::string& name, const std::string& scene) {
    for (auto& e : entities[scene]) {
        if (e.name && *e.name == name) {
            return e;
        }
    }
    throw CerealException("EntityManager: Entity <" + name + "> not found\nCurrent scene: " + currentScene + "\nEntity name: " + name);
}

bool EntityManager::entityExistsInScene(const std::string& name, const std::string& scene) {
    for (auto& e : entities[scene]) {
        if (e.name && *e.name == name) {
            return true;
        }
    }
    return false;
}

bool EntityManager::entityExists(const std::string& name) {
    for (auto& e : entities[currentScene]) {
        if (e.name && *e.name == name) {
            return true;
        }
    }
    return false;
}

std::string EntityManager::createScene(const std::string& name) {
    if (entities.find(name) != entities.end())
        throw CerealException("EntityManager: Scene already exists\nScene name: " + name);
    entities[name] = std::vector<Entity>();
    return name;
}

void EntityManager::setCurrentScene(const std::string& name) {
    currentScene = name;
}

std::string EntityManager::getCurrentScene() {
    return currentScene;
}

std::vector<Entity>& EntityManager::getEntitiesOfCurrentScene() {
    return entities[currentScene];
}

std::vector<Entity> EntityManager::getEntitiesWithTag(const std::string& tag) {
    std::vector<Entity> entitiesWithTags;
    for (auto& e : entities[currentScene]) {
        if (e.tag && *e.tag == tag) {
            entitiesWithTags.push_back(e);
        }
    }
    return entitiesWithTags;
}

std::vector<Entity>& EntityManager::getEntitiesOfScene(const std::string& name) {
    return entities[name];
}

std::vector<std::string> EntityManager::getScenes() {
    std::vector<std::string> scenes;
    for (auto& scene : entities) {
        scenes.push_back(scene.first);
    }
    return scenes;
}