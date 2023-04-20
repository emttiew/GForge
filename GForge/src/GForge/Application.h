#pragma once

#include "Core.h"

namespace gforge {
	class GFORGE_API Application
	{
	public:
		Application() {}
		virtual ~Application() {}
		void run();
	};

	Application* CreateApplication();
}

