#pragma once

#include "Event.h"

#include <sstream>

namespace BVE 
{
	class BVE_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : m_MouseX{ x }, m_MouseY{ y } {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }
		
		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << GetName() << "Event: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class BVE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset{ xOffset }, m_YOffset{ yOffset } {}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << "Event: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}
	private:
		float m_XOffset, m_YOffset;
	};


	class BVE_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : m_Button{ button } {}

		int m_Button;
	};

	class BVE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button, int repeatCount) : MouseButtonEvent(button), m_RepeatCount{ repeatCount } {}
		inline int GetRepeatCount() const { return m_RepeatCount; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << "Event: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	private:
		int m_RepeatCount;
	};

	class BVE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int keycode) : MouseButtonEvent(keycode) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << "Event: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
