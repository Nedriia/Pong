#pragma once
#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H
#include "Player.h"
#include "Ball.h"

class CollisionManager
{
public:
	CollisionManager();
	bool CollisionBars(Ball ball, const Player& p)const;
	bool CollisionX(Ball ball,const Player& p)const;
	bool CollisionY(Ball ball,const Player& p)const;

	void SetScorePlayer1(int scorePlayer1);
	void SetScorePlayer2(int scorePlayer2);

	int GetScore1()const;
	int GetScore2()const;
private:
	int m_scorePlayer1 =0, m_scorePlayer2 =0;
};
#endif // !COLLISIONMANAGER_H
