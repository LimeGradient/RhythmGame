#pragma once

#include <map>
#include <functional>

#include <SDL.h>

class InputManager {
public:
    static InputManager& get() {
        static InputManager instance;
        return instance;
    }

    void registerInput(int keyCode, std::function<void()> func);
    bool isKeyDown(int keyCode);

    std::map<int, std::function<void()>> inputMap;
};