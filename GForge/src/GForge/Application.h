#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace gforge {

	class GFORGE_API Application
	{
	public:
		Application();
		virtual ~Application() {}
		void run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	using ApplicationPtr = std::unique_ptr<Application>;
	ApplicationPtr createApplication();
}