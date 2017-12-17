#ifndef _KEYBOARD_HANDLER
#define _KEYBOARD_HANDLER
#include <stdio.h>
#include <iostream>
#include <glfw3.h>

/*
	Handles keyboard input from the user.
	This class is a singleton class
*/
class KeyboardHandler
{
private:
	KeyboardHandler(); // Creates a new keyboardhandler
	~KeyboardHandler(); // destroyes the keyboardhandler
	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods); // handles keyboard callbacks
	bool KEYS[348]; // stores the state of the keys on the keyboard
public:
	static KeyboardHandler& getKeyboard(); // returns a pointer to the single instance of the keyboardhandler
	static void destroyKeyboard(); // destroys the single instance of the keyboard handler
	static void keyCallbackFun(GLFWwindow* window, int key, int scancode, int action, int mods); // the callback function used as a pointer
	bool getKeyState(int key); // returns the state of a key
};

#endif