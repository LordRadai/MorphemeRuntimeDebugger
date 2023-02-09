#pragma once
#include <math.h>
#include <Windows.h>

namespace Math
{
	float frameToTime(int frame, int frameRate);

	int timeToFrame(float time, int frameRate);

	bool getBit(void* var, byte n);
}