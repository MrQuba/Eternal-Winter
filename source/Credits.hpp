#include "Entity.hpp"
#pragma once

class Credits : public Entity {
public:
	Credits(std::string path, sf::Vector2i start, sf::Vector2i size, float scale, sf::RenderWindow& window);
	~Credits();
};