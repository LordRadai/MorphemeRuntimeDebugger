#include "Math.h"
#include "common.h"
#include "Debug.h"

bool Math::worldToScreen(Vector3 position, ScreenPoint* sp)
{
	float clipCoordsX = (viewMatrix[0] * position.x) + (viewMatrix[4] * position.y) + (viewMatrix[8] * position.z) + viewMatrix[12];
	float clipCoordsY = (viewMatrix[1] * position.x) + (viewMatrix[5] * position.y) + (viewMatrix[9] * position.z) + viewMatrix[13];
	float clipCoordsZ = (viewMatrix[2] * position.x) + (viewMatrix[6] * position.y) + (viewMatrix[10] * position.z) + viewMatrix[14];
	float clipCoordsW = (viewMatrix[3] * position.x) + (viewMatrix[7] * position.y) + (viewMatrix[11] * position.z) + viewMatrix[15];

	if (clipCoordsW < 0.1f)
	{
		Debug::DebuggerMessage(Debug::LVL_DEBUG, "Point (%.3f, %.3f, %.3f) out of sight\n", position.x, position.y, position.z);
		return false;
	}

	Vector3 NDC;
	NDC.x = clipCoordsX / clipCoordsW;
	NDC.y = clipCoordsY / clipCoordsW;
	NDC.z = clipCoordsZ / clipCoordsW;

	sp->x = (width / 2 * NDC.x) + (NDC.x + width / 2);
	sp->y = -(height / 2 * NDC.y) + (NDC.y + height / 2);

	return true;
}

float Math::frameToTime(int frame, int frameRate)
{
	return ((float)frame / (float)frameRate);
}

int Math::timeToFrame(float time, int frameRate)
{
	float frame = (time * frameRate);

	return (frame + 0.9);
}