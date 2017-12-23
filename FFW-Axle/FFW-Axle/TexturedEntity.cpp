#include "TexturedEntity.h"



TexturedEntity::TexturedEntity(glm::vec3 position, float rx, float ry, float rz, float scale, TexturedMesh* texturedMesh) : Entity(position,rx,ry,rz,scale), _texturedMesh(texturedMesh)
{
}


TexturedEntity::~TexturedEntity()
{
}

TexturedMesh* TexturedEntity::getTexturedMesh()
{
	return _texturedMesh;
}

void TexturedEntity::render()
{
	Mesh* mesh = _texturedMesh->getMesh();
	glBindVertexArray(mesh->getVAOID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glActiveTexture(GL_TEXTURE0);
	_texturedMesh->getTexture()->bind();
	glDrawElements(GL_TRIANGLES, mesh->getVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}