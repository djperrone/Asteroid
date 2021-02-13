#pragma once
#include "game.h"
#include "Vector2D.h"

class Asteroid
{
public:
	Asteroid();
	Asteroid(const char* texturesheet, int x, int y, int sc);
	~Asteroid();
	
	void Update();
	void Render();

	Vector2D position;
	Vector2D velocity;

	float speed = 0.5f;
	int width =32, height = 32;
	int scale;

private:
	int xpos, ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};


