#include "Tower.hpp"

void Tower::Tower::manager(sf::RenderWindow& window, int current_sector, int base_sector, sf::Sprite& soul_sprite)
{
	if (current_sector == base_sector) {
		window.draw(tower_background->sprite);
		window.draw(soul_sprite);
	}
}

Tower::Tower::~Tower()
{
	delete tower_background;
}
