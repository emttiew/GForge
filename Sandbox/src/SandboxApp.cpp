#include <GForge.h>
#include <memory>

class Sandbox : public gforge::Application
{
public:
	Sandbox(){}
	~Sandbox(){}
};

gforge::ApplicationPtr gforge::createApplication()
{
	return std::make_unique<Sandbox>();
}