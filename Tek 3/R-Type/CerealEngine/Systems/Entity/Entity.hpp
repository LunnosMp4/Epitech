/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Entity.hpp
*/

#pragma once

#include <vector>
#include <iostream>
#include <optional>
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <utility>
#include <string>

#include "../Component/Component.hpp"

namespace Cereal {
    class Entity {
        private :
            std::type_index lastAddedComponentType = typeid(void);

        public:
            int id;
            std::optional<std::string> name;
            std::optional<std::string> tag;
            std::string sceneOwner;
            std::unordered_map<std::type_index, std::vector<std::shared_ptr<ComponentBase>>> components;

            // @brief Add a component
            // @param component The instance of a component herited from ComponentBase
            // @return The instance of the entity
            template<typename T, typename... Args>
            Entity& addComponent(Args&&... args) {
                auto component = std::make_shared<Component<T>>();
                component->data = T(std::forward<Args>(args)...);
                components[typeid(T)].emplace_back(std::dynamic_pointer_cast<ComponentBase>(component));
                lastAddedComponentType = typeid(T);
                return *this;
            }

            // @brief Add tag to the last component added
            // @param tag The tag to add
            // @return The instance of the entity
            template<typename T>
            Entity& addTag(const std::string& tag) {
                auto& componentList = components[lastAddedComponentType];
                if (!componentList.empty())
                    dynamic_cast<Component<T>&>(*componentList[componentList.size() - 1]).tag = tag;
                return *this;
            }

            Entity& addTagToEntity(const std::string& tag) {
                this->tag = tag;
                return *this;
            }

            // @brief Get a component
            // @return The component
            template<typename T>
            T* getComponent() {
                auto& component = components[typeid(T)];
                if (!component.empty())
                    return &(dynamic_cast<Component<T>&>(*component[0]).data);
                return nullptr;
            }

            // @brief Get a component by tag
            // @return The component
            template<typename T>
            T* getComponentByTag(const std::string& tag) {
                auto& component = components[typeid(T)];
                if (!component.empty()) {
                    for (auto& comp : component) {
                        if (dynamic_cast<Component<T>&>(*comp).tag == tag) {
                            return &(dynamic_cast<Component<T>&>(*comp).data);
                        }
                    }
                }
                return nullptr;
            }

            // @brief Get all components of a type
            // @return Vector of components of the specified type
            template<typename T>
            std::vector<T*> getComponents() {
                std::vector<T*> componentsOfType;
                auto& components = this->components[typeid(T)];
                for (auto& component : components) {
                    componentsOfType.emplace_back(&(dynamic_cast<Component<T>&>(*component).data));
                }
                return componentsOfType;
            }

            // @brief Has a component
            // @return True if the entity has the component, false otherwise
            template<typename T>
            bool hasComponent() {
                return components.find(typeid(T)) != components.end();
            }

            // @brief Has a component by tag
            // @return True if the entity has the component, false otherwise
            template<typename T>
            bool hasComponentByTag(const std::string& tag) {
                auto& component = components[typeid(T)];
                if (!component.empty()) {
                    for (auto& comp : component) {
                        if (dynamic_cast<Component<T>&>(*comp).tag == tag) {
                            return true;
                        }
                    }
                }
                return false;
            }

            // @brief Remove all components
            void removeComponents() {
                components.clear();
            }
    };
}
