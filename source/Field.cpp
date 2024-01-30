#include "Field.hpp"

void Field::Field::manager(sf::RenderWindow& window, int current_sector, int base_sector, sf::Sprite& marc_sprite)
{
	if (current_sector == base_sector) {
		window.draw(field_background->sprite);
		window.draw(marc_sprite);
	}
}

Field::Field::~Field()
{
	delete field_background;
}
