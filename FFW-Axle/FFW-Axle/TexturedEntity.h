#ifndef _TEXTURED_ENTITY_H
#define _TEXTURED_ENTITY_H

#include "Entity.h"
#include "TexturedMesh.h"

class TexturedEntity : public Entity
{
public:
	TexturedEntity(glm::vec3 position, float rx, float ry, float rz, float scale, TexturedMesh* mesh);
	~TexturedEntity();

	TexturedMesh* getTexturedMesh();

	void render(Shader* shader);
	void update();
private:
	TexturedMesh* _texturedMesh;
};

#endif