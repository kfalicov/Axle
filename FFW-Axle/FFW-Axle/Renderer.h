#ifndef _RENDERER_H
#define _RENDERER_H
#include <glew.h>
#include <glfw3.h>
#include "Mesh.h"
#include "TexturedMesh.h"
#include "Util.h"
#include "StaticShader.h"
#include "Entity.h"
#include <vector>

/*
	Renders the game.
*/
class Renderer
{
public:
	Renderer(StaticShader* shader);
	~Renderer();
	void clearScreen(); // Clears the screen and the relevent buffer bits
	void draw(std::vector<Entity*>* entities);
private:
	glm::mat4* _projectionMatrix;
	StaticShader* _staticShader;
protected:

};

#endif