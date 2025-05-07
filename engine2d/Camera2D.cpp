#include "Camera2D.h"
#include "Rectangle.h"

Camera2D::Camera2D()
{
	m_position = { 0, 0 };
	m_projection = glm::ortho(0.0f, EngineConfig::WINDOW_HEIGHT, EngineConfig::WINDOW_WIDTH, 0.0f, -1.0f, 1.0f);
	m_cameraState = CameraState::MOUSE;
	m_targetObj = nullptr;

	CalculateView();
}

Camera2D::~Camera2D()
{
}

void Camera2D::SetTarget(Rectangle* target)
{
	m_targetObj = target;
}

void Camera2D::Update(GLfloat dt, glm::vec2 position)
{
	if (m_cameraState == CameraState::STATIC)
	{
		return;
	}

	if (m_cameraState == CameraState::FOLLOW)
	{
		if (!m_targetObj)
		{
			Logger::Log(LogType::ERROR, "Camera state - FOLLOW but no target.");
			return;
		}
		
		glm::vec2 targetPos = m_targetObj->GetPosition();
		glm::vec2 size = m_targetObj->GetSize();

		glm::vec2 halfView = glm::vec2(EngineConfig::WINDOW_WIDTH * 0.5f - (size.x * 0.5), EngineConfig::WINDOW_HEIGHT * 0.5f - (size.y * 0.5));

		m_position = targetPos - halfView;
	}

	if (m_cameraState == CameraState::MOUSE)
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
			delta.y -= 1.0f;
		}
		else if (y <= EngineConfig::WINDOW_HEIGHT && y >= EngineConfig::WINDOW_HEIGHT - CameraConfig::MOVE_ZONE)
		{
			delta.y += 1.0f;
		}

		if (delta != glm::vec2(0.0f))
		{
			delta = glm::normalize(delta) * CameraConfig::CAMERA_SPEED * dt;
			m_position += delta;
		}
	}

	CalculateView();
}

void Camera2D::CalculateView()
{
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-m_position, 0.0f));

	m_view = m_projection * view;
}
