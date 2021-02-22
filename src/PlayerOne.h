#pragma once
#ifndef PLAYERONE_H
#define PLAYERONE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class PlayerOne
{
private:

	Sprite m_Sprite;

	Texture m_Texture;

	sf::IntRect m_SpriteRect;

	int m_Lives;
	bool is_Alive;

	IntRect m_Start;

	// Which directions is the Player Moving
	bool m_LeftMove;
	bool m_RightMove;

	bool m_IsJumping;
	bool m_IsFalling;

	bool m_facingRight;
	bool m_facingLeft;

	// How long does a jump last
	float m_JumpDuration;
	// How long has this jump lasted so far
	float m_TimeThisJump;

	float m_Gravity;

	//how fast creature moves
	float m_Speed = 500.0f;

	// Where is the player
	Vector2f m_Position;

	// Where are the characters various body parts?
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;


public:

	PlayerOne();

	void spawn();
	// Where is the player

	Sprite getSprite();

	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();

	// Where is the center of the character
	Vector2f getCenter();
	void update(Time dt);
	bool handleInput();

	FloatRect getPosition();

	// A rectangle representing the position of different parts of the sprite
	FloatRect getFeet();
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
