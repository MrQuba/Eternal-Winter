#include "Player.hpp"

Player::Player(std::string path, sf::Vector2i start, sf::Vector2i size, float scale)
{
	talks = false;
	if (!init(sprite, texture, path, start, size, scale)) std::cout << "error occured while loading texture for player" << std::endl;
	player_movement.init(8.f, 5.f, 0.5f);
	sprite.setPosition(0, 720);
}

Player::~Player()
{
}

bool Player::update(sf::RenderWindow& window)
{
	if (talks) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) talks = false;
		return true;
	}
	is_in += player_movement.update(sprite, window);
	if (1 > is_in) is_in = 1;
	if (is_in > 4) is_in = 4;
	return true;
}
