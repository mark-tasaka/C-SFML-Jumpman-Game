
#include "stdafx.h"
#include "PlayerOne.h"

using namespace sf;

//Clock clock;

PlayerOne::PlayerOne(): is_Alive(true), m_Lives(3)
{

	m_Texture.loadFromFile("../assets/images/jumpManSpriteSheet.png");

	m_Sprite.setTexture(m_Texture);

	m_SpriteRect = sf::IntRect(0, 100, 40, 50);


	m_Sprite.setTexture(m_Texture);
	m_Sprite.setTextureRect(m_SpriteRect);

	m_Sprite.setOrigin(20, 25);

	m_Sprite.setPosition(400.0f, 524.0f);


}

void PlayerOne::moveLeft()
{
	m_LeftMove = true;
	m_facingRight = false;
	m_facingLeft = true;
}

void PlayerOne::moveRight()
{
	m_RightMove = true;
	m_facingRight = true;
	m_facingLeft = false;
}

void PlayerOne::stopLeft()
{
	m_LeftMove = false;
	m_facingRight = false;
	m_facingLeft = true;
}

void PlayerOne::stopRight()
{
	m_RightMove = false;
	m_facingRight = true;
	m_facingLeft = false;
}


void PlayerOne::update(Time dt)
{
	/*
	if (m_facingRight)
	{
		m_SpriteRect.top += 0;
	}

	if (m_facingLeft)
	{
		m_SpriteRect.top += 50;
	}

	m_Sprite.setTextureRect(m_SpriteRect);
	*/

	if (m_LeftMove) {
		m_Position.x -= m_Speed * dt.asSeconds();
	}

	if (m_RightMove) {
		m_Position.x += m_Speed * dt.asSeconds();
	}


	// Update the rect for all body parts
	FloatRect r = getPosition();

	// Feet
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;

	// Head
	m_Head.left = r.left;
	m_Head.top = r.top + (r.height * .3);
	m_Head.width = r.width;
	m_Head.height = 1;

	// Right
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height * .35;
	m_Right.width = 1;
	m_Right.height = r.height * .3;

	// Left
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * .5;
	m_Left.width = 1;
	m_Left.height = r.height * .3;

	if (m_Feet.top > 524.0f)
	{
		m_Position.y = 524.0f;
	}

	if (m_Position.x < 90.0f)
	{
		m_Position.x = 90.0f;
	}

	m_Sprite.setPosition(m_Position);
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


FloatRect PlayerOne::getFeet()
{
	return m_Feet;
}

FloatRect PlayerOne::getHead()
{
	return m_Head;
}

FloatRect PlayerOne::getLeft()
{
	return m_Left;
}

FloatRect PlayerOne::getRight()
{
	return m_Right;
}
