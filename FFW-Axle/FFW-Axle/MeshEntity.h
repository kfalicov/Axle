#ifndef _MESH_ENTITY_H
#define _MESH_ENTITY_H
#include <glew.h>
#include <glfw3.h>
#include "Entity.h"
#include "Mesh.h"
class MeshEntity : public Entity
{
public:
	MeshEntity(glm::vec3 position, float rx, float ry, float rz, float scale, Mesh* mesh);
	~MeshEntity();

	void render();

	Mesh* getMesh();

private:
	Mesh* _mesh;
};

#endif