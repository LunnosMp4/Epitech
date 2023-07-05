/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGraphical.hpp
*/

#pragma once

#include <iostream>
#include <memory>
#include "../core/Utils.hpp"

class IGraphical {
    public:
        virtual ~IGraphical() = default;

        /**
         * @brief Create a window object
         *
         * @param width
         * @param height
         * @param title
         */
        virtual void createWindow(unsigned int width, unsigned int height, const std::string &title) = 0;
        /**
         * @brief Destroy the window object
         *
         */
        virtual void destroyWindow() = 0;
        /**
         * @brief Clear the window
         *
         */
        virtual void clear() const = 0;
        /**
         * @brief Refresh the window
         *
         */
        virtual void refresh() const = 0;
        /**
         * @brief Display the window
         *
         */
        virtual void display() const = 0;

        /**
         * @brief Draw a rectangle
         *
         * @param position
         * @param size
         * @param color
         */
        virtual void drawRectangle(Vector2f position, Vector2f size, Color color) const = 0;
        /**
         * @brief Draw a circle
         *
         * @param position
         * @param radius
         * @param color
         */
        virtual void drawCircle(Vector2f position, float radius, Color color) const = 0;
        /**
         * @brief Draw a text
         *
         * @param position
         * @param text
         * @param size
         * @param color
         */
        virtual void drawText(Vector2f position, const std::string &text, unsigned int size, Color color) const = 0;
        /**
         * @brief Draw a sprite
         *
         * @param position
         * @param path
         */
        virtual void drawSprite(Vector2f position, const std::string &path) const = 0;

        /**
         * @brief Check if the window is open
         *
         * @return true
         * @return false
         */
        virtual bool isOpen() const = 0;
        /**
         * @brief Get the Input object
         *
         * @return Input
         */
        virtual Input getInput() = 0;
};
