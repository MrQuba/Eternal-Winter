#include "DialogueBox.hpp"

DialogueBox::DialogueBox(std::string path, sf::Vector2i start, sf::Vector2i size, float scale, sf::RenderWindow& window)
{
	init(sprite, texture, path, start, size, scale);
	sprite.setPosition((window.getSize().x - sprite.getLocalBounds().width) / 2, window.getSize().y - sprite.getLocalBounds().height);
}

DialogueBox::~DialogueBox()
{
}
