#include "Elf.hpp"

Elf ::Elf(std::string path, sf::Vector2i start, sf::Vector2i size, float scale)
{
	init(sprite, texture, path, start, size, scale);
	sprite.setPosition((1280 / 2) + (sprite.getScale().x * sprite.getLocalBounds().width), GROUND_POS - (sprite.getScale().y * sprite.getLocalBounds().height));
}

Elf::~Elf()
{
}
