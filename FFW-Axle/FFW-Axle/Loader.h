#ifndef _LOADER_H
#define _LOADER_H
#include <glew.h>
#include <SOIL.h>
#include <glfw3.h>
#include <stdio.h>
#include "Mesh.h"
#include "Util.h"
#include <iostream>
#include <vector>

/*
	Loads files/meshes/textures into the game
	Loading meshes is based off of the ThinMatrix's implementation
*/
class Loader
{
public:
	Mesh* loadMesh(float* positions, int* indices, float* textureCoords, int vertexCount, int indicesCount); // Loads a mesh from a list of vertices and indices. Based on the ThinMatrix's implementation
	Loader();
	~Loader();

	GLuint loadTexture(char* filename);

private:
	std::vector<GLuint>* vaos; // stores all of the vaos
	std::vector<GLuint>* vbos; // stores all of the vbos
	std::vector<GLuint>* textures;

	GLuint createVAO(); // creates a vao. Based on the ThinMatrix's implementation.
	void storeDataInAttributeList(int attribNumber, int size, float* data, int vertexCount); // Helper method for storing data in an attribute list. Based on ThinMatrix's implementation
	void unbindVAO(); // Unbinds a vao. Based on the ThinMatrix's implementation.

	void bindIndicesBuffer(int* indices, int indicesCount); // Binds indices. Based on the ThinMatrix's implementation.

};

#endif