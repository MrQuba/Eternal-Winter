#include <SFML/Graphics.hpp>
#include <iostream>
#include "Event.hpp"
#include "Collisions.hpp"
#pragma once

class Movement {

public:
	struct value_of;
	struct state;
	enum Direction;
	Event input;
	Collisions player_collides;

	void init(const float speed, const float jump_height, const float air_resistance);
	float moveSideways(sf::Keyboard::Key key, int direction);
	int update(sf::Sprite& sprite, sf::RenderWindow& window);
	~Movement();
	float movesUpwards();
};