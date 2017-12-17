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
	Shader(char* vertexShaderFilename, char* fragmentShaderFilename);
	~Shader();

	void bind();

private:
	GLuint createShader(const char* shaderCode, GLenum shaderType);
	const char* getShaderCode(char* filename);

	GLuint _program;
	GLuint _fragmentShader;
	GLuint _vertexShader;

protected:


};

#endif