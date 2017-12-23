#ifndef _TEXTURE_H
#define _TEXTURE_H
#include <glew.h>
#include <glfw3.h>
class Texture
{
public:
	Texture(GLuint id);
	~Texture();

	GLuint getID();
	void bind();
private:
	GLuint _texture;
};

#endif