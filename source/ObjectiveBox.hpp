#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#pragma once

class ObjectiveBox : public Entity{
public:
	ObjectiveBox(std::string path, sf::Vector2i start, sf::Vector2i size, float scale, sf::RenderWindow& window);
	~ObjectiveBox();
};
