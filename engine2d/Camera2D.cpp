#include "Camera2D.h"
#include "GameObject.h"

Camera2D::Camera2D()
{
	m_position = { 0, 0 };
	m_cameraMoveState = CameraMoveState::STATIC;
	m_cameraZoomState = CameraZoomState::ZOOM;
	m_targetObj = nullptr;
	m_zoom = CameraConfig::DEFAULT_ZOOM;

	CalculateView();
	CalculateBaseProjection();
}

Camera2D::~Camera2D()
{
}

void Camera2D::SetTarget(GameObject* target)
{
	m_targetObj = target;
}

void Camera2D::Update(GLfloat dt, glm::vec2 position)
{
	if (m_cameraMoveState == CameraMoveState::STATIC)
	{
		m_position = glm::vec2{ 0, 0 };
	}
	else if (m_cameraMoveState == CameraMoveState::FOLLOW)
	{
		if (!m_targetObj)
		{
			Logger::Log(LogType::ERROR, "Camera state - FOLLOW but no target.");
			return;
			// TODO EXCEPTION
		}
		
		glm::vec2 targetPos = m_targetObj->GetPosition();
		glm::vec2 size = m_targetObj->GetSize();
		glm::vec2 objCenter = targetPos + size * 0.5f;

		m_position = objCenter;
	}
	else if (m_cameraMoveState == CameraMoveState::MOUSE)
	{
		float x = position.x;
		float y = position.y;

		glm::vec2 delta(0.0f);

		if (x >= 0 && x <= CameraConfig::MOVE_ZONE)
		{
			delta.x -= 1.0f;
		}
		else if (x <= EngineConfig::WINDOW_WIDTH && x >= EngineConfig::WINDOW_WIDTH - CameraConfig::MOVE_ZONE)
		{
			delta.x += 1.0f;
		}

		if (y >= 0 && y <= CameraConfig::MOVE_ZONE)
		{
			delta.y += 1.0f;
		}
		else if (y <= EngineConfig::WINDOW_HEIGHT && y >= EngineConfig::WINDOW_HEIGHT - CameraConfig::MOVE_ZONE)
		{
			delta.y -= 1.0f;
		}

		if (delta != glm::vec2(0.0f))
		{
			delta = glm::normalize(delta) * CameraConfig::CAMERA_SPEED * dt;
			m_position += delta;
		}
	}

	CalculateView();
}

void Camera2D::CalculateZoom(float scrollDirection)
{
	if (m_cameraZoomState != CameraZoomState::ZOOM)
	{
		m_projection = m_baseProjection;
		return;
	}

	if (scrollDirection == 1 && m_zoom <= CameraConfig::MAX_ZOOM)
	{
		m_zoom += CameraConfig::ZOOM_SPEED;
	}
	else if (scrollDirection == -1 && m_zoom >= CameraConfig::MIN_ZOOM)
	{
		m_zoom -= CameraConfig::ZOOM_SPEED;
	}

	float width = EngineConfig::WINDOW_WIDTH * 0.5f / m_zoom;
	float height = EngineConfig::WINDOW_HEIGHT * 0.5f / m_zoom;

	m_projection = glm::ortho(-width, +width, -height, +height, -1.0f, 1.0f);
}

void Camera2D::CalculateView()
{
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-m_position, 0.0f));

	m_view = m_projection * view;
}

void Camera2D::CalculateBaseProjection()
{
	float halfW = EngineConfig::WINDOW_WIDTH * 0.5f;
	float halfH = EngineConfig::WINDOW_HEIGHT * 0.5f;

	m_baseProjection = glm::ortho(-halfW, +halfW, -halfH, +halfH, -1.0f, +1.0f);
}
