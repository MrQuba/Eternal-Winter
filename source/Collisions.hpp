#include <SFML/Graphics.hpp>
#pragma once

class Collisions{
public:
#define RIGHT_BORDER_POS 1280
#define LEFT_BORDER_POS 0

enum Collision_Side 
{
	None = -1,
	Left = 1,
	Right = 10
};
	bool with_ground(sf::Sprite& sprite, short ground_level);
	short with_border(sf::Sprite& sprite, sf::RenderWindow& window);

};
