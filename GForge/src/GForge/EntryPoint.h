#pragma once

#ifdef GF_PLATFORM_WINDOWS

extern gforge::Application* gforge::CreateApplication();

int  main(int argc, char** argv)
{
	gforge::Log::init();
	GF_CORE_WARN("Initialized Log!");
	int a = 5;
	GF_INFO("Info: Var={0}", a);

	auto app = gforge::CreateApplication();
	app->run();
	delete app;
}
#endif