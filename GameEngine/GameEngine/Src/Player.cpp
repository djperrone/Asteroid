#include "Player.h"


Player::Player() {}

Player::Player(const char* texturesheet, int x, int y, int sc)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	position.x = x;
	position.y = y;
	scale = sc;
	width = height = 32;
	Point.x = position.x + (32 * scale / 2);
	Point.y = position.y;
}

void Player::Update()
{
	this->InputController();
	int mx, my;
	SDL_GetMouseState(&mx, &my);
	//std::cout << "mx: " << mx << ", my " << my << std::endl;
	//std::cout << "ship x: " << position.x << ", ship y: " << position.y << std::endl;
	//std::cout <<"Point x: "<< Point.x << ", Point y: " << Point.y << std::endl;

	this->angle = GetAngle(position.x, position.y, mx, my);

	position.x += velocity.x * speed;
	position.y += velocity.y * speed;
	Point.x = position.x + (32 * scale / 2);
	Point.y = position.y;


	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = position.x;
	srcRect.y = position.y;

	destRect.x = position.x;
	destRect.y = position.y;
	destRect.w = srcRect.w * scale;
	destRect.h = srcRect.h * scale;
}

void Player::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}

void Player::InputController()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			w = true;
			velocity.y = -1;
			break;
		case SDLK_a:
			a = true;
			velocity.x = -1;
			break;
		case SDLK_d:
			d = true;
			velocity.x = 1;
			break;
		case SDLK_s:
			s = true;
			velocity.y = 1;
			break;
		default:
			break;
		}
	}

	if (Game::event.type == SDL_KEYUP)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			if (s == true)
				velocity.y = 1;
			else
				velocity.y = 0;
			w = false;

			break;
		case SDLK_a:

			if (d == true)
				velocity.x = 1;
			else
				velocity.x = 0;
			a = false;

			break;

		case SDLK_d:


			if (a == true)
				velocity.x = -1;
			else
				velocity.x = 0;
			d = false;

			break;
		case SDLK_s:
			if (w == true)
				velocity.y = -1;
			else
				velocity.y = 0;
			s = false;

			break;
		case SDLK_ESCAPE:
			Game::isRunning = false;
		default:
			break;
		}
	}


}

float Player::GetAngle(int x1, int x2, int y1, int y2)
{
	float angle = -90 + atan2(y1 - y2, x1 - x2) * (180 / PI);
	return angle >= 0 ? angle : 360 + angle;
}

//void Player::Rotate(SDL_Texture* texture, int x, int y, float angle)
//{
//	SDL_Rect dstRect;
//
//	dstRect.x = x;
//	dstRect.y = y;
//	SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
//	dstRect.x -= (dstRect.w / 2);
//	dstRect.y -= (dstRect.h / 2);
//
//	SDL_RenderCopyEx(Game::renderer, texture, NULL, &dstRect, angle, NULL, SDL_FLIP_NONE);
//}
