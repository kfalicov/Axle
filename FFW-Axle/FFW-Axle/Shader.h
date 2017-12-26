#ifndef _SHADER_H
#define _SHADER_H
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <glm\glm.hpp>
#include "Camera.h"
#include "Util.h"
/*
	Defines a shader.
	Based on the ThinMatrix's version of a shader
*/
class Shader
{
public:
	Shader(char* vertexShaderFilename, char* fragmentShaderFilename);// creates a new shader
	void loadBooleanUniform(GLuint location, bool value);
	void loadMatrixUniform(GLuint location, glm::mat4 mat);
	~Shader(); // destroys the shader

	void bind(); // binds the shader program so it will be used by opengl
	void unbind();
	virtual void bindAttributes() = 0;
	void bindAttribute(int attrib, char* variableName);
	GLuint getUniformLocation(char* name);
	void loadFloatUniform(GLuint location, float value);
	void loadVectorUniform(GLuint location, glm::vec3 vector);
	virtual void getAllUniformLocations() = 0;

	void loadTransformationMatrix(glm::mat4 matrix);

	void loadProjectionMatrix(glm::mat4 projection);

	void loadViewMatrix(Camera * camera);

private:
	GLuint createShader(const std::string& shaderCode, GLenum shaderType); // helper method to create a shader
	std::string getShaderCode(char* filename); // helper method to get the code of a shader

	GLuint _program;
	GLuint _fragmentShader;
	GLuint _vertexShader;
	GLuint _transformationMatrixLocation;
	GLuint _projectionMatrixLocation;
	GLuint _viewMatrixLocation;
protected:


};

#endif