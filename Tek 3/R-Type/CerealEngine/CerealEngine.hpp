/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** Test.hpp
*/

#pragma once

#include "Systems/GameLoop.hpp"

namespace Cereal {
    class Engine {
        private:
            // @brief Initialize the game
            // @param Same as the constructor
            void InitGame(int width, int height, const std::string& title, int fps, bool fullscreen);

        public:
            EntityManager entityManager;
            RenderSystem renderSystem;
            InputSystem inputSystem;
            AudioSystem audioSystem;
            PhysicsSystem physicsSystem;
            InventorySystem inventorySystem;
            DrawSystem drawSystem;
            EntityFactory entityFactory;
            GameLoop gameLoop;
            static Engine* instance;

            // @brief Create a new instance of the engine
            // @param width The width of the window
            // @param height The height of the window
            // @param title The title on the window bar
            // @param fps The number of frame per second
            // @param fullscreen The fullscreen mode (default: false)
            Engine(int width, int height, const std::string& title, int fps, bool fullscreen = false);

            // @brief Destroy the instance of the engine, the resources, the window and the audio device
            ~Engine();
    };


    // All functions of the engine will be listed below to simplify the use of the engine
    // ---- ENTITY RELATED FUNCTIONS ---- //

    // @brief Get the entity manager
    // @return The entity manager
    inline EntityManager& GetEntityManager() {return Engine::instance->gameLoop.getEntityManager();}
    // @brief Create an entity
    // @return The entity created
    inline Entity& CreateEntity(std::string SceneName, std::optional<std::string> name = std::nullopt) {return Engine::instance->gameLoop.getEntityManager().createEntity(SceneName, name);}
    // @brief Destroy an entity
    // @param entity The entity to destroy
    inline void DestroyEntity(Entity& entity) {Engine::instance->gameLoop.getEntityManager().destroyEntity(entity);}
    // @brief Get an entity by its name from the current scene
    // @param name The name of the entity
    // @return The entity
    inline Entity& GetEntityByName(const std::string& name) {return Engine::instance->gameLoop.getEntityManager().getEntityByName(name);}
    // @brief Get an entity by its name from a scene
    // @param name The name of the entity
    // @param sceneName The name of the scene
    inline Entity& GetEntityByNameInScene(const std::string& name, const std::string& scene) {return Engine::instance->gameLoop.getEntityManager().getEntityByNameInScene(name, scene);}
    // @brief Check if an entity exists from the current scene
    // @param name The name of the entity
    // @return True if the entity exists, false otherwise
    inline bool EntityExists(const std::string& name) {return Engine::instance->gameLoop.getEntityManager().entityExists(name);}
    // @brief Get all entities of the current scene with a specific tag
    // @param tag The tag of the entities
    // @return Vector of entities
    inline std::vector<Entity> GetEntitiesWithTag(const std::string& tag) {return Engine::instance->gameLoop.getEntityManager().getEntitiesWithTag(tag);}
    // @brief Get all entities with a specific component
    // @return Vector of entities
    template<typename T>
    inline std::vector<Entity> GetEntitiesWithComponent() {return Engine::instance->gameLoop.getEntityManager().getEntitiesWithComponent<T>();}
    // @brief Get all entities with a specific component in a specific scene
    // @return Vector of entities
    template<typename T>
    inline std::vector<Entity> GetEntitiesWithComponentInScene(const std::string& scene) {return Engine::instance->gameLoop.getEntityManager().getEntitiesWithComponentInScene<T>(scene);}
    // @brief Get all entities in a specific scene
    // @return Vector of entities
    inline std::vector<Entity> GetEntitiesInScene(const std::string& scene) {return Engine::instance->gameLoop.getEntityManager().getEntitiesOfScene(scene);}
    // @brief Get all entities in the current scene
    // @return Vector of entities
    inline std::vector<Entity> GetEntitiesInCurrentScene() {return Engine::instance->gameLoop.getEntityManager().getEntitiesOfCurrentScene();}    

