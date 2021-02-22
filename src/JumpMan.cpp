// JumpMan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stdafx.h"
#include "targetver.h"
#include "PlayerOne.h"
//#include "Player.h"
//#include "TextureHolder.h"
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
using namespace sf;

int main()
{
	//TextureHolder texture;

	// Create a video mode object
	VideoMode vm(800, 600);

	// Create and open a window for the game
	RenderWindow window(vm, "Jumpman", Style::Close);

	PlayerOne jumpMan;

	//Player jumpMan;

	//Vector2f jumpManStart = Vector2f(400.0f, 500.0f);

	//jumpMan.getPosition();



	// Create a Text object called HUD
//	Text hud;


	//Background Stage Graphic
	Texture background;
	background.loadFromFile("../assets/images/jumpManBackground.png");

	Sprite spriteBackground;
	spriteBackground.setTexture(background);

	// Here is our clock for timing everything
	Clock clock;

	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				// Quit the game when the window is closed
				window.close();
			}

		}

		//jumpMan.spawn();

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Handle the pressing and releasing of the arrow keys
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (jumpMan.getPosition().left < 50)
			{
				jumpMan.stopLeft();
			}
			else
			{
				jumpMan.moveLeft();
			}
		}
		else
		{
			jumpMan.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{

			if (jumpMan.getPosition().left + 110 > window.getSize().x)
			{
				jumpMan.stopRight();
			}
			else
			{
				jumpMan.moveRight();
			}
		}
		else
		{
			jumpMan.stopRight();
		}

		/*UPDATE THE GAME*/
		Time dt = clock.restart();
		jumpMan.update(dt);


		/*DRAW THE GAME*/
		window.clear();

		window.draw(spriteBackground);


		window.draw(jumpMan.getSprite() );

		//window.draw(hud);

		window.display();

	}

	return 0;
}

