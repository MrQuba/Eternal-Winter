#include "background.hpp"

Background::Background(std::string path, sf::Vector2i start, sf::Vector2i size, float scale)
{
	init(sprite, texture, path, start, size, scale);
}

Background::~Background()
{
}
