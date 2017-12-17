#ifndef _INPUT_HANDLER_H
#define _INPUT_HANDLER_H
#include "GamePadHandler.h"
#include "MouseHandler.h"
#include "KeyboardHandler.h"
#include <stdio.h>
#include <glm\glm.hpp>

/*
	Wrapper class. This is a singleton
	This wraps around the keyboard, mouse, and gamepad input handlers
*/
class InputHandler
{
public:
	~InputHandler(); // destroys the input handler

	static InputHandler& getInputHandler(); // returns the single instance of inputhandler
	void destroyInputHandler(); // destroys the inputhandler

	bool getKeyState(int key); // returns the state of a key on the keyboard
	bool getButtonState(int button); // returns the state of a button on the mouse

	glm::vec2 getMousePosition(); // returns the position of the mouse
	
private:
	InputHandler();

	GamePadHandler* gamePadHandler;
	MouseHandler* mouseHandler;
	KeyboardHandler* keyboardHandler;

protected:
};

#endif