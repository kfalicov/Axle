#include "InputHandler.h"



InputHandler::InputHandler()
{
	keyboardHandler = new KeyboardHandler();
	mouseHandler = new MouseHandler();
	gamePadHandler = new GamePadHandler();
}


InputHandler::~InputHandler()
{
}
