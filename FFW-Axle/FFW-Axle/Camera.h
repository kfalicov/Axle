#ifndef _CAMERA_H
#define _CAMERA_H

#include <glm/glm.hpp>

/*
	Controls what is displayed to the user
*/
class Camera
{
public:
	Camera(glm::vec3 position); // creates a new camera
	~Camera(); // destroyes the camera

	glm::vec3 getPosition();
	float getPitch();
	float getYaw();
	float getRoll();
	void move();

private:
	glm::vec3 _position;
	float _pitch;
	float _yaw;
	float _roll;
protected:

};

#endif