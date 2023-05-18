#pragma once

#ifdef GF_PLATFORM_WINDOWS

extern gforge::ApplicationPtr gforge::createApplication();

int  main(int argc, char** argv)
{
	gforge::Log::init();
	GF_CORE_WARN("Initialized Log!");
	int a = 5;
	GF_INFO("Info: Var={0}", a);

	gforge::ApplicationPtr app = gforge::createApplication();
	app->run();
}
#endif