#include "Renderer.h"



Renderer::Renderer()
{

}


Renderer::~Renderer()
{
}

void Renderer::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 1, 0, 1);
}

void Renderer::draw(std::vector<Entity*>* entities, StaticShader* shader)
{
	for (int i = 0; i < entities->size(); i++)
	{
		Entity* entity = entities->at(i);
		entity->render(shader);
	}
}