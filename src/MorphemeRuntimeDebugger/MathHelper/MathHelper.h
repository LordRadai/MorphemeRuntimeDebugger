#pragma once
#include <math.h>
#include <Windows.h>

#include <iostream>
#include <cmath>

using namespace std;

namespace MathHelper
{
	float FrameToTime(int frame, int frameRate = 60);

	int TimeToFrame(float time, int frameRate = 60);
}