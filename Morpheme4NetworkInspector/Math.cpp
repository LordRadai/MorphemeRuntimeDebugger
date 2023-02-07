#include "Math.h"

float Math::frameToTime(int frame, int frameRate)
{
	return ((float)frame / (float)frameRate);
}

int Math::timeToFrame(float time, int frameRate)
{
	return (time * frameRate);
}

/*
bool Math::getBit(void* var, byte n)
{
	return ((*var & pow(2, n)) >> n);
}
*/