#include "bvepch.h"

#include "Application.h"

#include "BVE/Events/ApplicationEvent.h"
#include "BVE/Events/MouseEvent.h"
#include "BVE/Log.h"

namespace BVE {

	// Application interface

	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		int a = 5;
		
		MouseMovedEvent e(10, 20);
		if (e.IsInCategory(EventCategoryInput) && e.IsInCategory(EventCategoryMouse))
			BVE_TRACE(e.ToString());
		else BVE_TRACE("nn");
		while (true)
		{

		}
	}

}