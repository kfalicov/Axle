#ifndef _GAME_H
#define _GAME_H
#include "Renderer.h"
#include "Loader.h"
#include "InputHandler.h"
#include "StaticShader.h"
#include "TexturedEntity.h"
#include "Util.h"

/*
	Puts everything together
*/
class Game
{
public:
	Game(int width, int height); // Creates a new game
	~Game(); // Destroyes the game
	
	void update(); // updates the games logic.
	void render(); // renders the game
	void destroyGame(); // cleans up memory

private:
	int _width;
	int _height;
	InputHandler* _inputHandler;
	Camera* _camera;

	Renderer* _renderer;
	Loader* _loader;
	StaticShader* _staticShader;

	Mesh* tmpMesh;
	TexturedMesh* tmpTexturedMesh;

	std::vector<Entity*>* _entities;
protected:

};

#endif