#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>

#include "Player.h"
#include "Ball.h"
#include "CollisionManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "PONG");
	window.setFramerateLimit(60);

#pragma region Objects Inialization
	Ball ball(sf::Vector2f(400, 300), sf::Vector2f(8, 8), sf::Color::Blue);
	//Actual Players
	Player p1(sf::Vector2f(30, 300), sf::Vector2f(10, 50), sf::Color::Red);
	Player p2(sf::Vector2f(755, 300), sf::Vector2f(10, 50), sf::Color::Green);
	//Collision Rects 
	Player p_Y1(sf::Vector2f(0, -10), sf::Vector2f(800, 10), sf::Color::Cyan);
	Player p_X1(sf::Vector2f(-10, 0), sf::Vector2f(10, 600), sf::Color::Cyan);
	Player p_X2(sf::Vector2f(800, 0), sf::Vector2f(10, 600), sf::Color::Cyan);
	Player p_Y2(sf::Vector2f(0, 600), sf::Vector2f(800, 10), sf::Color::Cyan);
	//Collision Manager
	CollisionManager colManager;
#pragma endregion

#pragma region Loading Assets
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		EXIT_FAILURE;
	else
		std::cout << "Succesful Loading" << std::endl;

	sf::Texture texture;
	if (!texture.loadFromFile("background.png"))
		EXIT_FAILURE;
	else
		std::cout << "Background Texture succesfully loaded" << std::endl;

	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::SoundBuffer audio, danger;
	if (!audio.loadFromFile("ping_pong_8bit_plop.ogg"))
		EXIT_FAILURE;
	else
		std::cout << "Audio Succesfully loaded" << std::endl;

	if (!danger.loadFromFile("Danger2.wav"))
		EXIT_FAILURE;
	else
		std::cout << "Danger sound loaded" << std::endl;
		
	sf::Sound sound, loseSound;
	sound.setBuffer(audio);
	loseSound.setBuffer(danger);
#pragma endregion

	sf::Clock clock;

	while (window.isOpen())
	{
#pragma region  Collision Update
		p1.Update();
		p2.Update();
		ball.Update();
		p_Y1.Update();
		p_Y2.Update();

		p_X1.Update();
		p_X2.Update();

		if (colManager.CollisionBars(ball, p1) || colManager.CollisionBars(ball, p2))
		{
			sound.play();
			ball.m_movementSpeedX *= -1;
			ball.Ball_Movement(ball.m_movementSpeedX, ball.m_movementSpeedY);
		}
		if (colManager.CollisionY(ball, p_Y1) || colManager.CollisionY(ball, p_Y2))
		{
			sound.play();
			ball.m_movementSpeedY *= -1;
			ball.Ball_Movement(ball.m_movementSpeedX, ball.m_movementSpeedY);
		}
		if (colManager.CollisionX(ball, p_X1) && !ball.GetReset())
		{
			loseSound.play();
			int score = colManager.GetScore2();
			score++;
			colManager.SetScorePlayer2(score);
		}
		else if(colManager.CollisionX(ball, p_X2) && !ball.GetReset())
		{
			loseSound.play();
			int score = colManager.GetScore1();
			score++;
			colManager.SetScorePlayer1(score);
		}
#pragma endregion

		sf::Text text;
		text.setFont(font);
		text.setString(std::to_string(colManager.GetScore1()) + "        " + std::to_string(colManager.GetScore2()));
		text.setCharacterSize(32);
		text.setPosition(350, 50);

		ball.Ball_Movement(ball.m_movementSpeedX, ball.m_movementSpeedY);
		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() > 1.f)
		{
			if (ball.m_movementSpeedX < 20 && ball.m_movementSpeedX > -20)
			{
				if (ball.m_movementSpeedX < 0)
					ball.m_movementSpeedX--;
				else
					ball.m_movementSpeedX++;
				clock.restart();
			}
		}
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		p1.Player_Control("player1");
		p2.Player_Control("player2");		

#pragma region ResetCondition
		if (loseSound.getStatus() == 2)
			ball.SetReset(true);
		if(loseSound.getStatus() == 0 && ball.GetReset())
		{
			if(ball.GetPosition().x < sf::VideoMode::getDesktopMode().width/2)
			{ 
				
				ball.m_movementSpeedX *= -1;
				ball.m_movementSpeedY *= -1;
				ball.m_movementSpeedX = -8;
				ball.m_movementSpeedY = rand() % -20 -1;
			}
			else
			{
				ball.m_movementSpeedX = 8;
				ball.m_movementSpeedY = rand() % 20 + 1;;
			}
			ball.Set_Position(400, 300);

			clock.restart();
			ball.SetReset(false);
		}	
#pragma endregion

#pragma region Drawing Config
		window.clear();
		window.draw(sprite);
		window.draw(ball.Get_Visual());
		window.draw(p1.Get_Visual());
		window.draw(p2.Get_Visual());			
		window.draw(text);
		window.display();
#pragma endregion
	}
	return 0;
}