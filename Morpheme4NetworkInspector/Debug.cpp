#include "Debug.h"

void Debug::debuggerMessage(MsgLevel level, const char* fmt, ...)
{
#ifdef DEBUG_MSG
	va_list args;
	__va_start(&args, fmt);
	std::string msg_level;
	std::string msg_body;

	char msg[256];

	switch (level)
	{
	case LVL_DEBUG:
		msg_level = "[DEBUG]";
		break;
	case LVL_INFO:
		msg_level = "[INFO]";
		break;
	case LVL_WARN:
		msg_level = "[WARN]";
		break;
	case LVL_ERROR:
		msg_level = "[ERROR]";
		break;
	default:
		break;
	}

	msg_body = fmt;
	vsprintf(msg, (msg_level + " " + msg_body).c_str(), args);

	OutputDebugStringA(msg);
#endif
}
