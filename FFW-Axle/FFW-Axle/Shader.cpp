#include "Shader.h"
#include <fstream>
#include <string>

Shader::Shader(char* vertexShaderFilename, char* fragmentShaderFilename)
{
	_program = glCreateProgram();
	_vertexShader = createShader(getShaderCode(vertexShaderFilename), GL_VERTEX_SHADER);
	_fragmentShader = createShader(getShaderCode(fragmentShaderFilename), GL_FRAGMENT_SHADER);

	glAttachShader(_program, _vertexShader);
	glAttachShader(_program, _fragmentShader);

	glBindAttribLocation(_program, 0, "position");

	glLinkProgram(_program); 
	GLint result = 0;
	glGetProgramiv(_program, GL_LINK_STATUS, &result);
	if (result == GL_FALSE)
	{
		std::cerr << "ERROR: Program Creation Failed. Linking failed\n";
		exit(-1);
	}
	glValidateProgram(_program);
	glGetProgramiv(_program, GL_VALIDATE_STATUS, &result);
	if (result == GL_FALSE)
	{
		std::cerr << "ERROR: Program Creation Failed. Validation failed\n";
		exit(-1);
	}
}


Shader::~Shader()
{
	glDetachShader(_program,_fragmentShader);
	glDetachShader(_program,_vertexShader);

	glDeleteShader(_fragmentShader);
	glDeleteShader(_vertexShader);
	glDeleteProgram(_program);
}

void Shader::bind()
{
	glUseProgram(_program);
}

GLuint Shader::createShader(const char* shaderCode, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	if (shader == 0)
	{
		std::cerr << "Error: Shader Creation Failed\n";
		exit(-1);
	}

	const GLchar* shaderSource[1];
	GLint shaderSourceLength[1];

	shaderSource[0] = shaderCode;
	shaderSourceLength[0] = strlen(shaderCode);

	glShaderSource(shader, 1, shaderSource, shaderSourceLength);
	glCompileShader(shader);

	GLint result = 0;
	glGetProgramiv(_program, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		std::cerr << "ERROR: Shader failed to compile\n";
	}
	return shader;
}
const char* Shader::getShaderCode(char* filename)
{
	std::ifstream file;
	file.open(filename);

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable to load shader: " << filename << std::endl;
	}
	const char* tmp = output.c_str();
	return tmp;
}
