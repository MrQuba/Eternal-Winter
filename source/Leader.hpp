#include "Entity.hpp"
#include "Collisions.hpp"
#include "Sector.hpp"
#include <SFML/Graphics.hpp>
#pragma once

class Leader : public Entity {
public:
	Leader(std::string path, sf::Vector2i start, sf::Vector2i size, float scale);
	bool update(sf::RenderWindow& window) override;
	void draw_entity(sf::RenderWindow& window, int sector) override;
	~Leader();
private:
	Collisions leader_collides;
	Sector current;
};