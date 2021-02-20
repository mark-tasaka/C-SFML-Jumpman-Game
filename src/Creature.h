#pragma once
#ifndef CREATURE_H
#define CREATURE_H


#include <SFML/Graphics.hpp>

using namespace sf;

class Creature
{
protected:

	Sprite m_Sprite;

	bool m_IsJumping;
	bool m_IsFalling;

	// How long does a jump last
	float m_JumpDuration;
	// How long has this jump lasted so far
	float m_TimeThisJump;

	float m_Gravity;

	//how fast creature moves
	float m_Speed;

	// Where is the player
	Vector2f m_Position;

	// Where are the characters various body parts?
	FloatRect m_Bottom;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	// And a texture
	Texture m_Texture;

public:

	void spawn(Vector2f startPosition, float gravity);
	// Where is the player

	FloatRect getPosition();

	// A rectangle representing the position of different parts of the sprite
	FloatRect getBottom();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	// Send a copy of the sprite to main
	Sprite getSprite();

	// Make the character stand firm
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	// Where is the center of the character
	Vector2f getCenter();

	// We will call this function once every frame
	void update(float elapsedTime);


};

#endif // !CREATURE_H

