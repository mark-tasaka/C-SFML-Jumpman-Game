#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Creature.h"

class Player :public Creature
{
public:

	int m_Lives;
	bool is_Alive;

	// Which directions is the Player Moving
	bool m_LeftPressed;
	bool m_RightPressed;

	Player();
	void update(float elapsedTime);
	bool handleInput();

};


#endif // !PLAYER_H

