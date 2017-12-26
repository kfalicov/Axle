#include "Game.h"



Game::Game(int width, int height) : 
	_width(width), 
	_height(height),
	_inputHandler(&InputHandler::getInputHandler())
{
	_entities = new std::vector<Entity*>();
	_loader = new Loader();
	_camera = new Camera(glm::vec3(0,0,0));
	_staticShader = new StaticShader("./res/shaders/vertexShader.vs", "./res/shaders/fragmentShader.fs");
	glm::mat4* projectionMatrix = new glm::mat4();
	createProjectionMatrix(projectionMatrix);
	_staticShader->bind();
	_staticShader->loadProjectionMatrix(*projectionMatrix);
	_staticShader->unbind();
	_renderer = new Renderer();
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

	Entity* testEntity = new TexturedEntity(glm::vec3(0,0,-1),0,0,0,1,tmpTexturedMesh);
	_entities->push_back(testEntity);
}


Game::~Game()
{
}

void Game::update()
{
	for (int i = 0; i < _entities->size(); i++)
	{
		Entity* entity = _entities->at(i);
		entity->update();
	}
}

void Game::render()
{
	_renderer->clearScreen();
	_staticShader->bind();
	_staticShader->loadViewMatrix(_camera);
	_renderer->draw(_entities, _staticShader);
	_staticShader->unbind();
}


void Game::destroyGame()
{
	delete _loader;
	delete _staticShader;
	_inputHandler->destroyInputHandler();
}