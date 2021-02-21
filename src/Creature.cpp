#include "stdafx.h"
#include "Creature.h"

void Creature::spawn(Vector2f startPosition, float gravity)
{
	// Place the creature at the starting point
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	// Initialize the gravity
	m_Gravity = gravity;

	// Move the sprite in to position
	m_Sprite.setPosition(m_Position);

}



FloatRect Creature::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

FloatRect Creature::getBottom()
{
	return m_Bottom;
}

FloatRect Creature::getHead()
{
	return m_Head;
}

FloatRect Creature::getLeft()
{
	return m_Left;
}

FloatRect Creature::getRight()
{
	return m_Right;
}


void Creature::stopFalling(float position)
{
	m_Position.y = position - getPosition().height;
	m_Sprite.setPosition(m_Position);
	m_IsFalling = false;
}

void Creature::stopRight(float position)
{

	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void Creature::stopLeft(float position)
{
	m_Position.x = position + m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void Creature::stopJump()
{
	// Stop a jump early 
	m_IsJumping = false;
	m_IsFalling = true;
}


Sprite Creature::getSprite()
{
	return m_Sprite;
}


