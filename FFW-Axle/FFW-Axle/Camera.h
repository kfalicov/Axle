#ifndef _CAMERA_H
#define _CAMERA_H

#include <glm/glm.hpp>

/*
	Controls what is displayed to the user
*/
class Camera
{
public:
	Camera(); // creates a new camera
	~Camera(); // destroyes the camera

private:
	glm::vec3 position;
protected:

};

#endif