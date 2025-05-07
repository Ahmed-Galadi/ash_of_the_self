
#include "GameCore.hpp"
#include <stdexcept>
#include <iostream>

GameCore::GameCore() : settings() {
    try {
        initWindow();
        loadCursor();
        registerEventCallback(sf::Event::Closed, [this](const sf::Event& e) { closeGame(e); });
        registerEventCallback(sf::Event::KeyPressed, [this](const sf::Event& e) {
            if (e.key.code == sf::Keyboard::Escape) closeGame(e);
        });
    } catch (const std::exception& e) {
        std::cerr << "GameCore initialization failed: " << e.what() << std::endl;
        throw;
    }
}

GameCore::GameCore(const GameSettings& settings) : settings(settings) {
    try {
        initWindow();
        loadCursor();
        registerEventCallback(sf::Event::Closed, [this](const sf::Event& e) { closeGame(e); });
        registerEventCallback(sf::Event::KeyPressed, [this](const sf::Event& e) {
            if (e.key.code == sf::Keyboard::Escape)
				closeGame(e);
        });
    } catch (const std::exception& e) {
        std::cerr << "GameCore initialization failed: " << e.what() << std::endl;
        throw;
    }
}

void GameCore::initWindow() {
    window.create(sf::VideoMode(settings.width, settings.height), settings.title);
}

void GameCore::loadCursor() {
    setCursor(settings.cursorPath);
}

sf::RenderWindow& GameCore::getWindow() {
    return window;
}

void GameCore::registerEventCallback(sf::Event::EventType type, std::function<void(const sf::Event&)> callback) {
    eventCallbacks[type] = callback;
}

void GameCore::eventHandler() {
    while (window.pollEvent(event)) {
        if (auto it = eventCallbacks.find(event.type); it != eventCallbacks.end()) {
            it->second(event);
        }
    }
}

void GameCore::render(const std::vector<std::reference_wrapper<sf::Drawable>>& drawables) {
    window.clear();
    for (auto& drawable : drawables) {
        window.draw(drawable);
    }
    window.display();
}

void GameCore::setCursor(const std::string& path) {
    sf::Image cursorImage;
    if (!cursorImage.loadFromFile(path)) {
        throw std::runtime_error("Failed to load cursor image: " + path);
    }
    if (!cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), {0, 0})) {
        throw std::runtime_error("Failed to create cursor from image");
    }
    window.setMouseCursor(cursor);
}

void GameCore::closeGame(const sf::Event& event) {
    window.close();
}










