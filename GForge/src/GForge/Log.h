#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include <memory>

namespace gforge
{
	class GFORGE_API Log
	{
	public: 
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define GF_CORE_ERROR(...)	::gforge::Log::getCoreLogger()->error(__VA_ARGS__)
#define GF_CORE_WARN(...)	::gforge::Log::getCoreLogger()->warn(__VA_ARGS__)
#define GF_CORE_INFO(...)	::gforge::Log::getCoreLogger()->info(__VA_ARGS__)
#define GF_CORE_TRACE(...)	::gforge::Log::getCoreLogger()->trace(__VA_ARGS__)
#define GF_CORE_FATAL(...)	::gforge::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define GF_ERROR(...)	::gforge::Log::getClientLogger()->error(__VA_ARGS__)
#define GF_WARN(...)	::gforge::Log::getClientLogger()->warn(__VA_ARGS__)
#define GF_INFO(...)	::gforge::Log::getClientLogger()->info(__VA_ARGS__)
#define GF_TRACE(...)	::gforge::Log::getClientLogger()->trace(__VA_ARGS__)
#define GF_FATAL(...)	::gforge::Log::getClientLogger()->fatal(__VA_ARGS__)