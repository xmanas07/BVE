#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace BVE {
	class BVE_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
// Core log macros
#define BVE_CORE_TRACE(...) ::BVE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BVE_CORE_INFO(...)  ::BVE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BVE_CORE_WARN(...)  ::BVE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BVE_CORE_ERROR(...) ::BVE::Log::GetCoreLogger()->error(__VA_ARGS__)
//#define BVE_CORE_FATAL(...) ::BVE::Log::GetCoreLogger()->fatal(__VA_ARGS__)
// Client log macros
#define BVE_TRACE(...) ::BVE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BVE_INFO(...)  ::BVE::Log::GetClientLogger()->info(__VA_ARGS__)
#define BVE_WARN(...)  ::BVE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BVE_ERROR(...) ::BVE::Log::GetClientLogger()->error(__VA_ARGS__)
//#define BVE_FATAL(...) ::BVE::Log::GetClientLogger()->fatal(__VA_ARGS__)

