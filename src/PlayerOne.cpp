
#include "stdafx.h"
#include "PlayerOne.h"

using namespace sf;

PlayerOne::PlayerOne(): is_Alive(true), m_Lives(3)
{
	Texture player;

	player.loadFromFile("../assets/images/jumpManSpriteSheet.png");

	m_Sprite.setTexture(player);

	m_Sprite = Sprite(player, sf::IntRect(0, 100, 40, 50));

	m_Sprite.setOrigin(20, 25);

	m_Sprite.setPosition(400.0f, 520.0f);


}


Sprite PlayerOne::getSprite()
{
	return m_Sprite;
}

FloatRect PlayerOne::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

void PlayerOne::spawn()
{
	m_Position.x = 400.0f;
	m_Position.y = 500.0f;
}
