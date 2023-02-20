#pragma once
#include <windows.h>
#include <string>

namespace Debug
{
	enum MsgLevel
	{
		LVL_DEBUG = 200000001,
		LVL_INFO = 1000000001,
		LVL_WARN = 1300000001,
		LVL_ERROR = 1400000001,
	};

	void debuggerMessage(MsgLevel level, const char* fmt, ...);
}