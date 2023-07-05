/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-edgar.falcou
** File description:
** ZappyGUI.hpp
*/

#pragma once

#include <arpa/inet.h>
#include <cmath>
#include <iostream>
#include <memory>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <fcntl.h>
#include <sstream>
#include <map>
#include <random>
#include <algorithm>

#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include "rlgl.h"
#include "rlights.h"
#include "raygui.h"

#include "Commands.h"

#define RAYGUI_IMPLEMENTATION
#define Cast(type, value) static_cast<type>(value)
#define tileSize 2.0f
#define InvalidTile (tile.position.x == 0 || tile.position.z == 0 || tile.position.x == (_mapSizeVector.x * tileSize - tileSize) || tile.position.z == (_mapSizeVector.y * tileSize - tileSize))