#include "pch.h"
#include "Player.h"
#include <iostream>

Player::Player(){}

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Color color) : m_position(position), m_size(size), m_color(color)
{
	this->m_rect.setFillColor(color);
	this->m_rect.setPosition(position);
	this->m_rect.setSize(size);
}

void Player::Update()
{
	this->m_top = m_rect.getPosition().y;
	this->m_bottom = m_rect.getPosition().y + m_rect.getSize().y;
	this->m_right = m_rect.getPosition().x + m_rect.getSize().x;
	this->m_left = m_rect.getPosition().x;
}

sf::RectangleShape Player::Get_Visual()const
{
	return this->m_rect;
}

void Player::Player_Control(const std::string playerConfig)
{
	if (playerConfig == "player1")
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			this->m_rect.move(0, -10.f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			this->m_rect.move(0, 10.f);
	}
	else if(playerConfig=="player2")
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
			this->m_rect.move(0, -10.f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			this->m_rect.move(0, 10.f);
	}
}
