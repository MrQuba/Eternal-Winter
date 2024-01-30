#include "Entity.hpp"
#include "Movement.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

class Player : public Entity {
public:
#define GROUND_POS 600
	Player(std::string path, sf::Vector2i start, sf::Vector2i size, float scale);
	~Player();
	bool update(sf::RenderWindow& window) override;
private:
	Movement player_movement;
};
