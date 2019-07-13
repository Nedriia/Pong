#pragma once
#ifndef  BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <random>

class Ball : public Player
{
public:
	Ball();
	Ball(sf::Vector2f position, sf::Vector2f size, sf::Color color);

	void Ball_Movement(float movementSpeedX, float movementSpeedY);
	void Set_Position(float positionX, float positionY);
	void Update();
	void SetReset(bool resetState);

	sf::Vector2f GetPosition()const;
	sf::CircleShape Get_Visual()const;

	
	bool GetReset()const;
	float m_movementSpeedX = 8, m_movementSpeedY = rand() % 10 + 1;
	float m_bottom, m_top, m_left, m_right;
	
private:
	bool m_reset;
	sf::CircleShape m_circle;
};
#endif // ! BALL_H