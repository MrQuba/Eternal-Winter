#include "Leader.hpp"

Leader::Leader(std::string path, sf::Vector2i start, sf::Vector2i size, float scale)
{
	init(sprite, texture, path, start, size, scale);
	sprite.setPosition((1280 / 2) + (sprite.getScale().x * sprite.getLocalBounds().width), GROUND_POS - (sprite.getScale().y * sprite.getLocalBounds().height));
}

bool Leader::update(sf::RenderWindow& window)
{
	leader_collides.with_ground(sprite, GROUND_POS);
	return false;
}

void Leader::draw_entity(sf::RenderWindow& window, int sector)
{
	if (sector == current.Village) window.draw(sprite);
}

Leader::~Leader()
{
}
