#include <SFML/Graphics.hpp>
#pragma once
	class Window {
	public:
		sf::RenderWindow window;
		Window(int Width, int Heigth, const char* Title, int framerate) {
			window.create(sf::VideoMode(Width, Heigth), Title);
			window.setFramerateLimit(framerate);
		}
	};