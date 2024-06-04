/*
** EPITECH PROJECT, 2023
** B-CPP-500-MPL-5-2-rtype-maxime.santos
** File description:
** InventorySystem.cpp
*/

#include "InventorySystem.hpp"

namespace Cereal {
    void InventorySystem::addItem(Inventory& inventory, const std::string& itemName, int quantity)
    {
        for (auto& item : inventory.items) {
            if (item.name == itemName) {
                item.quantity += quantity;
                return;
            }
        }
        inventory.items.emplace_back(itemName, quantity);
    }

    void Cereal::InventorySystem::removeItem(Cereal::Inventory& inventory, const std::string& itemName, int quantity) {
        for (auto& item : inventory.items) {
            if (item.name == itemName) {
                item.quantity -= quantity;
                if (item.quantity <= 0)
                    inventory.items.erase(std::remove(inventory.items.begin(), inventory.items.end(), item), inventory.items.end());
                return;
            }
        }
    }

    bool InventorySystem::hasItem(Inventory& inventory, const std::string& itemName)
    {
        for (auto& item : inventory.items) {
            if (item.name == itemName)
                return true;
        }
        return false;
    }

    int InventorySystem::getItemQuantity(Inventory& inventory, const std::string& itemName)
    {
        for (auto& item : inventory.items) {
            if (item.name == itemName)
                return item.quantity;
        }
        return 0;
    }

    void InventorySystem::clear(Inventory& inventory)
    {
        inventory.items.clear();
    }
}
