
#ifndef GAMECORE_HPP
# define GAMECORE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

class GameCore {
	private:
		std::string			gameName;
		sf::RenderWindow	window;
		sf::Event			event;
		sf::Cursor			cursor;
		
		void initWindow(int width, int height);
		void loadCursor();
	public:
		GameCore();
		GameCore(int width, int height);
		~GameCore();

		void	getWindow();
		void	changeCursor(std::string &cursorPath);
		void	eventHander();
		int		getPollEvent();
};

#endif
