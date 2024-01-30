#include <SFML/Graphics.hpp>
#include "Background.hpp"
#include "Entity.hpp"
#pragma once
namespace Village{
class Village {
public:
	void manager(sf::RenderWindow& window, int current_sector, int base_sector, sf::Sprite& leader_sprite);
	~Village();
private:
	Entity* village_background = new Background("assets/world.png", sf::Vector2i(0, 0), sf::Vector2i(1280, 720), 1.f);
};
}