#include "GameObject.h"
#include "TextureManager.h"
#include "game.h"

GameObject::GameObject() {}

GameObject::GameObject(const char* textureSheet, int x, int y, int sc)
{
	
	objTexture = TextureManager::LoadTexture(textureSheet);
	position.x = x;
	position.y = y;
	scale = sc;


}

GameObject::~GameObject()
{}

void GameObject::Update()
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

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}


