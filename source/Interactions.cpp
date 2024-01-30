#include "Interactions.hpp"

bool Interactions::with_npc(sf::Sprite& player, sf::Sprite& npc, sf::RenderWindow& window, sf::Text& text)
{
    if (abs(player.getPosition().x - npc.getPosition().x) <= 100) {
        text.setPosition(npc.getPosition().x - (text.getLocalBounds().width / 4), npc.getPosition().y - text.getLocalBounds().height);
        window.draw(text);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        return true;
    }
    else return false;
}
