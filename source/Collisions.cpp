#include "Collisions.hpp"

bool Collisions::with_ground(sf::Sprite& sprite, short ground_level)
{
    if (sprite.getPosition().y + sprite.getLocalBounds().height >= ground_level)
    {
        sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - sprite.getLocalBounds().height);
        return true;
    }
    else 
    return false;
}

short Collisions::with_border(sf::Sprite& sprite, sf::RenderWindow& window)
{
    if (sprite.getPosition().x - (sprite.getScale().x * sprite.getLocalBounds().width) <= LEFT_BORDER_POS) {
        sprite.setPosition(LEFT_BORDER_POS + sprite.getLocalBounds().width, sprite.getPosition().y);
        return Left;
    }
    else if (sprite.getPosition().x + (sprite.getScale().x * sprite.getLocalBounds().width) >= RIGHT_BORDER_POS) {
        sprite.setPosition(RIGHT_BORDER_POS - sprite.getLocalBounds().width, sprite.getPosition().y);
        return Right;
    }
    else return None;
}
