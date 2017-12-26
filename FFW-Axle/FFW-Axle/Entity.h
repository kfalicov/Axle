#ifndef  _ENTITY_H
#define _ENTITY_H
#include <glm\glm.hpp>
#include "Shader.h"

/*
	Store the basic properties of an Entity. An entity is something that exists in the game world. It does not have to be renderered
*/
class Entity
{
public:
	Entity(glm::vec3 position, float rx, float ry, float rz, float scale);
	~Entity();


	// Getters and setters
	glm::vec3 getPosition();
	float getRotationX();
	float getRotationY();
	float getRotationZ();
	float getScale();

	void setPosition(glm::vec3 pos);
	void setRotationX(float x);
	void setRotationY(float y);
	void setRotationZ(float z);
	void setScale(float s);

	virtual void render(Shader* shader) = 0;
	virtual void update() = 0;

private:
	glm::vec3 _position;
	float _rx;
	float _ry;
	float _rz;
	float _scale;
};

#endif