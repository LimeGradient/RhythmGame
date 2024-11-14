#include "InputManager.hpp"

void InputManager::registerInput(int keyCode, std::function<void()> func) {
    this->inputMap[keyCode] = func;
}