#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include "ConfigFile.h"

class Rectangle;

enum CameraState {
	STATIC,
	FOLLOW,
	MOUSE
};

class Camera2D
{
private:
	glm::vec2 m_position;
	glm::mat4 m_projection;
	glm::mat4 m_view;

	Rectangle* m_targetObj;

	CameraState m_cameraState;

public:
	Camera2D();
	~Camera2D();

	glm::mat4 GetView() const { return m_view; }
	void SetTarget(Rectangle* target);

	void Update(GLfloat dt, glm::vec2 position);

private:
	void CalculateView();

};