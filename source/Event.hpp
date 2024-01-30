#include <SFML/Graphics.hpp>
#pragma once
class Event {
public:
    sf::Event event;
    bool closed = false;
    bool paused = false;
    void Loop(sf::RenderWindow& window, bool& released);
    int key_released(sf::Keyboard::Key key, sf::RenderWindow& window, sf::Event& event);
    int button_released(sf::Mouse::Button button, sf::RenderWindow& window, sf::Event& event);
    bool has_paused(sf::Event& event);
};