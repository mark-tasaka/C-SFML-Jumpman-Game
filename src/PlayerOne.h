#pragma once
#ifndef PLAYERONE_H
#define PLAYERONE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class PlayerOne
{
private:

	Sprite m_Sprite;

	int m_Lives;
	bool is_Alive;

	IntRect m_Start;

	// Which directions is the Player Moving
	bool m_LeftPressed;
	bool m_RightPressed;

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

	PlayerOne();

	void spawn();
	// Where is the player

	Sprite getSprite();

	// Where is the center of the character
	Vector2f getCenter();
	void update(float elapsedTime);
	bool handleInput();

	FloatRect getPosition();

	// A rectangle representing the position of different parts of the sprite
	FloatRect getBottom();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();


	// Make the character stand firm
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

};

#endif // !PLAYERONE_H
