#include "Window.hpp"

void Window::initWindow(int width, int height, std::string title) {
    this->m_window.create(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close);
    this->m_window.setVerticalSyncEnabled(true);

    signal(SIGSEGV, Crashlog::generateCrashlog);
    sf::Font sourGummyFont;
    if (!sourGummyFont.loadFromFile(fmt::format("{}/sour-gummy.ttf", Dirs::getResourcesDir()))) {
        spdlog::error("Error loading Sour Gummy Font");
    }
    sf::Text fpsLabel;
    fpsLabel.setFont(sourGummyFont);
    fpsLabel.setFillColor(sf::Color::Black);

    unsigned int mFrame;
	unsigned int mFps;
	sf::Clock mClock;
    while (this->m_window.isOpen()) {
        sf::Event event;
        while (this->m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->m_window.close();
            }
        }

        if (mClock.getElapsedTime().asSeconds() >= 1.f) {
            mFps = mFrame;
            mFrame = 0;
            mClock.restart();
        }

        ++mFrame;

        this->m_window.clear(sf::Color(248, 200, 220));
        
        fpsLabel.setString(fmt::format("{} FPS", mFps));
        this->m_window.draw(fpsLabel);

        this->m_window.display();
    }
}