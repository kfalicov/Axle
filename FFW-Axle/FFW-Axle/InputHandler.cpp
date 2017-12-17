#include "InputHandler.h"



InputHandler::InputHandler()
{
	keyboardHandler = &KeyboardHandler::getKeyboard();
	mouseHandler = &MouseHandler::getMouse();
	gamePadHandler = &GamePadHandler::getGamePad();
}


InputHandler::~InputHandler()
{
}


InputHandler& InputHandler::getInputHandler()
{
	static InputHandler* handler = NULL;
	if (handler == NULL)
	{
		handler = new InputHandler();
	}
	return *handler;
}

void InputHandler::destroyInputHandler()
{
	InputHandler* handler = &getInputHandler();
	delete handler;
}


bool InputHandler::getKeyState(int key)
{
	return keyboardHandler->getKeyState(key);
}
bool InputHandler::getButtonState(int button)
{
	return mouseHandler->getMouseState(button);
}

glm::vec2 InputHandler::getMousePosition()
{
	glm::vec2 pos;
	pos.x = (float)mouseHandler->getX();
	pos.y = (float)mouseHandler->getY();
	return pos;
}