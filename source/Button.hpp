#include "Entity.hpp"
#pragma once

class Button : public Entity {
public:
	sf::Texture brightened_texture;
	bool is_clicked = false;
	Button(std::string path, sf::Vector2i start, sf::Vector2i size, float scale, sf::Vector2i start_b, sf::Vector2i size_b);
	bool isHoveredOn(sf::Sprite& button, sf::RenderWindow& window);
	bool isClicked(sf::Sprite& button, sf::RenderWindow& window);
	void update(sf::Sprite& button, sf::RenderWindow& window);
};
