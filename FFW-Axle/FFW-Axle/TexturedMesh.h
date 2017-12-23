#ifndef _TEXTURED_MESH_H
#define _TEXTURED_MESH_H
#include "Texture.h"
#include "Mesh.h"

class TexturedMesh
{
public:
	TexturedMesh(Mesh* mesh, Texture* texture);
	~TexturedMesh();

	Mesh* getMesh();
	Texture* getTexture();

private:
	Mesh* _mesh;
	Texture* _texture;
};

#endif