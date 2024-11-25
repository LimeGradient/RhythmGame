#pragma once

#include <SFML/Graphics.hpp>

#include "types/Vector2.hpp"

class ColorCube {
public:
    ColorCube(Vector2 position, Vector2 size, sf::Color color, bool showOutline = true) {
        this->position = position;
        this->size = size;
        this->color = color;
        this->showOutline = showOutline;
    }

    sf::RectangleShape renderCube() {
        sf::RectangleShape rect(size.toVector2f());
        rect.setFillColor(color);
        rect.setPosition(position.toVector2f());

        if (showOutline) {
            rect.setOutlineThickness(2.f);
            rect.setOutlineColor(sf::Color::Black);
        }

        return rect;
    }

    Vector2 position;
    Vector2 size;
    sf::Color color;
    bool showOutline;
};