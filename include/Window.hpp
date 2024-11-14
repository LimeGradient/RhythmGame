#pragma once

#include <string>

#include <SDL.h>
#include <spdlog/spdlog.h>

#include "InputManager.hpp"

class Window {
public:
    static Window& get() {
        static Window instance;
        return instance;
    }

    void InitWindow(int winWidth, int winHeight, std::string winTitle);

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    int m_width;
    int m_height;
    std::string m_title;
    bool m_willQuit;
};