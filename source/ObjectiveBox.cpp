#include "ObjectiveBox.hpp"

ObjectiveBox::ObjectiveBox(std::string path, sf::Vector2i start, sf::Vector2i size, float scale, sf::RenderWindow& window)
{
	init(sprite, texture, path, start, size, scale);
	sprite.setPosition(0, 0);
}

ObjectiveBox::~ObjectiveBox()
{
}