    // ---- SCENE RELATED FUNCTIONS ---- //
    
    // @brief Create a scene
    // @param name The name of the scene
    // @return The name of the scene    
    inline std::string CreateScene(const std::string& name) {return Engine::instance->gameLoop.getEntityManager().createScene(name);}
    // @brief Set the current scene
    // @param name The name of the scene
    inline void SetCurrentScene(const std::string& name) {Engine::instance->gameLoop.getEntityManager().setCurrentScene(name);}
    // @brief Get the current scene
    // @return The name of the current scene
    inline std::string GetCurrentScene() {return Engine::instance->gameLoop.getEntityManager().getCurrentScene();}

    // ---- INPUT RELATED FUNCTIONS ---- //

    // @brief Get the input system
    // @return The input system
    inline InputSystem& GetInputSystem() {return Engine::instance->gameLoop.getInputSystem();}
    // @brief Get current action down (the action that is maintained)
    // @return actionName The name of the action
    inline std::string GetActionDown() {return Engine::instance->gameLoop.getInputSystem().getActionDown();}
    // @brief Get current action pressed (the action that is pressed)
    // @return actionName The name of the action
    inline std::string GetActionPressed() {return Engine::instance->gameLoop.getInputSystem().getActionPressed();}
    // @brief Get the key code pressed and the input type
    // @return std::pair<int, InputType> The key code and the input type
    inline std::pair<int, Cereal::InputType> GetKeyPressed() {return Engine::instance->gameLoop.getInputSystem().getKeyPressed();}
    // @brief Add a key mapping
    // @param actionName The name of the action
    // @param key The key to map
    // @param inputType The input type
    inline void MapKey(const std::string& action, const int &key, Cereal::InputType type) {Engine::instance->gameLoop.getInputSystem().mapKey(action, key, type);}
    // @brief Remove a key mapping
    // @param actionName The name of the action
    // @param key The key to remove
    inline void RemoveKeyMapping(const std::string& action, int &key) {Engine::instance->gameLoop.getInputSystem().removeKeyMapping(action, key);}
    // @brief Remove all key mapping linked to an action
    // @param actionName The name of the action
    inline void RemoveAllKeyMapping(const std::string& action) {Engine::instance->gameLoop.getInputSystem().removeAllKeyMapping(action);}

    // ---- RENDER / DRAW RELATED FUNCTIONS ---- //

    // @brief Get the render system
    // @return The render system
    inline RenderSystem& GetRenderSystem() {return Engine::instance->gameLoop.getRenderSystem();}
    // @brief Use this function to start drawing 2D and 3D elements
    inline void StartDrawing() { ClearBackground(WHITE); BeginDrawing();}
    // @brief Use this function to stop drawing 2D and 3D elements
    inline void StopDrawing() {EndDrawing();}
    // @brief Draw a Text without using entities
    inline void RenderText(const std::string& text, int posX, int posY, int fontSize, Color color, std::optional<std::string> fontPath = std::nullopt) {Engine::instance->gameLoop.getDrawSystem().drawText(text, posX, posY, fontSize, color, fontPath);}

    // ---- AUDIO RELATED FUNCTIONS ---- //

    // @brief Get the audio system
    // @return The audio system
    inline AudioSystem& GetAudioSystem() {return Engine::instance->gameLoop.getAudioSystem();}
    // @brief Play a sound
    // @param sound The sound to play
    inline void PlaySound(SoundAmbiant* sound) {Engine::instance->gameLoop.getAudioSystem().playSound(sound);}
    // @brief Play a music
    // @param music The music to play
    inline void PlayMusic(MusicAmbiant* music) {Engine::instance->gameLoop.getAudioSystem().playMusic(music);}

    // ---- PHYSICS RELATED FUNCTIONS ---- //
    
