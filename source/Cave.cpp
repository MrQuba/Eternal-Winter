#include "Cave.hpp"

void Cave::Cave::manager(sf::RenderWindow& window, int current_sector, int base_sector, sf::Sprite& elf_sprite)
{
	if (current_sector == base_sector) {
		window.draw(cave_background->sprite);
		window.draw(elf_sprite);
	}
}

Cave::Cave::~Cave()
{
	delete cave_background;
}
