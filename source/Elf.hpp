#include "Entity.hpp"
#include "Collisions.hpp"
#include "Sector.hpp"
#include <SFML/Graphics.hpp>
#pragma once

class Elf : public Entity {
public:
	Elf(std::string path, sf::Vector2i start, sf::Vector2i size, float scale);
	~Elf();
private:
	Sector current;
};