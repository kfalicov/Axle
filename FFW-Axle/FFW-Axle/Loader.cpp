#include "Loader.h"

Loader::Loader()
{
	vaos = new std::vector<GLuint>();
	vbos = new std::vector<GLuint>();
	textures = new std::vector<GLuint>();
}

Loader::~Loader()
{
	for (int i = 0; (unsigned int)i < vaos->size(); i++)
	{
		glDeleteVertexArrays(1, &(vaos->at(i)));
	}
	for (int i = 0; (unsigned int)i < vbos->size(); i++)
	{
		glDeleteBuffers(1, &(vbos->at(i)));
	}
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