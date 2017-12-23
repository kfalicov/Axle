#ifndef _STATIC_SHADER_H
#define _STATIC_SHADER_H
#include "Shader.h"

/*
	A shader to be used with a static model
*/
class StaticShader : public Shader
{
public:
	StaticShader(char* vertexShaderFilename, char* fragmentShaderFilename);
	~StaticShader();
	virtual void bindAttributes();
};

#endif