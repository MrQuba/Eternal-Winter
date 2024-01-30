#include "Entity.hpp"
#pragma once

class Soul : public Entity {
public:
	Soul(std::string path, sf::Vector2i start, sf::Vector2i size, float scale, sf::RenderWindow& window);
	bool is_destroyed;
	void rotate();
	~Soul();
};
