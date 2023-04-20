#pragma once

#ifdef GF_PLATFORM_WINDOWS

extern gforge::Application* gforge::CreateApplication();

int  main(int argc, char** argv)
{
	auto app = gforge::CreateApplication();
	app->run();
	delete app;
}
#endif