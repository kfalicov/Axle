#include "Shader.h"
#include <fstream>
#include <string>

Shader::Shader(char* vertexShaderFilename, char* fragmentShaderFilename)
{
	_program = glCreateProgram(); // Creates a shader program

	// Creates a vertex shader and a fragment shader
	_vertexShader = createShader(getShaderCode(vertexShaderFilename), GL_VERTEX_SHADER);
	_fragmentShader = createShader(getShaderCode(fragmentShaderFilename), GL_FRAGMENT_SHADER);

	// attaches the shaders to the program
	glAttachShader(_program, _vertexShader);
	glAttachShader(_program, _fragmentShader);

	//Binds attriblocations to the program
	glBindAttribLocation(_program, 0, "position");

	// Links the program and verifies the linking succeeded
	glLinkProgram(_program); 
	GLint result = 0;
	glGetProgramiv(_program, GL_LINK_STATUS, &result);
	if (result == GL_FALSE)
	{
		std::cerr << "ERROR: Program Creation Failed. Linking failed\n";
		exit(-1);
	}

	// Validates the program and verifies the validation succeeded
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
	// detaches the shaders from the program
	glDetachShader(_program, _fragmentShader);
	glDetachShader(_program, _vertexShader);

	// deletes the shaders and then the program
	glDeleteShader(_fragmentShader);
	glDeleteShader(_vertexShader);
	glDeleteProgram(_program);
}

void Shader::bind()
{
	glUseProgram(_program); // tells opengl to use the shader program
}

GLuint Shader::createShader(const char* shaderCode, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType); // creates a shader

	if (shader == 0) // verifies the shader created successfully
	{
		std::cerr << "Error: Shader Creation Failed\n";
		exit(-1);
	}

	// prepares the shader code to be compiled
	const GLchar* shaderSource[1];
	GLint shaderSourceLength[1];

	shaderSource[0] = shaderCode;
	shaderSourceLength[0] = strlen(shaderCode);

	glShaderSource(shader, 1, shaderSource, shaderSourceLength); // adds the shader source code to the shader
	glCompileShader(shader); // compiles the shader

	// verifies the shader compiled successfully
	GLint result = 0;
	glGetShaderiv(_program, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		std::cerr << "ERROR: Shader failed to compile\n";
	}
	return shader;
}
const char* Shader::getShaderCode(char* filename)
{
	std::ifstream file;
	file.open(filename); // opens the file asked to by the parameter

	std::string output;
	std::string line;

	// copies the code from the file and adds newline characters
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
	// returns the contents of the file
	return output.c_str();
}
