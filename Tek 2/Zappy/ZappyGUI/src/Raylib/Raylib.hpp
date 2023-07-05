/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** Raylib.hpp
*/

#pragma once

#include "ZappyGUI.h"

namespace Zappy {
    class Raylib {
        class RaylibException : public std::exception {
            public:
                RaylibException(std::string const &message) : _message(message) {}
                const char *what() const noexcept override { return _message.c_str(); }
            private:
                std::string _message;
        };

        public:

            Raylib() = default;
            ~Raylib() = default;

            void initWindow(int width, int height, std::string const &title) {
                InitWindow(width, height, title.c_str());
            }

            bool windowShouldClose() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return WindowShouldClose();
            }

            void closeWindow() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                CloseWindow();
            }

            void beginDrawing() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                BeginDrawing();
            }

            void endDrawing() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                EndDrawing();
            }

            void beginShaderMode(Shader const &shader) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                BeginShaderMode(shader);
            }

            void endShaderMode() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                EndShaderMode();
            }

            void clearBackground(Color const &color) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                ClearBackground(color);
            }

            void beginMode2D(Camera2D const &camera) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                BeginMode2D(camera);
            }

            void endMode2D() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                EndMode2D();
            }

            void beginMode3D(Camera3D const &camera) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                BeginMode3D(camera);
            }

            void endMode3D() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                EndMode3D();
            }

            void beginTextureMode(RenderTexture2D const &target) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                BeginTextureMode(target);
            }

            void endTextureMode() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                EndTextureMode();
            }

            void rlDisableBackfaceCulling() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                rlDisableBackfaceCulling();
            }

            void rlEnableBackfaceCulling() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                rlEnableBackfaceCulling();
            }

            void rlDisableDepthMask() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                rlDisableDepthMask();
            }

            void rlEnableDepthMask() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                rlEnableDepthMask();
            }

            /********* DRAWING FUNCTIONS *********/

            void drawTextureRec(Texture2D const &texture, Rectangle const &sourceRec, Vector2 const &position, Color const &tint) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawTextureRec(texture, sourceRec, position, tint);
            }

            void drawTexture(Texture2D const &texture, int posX, int posY, Color const &tint) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawTexture(texture, posX, posY, tint);
            }

            void drawTextureEx(Texture2D const &texture, Vector2 const &position, float const &rotation, float const &scale, Color const &tint) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawTextureEx(texture, position, rotation, scale, tint);
            }

            void drawModel(Model const &model, Vector3 const &position, float const &scale, Color const &tint) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawModel(model, position, scale, tint);
            }

            void drawModelEx(Model const &model, Vector3 const &position, Vector3 const &rotationAxis, float rotationAngle, Vector3 const &scale, Color const &tint) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
            }

            void drawModelWires(Model const &model, Vector3 const &position, float const &scale, Color const &tint) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawModelWires(model, position, scale, tint);
            }

            void drawModelWiresEx(Model const &model, Vector3 const &position, Vector3 const &rotationAxis, float rotationAngle, Vector3 const &scale, Color const &tint) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawModelWiresEx(model, position, rotationAxis, rotationAngle, scale, tint);
            }

            void drawCubeWires(Vector3 const &position, float const &width, float const &height, float const &length, Color const &color) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawCubeWires(position, width, height, length, color);
            }

            void drawBoundingBox(BoundingBox const &box, Color const &color) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawBoundingBox(box, color);
            }

            void drawRectangle(int const &posX, int const &posY, int const &width, int const &height, Color const &color) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawRectangle(posX, posY, width, height, color);
            }

            void drawRectangleRounded(Rectangle const &rec, float const &roundness, int const &segments, Color const &color) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawRectangleRounded(rec, roundness, segments, color);
            }

            void drawText(std::string const &text, int const &posX, int const &posY, int const &fontSize, Color const &color) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawText(text.c_str(), posX, posY, fontSize, color);
            }

            void drawTextEx(Font const &font, std::string const &text, Vector2 const &position, float const &fontSize, float const &spacing, Color const &tint) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawTextEx(font, text.c_str(), position, fontSize, spacing, tint);
            }

            const char *textFormat(const char *text, ...) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return TextFormat(text);
            }

            void drawFPS(int const &posX, int const &posY) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                DrawFPS(posX, posY);
            }

            /*********** SETTERS ***********/

            void setTargetFPS(int const &fps) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                SetTargetFPS(fps);
            }

            void setExitKey(int const &key) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                SetExitKey(key);
            }

            void setTraceLogLevel(int const &logType) {
                SetTraceLogLevel(logType);
            }

            void setConfigFlags(int const &flags) {
                SetConfigFlags(flags);
            }

            void setShaderValue(Shader const &shader, int const &uniformLoc, const void *value, int const &uniformType) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                SetShaderValue(shader, uniformLoc, value, uniformType);
            }

            void setMusicVolume(Music const &music, float const &volume) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                SetMusicVolume(music, volume);
            }

            void setSoundVolume(Sound const &sound, float const &volume) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                SetSoundVolume(sound, volume);
            }

            /*********** GETTERS ***********/

            int getScreenWidth() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return GetScreenWidth();
            }

            int getScreenHeight() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return GetScreenHeight();
            }

            int getShaderLocation(Shader const &shader, std::string const &uniformName) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return GetShaderLocation(shader, uniformName.c_str());
            }

            double getTime() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return GetTime();
            }

            RayCollision getRayCollisionBox(Ray const &ray, BoundingBox const &box) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return GetRayCollisionBox(ray, box);
            }

            Ray getMouseRay(Vector2 const &mousePosition, Camera const &camera) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return GetMouseRay(mousePosition, camera);
            }

            Vector2 getMousePosition() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return GetMousePosition();
            }

            /*********** LOADERS ***********/

            Shader loadShader(std::string const &vsFileName, std::string const &fsFileName) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return LoadShader(vsFileName.c_str(), fsFileName.c_str());
            }

            Texture2D loadTexture(std::string const &fileName) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return LoadTexture(fileName.c_str());
            }

            Texture2D loadTextureFromImage(Image const &image) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return LoadTextureFromImage(image);
            }

            Model loadModel(std::string const &fileName) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return LoadModel(fileName.c_str());
            }

            Model loadModelFromMesh(Mesh const &mesh) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return LoadModelFromMesh(mesh);
            }

            RenderTexture2D loadRenderTexture(int const &width, int const &height) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return LoadRenderTexture(width, height);
            }

            Music loadMusicStream(std::string const &fileName) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return LoadMusicStream(fileName.c_str());
            }

            Sound loadSound(std::string const &fileName) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return LoadSound(fileName.c_str());
            }

            Mesh genMeshCube(float const &width, float const &height, float const &length) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return GenMeshCube(width, height, length);
            }

            Light createLight(int type, Vector3 position, Vector3 target, Color color, Shader shader) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return CreateLight(type, position, target, color, shader);
            }

            Image loadImage(std::string const &fileName) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return LoadImage(fileName.c_str());
            }

            TextureCubemap loadTextureCubemap(Image const &image, int const &layoutType) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return LoadTextureCubemap(image, layoutType);
            }

            /*********** UNLOADERS ***********/

            void unloadShader(Shader const &shader) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                UnloadShader(shader);
            }

            void unloadTexture(Texture2D const &texture) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                UnloadTexture(texture);
            }

            void unloadModel(Model const &model) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                UnloadModel(model);
            }

            void unloadRenderTexture(RenderTexture2D const &target) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                UnloadRenderTexture(target);
            }

            void unloadMusicStream(Music const &music) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                UnloadMusicStream(music);
            }

            void unloadSound(Sound const &sound) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                UnloadSound(sound);
            }

            void unloadMesh(Mesh const &mesh) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                UnloadMesh(mesh);
            }

            void unloadImage(Image const &image) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                UnloadImage(image);
            }

            void stopMusicStream(Music const &music) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                StopMusicStream(music);
            }

            void stopSound(Sound const &sound) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                StopSound(sound);
            }

            void closeAudioDevice() {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                CloseAudioDevice();
            }

            /*********** EVENTS ***********/

            bool isKeyPressed(int const &key) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return IsKeyPressed(key);
            }

            bool isKeyReleased(int const &key) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return IsKeyReleased(key);
            }

            bool isKeyDown(int const &key) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return IsKeyDown(key);
            }

            bool isMouseButtonPressed(int const &button) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return IsMouseButtonPressed(button);
            }

            bool checkCollisionPointRec(Vector2 const &point, Rectangle const &rec) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                return CheckCollisionPointRec(point, rec);
            }

            /********* Update *********/

            void updateMusicStream(Music const &music) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                UpdateMusicStream(music);
            }

            void updateLightValues(Shader const &shader, Light const &light) {
                if (!IsWindowReady())
                    throw RaylibException("Window is not ready");
                UpdateLightValues(shader, light);
            }
            
    };
}