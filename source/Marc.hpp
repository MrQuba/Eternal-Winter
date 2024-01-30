#include "Entity.hpp"
#include "Collisions.hpp"
#include "Sector.hpp"
#include <SFML/Graphics.hpp>
#pragma once

class Marc : public Entity {
public:
	Marc(std::string path, sf::Vector2i start, sf::Vector2i size, float scale);
	~Marc();
	int marc_only;
private:
	Sector current;
};