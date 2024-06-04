/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** RenderSystem.cpp
*/

#include "RenderSystem.hpp"

using namespace Cereal;

void RenderSystem::drawSprite(const Sprite* sprite, const Cereal::Transform* transform) {
    if (!sprite || !transform)
        throw CerealException("RenderSystem: Sprite or Transform component is null");

    if (sprite->isLooping) {
        float offset = sprite->speed * GetFrameTime();
        sprite->currentFrame += offset;

        if (sprite->currentFrame >= 1.0f) {
            sprite->currentFrame -= 1.0f;
        }

        DrawTexturePro(sprite->image,
                    {sprite->currentFrame * sprite->image.width, 0, static_cast<float>(sprite->image.width), static_cast<float>(sprite->image.height)},
                    {transform->position.x, transform->position.y,
                        static_cast<float>(sprite->image.width) * transform->scale,
                        static_cast<float>(sprite->image.height) * transform->scale},
                    {0, 0}, transform->rotation.z, WHITE);
    } else {
        // Dessiner le sprite sans parallaxe
        DrawTexturePro(sprite->image,
                       {0, 0, static_cast<float>(sprite->image.width), static_cast<float>(sprite->image.height)},
                       {transform->position.x, transform->position.y,
                        static_cast<float>(sprite->image.width) * transform->scale,
                        static_cast<float>(sprite->image.height) * transform->scale},
                       {0, 0}, transform->rotation.z, WHITE);
    }
}

void RenderSystem::drawModel(const Model3D* model, const Cereal::Transform* transform) {
    if (!model || !transform)
        throw CerealException("RenderSystem: Model or Transform component is null");

    DrawModelEx(model->model, transform->position, model->rotationAxis, model->rotationAngle,
                {transform->scale, transform->scale, transform->scale}, WHITE);
}

void RenderSystem::drawText(const Text* text) {
    if (!text)
        throw CerealException("RenderSystem: Text component is null");

    DrawTextEx(text->font, text->text.c_str(), text->position, text->fontSize, 0, text->color);
}

void RenderSystem::drawDebug(Entity &e) {
    DrawFPS(0, 0);
}

void RenderSystem::drawLight(const LightComponent* light) {
    Raylib::UpdateLightValues(light->shader, light->light);
}

void RenderSystem::updateComponents(bool debug) {
    for (auto& e : entityManager.getEntitiesOfCurrentScene()) {

        auto transform = e.getComponent<Cereal::Transform>();
        auto sprites = e.getComponents<Sprite>();
        auto models = e.getComponents<Model3D>();
        auto texts = e.getComponents<Text>();
        auto scripts = e.getComponents<Script>();
        auto light = e.getComponent<LightComponent>();

        if (debug) drawDebug(e);

        if (e.hasComponent<Render>() && e.getComponent<Render>()->enabled) {
            auto cameraComponent = entityManager.getEntityByName("Camera").getComponent<Cereal::Camera>();

            for (auto& sprite : sprites)
                drawSprite(sprite, transform);

            if (entityManager.entityExists("Camera")) {
                BeginMode3D(cameraComponent->camera);
                for (auto& model : models)
                    drawModel(model, transform);

                if (light)
                    drawLight(light);

                if (e.hasComponent<BoxCollider>() && debug) {
                    auto boxCollider = e.getComponent<BoxCollider>();
                    Raylib::Vector3 position = transform->position;
                    Raylib::BoundingBox box = {
                        Raylib::Vector3{position.x - boxCollider->box.max.x / 2, position.y - boxCollider->box.max.y / 2, position.z - boxCollider->box.max.z / 2},
                        Raylib::Vector3{position.x + boxCollider->box.max.x / 2, position.y + boxCollider->box.max.y / 2, position.z + boxCollider->box.max.z / 2}
                    };
                    DrawBoundingBox(box, RED);
                }


                EndMode3D();
            } else throw Cereal::CerealException("RenderSystem: Trying to draw 3D components without a camera");

            for (auto& text : texts)
                drawText(text);
        }
        if (e.hasComponent<Script>()) {
            for (auto& script : scripts)
                script->scriptFunction();
        }
    }
}