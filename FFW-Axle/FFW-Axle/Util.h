#ifndef _UTILS
#define _UTILS
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include "Camera.h"

static float FOV = 65;
static float NEAR = 0.1f;
static float FAR = 1000.0f;
static int width = 1366;
static int height = 768;

// found on https://www.geeksforgeeks.org/how-to-find-size-of-array-in-cc-without-using-sizeof-operator/
#define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

static glm::mat4 createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale)
{
	glm::mat4* matrix = new glm::mat4(1);
	*matrix = glm::translate(*matrix,translation);
	*matrix = glm::rotate(*matrix, glm::radians(rx), glm::vec3(1, 0, 0));
	*matrix = glm::rotate(*matrix, glm::radians(ry), glm::vec3(0, 1, 0));
	*matrix = glm::rotate(*matrix, glm::radians(rz), glm::vec3(0, 0, 1));
	*matrix = glm::scale(*matrix, glm::vec3(scale, scale, scale));

	return *matrix;
}

static void createProjectionMatrix(glm::mat4* matrix)
{
	float aspectRatio = (float)width / (float)height;
	float yScale = (1.0f / glm::tan(glm::radians(FOV / 2.0f))) * aspectRatio;
	float xScale = yScale / aspectRatio;
	float frustumLength = FAR - NEAR;

	glm::mat4* tmp = new glm::mat4();
	(*tmp)[0][0] = xScale;
	(*tmp)[1][1] = yScale;
	(*tmp)[2][2] = -((FAR + NEAR) / frustumLength);
	(*tmp)[2][3] = -1;
	(*tmp)[3][2] = -((2 * NEAR * FAR) / frustumLength);
	(*tmp)[3][3] = 0;

	*matrix = *tmp;
}

static glm::mat4 createViewMatrix(Camera* camera)
{
	glm::mat4* viewMatrix = new glm::mat4(1);
	glm::rotate(*viewMatrix,(float)glm::radians(camera->getPitch()), glm::vec3(1, 0, 0));
	glm::rotate(*viewMatrix, (float)glm::radians(camera->getYaw()), glm::vec3(0, 1, 0));
	glm::rotate(*viewMatrix, (float)glm::radians(camera->getRoll()), glm::vec3(0, 0, 1));

	glm::vec3 cameraPos = camera->getPosition();
	glm::vec3 negativeCameraPos = glm::vec3(-cameraPos.x, -cameraPos.y, -cameraPos.z);
	glm::translate(*viewMatrix, negativeCameraPos);
	return *viewMatrix;

}

#endif
