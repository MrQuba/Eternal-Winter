#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#pragma once

class DialogueBox : public Entity {
public:
	DialogueBox(std::string path, sf::Vector2i start, sf::Vector2i size, float scale, sf::RenderWindow& window);
	~DialogueBox();

};
