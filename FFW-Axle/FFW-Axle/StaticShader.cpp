#include "StaticShader.h"



StaticShader::StaticShader(char* vertexShaderFilename, char* fragmentShaderFilename) : Shader(vertexShaderFilename,fragmentShaderFilename)
{
}


StaticShader::~StaticShader()
{
}

void StaticShader::bindAttributes()
{
	bindAttribute(0, "position");
	bindAttribute(1, "textureCoords");
}

void StaticShader::getAllUniformLocations()
{
	_transformationMatrixLocation = getUniformLocation("transformationMatrix");
	_projectionMatrixLocation = getUniformLocation("projectionMatrix");
	_viewMatrixLocation = getUniformLocation("viewMatrix");
}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix)
{
	loadMatrixUniform(_transformationMatrixLocation,matrix);
}

void StaticShader::loadProjectionMatrix(glm::mat4 projection)
{
	loadMatrixUniform(_projectionMatrixLocation, projection);
}

void StaticShader::loadViewMatrix(Camera* camera)
{
	glm::mat4 viewMatrix = createViewMatrix(camera);

	loadMatrixUniform(_viewMatrixLocation, viewMatrix);
}