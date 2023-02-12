#include "Math.h"

float Math::frameToTime(int frame, int frameRate)
{
	return ((float)frame / (float)frameRate);
}

int Math::timeToFrame(float time, int frameRate)
{
	float frame = (time * frameRate);

	return (frame + 0.9);
}

bool Math::getBit(void* var, byte n)
{
	int power = pow(2, n);
	if (((int)var & power) >> n)
	{

	}
	return false;
}