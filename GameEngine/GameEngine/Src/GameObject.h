#pragma once
#include "game.h"
#include "Vector2D.h"

class GameObject
{
public:
	GameObject();
	GameObject(const char* texturesheet, int x, int y, int sc);
	~GameObject();	

	virtual void Update();
	virtual void Render();

	Vector2D position;
	Vector2D velocity;

	int speed = 3;

private:
	int xpos, ypos, scale;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};

