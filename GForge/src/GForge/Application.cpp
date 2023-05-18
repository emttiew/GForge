#include "Application.h"

#include "Application.h"
#include "GForge/Log.h"
#include "GForge/Events/ApplicationEvent.h"
#include <GLFW/glfw3.h>

#include <memory>

namespace gforge {

	Application::Application()
	{
		m_Window = Window::create();
	}

	void Application::run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->onUpdate();
		}
	}
}