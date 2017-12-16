#ifndef _INPUT_HANDLER_H
#define _INPUT_HANDLER_H
#include "GamePadHandler.h"
#include "MouseHandler.h"
#include "KeyboardHandler.h"
#include <stdio.h>

/*
	Wrapper class. This is a singleton
	This wraps around the keyboard, mouse, and gamepad input handlers
*/
class InputHandler
{
public:
	static InputHandler* getInputHandler()
	{
		if (InputHandler::inputHandlerInstance == NULL)
		{
			InputHandler::inputHandlerInstance = new InputHandler();
		}
		return InputHandler::inputHandlerInstance;
	}
	~InputHandler();

private:
	InputHandler();
	static InputHandler* inputHandlerInstance;

	GamePadHandler* gamePadHandler;
	MouseHandler* mouseHandler;
	KeyboardHandler* keyboardHandler;

protected:
};

#endif