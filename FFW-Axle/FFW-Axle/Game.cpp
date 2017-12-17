#include "Game.h"



Game::Game(int width, int height) : 
	_width(width), 
	_height(height),
	_inputHandler(&InputHandler::getInputHandler())
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
	_inputHandler->destroyInputHandler();
}