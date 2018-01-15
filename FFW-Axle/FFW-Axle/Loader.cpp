#include "Loader.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

Loader::Loader()
{
	vaos = new std::vector<GLuint>();
	vbos = new std::vector<GLuint>();
	textures = new std::vector<GLuint>();
}

Loader::~Loader()
{
	// Deletes the vaos
	for (int i = 0; (unsigned int)i < vaos->size(); i++)
	{
		glDeleteVertexArrays(1, &(vaos->at(i)));
	}

	// deletes the vbos
	for (int i = 0; (unsigned int)i < vbos->size(); i++)
	{
		glDeleteBuffers(1, &(vbos->at(i)));
	}

	// deletes the textures
	for (int i = 0; (unsigned int)i < textures->size(); i++)\
	{
		glDeleteTextures(1, &(textures->at(i)));
	}
}

GLuint Loader::createVAO()
{
	GLuint vaoID;
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
	vaos->push_back(vaoID);
	return vaoID;
}

void Loader::storeDataInAttributeList(int attribNumber, int size, float* data, int vertexCount)
{
	GLuint vboID;
	glGenBuffers(1, &vboID);
	vbos->push_back(vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), data, GL_STATIC_DRAW);
	glVertexAttribPointer(attribNumber, size, GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVAO()
{
	glBindVertexArray(0);
}


Mesh* Loader::loadMesh(float* positions, int* indices, float* textureCoords, int vertexCount, int indicesCount)
{
	GLuint vaoID = createVAO();
	bindIndicesBuffer(indices, indicesCount);
	storeDataInAttributeList(0, 3, positions, vertexCount);
	storeDataInAttributeList(1, 2, textureCoords, vertexCount);
	unbindVAO();
	printf("Number of vertices: %d\n", vertexCount);
	return new Mesh(vaoID, indicesCount);
}


void Loader::bindIndicesBuffer(int* indices, int indicesCount)
{
	GLuint vboID;
	glGenBuffers(1, &vboID);
	vbos->push_back(vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesCount * sizeof(int), indices, GL_STATIC_DRAW);
}

GLuint Loader::loadTexture(char* filename)
{
	GLuint texture = SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	textures->push_back(texture);
	return texture;
}



/*
Based on the ThinMatrix's implementation
*/
void processVertex(char* vertexData0, char* vertexData1, char* vertexData2, std::vector<int>* indices, std::vector<glm::vec2>* textures, std::vector<glm::vec3>* normals, float* textureArray,float* normalsArray)
{
	int currentVertexPointer = ::atoi(vertexData0) - 1;
	indices->push_back(currentVertexPointer);
	int index = ::atoi(vertexData1) - 1;
	glm::vec2 currentTex = textures->at(index);
	textureArray[currentVertexPointer * 2] = currentTex.x;
	textureArray[currentVertexPointer * 2 + 1] = 1 - currentTex.y;
	glm::vec3 currentNorm = normals->at(::atoi(vertexData2) - 1);
	normalsArray[currentVertexPointer * 3] = currentNorm.x;
	normalsArray[currentVertexPointer * 3 + 1] = currentNorm.y;
	normalsArray[currentVertexPointer * 3 + 2] = currentNorm.z;

	free(vertexData0);
	free(vertexData1);
	free(vertexData2);
}

/*
	Based on the ThinMatrix's implementation
*/
Mesh* Loader::loadObj(char* filename)
{
	std::ifstream file;
	file.open(filename); // opens the file asked to by the parameter

	std::string line;
	std::vector<glm::vec3>* vertices = new std::vector<glm::vec3>();
	std::vector<glm::vec2>* texCoords = new std::vector<glm::vec2>();
	std::vector<glm::vec3>* normals = new std::vector<glm::vec3>();
	std::vector<int>* indices = new std::vector<int>();

	float* verticesArray = NULL;
	float* texturesArray = NULL;
	float* normalsArray = NULL;
	int* indicesArray = NULL;

	// copies the code from the file and adds newline characters
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			std::cout << "Handling line: " << line << std::endl;
			if (line.length() == 0)
			{
				continue;
			}
			if (line.at(0) == 'v' && line.at(1) == 't')
			{
				char* str = (char*)line.c_str();
				char* tokens;
				char* context;
				const char* del = " ";
				glm::vec2 texCoord;
				char tmpCounter = 0;
				int loopCounter = 0;

				tokens = strtok_s(str, del, &context);
				while (tokens != NULL)
				{
					if (loopCounter == 0)
					{
						tokens = strtok_s(NULL, del, &context);
						loopCounter++;
						continue;
					}
					float tmp = (float)::atof(tokens);
					if (tmpCounter == 0)
					{
						texCoord.x = tmp;
						tmpCounter++;
					}
					else if (tmpCounter == 1)
					{
						texCoord.y = tmp;
						tmpCounter++;
					}
					tokens = strtok_s(NULL, del, &context);
				}
				std::cout << "Added tex coord\n";
				texCoords->push_back(texCoord);
			}
			else if (line.at(0) == 'v' && line.at(1) == 'n')
			{
				char* str = (char*)line.c_str();
				char* tokens;
				char* context;
				const char* del = " ";
				glm::vec3 normalVertex;
				char tmpCounter = 0;
				int loopCounter = 0;
				tokens = strtok_s(str, del, &context);
				while (tokens != NULL)
				{
					if (loopCounter == 0)
					{
						tokens = strtok_s(NULL, del, &context);
						loopCounter++;
						continue;
					}
					float tmp = ::atof(tokens);
					if (tmpCounter == 0)
					{
						normalVertex.x = tmp;
						tmpCounter++;
					}
					else if (tmpCounter == 1)
					{
						normalVertex.y = tmp;
						tmpCounter++;
					}
					else if (tmpCounter == 2)
					{
						normalVertex.z = tmp;
						tmpCounter++;
					}
					tokens = strtok_s(NULL, del, &context);
				}
				normals->push_back(normalVertex);
			}
			else if (line.at(0) == 'v')
			{
				char* str = (char*)line.c_str();
				char* tokens;
				char* context;
				const char* del = " ";
				glm::vec3 vertex;
				char tmpCounter = 0;
				int loopCounter = 0;

				tokens = strtok_s(str, del, &context);
				while (tokens != NULL)
				{
					if (loopCounter == 0)
					{
						tokens = strtok_s(NULL, del, &context);
						loopCounter++;
						continue;
					}
					float tmp = ::atof(tokens);
					if (tmpCounter == 0)
					{
						vertex.x = tmp;
						tmpCounter++;
					}
					else if (tmpCounter == 1)
					{
						vertex.y = tmp;
						tmpCounter++;
					}
					else if (tmpCounter == 2)
					{
						vertex.z = tmp;
						tmpCounter++;
					}
					tokens = strtok_s(NULL, del, &context);
				}
				vertices->push_back(vertex);
			}
			else if (line.at(0) == 'f')
			{
				if (texturesArray == NULL && normalsArray == NULL)
				{
					texturesArray = new float[vertices->size() * 2];
					normalsArray = new float[vertices->size() * 3];
				}

				char* str = (char*)line.c_str();
				std::cout << "F Line: " << str << std::endl;
				char* tokens;
				char* context;
				const char* del = " ";
				int loopCounter = 0;

				tokens = strtok_s(str, del, &context);
				while (tokens != NULL)
				{
					if (loopCounter == 0)
					{
						tokens = strtok_s(NULL, del, &context);
						loopCounter++;
						continue;
					}
					std::cout << "FIRST STRTOK TOKENS: " << tokens << std::endl;
					char* vertexContext;
					const char* vertexDel = "/";
					char* vertexTokens = strtok_s(tokens,vertexDel,&vertexContext);

					char* point1 = (char*)malloc(60 * sizeof(char));
					char* point2 = (char*)malloc(60 * sizeof(char));
					char* point3 = (char*)malloc(60 * sizeof(char));
					char counter = 0;
					while (vertexTokens != NULL)
					{
						std::cout << vertexTokens << std::endl;
						if (counter == 0) strcpy_s(point1, 60, vertexTokens);
						else if(counter == 1) strcpy_s(point2, 60, vertexTokens);
						else strcpy_s(point3, 60, vertexTokens);
						//point[counter] = vertexTokens;
						counter++;
						vertexTokens = strtok_s(NULL, vertexDel, &vertexContext);
					}

					processVertex(point1,point2,point3, indices, texCoords, normals, texturesArray, normalsArray);

					tokens = strtok_s(NULL, del, &context);
				}
			}
		}

		verticesArray = new float[vertices->size() * 3];
		indicesArray = new int[indices->size()];

		int vertexPointer = 0;
		for (int i = 0; i < vertices->size(); i++)
		{
			std::cout << "Adding vertex to vertices array: " << (vertices->at(i)).x << std::endl;
			verticesArray[vertexPointer++] = (vertices->at(i)).x;
			verticesArray[vertexPointer++] = (vertices->at(i)).y;
			verticesArray[vertexPointer++] = (vertices->at(i)).z;
		}

		for (int i = 0; i < indices->size(); i++)
		{
			indicesArray[i]  = (indices->at(i));
		}
		file.close();
		//if (texturesArray == NULL)
		//{
			//texturesArray = new float[1];
		//	std::cerr << "Error no texture coords\n";
		//	exit(-1);
		//}
		std::cout << "There should be : " << vertices->size() << " vertices\n";
		std::cout << "There should be : " << indices->size() << " indices\n";
		std::cout << "There should be : " << normals->size() << " normals\n";
		std::cout << "There should be : " << texCoords->size() << " textures\n";
		return loadMesh(verticesArray, indicesArray, texturesArray, vertices->size() * 3, indices->size());
	}
	else
	{
		std::cerr << "Unable to load model: " << filename << std::endl;
	}
	file.close();
	return NULL;
}