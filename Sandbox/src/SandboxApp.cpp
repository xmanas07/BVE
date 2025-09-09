#include <BVE.h>
// extends BVE::Application interface
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