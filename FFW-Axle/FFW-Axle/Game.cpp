#include "Game.h"



Game::Game(int width, int height) : 
	_width(width), 
	_height(height),
	_inputHandler(&InputHandler::getInputHandler()),
	_renderer(new Renderer())
{
	_loader = new Loader();
	_staticShader = new StaticShader("./res/shaders/vertexShader.vs", "./res/shaders/fragmentShader.fs");
	float vertices[] = {
		-0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f
	};

	int indices[] = {
		0, 1, 3,
		3, 1, 2
	};

	float textureCoords[] = {
		0,0,
		0,1,
		1,1,
		1,0
	};

	tmpMesh = _loader->loadMesh(vertices, indices, textureCoords, my_sizeof(vertices) / my_sizeof(vertices[0]),my_sizeof(indices) / my_sizeof(indices[0]));
	Texture* texture = new Texture(_loader->loadTexture("./res/textures/bridge.png"));
	tmpTexturedMesh = new TexturedMesh(tmpMesh, texture);
}


Game::~Game()
{
}

void Game::update()
{

}

void Game::render()
{
	_renderer->clearScreen();
	_staticShader->bind();
	_renderer->renderTexturedMesh(tmpTexturedMesh);
	_staticShader->unbind();
}


void Game::destroyGame()
{
	delete _loader;
	delete _staticShader;
	_inputHandler->destroyInputHandler();
}