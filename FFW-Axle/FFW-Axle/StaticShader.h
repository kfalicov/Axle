#ifndef _STATIC_SHADER_H
#define _STATIC_SHADER_H
#include "Shader.h"
#include "Camera.h"
#include "Util.h"

/*
	A shader to be used with a static model
*/
class StaticShader : public Shader
{
public:
	StaticShader(char* vertexShaderFilename, char* fragmentShaderFilename);
	~StaticShader();
	void bindAttributes();
	void getAllUniformLocations();

	void loadTransformationMatrix(glm::mat4 matrix);

	void loadProjectionMatrix(glm::mat4 projection);

	void loadViewMatrix(Camera * camera);

private:
	GLuint _transformationMatrixLocation;
	GLuint _projectionMatrixLocation;
	GLuint _viewMatrixLocation;
};

#endif