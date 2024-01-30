#include "Entity.hpp"

bool Entity::init(sf::Sprite& sprite, sf::Texture& texture, std::string& path, sf::Vector2i start, sf::Vector2i size, float scale) 
{
	if (!texture.loadFromFile(path, sf::IntRect(start, size))) return false;
	else {
		sprite.setTexture(texture);
		sprite.setScale(scale, scale);
		return true;
	}
}

void Entity::draw_entity(sf::RenderWindow& window, int sector)
{
}

bool Entity::update(sf::RenderWindow& window)
{
	return false;
}

Entity::~Entity()
{
	std::cout << "Destroyed Entity object" << std::endl;
}
