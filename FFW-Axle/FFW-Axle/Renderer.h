#ifndef _RENDERER_H
#define _RENDERER_H
#include <glew.h>
#include <glfw3.h>
#include "Mesh.h"
#include "TexturedMesh.h"

/*
	Renders the game.
*/
class Renderer
{
public:
	Renderer();
	~Renderer();
	void clearScreen(); // Clears the screen and the relevent buffer bits
	virtual void draw(); 
	void renderMesh(Mesh* mesh); // Renders a mesh to the screen
	void renderTexturedMesh(TexturedMesh* texturedMesh);
private:

protected:

};

#endif