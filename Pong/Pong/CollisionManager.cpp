#include "pch.h"
#include "CollisionManager.h"

CollisionManager::CollisionManager()
{}

bool CollisionManager::CollisionBars(Ball ball,const Player& p)const
{
	if (ball.m_right < p.m_left || ball.m_left > p.m_right || ball.m_top > p.m_bottom || ball.m_bottom < p.m_top)
		return false;
	else
		return true;
}

bool CollisionManager::CollisionX(Ball ball, const Player& p)const
{
	if (ball.m_right < p.m_left || ball.m_left > p.m_right)
		return false; 
	else
		return true;
}

bool CollisionManager::CollisionY(Ball ball,const Player& p)const
{
	if (ball.m_top > p.m_bottom || ball.m_bottom < p.m_top)
		return false;
	else
		return true;
}

void CollisionManager::SetScorePlayer1(int scorePlayer1)
{
	this->m_scorePlayer1 = scorePlayer1;
}

void CollisionManager::SetScorePlayer2(int scorePlayer2)
{
	this->m_scorePlayer2= scorePlayer2;
}

int CollisionManager::GetScore1()const
{
	return this->m_scorePlayer1;
}

int CollisionManager::GetScore2()const
{
	return this->m_scorePlayer2;
}
