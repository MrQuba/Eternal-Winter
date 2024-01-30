#include "Button.hpp"

Button::Button(std::string path, sf::Vector2i start, sf::Vector2i size, float scale, sf::Vector2i start_b, sf::Vector2i size_b)
{
	init(sprite, brightened_texture, path, start_b, size_b, scale);
	init(sprite, texture, path, start, size, scale);
}

bool Button::isHoveredOn(sf::Sprite& button, sf::RenderWindow& window)
{
	if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) return true;
	else return false;
}

bool Button::isClicked(sf::Sprite& button, sf::RenderWindow& window)
{
	if (isHoveredOn(button, window)) {
		button.setTexture(brightened_texture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isHoveredOn(button, window)) {
			return true;
		}
		return false;

	}
	else {
		button.setTexture(texture);
		return false;
	}
}

void Button::update(sf::Sprite& button, sf::RenderWindow& window)
{
	if (isClicked(button, window)) is_clicked = true;
	else is_clicked = false;
	window.draw(sprite);
}
