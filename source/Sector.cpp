#include "Sector.hpp"

void Sector::manager(sf::RenderWindow& window, int current_sector, sf::Sprite& leader_sprite, sf::Sprite& marc_sprite, sf::Sprite& elf_sprite, sf::Sprite& soul_sprite)
{
	village.manager(window, current_sector, Village, leader_sprite);
	field.manager(window, current_sector, Field_2, marc_sprite);
	cave.manager(window, current_sector, Cave, elf_sprite);
	tower.manager(window, current_sector, Tower, soul_sprite);
}
