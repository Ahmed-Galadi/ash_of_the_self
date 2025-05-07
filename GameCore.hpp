
#ifndef GAMECORE_HPP
#define GAMECORE_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>
#include <vector>
#include <memory>

struct GameSettings {
    std::string title = "Ash Of The Self";
    unsigned width = 1200;
    unsigned height = 1200;
    std::string cursorPath = "/home/ahmed-galadi/Downloads/HandCursor1.png";
};

class GameCore {
private:
    GameSettings settings;
    sf::RenderWindow window;
    sf::Event event;
    sf::Cursor cursor;
    
    std::unordered_map<sf::Event::EventType, std::function<void(const sf::Event&)>> eventCallbacks;

    void initWindow();
    void loadCursor();
    void closeGame(const sf::Event& event);

public:
    GameCore();
    GameCore(const GameSettings& settings);
    ~GameCore() = default;

    sf::RenderWindow& getWindow();
    void registerEventCallback(sf::Event::EventType type, std::function<void(const sf::Event&)> callback);
    void eventHandler();
    void render(const std::vector<std::reference_wrapper<sf::Drawable>>& drawables);
    void setCursor(const std::string& path);
};

#endif
