// JumpMan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stdafx.h"
#include "targetver.h"
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

int main()
{
	// Create a video mode object
	VideoMode vm(800, 600);

	// Create and open a window for the game
	RenderWindow window(vm, "Jumpman", Style::Close);


	// Create a Text object called HUD
//	Text hud;


	//Background Stage Graphic
	Texture background;
	background.loadFromFile("../assets/images/jumpManBackground.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(background);
	//set the spriteBackground to cover the screne
	spriteBackground.setPosition(0, 0);



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


		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}




		/*DRAW THE GAME*/
		window.clear();

		window.draw(spriteBackground);
		//window.draw(hud);

	}

	return 0;
}

