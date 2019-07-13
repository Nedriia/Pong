#pragma once
#include <SFML/Graphics.hpp>


class Manager
{
public:
	Manager();
	void Initialization(const std::string &stream_textFont, const std::string &stream_backgroundTexture);
	void Update(sf::RenderWindow& window);
	~Manager();
private:
	sf::Text m_text;
	sf::Sprite m_backgroudSprite;
};