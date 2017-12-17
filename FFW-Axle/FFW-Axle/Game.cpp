#include "Game.h"



Game::Game(int width, int height) : 
	windowWidth(width), 
	windowHeight(height),
	inputHandler(&InputHandler::getInputHandler())
{
}


Game::~Game()
{
}

void Game::update()
{

}

void Game::render()
{

}


void Game::destroyGame()
{
	inputHandler->destroyInputHandler();
}