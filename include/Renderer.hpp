#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "types/TextObject.hpp"
#include "Window.hpp"

class Renderer {
public:
    static Renderer& get() {
        static Renderer instance;
        return instance;
    }

    void createText(TextObject textObject);

    void renderAllText();

    std::vector<sf::Text> m_textObjects;
};