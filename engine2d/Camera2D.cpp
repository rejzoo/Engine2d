#include "Camera2D.h"
#include "Logger.h"

Camera2D::Camera2D()
{
	m_position = { 0, 0 };
	m_projection = glm::ortho(0.0f, EngineConfig::WINDOW_HEIGHT, EngineConfig::WINDOW_WIDTH, 0.0f, -1.0f, 1.0f);
	m_cameraState = CameraState::STATIC;
	m_targetCords = { 0, 0 };

	CalculateView();
}

Camera2D::~Camera2D()
{
}

void Camera2D::Update(GLfloat dt, glm::vec2 mousePos)
{
	if (m_cameraState == CameraState::STATIC)
	{
		return;
	}

	if (m_cameraState == CameraState::FOLLOW)
	{
		m_position = mousePos;
	}

	if (m_cameraState == CameraState::MOUSE)
	{

	}

	CalculateView();
}

void Camera2D::CalculateView()
{
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(m_position, 0.0f));

	m_view = m_projection * view;
}
