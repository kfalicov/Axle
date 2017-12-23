#ifndef _MESH_H
#define _MESH_H
#include <glfw3.h>

// Stores data about a Mesh
class Mesh
{
public:
	Mesh(GLuint vaoID, int vertexCount); // Stores a vao and the number of vertices in the mesh
	~Mesh();

	GLuint getVAOID(); // Returns the vaoid of the mesh
	int getVertexCount(); // Returns the number of vertices in the mesh

private:
	GLuint _vaoID;
	int _vertexCount;
protected:
};

#endif