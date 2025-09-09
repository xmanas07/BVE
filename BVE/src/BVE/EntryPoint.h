#pragma once


#ifdef BVE_PLATFORM_WINDOWS

extern BVE::Application* BVE::CreateApplication();

int main(int argc, char** argv)
{
	BVE::Log::Init();
	BVE_CORE_WARN("Initialized Log!");
	int a = 5;
	BVE_INFO("Initialized Log! Var={0}", a);
	BVE_CORE_TRACE("Initialized Log!");
	BVE_INFO("Hello!");

	auto app = BVE::CreateApplication();
	app->Run();
	delete app;
}


#endif
