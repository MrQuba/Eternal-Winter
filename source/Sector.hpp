#include <SFML/Graphics.hpp>
#include "Background.hpp"
#include "Field.hpp"
#include "Village.hpp"
#include "Cave.hpp"
#include "Tower.hpp"
#pragma once

class Sector {
public:
	enum Room {
		Dungeon = -1,
		Field_1 = 0,
		Village = 1,
		Field_2 = 2,
		Cave = 3,
		Tower = 4,
		Menu = -10,
		Pause_Menu = 123
	};
	void manager(sf::RenderWindow& window, int current_sector, sf::Sprite& leader_sprite, sf::Sprite& marc_sprite, sf::Sprite& elf_sprite, sf::Sprite& soul_sprite);
private:
	Village::Village village;
	Field::Field field;
	Cave::Cave cave;
	Tower::Tower tower;
};
