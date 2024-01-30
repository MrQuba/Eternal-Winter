#pragma once
#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#pragma once


class Background : public Entity {
private:
public:
	Background(std::string path, sf::Vector2i start, sf::Vector2i size, float scale);
	~Background();

};