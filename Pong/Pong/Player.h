#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player
{
public :
	Player();
	Player(sf::Vector2f position, sf::Vector2f size, sf::Color color);	
	
	void Player_Control(const std::string playerConfig);
	void Update();

	sf::RectangleShape Get_Visual()const;

	float m_bottom, m_top, m_left, m_right;

private:

	sf::Vector2f m_position;
	sf::Vector2f m_size;
	sf::Color m_color;
	sf::RectangleShape m_rect;
};
#endif 