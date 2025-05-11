#include "Engine.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
	delete m_window;
	delete m_input;
	delete m_camera;
	delete m_renderer;
	delete m_playerController;
	Logger::Log(LogType::MESSAGE, "Engine Stopped.");
}

void Engine::Run()
{
	Logger::Log(LogType::MESSAGE, "Engine Started.");

	GLfloat dt = 0, lastTime = 0;

	// DEBUG
	Player* player = new Player(0, 0, 100, 100);
	m_playerController->Controll(player);

	m_camera->SetTarget(player);

	// DEBUG
	while (!m_window->ShouldClose())
	{
		GLfloat now = glfwGetTime();
		dt = now - lastTime;
		lastTime = now;

		glClear(GL_COLOR_BUFFER_BIT);

		Draw(dt);
		player->Draw(m_renderer);
		Update(dt);

		m_window->SwapBuffers();
		glfwPollEvents();
	}

	delete player;
}

void Engine::Init()
{
	m_window = new Window();
	m_window->Init();

	m_input = new Input(m_window);
	m_window->SetInput(m_input);
	m_camera = new Camera2D();
	m_renderer = new Renderer2D(m_camera);

	InputActionMapper& actionMapper = InputActionMapper::Instance();
	actionMapper.Init(m_input);

	m_playerController = new PlayerController();
}

void Engine::Update(float dt)
{
	m_camera->Update(dt, { m_input->GetMouseX(), m_input->GetMouseY() });
	m_camera->CalculateZoom(m_input->GetMouseScrollY());

	m_playerController->Update(dt);

	m_input->ResetMouseScrollData();
	m_input->ResetKeyPressed();
}

void Engine::Draw(float dt)
{
	
}
