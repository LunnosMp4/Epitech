/*
** EPITECH PROJECT, 2023
** B-CCP-400-MPL-4-1-theplazza-enzo.daumalle
** File description:
** APizza
*/

#pragma once

#include "IPizza.hpp"

namespace Plazza
{
    class APizza : public IPizza
    {
        public:
            APizza() = default;
            APizza(PizzaType type, PizzaSize size, double cookingMultiplier): _type(type), _size(size), _cookingMultiplier(cookingMultiplier), _isCooked(false) {
                init_ingredients();
            }
            ~APizza() = default;

            /* Getters */
            PizzaType getType() const { return _type; }
            PizzaSize getSize() const { return _size; }
            std::string getSizeString() const {
                switch (_size) {
                    case S:
                        return "S";
                    case M:
                        return "M";
                    case L:
                        return "L";
                    case XL:
                        return "XL";
                    case XXL:
                        return "XXL";
                    default:
                        return "unknown";
                }
            }
            std::string getTypeString() const {
                switch (_type) {
                    case Regina:
                        return "regina";
                    case Margarita:
                        return "margarita";
                    case Americana:
                        return "americana";
                    case Fantasia:
                        return "fantasia";
                    default:
                        return "unknown";
                }
            }
            void setStatus(std::string status) { _status = status; }
            std::string getStatus() const { return _status; }
            double getCookingMultiplier() const { return _cookingMultiplier; }
            std::map<Ingredient, int> getIngredients() const { return _ingredients; }
            bool getIsCooked() const { return _isCooked; }

        protected:
            std::map<Ingredient, int> _ingredients;
            PizzaType _type;
            PizzaSize _size;
            double _cookingTime;
            double _cookingMultiplier;
            bool _isCooked;
            std::string _status;

        private:
            void init_ingredients() {
                _ingredients[ChiefLove] = 0;
                _ingredients[Dough] = 0;
                _ingredients[Eggplant] = 0;
                _ingredients[GoatCheese] = 0;
                _ingredients[Gruyere] = 0;
                _ingredients[Ham] = 0;
                _ingredients[Mushrooms] = 0;
                _ingredients[Steak] = 0;
                _ingredients[Tomato] = 0;
            }
    };

}
