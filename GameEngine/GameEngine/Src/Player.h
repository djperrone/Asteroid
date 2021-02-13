#pragma once
#include "Player.h"
#include "Vector2D.h"
#include "game.h"
#include "TextureManager.h"

#define PI 3.14159265358979323846


class Player
{

public:	
	Player();
	Player(const char* texturesheet, int x, int y, int sc);
	~Player();

	void Update();
	void Render();
	void InputController();
	float GetAngle(int x1, int y1, int x2, int y2);
	void Rotate(SDL_Texture* texture, int x, int y, float angle);


	Vector2D position;
	Vector2D velocity;

	int speed = 5;
	int width, height;
	int scale;

	int angle;
	Vector2D Point;

	bool w = false;
	bool a = false;
	bool s = false;
	bool d = false;


private:
	int xpos, ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};

