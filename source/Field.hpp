#include <SFML/Graphics.hpp>
#include "Background.hpp"
#include "Entity.hpp"
#pragma once
namespace Field {
	class Field {
	public:
		void manager(sf::RenderWindow& window, int current_sector, int base_sector, sf::Sprite& marc_sprite);
		~Field();
	private:
		Entity* field_background = new Background("assets/world.png", sf::Vector2i(0, 720), sf::Vector2i(1280, 720), 1.f);
	};
}