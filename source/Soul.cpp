#include "Soul.hpp"

Soul::Soul(std::string path, sf::Vector2i start, sf::Vector2i size, float scale, sf::RenderWindow& window)
{
	init(sprite, texture, path, start, size, scale);
	is_destroyed = false;
	sprite.setPosition((window.getSize().x / 2) - ((sprite.getLocalBounds().width * sprite.getScale().x) / 2), (window.getSize().x / 2) - ((sprite.getLocalBounds().height * sprite.getScale().y) / 2));
}

void Soul::rotate()
{
	sprite.rotate(1);
}

Soul::~Soul()
{
}
