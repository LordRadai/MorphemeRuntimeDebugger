#include "../includes.h"
#include "../Morpheme/Morpheme.h"
#include "../TimeAct/TimeAct.h"

typedef void(__fastcall* oUpdateCPInt)(UINT64 pMorphemeMotionCtrl, short idx, int value);
extern oUpdateCPInt pUpdateCpInt;
extern oUpdateCPInt pUpdateCpIntTarget;

typedef void(__fastcall* oUpdateCPFloat)(UINT64 pMorphemeMotionCtrl, short idx, float value);
extern oUpdateCPFloat pUpdateCpFloat;
extern oUpdateCPFloat pUpdateCpFloatTarget;

namespace FRPG2Hook
{
	void InitHooks();

	void hUpdateCpInt(UINT64 pMorphemeMotionCtrl, short idx, int value);
	void hUpdateCpFloat(UINT64 pMorphemeMotionCtrl, short idx, float value);
}