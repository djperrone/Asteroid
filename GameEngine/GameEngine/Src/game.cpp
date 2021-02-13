#include "game.h"
#include "TextureManager.h"
#include "Asteroid.h"
#include "Map.h"
#include "Player.h"
#include "GameManager.h"

Player* player;
Map* map;
GameManager* gameManager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

bool Game::isRunning = false;
Timer timer;


Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0,255);
			std::cout << "Renderer Created!" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	// parameters are filepath to picture, xloc, yloc, scale
	player = new Player("assets/ship.png", 0, 0,4);
	
	gameManager = new GameManager;	
	
	map = new Map();
	
	timer.Start();


	// ADD MAP HERE

	//ADD PLAYER HERE
		// with controller, collider	


}

//COLLISION GROUPS


void Game::handleEvents()
{	
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	cnt++;
	//std::cout << cnt << std::endl;
	player->Update();
	//asteroid->Update();
	
	for (auto a : gameManager->asteroidVec)
	{
		a->Update();
	}
	timer.Stop();
	timer.Calc();
	//std::cout << timer.GetEnd() - timer.GetStart() << std::endl;
	long int current = (timer.GetEnd() - timer.GetStart());

	srand(time(NULL));
	int randx = rand() * cnt % 800;

	if((cnt % 60) == 0)
	{
		gameManager->SpawnAsteroid((randx * current)%800,0);
		std::cout << gameManager->asteroidVec.size() << std::endl;
	}	
	
	for (int i = 0; i < gameManager->asteroidVec.size();)
	{

		if (gameManager->CheckCollision(player, gameManager->asteroidVec[i])) {
			delete gameManager->asteroidVec[i];
			gameManager->asteroidVec.erase(gameManager->asteroidVec.begin() + i);	
			
		}
		else if (gameManager->asteroidVec[i]->position.y >= 600)
		{
			delete gameManager->asteroidVec[i];
			gameManager->asteroidVec.erase(gameManager->asteroidVec.begin() + i);		
		}
		else
		{
			i++;
		}
	}

	//gameManager->it = gameManager->asteroidVec.begin();
	//while (gameManager->it != gameManager->asteroidVec.end())
	//for(auto a : gameManager->asteroidVec)
	//{	
	//	
	//	if (gameManager->CheckCollision(player, a)) {
	//	gameManager->it = gameManager->asteroidVec.erase(gameManager->it);
	//	//gameManager->asteroidVec.erase(a);
	//	delete a;
	//	//a->~Asteroid();
	//	}
	//	else if (a->position.y >= 600)
	//	{
	//		gameManager->it = gameManager->asteroidVec.erase(gameManager->it);
	//		//gameManager->asteroidVec.erase(a);
	//		delete a;
	//		//a->~Asteroid();
	//	}
	//	else
	//	{
	//		gameManager->it++;

	//	}
	//}	

	//map->LoadMap(menu first then level1);

	//std::cout << cnt << std::endl;

	//COLLISION!!!!!!
	
	//CAMERA
}



void Game::render()
{
	SDL_RenderClear(renderer);
	// order of render groupings
	//render map tiles, characters

	// top is background, bottom goes to foreground
	map->DrawMap();
	player->Render();
	//gameManager->asteroidVec[0]->Render();
	for (auto a : gameManager->asteroidVec)
	{
		a->Render();
	}


	//steroid->Render();
	

	SDL_RenderPresent(renderer);	
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}