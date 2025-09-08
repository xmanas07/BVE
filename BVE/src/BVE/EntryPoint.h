#pragma once


#ifdef BVE_PLATFORM_WINDOWS

extern BVE::Application* BVE::CreateApplication();

int main(int argc, char** argv)
{
	auto app = BVE::CreateApplication();
	app->Run();
	delete app;
}


#endif
