#ifndef _SHADER_H
#define _SHADER_H
#include <glew.h>
#include <glfw3.h>
#include <iostream>
/*
	Defines a shader.
	Based on the ThinMatrix's version of a shader
*/
class Shader
{
public:
	Shader(char* vertexShaderFilename, char* fragmentShaderFilename); // creates a new shader
	~Shader(); // destroys the shader

	void bind(); // binds the shader program so it will be used by opengl
	void unbind();
	virtual void bindAttributes() = 0;
	void bindAttribute(int attrib, char* variableName);

private:
	GLuint createShader(const std::string& shaderCode, GLenum shaderType); // helper method to create a shader
	std::string getShaderCode(char* filename); // helper method to get the code of a shader

	GLuint _program;
	GLuint _fragmentShader;
	GLuint _vertexShader;
protected:


};

#endif