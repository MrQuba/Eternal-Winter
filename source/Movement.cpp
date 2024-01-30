#include "Movement.hpp"
struct Movement::value_of
{
	float jump_height;
	float air_resistance;
	float speed;
	sf::Vector2f velocity;
}player, current;
struct Movement::state {
	bool jumped = false;
	bool jumping = false;
	bool can_jump = true;
}player_state;
enum Movement::Direction 
{
	Left = -1,
	Right = 1
};

void Movement::init(float speed, float jump_height, float air_resistance)
{
	player.speed = speed;
	player.jump_height = jump_height;
	player.air_resistance = air_resistance;
}
float Movement::moveSideways(sf::Keyboard::Key key, int player_direction)
{
	if (sf::Keyboard::isKeyPressed(key)) return player.speed * player_direction;
	else return 0;
}

int Movement::update(sf::Sprite& sprite, sf::RenderWindow& window)
{
	player.velocity.x = moveSideways(sf::Keyboard::A, -1) + moveSideways(sf::Keyboard::D, 1);
	player.velocity.y += movesUpwards();
	player.velocity.x *= input.key_released(sf::Keyboard::A, window, input.event);
	player.velocity.x *= input.key_released(sf::Keyboard::D, window, input.event);

	sprite.move(player.velocity);

	if (player_collides.with_ground(sprite, 600)) {
		player_state.can_jump = true;
		player_state.jumping = false;
		player.velocity.y = 0;
	}
	if (player_collides.with_border(sprite, window) != player_collides.None) player.velocity.x = 0;
	if (player_collides.with_border(sprite, window) == player_collides.Left) {
		sprite.setPosition(window.getSize().x - (2 * sprite.getScale().x * sprite.getLocalBounds().width), sprite.getPosition().y);
		return -1;
	}
	else if (player_collides.with_border(sprite, window) == player_collides.Right) {
		sprite.setPosition(2 * sprite.getScale().x * sprite.getLocalBounds().width, sprite.getPosition().y);
		return 1;
	}
	else return 0;

}

Movement::~Movement()
{
}

float Movement::movesUpwards()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player_state.can_jump) {
		player_state.jumped = true;
		player_state.can_jump = false;
	}
	if (player_state.jumped)
	{
		player_state.jumped = false;
		player_state.jumping = true;
		current.jump_height = -player.jump_height;
		return current.jump_height;
	}
	if (player_state.jumping)
	{
		current.jump_height += player.air_resistance;
		return current.jump_height;
	}
	else return 0.0f;
}
