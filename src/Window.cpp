#include "Window.hpp"

namespace log = spdlog;

void Window::InitWindow(int winWidth, int winHeight, std::string winTitle) {
    this->m_width = winWidth;
    this->m_height = winHeight;
    this->m_title = winTitle;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        log::error("SDL_Init Error: {}", SDL_GetError());
        return;
    }

    this->m_window = SDL_CreateWindow(winTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
    if (this->m_window == nullptr) {
        log::error("SDL_CreateWindow Error: {}", SDL_GetError());
        SDL_Quit();
        return;
    }

    this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->m_renderer == nullptr) {
        SDL_DestroyWindow(this->m_window);
        log::error("SDL_CreateRenderer Error: {}", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_Event e;

    while (!this->m_willQuit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                this->m_willQuit = true;
            } else if (e.type == SDL_KEYDOWN) {
                if (!InputManager::get().inputMap.empty())
                    InputManager::get().inputMap[e.key.keysym.sym]();
            }
        }
    }

    SDL_DestroyRenderer(this->m_renderer);
    SDL_DestroyWindow(this->m_window);
    SDL_Quit();
}