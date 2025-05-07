#include "GameCore.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <iostream>

int main() {
    try {
        // Create with default settings
        GameCore game;

        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Red);
		// sf::Image menue;

		// menue.loadFromFile("/home/ahmed-galadi/Downloads/mainMenueOfficial.png");

        while (game.getWindow().isOpen()) {
            game.eventHandler();
            
            std::vector<std::reference_wrapper<sf::Drawable>> drawables;
            drawables.push_back(shape);
            
            game.render(drawables);
        }
    } catch (const std::exception& e) {
        std::cerr << "Game crashed: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}




//--------- render font text ------------------
// #include <SFML/Graphics.hpp>
// #include <string>
//
// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(800, 800), "Typing Text");
//     sf::Font font;
//     if (!font.loadFromFile("/home/ahmed-galadi/Downloads/GohuFont11NerdFontMono-Regular.ttf"))
//         return -1;
//
//     std::string fullText = "Ah... another one.\nAnother fractured soul...\ncrawling in from\nthe threshold";
//     std::string currentText = "";
//     size_t charIndex = 0;
//
//     sf::Text text;
//     text.setFont(font);
//     text.setCharacterSize(36);
//     text.setFillColor(sf::Color::White);
//     text.setPosition(200.f, 400.f);
//
//     sf::Clock clock;
//     float typingDelay = 0.04f; // seconds between letters
//
//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed 
//                 || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
//                 window.close();
//         }
//
//         // Add next letter every 0.1 seconds
//         if (charIndex < fullText.size() && clock.getElapsedTime().asSeconds() >= typingDelay)
//         {
//             currentText += fullText[charIndex++];
//             text.setString(currentText);
//             clock.restart();
//         }
//
//         window.clear();
//         window.draw(text);
//         window.display();
//     }
//
//     return 0;
// }
