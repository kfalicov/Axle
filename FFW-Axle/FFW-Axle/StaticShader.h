#ifndef _STATIC_SHADER_H
#define _STATIC_SHADER_H
#include "Shader.h"
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

private:
};

#endif