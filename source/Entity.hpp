#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once
	class Entity {
	protected:
		sf::Texture texture;
		bool init(sf::Sprite& sprite, sf::Texture& texture, std::string& path, sf::Vector2i start, sf::Vector2i size, float scale);
	public:
	#define GROUND_POS 600
		short is_in;
		bool talked = false;
		bool talks = false;
		short talks_with = 0;
		bool finished_talking = false;
		sf::Sprite sprite;
		virtual void draw_entity(sf::RenderWindow& window, int sector);
		virtual bool update(sf::RenderWindow& window);
		~Entity();
	};