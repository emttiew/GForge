#include "Application.h"

#include "Application.h"
#include "GForge/Log.h"
#include "GForge/Events/ApplicationEvent.h"


namespace gforge {

	void Application::run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.isInCategory(EventCategoryApplication))
		{
			GF_TRACE(e);
		}
		if (e.isInCategory(EventCategoryInput))
		{
			GF_TRACE(e);
		}
		while (true);
	}
}