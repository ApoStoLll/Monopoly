#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

void printMap2()
{
	RenderWindow window(VideoMode(900, 814), "Mono");
	Texture map;
	map.loadFromFile("1.jpg");
	Sprite mapa;
	mapa.setTexture(map);
	mapa.setPosition(0, 0);

	Texture player1;
	player1.loadFromFile("2.png");
	Sprite player11;
	player11.setTexture(player1);
	player11.setPosition(800, 750);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(mapa);
		window.draw(player11);
		window.display();
	}

	return 0;
}