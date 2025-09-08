#include <BVE.h>

class Sandbox : public BVE::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


// Entry point
BVE::Application* BVE::CreateApplication()
{
	return new Sandbox();
}