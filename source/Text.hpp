#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

class Text {
public:
	sf::Text text;
	sf::Font font;
	Text(std::string path, int character_size, sf::IntRect color, std::string content);
	~Text();
	void set_text_pos(sf::Vector2f& pos);
	void set_text_string(std::string text);
	void set_text_color(sf::IntRect color);
	void set_text_size(int size);
	void draw_text(sf::RenderWindow& window);
};
