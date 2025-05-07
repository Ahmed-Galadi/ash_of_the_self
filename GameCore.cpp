
#include "GameCore.hpp"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

GameCore::GameCore() : gameName("Ash Of The Self") {
	initWindow(1200, 1200);
	loadCursor();
}

GameCore::GameCore(int width, int height) : gameName("Ash Of The Self") {
	initWindow(width, height);
	loadCursor();
}

void GameCore::initWindow(int width, int height) {
	window.create(sf::VideoMode(width, height), gameName);
}

void GameCore::loadCursor() {
	sf::Image cursorImage;
	if (!cursorImage.loadFromFile("/home/ahmed-galadi/Downloads/handCursor1.png"))
		exit(1);
	if (cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), sf::Vector2u(0, 0)))
		window.setMouseCursor(cursor);
}
