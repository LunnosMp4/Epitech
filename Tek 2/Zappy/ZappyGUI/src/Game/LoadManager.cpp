/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** LoadManager.cpp
*/

#include "Game.hpp"

using namespace Zappy;

#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"
#define GLSL_VERSION    330

void Game::loadShader() {
    _shader = raylib->loadShader(TextFormat("resources/shaders/glsl%i/lighting.vs", GLSL_VERSION),
                         TextFormat("resources/shaders/glsl%i/lighting.fs", GLSL_VERSION));
    _shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(_shader, "viewPos");
    int ambientLoc = GetShaderLocation(_shader, "ambient");
    float ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    raylib->setShaderValue(_shader, ambientLoc, ambient, SHADER_UNIFORM_VEC4);

    Mesh cube = raylib->genMeshCube(1.0f, 1.0f, 1.0f);
    _skybox = raylib->loadModelFromMesh(cube);

    _skybox.materials[0].shader = LoadShader(TextFormat("resources/shaders/glsl%i/skybox.vs", GLSL_VERSION),
                                            TextFormat("resources/shaders/glsl%i/skybox.fs", GLSL_VERSION));

    Shader skyboxShader = _skybox.materials[0].shader;
    int environmentMapLoc = raylib->getShaderLocation(skyboxShader, "environmentMap");
    int doGammaLoc = raylib->getShaderLocation(skyboxShader, "doGamma");
    int vflippedLoc = raylib->getShaderLocation(skyboxShader, "vflipped");

    int environmentMapValue[1] = { MATERIAL_MAP_CUBEMAP };
    int doGammaValue[1] = { 0 };
    int vflippedValue[1] = { 0 };

    raylib->setShaderValue(skyboxShader, environmentMapLoc, environmentMapValue, SHADER_UNIFORM_INT);
    raylib->setShaderValue(skyboxShader, doGammaLoc, doGammaValue, SHADER_UNIFORM_INT);
    raylib->setShaderValue(skyboxShader, vflippedLoc, vflippedValue, SHADER_UNIFORM_INT);

    Image img = raylib->loadImage("resources/skybox.png");
    _skybox.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = raylib->loadTextureCubemap(img, CUBEMAP_LAYOUT_AUTO_DETECT);
    raylib->unloadImage(img);

    _bgShader = LoadShader(0, TextFormat("resources/shaders/glsl%i/blur.fs", GLSL_VERSION));
    _bgShaderTarget = raylib->loadRenderTexture(raylib->getScreenWidth(), raylib->getScreenHeight());
}

void Game::loadModels() {
    _models["tile"] = raylib->loadModel("resources/square_forest_detail.gltf.glb");
    _models["tileHalf"] = raylib->loadModel("resources/square_forest_waterStraight.gltf.glb");
    _models["tileCorner"] = raylib->loadModel("resources/square_forest_waterOuterCorner.gltf.glb");
    _models["treeA"] = raylib->loadModel("resources/detail_treeA.gltf.glb");
    _models["treeB"] = raylib->loadModel("resources/detail_treeB.gltf.glb");
    _models["treeC"] = raylib->loadModel("resources/detail_treeC.gltf.glb");
    _models["rock"] = raylib->loadModel("resources/detail_rocks_small.gltf.glb");
    _models["food"] = raylib->loadModel("resources/food.glb");
    _models["linemate"] = raylib->loadModel("resources/gems1.glb");
    _models["deraumere"] = raylib->loadModel("resources/gems2.glb");
    _models["sibur"] = raylib->loadModel("resources/gems3.glb");
    _models["mendiane"] = raylib->loadModel("resources/gems4.glb");
    _models["phiras"] = raylib->loadModel("resources/gems5.glb");
    _models["thystame"] = raylib->loadModel("resources/gems6.glb");

    for (auto& modelPair : _models) {
        Model& model = modelPair.second;
        for (int i = 0; i < model.materialCount; i++)
            model.materials[i].shader = _shader;
    }
}

void Game::loadImages() {
    _textures2D["food"] = raylib->loadTexture("resources/images/food.png");
    _textures2D["gem1"] = raylib->loadTexture("resources/images/gem1.png");
    _textures2D["gem2"] = raylib->loadTexture("resources/images/gem2.png");
    _textures2D["gem3"] = raylib->loadTexture("resources/images/gem3.png");
    _textures2D["gem4"] = raylib->loadTexture("resources/images/gem4.png");
    _textures2D["gem5"] = raylib->loadTexture("resources/images/gem5.png");
    _textures2D["gem6"] = raylib->loadTexture("resources/images/gem6.png");
    _textures2D["cursor_normal"] = raylib->loadTexture("resources/images/cursor_normal.png");
    _textures2D["cursor_select"] = raylib->loadTexture("resources/images/cursor_select.png");
    _textures2D["cursor_move"] = raylib->loadTexture("resources/images/cursor_move.png");
}

void Game::loadLights() {
    _light = raylib->createLight(LIGHT_POINT, (Vector3){ 11, 20, 11 }, (Vector3){11, 0, 11}, WHITE, _shader);
}

void Game::initAudio() {
    InitAudioDevice();

    _music = raylib->loadMusicStream("resources/audio/music.mp3");
    _sounds["click"] = raylib->loadSound("resources/audio/click.mp3");
    _sounds["levelup"] = raylib->loadSound("resources/audio/levelup.wav");

    PlayMusicStream(_music);

    raylib->setMusicVolume(_music, 0.3f);
    raylib->setSoundVolume(_sounds["click"], 0.5f);
    raylib->setSoundVolume(_sounds["levelup"], 0.5f);
}

void Game::stopAudio() {
    raylib->stopMusicStream(_music);
    for (auto& soundPair : _sounds)
        raylib->stopSound(soundPair.second);
    raylib->unloadMusicStream(_music);
    for (auto& soundPair : _sounds)
        raylib->unloadSound(soundPair.second);

    raylib->closeAudioDevice();
}