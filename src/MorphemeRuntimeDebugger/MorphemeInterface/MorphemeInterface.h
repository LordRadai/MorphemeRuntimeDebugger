#pragma once
#include "../Morpheme/Morpheme.h"

namespace MorphemeInterface
{
	int getNodeContentAmount(Morpheme::NodeDef* node);
	void renderNodeAttributeType(Morpheme::NodeDef* node, int data_amount);
}