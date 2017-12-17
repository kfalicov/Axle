#ifndef _GAMEPAD_HANDLER_H
#define _GAMEPAD_HANDLER_H
#include <stdio.h>

/*
	Handles gamepad input
*/
class GamePadHandler
{
private:
	GamePadHandler();

public:
	~GamePadHandler();
	static GamePadHandler& getGamePad();
	void destroyGamePad();

protected:
};

#endif