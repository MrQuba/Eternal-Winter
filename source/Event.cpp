#include "Event.hpp"
#include <iostream>
void Event::Loop(sf::RenderWindow& window, bool& released)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) closed = true;
        if (button_released(sf::Mouse::Left, window, event) == 1) released = true;
        has_paused(event);
    }
}

int Event::key_released(sf::Keyboard::Key key, sf::RenderWindow& window, sf::Event& event)
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyReleased && event.key.code == key) return 0;
        else return 1;
    }
    return 1;
}

int Event::button_released(sf::Mouse::Button button, sf::RenderWindow& window, sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == button) return 1;
}
bool Event::has_paused(sf::Event& event) 
{
   // if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && paused) return false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !paused) paused = true;
    return false;
}

