/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** EntityManager.hpp
*/

#pragma once

#include "../../CerealException.hpp"
#include <vector>
#include <iostream>
#include <optional>
#include <map>
#include "Entity.hpp"
#include <thread>
#include <chrono>

namespace Cereal {
    class EntityManager {
        public:
            std::map<std::string, std::vector<Entity>> entities;
            std::string currentScene = "default";
            int nextId = 0;

            // @brief Create an entity
            // @return The entity created
            Entity& createEntity(std::string SceneName, std::optional<std::string> name = std::nullopt);

            // @brief Destroy an entity
            // @param entity The entity to destroy
            void destroyEntity(Entity& entity);

            // @brief Get an entity by its name from the current scene
            // @param name The name of the entity
            // @return The entity
            Entity& getEntityByName(const std::string& name);

            // @brief Get an entity by its name from a scene
            // @param name The name of the entity
            // @param sceneName The name of the scene
            // @return The entity
            Entity& getEntityByNameInScene(const std::string& name, const std::string& sceneName);

            // @brief Know if an entity exists from the current scene
            // @param name The name of the entity
            // @return True if the entity exists, false otherwise
            bool entityExists(const std::string& name);

            // @brief Create a scene
            // @param name The name of the scene
            // @return The name of the scene
            std::string createScene(const std::string& name);

            // @brief Set the current scene
            // @param name The name of the scene
            void setCurrentScene(const std::string& name);

            // @brief Get the current scene
            // @return The name of the current scene
            std::string getCurrentScene();

            // @brief Get all entities of the current scene
            // @return The entities of the current scene
            std::vector<Entity>& getEntitiesOfCurrentScene();

            // @brief Get all entities with a tag from the current scene
            // @param tag The tag of the entities
            // @return The entities with the tag
            std::vector<Entity> getEntitiesWithTag(const std::string& tag);

            // @brief Get all entities with a component from the current scene
            // @return The entities with the component
            template<typename T>
            std::vector<Entity> getEntitiesWithComponent() {
                std::vector<Entity> entitiesWithComponent;
                for (auto& e : entities[currentScene]) {
                    if (e.hasComponent<T>()) {
                        entitiesWithComponent.push_back(e);
                    }
                }
                return entitiesWithComponent;
            }

            // @brief Get all entities with a component from a scene
            // @param scene The name of the scene
            // @return The entities with the component
            template<typename T>
            std::vector<Entity> getEntitiesWithComponentInScene(const std::string& scene) {
                std::vector<Entity> entitiesWithComponent;
                for (auto& e : entities[scene]) {
                    if (e.hasComponent<T>()) {
                        entitiesWithComponent.push_back(e);
                    }
                }
                return entitiesWithComponent;
            }

            // @brief Get all entities of a scene
            // @param name The name of the scene
            // @return The entities of the scene
            std::vector<Entity>& getEntitiesOfScene(const std::string& name);

            // @brief Know if an entity exists in a scene
            // @param name The name of the entity
            // @param sceneName The name of the scene
            // @return True if the entity exists in the scene, false otherwise
            bool entityExistsInScene(const std::string& name, const std::string& sceneName);

            // @brief Get all scenes
            // @return The scenes
            std::vector<std::string> getScenes();
    };
}