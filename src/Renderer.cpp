#include "Renderer.hpp"

void Renderer::createText(TextObject textObject) {
    sf::Text rawText = textObject.convertToText();
    this->m_textObjects.push_back(rawText);
}

void Renderer::renderAllText() {
    for (auto textObj : this->m_textObjects) {
        Window::get().m_window.draw(textObj);
    }
}