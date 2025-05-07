#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

void close_game(sf::RenderWindow &window, sf::Event &event) {
	if (event.type == sf::Event::Closed 
		|| (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            window.close();

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			close_game(window, event);
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
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
