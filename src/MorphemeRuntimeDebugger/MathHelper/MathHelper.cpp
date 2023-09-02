#include "MathHelper.h"
#include "../common.h"
#include "../Debug/Debug.h"

float MathHelper::FrameToTime(int frame, int frameRate)
{
	return ((float)frame / (float)frameRate);
}

int MathHelper::TimeToFrame(float time, int frameRate)
{
	float frame = (time * frameRate);

	if (std::round(frame) == 0 && frame > 0)
		return 1;

	return frame;
}