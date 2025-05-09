#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include "ConfigFile.h"

class GameObject;

enum class CameraMoveState {
	STATIC,
	FOLLOW,
	MOUSE
};

enum class CameraZoomState {
	ZOOM,
	NO_ZOOM
};

class Camera2D
{
private:
	glm::vec2 m_position;
	glm::mat4 m_projection;
	glm::mat4 m_baseProjection;
	glm::mat4 m_view;
	float m_zoom;

	GameObject* m_targetObj;

	CameraMoveState m_cameraMoveState;
	CameraZoomState m_cameraZoomState;

public:
	Camera2D();
	~Camera2D();

	glm::mat4 GetView() const { return m_view; }
	void SetTarget(GameObject* target);

	void Update(GLfloat dt, glm::vec2 position);
	void CalculateZoom(float scrollDirection);

private:
	void CalculateView();
	void CalculateBaseProjection();
};