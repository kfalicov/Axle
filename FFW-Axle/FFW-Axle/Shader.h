#ifndef _SHADER_H
#define _SHADER_H
#include <glew.h>
#include <glfw3.h>
#include <iostream>
/*
	Defines a shader
*/
class Shader
{
public:
	Shader(char* vertexShaderFilename, char* fragmentShaderFilename); // creates a new shader
	~Shader(); // destroys the shader

	void bind(); // binds the shader program so it will be used by opengl

private:
	GLuint createShader(const char* shaderCode, GLenum shaderType); // helper method to create a shader
	const char* getShaderCode(char* filename); // helper method to get the code of a shader

	GLuint _program;
	GLuint _fragmentShader;
	GLuint _vertexShader;
protected:


};

#endif