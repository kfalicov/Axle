#ifndef _GAME_H
#define _GAME_H

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

private:
	int windowWidth;
	int windowHeight;
protected:

};

#endif