#pragma once
#include "game.h"
#include <vector>
#include "Asteroid.h"

class Player;
class Asteroid;
class GameManager
{
private:

public:

	//friend class Asteroid;
	std::vector<Asteroid*> asteroidVec;
	std::vector<Asteroid*>::iterator it;
	GameManager() {}

	GameManager(std::vector<Asteroid*>& vec)
	{
		//asteroidVec.resize(10);
		
		this->asteroidVec = vec;
	}


	void SpawnAsteroid(int x=200, int y=0)
	{
		Asteroid* asteroid = new Asteroid("assets/asteroid.png", x, y, 1);
		asteroidVec.push_back(asteroid);
	}

	void DestroyAsteroid(Asteroid* asteroid)
	{
		delete asteroid;
		asteroidVec.resize(asteroidVec.size() - 1);		
	}

	
	bool CheckCollision(Player* player, Asteroid* asteroid)
	{
		if (player->position.x + player->width * player->scale >= asteroid->position.x &&
			asteroid->position.x + asteroid->width * asteroid->scale >= player->position.x &&

			player->position.y + player->height * player->scale >= asteroid->position.y &&			
			asteroid->position.y + asteroid->height * asteroid->scale >= player->position.y)
		{
			return true;
		}
		return false;
	}
	//template<typename T1, typename T2>
	//bool Collision(const T1& object, const T2& other);
};



//void SpawnAsteroid()
//{
//	//if (asteroidVec.size() < 10)
//	//{
//	Asteroid* asteroid = new Asteroid("assets/asteroid.png", 200, 0, 1);
//	asteroidVec.emplace_back(asteroid);
//	//asteroidVec.push_back(asteroid);
//	//delete asteroid;
////}		
//}