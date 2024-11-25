#pragma once

#include <SFML/Graphics.hpp>

class Vector2 {
public:
    Vector2(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Vector2() = default;

    sf::Vector2f toVector2f() {
        return sf::Vector2f(x, y);
    }

    float x;
    float y;
};