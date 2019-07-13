#include "pch.h"
#include "Manager.h"
#include <iostream>


Manager::Manager()
{}

void Manager::Initialization(const std::string &stream_textFont,const std::string &stream_backgroundTexture)
{
	sf::Font text_Font;
	sf::Texture background_Texture;

	if (!text_Font.loadFromFile(stream_textFont))
		EXIT_FAILURE;
	else
	{
		std::cout << "Succesful loading " << std::endl;

		m_text.setFont(text_Font);

		if (!background_Texture.loadFromFile(stream_backgroundTexture))
			EXIT_FAILURE;
		else
		{
			std::cout << "Background Texture Succefully Loaded" << std::endl;
			m_backgroudSprite.setTexture(background_Texture);
			//If success we can create audio
		}
	}		
}

void Manager::Update(sf::RenderWindow& window)
{
	window.draw(m_backgroudSprite);
}

Manager::~Manager()
{}

