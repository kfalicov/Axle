#ifndef _MOUSEHANDLER_H
#define _MOUSEHANDLER_H
#include <stdio.h>
#include <iostream>
#include <glfw3.h>

/*
	Handles mouse input.
	This class is a singleton
*/
class MouseHandler
{
private:
	MouseHandler(); // Creates a new MouseHandler
	~MouseHandler(); // Destroys the MouseHandler
	void cursor_position_callback(GLFWwindow* window, double x, double y); // Handles the callback of the cursor
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods); // Handles the callback of the mouse button
	void scroll_callback(GLFWwindow* window, double x, double y); // Handles the callback of scrolling
	double _x; // stores the x position of the mouse
	double _y; // stores the y position of the mouse
	GLFWimage* image; // store an image icon of the mouse to render where the mouse is
	bool MOUSE[12]; // stores the states of the mouse buttons
public:
	double getX(); // getter to get the x position of the mouse
	double getY(); // getter to get the y position of the mouse
	bool getMouseState(int button); // returns the state of a mouse button
	static MouseHandler& getMouse(); // returns a pointer to the single instance of the mousehandler
	static void destroyMouse(); // destroyes the mousehandler.
	static void cursor_position_callbackFun(GLFWwindow* window, double x, double y); // the callback function used as a pointer
	static void mouse_button_callbackFun(GLFWwindow* window, int button, int action, int mods); // the callback function used as a pointer
	static void scroll_callbackFun(GLFWwindow* window, double x, double y); // the callback function used as a pointer
};

#endif