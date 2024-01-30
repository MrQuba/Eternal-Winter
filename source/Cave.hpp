#include <SFML/Graphics.hpp>
#include "Background.hpp"
#include "Entity.hpp"
#pragma once
namespace Cave {
	class Cave {
	public:
		void manager(sf::RenderWindow& window, int current_sector, int base_sector, sf::Sprite& marc_sprite);
		~Cave();
	private:
		Entity* cave_background = new Background("assets/world.png", sf::Vector2i(0, 1440), sf::Vector2i(1280, 720), 1.f);
	};
}