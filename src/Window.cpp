#include "Window.hpp"

void Window::InitWindow(int winWidth, int winHeight, std::string winTitle) {
    this->m_width = winWidth;
    this->m_height = winHeight;
    this->m_title = winTitle;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        spdlog::error("SDL_Init Error: {}", SDL_GetError());
        return;
    }

    this->m_window = SDL_CreateWindow(winTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
    if (this->m_window == nullptr) {
        spdlog::error("SDL_CreateWindow Error: {}", SDL_GetError());
        SDL_Quit();
        return;
    }

    this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->m_renderer == nullptr) {
        SDL_DestroyWindow(this->m_window);
        spdlog::error("SDL_CreateRenderer Error: {}", SDL_GetError());
        SDL_Quit();
        return;
    }

    this->m_inputManager = InputManager::get();
    this->m_inputManager.registerInput(SDLK_w, []() {
        spdlog::info("hello game!!");
    });

    SDL_Event e;
    while (!this->m_willQuit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                this->m_willQuit = true;
            } else if (e.type == SDL_KEYDOWN) {
                if (!this->m_inputManager.inputMap.empty())
                    this->m_inputManager.inputMap[e.key.keysym.sym]();
            }
        }
    }

    SDL_DestroyRenderer(this->m_renderer);
    SDL_DestroyWindow(this->m_window);
    SDL_Quit();
}