    // @brief Get the physics system
    // @return The physics system
    inline PhysicsSystem& GetPhysicsSystem() {return Engine::instance->gameLoop.getPhysicsSystem();}
    // @brief Check if two entities are colliding
    // @param entityA The first entity
    // @param entityB The second entity
    // @return True if the entities are colliding, false otherwise
    inline bool CheckCollision(Entity& entityA, Entity& entityB) {return Engine::instance->gameLoop.getPhysicsSystem().checkCollision(entityA, entityB);}
    // @brief Check if an entity is hovered by the mouse
    // @param entity The entity to check
    // @return True if the entity is hovered, false otherwise
    inline bool CheckHoverOnEntity(Entity& entity) {return Engine::instance->gameLoop.getPhysicsSystem().checkHoverOnEntity(entity);}
    // @brief Get the entity hovered by the mouse
    // @return The entity hovered
    inline Entity GetHoveredEntity() {return Engine::instance->gameLoop.getPhysicsSystem().getHoveredEntity();}

    // ---- INVENTORY RELATED FUNCTIONS ---- //

    // @brief Get the inventory system
    // @return The inventory system
    inline InventorySystem& GetInventorySystem() {return Engine::instance->gameLoop.getInventorySystem();}
    // @brief Add an item to an inventory
    // @param inventory The inventory
    // @param name The name of the item
    // @param quantity The quantity of the item
    inline void AddItem(Inventory& inventory, const std::string& name, int quantity) {Engine::instance->gameLoop.getInventorySystem().addItem(inventory, name, quantity);}
    // @brief Remove an item from an inventory
    // @param inventory The inventory
    // @param name The name of the item
    // @param quantity The quantity of the item
    inline void RemoveItem(Inventory& inventory, const std::string& name, int quantity) {Engine::instance->gameLoop.getInventorySystem().removeItem(inventory, name, quantity);}
    // @brief Clear an inventory
    // @param inventory The inventory
    inline void ClearInventory(Inventory& inventory) {Engine::instance->gameLoop.getInventorySystem().clear(inventory);}
    // @brief Get the quantity of an item in an inventory
    // @param inventory The inventory
    // @param name The name of the item
    // @return The quantity of the itemS
    inline int GetItemQuantity(Inventory& inventory, const std::string& name) {return Engine::instance->gameLoop.getInventorySystem().getItemQuantity(inventory, name);}
    // @brief Check if an inventory has an item
    // @param inventory The inventory
    // @param name The name of the item
    // @return True if the inventory has the item, false otherwise
    inline bool HasItem(Inventory& inventory, const std::string& name) {return Engine::instance->gameLoop.getInventorySystem().hasItem(inventory, name);}

    // ---- ENTITY FACTORY RELATED FUNCTIONS ---- //

    // @brief Create a button Prefab
    // @param sceneName The name of the scene
    // @param name The name of the button
    // @param texturePath The path of the texture
    // @param position The position of the button
    // @param rotation The rotation of the button
    // @param scale The scale of the button
    inline Entity CreateButton(const std::string sceneName, const std::string& name, const std::string& texturePath, const Vector3& position, const Vector3& rotation, const float& scale) {return Engine::instance->gameLoop.getEntityFactory().createButton(sceneName, name, texturePath, position, rotation, scale);}
    // @brief Create a text Prefab
    // @param sceneName The name of the scene
    // @param name The name of the text
    // @param text The text
    // @param position The position of the text
    // @param fontSize The font size of the text
    // @param fontPath The path of the font
    // @param color The color of the text
    inline Entity CreateText(const std::string sceneName, const std::string& name, const std::string& text, const Vector2& position, const int& fontSize, const std::string& fontPath, const Color& color) {return Engine::instance->gameLoop.getEntityFactory().createText(sceneName, name, text, position, fontSize, fontPath, color);}
    // @brief Create a camera Prefab
    // @param sceneName The name of the scene
    // @param position The position of the camera
    // @param target The target of the camera
    // @param up The up of the camera
    // @param fovy The fovy of the camera
    // @param projection The projection of the camera
    inline Entity CreateCamera(const std::string sceneName, const Vector3& position, const Vector3& target, const Vector3& up, const float& fovy = 45.0f, const int& projection = CAMERA_PERSPECTIVE) {return Engine::instance->gameLoop.getEntityFactory().createCamera(sceneName, position, target, up, fovy, projection);}
    // @brief Create a light Prefab (Make sure to use the AddLightToAllModelsInScene or AddLightShaderToModel functions to add the light shader to the models)
    // @param sceneName The name of the scene
    // @param position The position of the light
    // @param color The color of the light
    inline Entity CreateLight(const std::string sceneName, const Vector3& position, const Color& color) {return Engine::instance->gameLoop.getEntityFactory().createLight(sceneName, position, color);}
    // @brief Create a global camera Prefab on all scenes (Make sure to call this function after all scenes are created)
    // @param position The position of the camera
    // @param target The target of the camera
    // @param up The up of the camera
    // @param fovy The fovy of the camera
    // @param projection The projection of the camera
    inline void CreateGlobalCamera(const Vector3& position, const Vector3& target, const Vector3& up, const float& fovy = 45.0f, const int& projection = CAMERA_PERSPECTIVE) {Engine::instance->gameLoop.getEntityFactory().createGlobalCamera(position, target, up, fovy, projection);}

