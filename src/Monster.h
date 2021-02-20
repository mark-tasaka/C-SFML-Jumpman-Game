#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"

class Monster :public Creature
{
public:

	// Which directions is the Player Moving
	bool m_LeftMove;
	bool m_RightMove;

	Monster();
	void update(float elapsedTime);

};



#endif // !MONSTER_H
