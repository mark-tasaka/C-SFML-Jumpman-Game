#include "Player.h"
#include "stdafx.h"

using namespace sf;

Player::Player(): is_Alive (true), m_Lives(3)
{
	
	Texture player;

	player.loadFromFile("../assets/images/jumpManSpriteSheet.png");

	sf::Sprite m_Sprite = Sprite(player, sf::IntRect(0, 100, 40, 50));
	
	m_JumpDuration = 0.25f;

}

Vector2f Player::getCenter()
{
	return Vector2f(
		m_Position.x + m_Sprite.getGlobalBounds().width / 2,
		m_Position.y + m_Sprite.getGlobalBounds().height / 2
	);
}