    // ---- RESOURCE MANAGER RELATED FUNCTIONS ---- //

    // @brief Get a model from path or create it if it doesn't exist
    // @param name The name of the model
    // @return The model
    inline Model GetModel(const std::string& name) {return ResourceManager::getInstance().getModel(name);}
    // @brief Get a music from path or create it if it doesn't exist
    // @param name The name of the music
    // @param loop If the music have to loop
    // @param volume The volume of the music
    // @return The music
    inline Music GetMusic(const std::string& name, bool loop, float volume) {return ResourceManager::getInstance().getMusic(name, loop, volume);}
    // @brief Get a sound from path or create it if it doesn't exist
    // @param name The name of the sound
    // @param volume The volume of the sound
    // @return The sound
    inline Sound GetSound(const std::string& name, float volume) {return ResourceManager::getInstance().getSound(name, volume);}
    // @brief Get a font from path or create it if it doesn't exist
    // @param name The name of the font
    // @return The font
    inline Font GetFont(const std::string& name) {return ResourceManager::getInstance().getFont(name);}

    // ---- CUSTOM FUNCTIONS ---- //

    // @brief Get the camera of the current scene
    // @return The camera
    inline Raylib::Camera3D GetCamera() {return Engine::instance->gameLoop.getEntityManager().getEntityByName("Camera").getComponent<Cereal::Camera>()->camera;}
    // @brief Get the light of a specific scene
    // @param sceneName The name of the scene
    // @return The light
    inline LightComponent* GetLightComponentInScene(const std::string& sceneName) {return Engine::instance->gameLoop.getEntityManager().getEntityByNameInScene("Light", sceneName).getComponent<LightComponent>();}
    // @brief Add light shader to a model (Must be called after the model is created in order to make light work)
    // @param model The model
    // @param light The light
    inline void AddLightShaderToModel(Model3D& model, LightComponent& light) {for (int i = 0; i < model.model.materialCount; i++) { model.model.materials[i].shader = light.shader;}}
    // @brief Add light shader to all models in a scene (Must be called after the models are created in order to make light work)
    // @param sceneName The name of the scene
    // @param light The light
    inline void AddLightToAllModelsInScene(LightComponent* light, const std::string& sceneName) {for (auto& entity : GetEntitiesWithComponentInScene<Model3D>(sceneName)) {auto model = entity.getComponent<Model3D>();AddLightShaderToModel(*model, *light);}}
    // @brief Check if a gamepad is connected
    // @param gamepad The gamepad to check
    // @return True if the gamepad is connected, false otherwise
    inline bool IsGamepadConnected(int gamepad) {return IsGamepadAvailable(gamepad);}

}