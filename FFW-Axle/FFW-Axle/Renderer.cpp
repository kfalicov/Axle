#include "Renderer.h"



Renderer::Renderer(StaticShader* shader)
{
	_staticShader = shader;
	_projectionMatrix = new glm::mat4();
	createProjectionMatrix(_projectionMatrix);
	_staticShader->bind();
	_staticShader->loadProjectionMatrix(*_projectionMatrix);
	_staticShader->unbind();
}


Renderer::~Renderer()
{
}

void Renderer::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 1, 0, 1);
}

void Renderer::draw(std::vector<Entity*>* entities)
{
	for (int i = 0; i < entities->size(); i++)
	{
		Entity* entity = entities->at(i);
		entity->render();
	}
}