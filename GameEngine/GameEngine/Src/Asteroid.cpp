#include "Asteroid.h"
#include "TextureManager.h"
#include "game.h"

Asteroid::Asteroid() {}

Asteroid::Asteroid(const char* textureSheet, int x, int y, int sc)
{

	objTexture = TextureManager::LoadTexture(textureSheet);
	position.x = x;
	position.y = y;
	scale = sc;

	velocity.x = 0;
	velocity.y = 5;


}

Asteroid::~Asteroid()
{
	std::cout << "destroy asteroid" << std::endl;
}

void Asteroid::Update()
{
	position.x += velocity.x * speed;
	position.y += velocity.y * speed;


	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = position.x;
	srcRect.y = position.y;

	destRect.x = position.x;
	destRect.y = position.y;
	destRect.w = srcRect.w * scale;
	destRect.h = srcRect.h * scale;
}

void Asteroid::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}


