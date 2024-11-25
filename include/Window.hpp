#pragma once

#include <string>
#include <csignal>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

#include "GameObjects/ColorCube.hpp"
#include "Renderer.hpp"
#include "utils/Crashlog.hpp"
#include "utils/dirs.hpp"

class Window {
public:
    static Window& get() {
        static Window instance;
        return instance;
    }

    void initWindow(int width, int height, std::string title);
    float getFPS();

    sf::RenderWindow m_window;
};