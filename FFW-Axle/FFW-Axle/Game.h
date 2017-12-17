#ifndef _GAME_H
#define _GAME_H
#include "InputHandler.h"

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
	int windowWidth;
	int windowHeight;
	InputHandler* inputHandler;
protected:

};

#endif