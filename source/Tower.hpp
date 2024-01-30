#include <SFML/Graphics.hpp>
#include "Background.hpp"
#include "Entity.hpp"
#pragma once
namespace Tower {
	class Tower {
	public:
		void manager(sf::RenderWindow& window, int current_sector, int base_sector, sf::Sprite& soul_sprite);
		~Tower();
	private:
		Entity* tower_background = new Background("assets/world.png", sf::Vector2i(0, 2160), sf::Vector2i(1280, 720), 1.f);
	};
}