#include "Village.hpp"

void Village::Village::manager(sf::RenderWindow& window, int current_sector, int base_sector, sf::Sprite& leader_sprite)
{
	if (current_sector == base_sector) {
		window.draw(village_background->sprite);
		window.draw(leader_sprite);
	}
}

Village::Village::~Village()
{
	delete village_background;
}
