/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InventorySystem.hpp
*/

#pragma once

#include "../../Components/InventoryComponent.hpp"
#include "../../Components/TimerComponent.hpp"
#include <algorithm>

namespace Cereal {
    class InventorySystem {
        public:
            static void addItem(Inventory& inventory, const std::string& itemName, int quantity = 1);
            static void removeItem(Inventory& inventory, const std::string& itemName, int quantity = 1);
            static bool hasItem(Inventory& inventory, const std::string& itemName);
            static int getItemQuantity(Inventory& inventory, const std::string& itemName);
            static void clear(Inventory& inventory);
    };
}