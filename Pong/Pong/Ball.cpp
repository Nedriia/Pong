#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include <iostream>


Ball::Ball()
{}

Ball::Ball(sf::Vector2f position, sf::Vector2f size, sf::Color color) : Player(position, size, color)
{
	this->m_circle.setPosition(position);
	this->m_circle.setFillColor(color);
	this->m_circle.setRadius(size.x);
}

void Ball::Ball_Movement(float movementSpeedX, float movementSpeedY)
{
	this->m_circle.move(movementSpeedX, movementSpeedY);
}


void Ball::Set_Position(float positionX, float positionY)
{
	this->m_circle.setPosition(positionX, positionY);
}

void Ball::Update()
{
	this->m_top = m_circle.getPosition().y;
	this->m_bottom = m_circle.getPosition().y + m_circle.getRadius();
	this->m_left = m_circle.getPosition().x;
	this->m_right = m_circle.getPosition().x + m_circle.getRadius();
}

sf::CircleShape Ball::Get_Visual()const
{
	return this->m_circle;
}

void Ball::SetReset(bool resetState) 
{
	this->m_reset=resetState;
}

bool Ball::GetReset()const 
{
	return this->m_reset;
}

sf::Vector2f Ball::GetPosition()const
{
	return this->m_circle.getPosition();
}