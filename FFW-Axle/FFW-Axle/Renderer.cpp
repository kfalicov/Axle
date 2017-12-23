#include "Renderer.h"



Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 1, 0, 1);
}

void Renderer::renderMesh(Mesh* mesh)
{
	glBindVertexArray(mesh->getVAOID());
	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, mesh->getVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}


void Renderer::renderTexturedMesh(TexturedMesh* texturedMesh)
{
	Mesh* mesh = texturedMesh->getMesh();
	glBindVertexArray(mesh->getVAOID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glActiveTexture(GL_TEXTURE0);
	texturedMesh->getTexture()->bind();
	glDrawElements(GL_TRIANGLES, mesh->getVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}

void Renderer::draw()
{

}