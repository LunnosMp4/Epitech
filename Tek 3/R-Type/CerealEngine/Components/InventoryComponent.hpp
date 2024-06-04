/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InventorySystem.hpp
*/

#pragma once

#include "../Systems/Component/Component.hpp"
#include <vector>

namespace Cereal {
    struct InventoryItem {
        std::string name;
        int quantity;

        InventoryItem(const std::string& itemName, int itemQuantity) : name(itemName), quantity(itemQuantity) {}
        bool operator==(const InventoryItem& other) const {
            return name == other.name && quantity == other.quantity;
        }
    };

    class Inventory : public ComponentBase {
        public:
            std::vector<InventoryItem> items;

            Inventory() = default;
    };
}