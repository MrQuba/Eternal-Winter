#include "Text.hpp"

Text::Text(std::string path, int character_size, sf::IntRect color, std::string content)
{
	if (!font.loadFromFile(path)) std::cout << "There was an error while loading font" << std::endl;
	text.setFont(font);
	set_text_string(content);
	set_text_size(character_size);
	set_text_color(color);
}
Text::~Text()
{
}

void Text::set_text_pos(sf::Vector2f& pos)
{
	text.setPosition(pos);
}

void Text::set_text_string(std::string text)
{
	this->text.setString(text);
}

void Text::set_text_color(sf::IntRect color)
{
	text.setFillColor(sf::Color(color.left, color.top, color.width, color.height));
}

void Text::set_text_size(int size)
{
	text.setCharacterSize(size);
}

void Text::draw_text(sf::RenderWindow& window)
{
	window.draw(text);
}
