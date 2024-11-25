#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

class TextObject {
public:
    TextObject(std::string text, std::string fontPath, int fontSize, sf::Color textColor = sf::Color::Black, sf::Text::Style textStyle = sf::Text::Style::Regular) {
        this->text = text;
        this->fontPath = fontPath;
        this->fontSize = fontSize;
        this->textColor = textColor;
        this->textStyle = textStyle;
    }

    sf::Text convertToText() {
        sf::Font font;
        if (!font.loadFromFile(this->fontPath)) {
            spdlog::error("Error loading font: {}", fontPath);
        }

        sf::Text text;
        text.setFont(font);
        text.setString(this->text);
        text.setCharacterSize(fontSize);
        text.setFillColor(this->textColor);
        text.setStyle(this->textStyle);

        return text;
    }

    std::string text;
    std::string fontPath;
    int fontSize;
    sf::Color textColor;
    sf::Text::Style textStyle;
};