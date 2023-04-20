#include <GForge.h>
#include <memory>

class Sandbox : public gforge::Application
{
public:
	Sandbox(){}
	~Sandbox(){}
};

gforge::Application* gforge::CreateApplication()
{
	return new Sandbox();
}