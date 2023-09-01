#pragma once
#include "Morpheme.h"

namespace MorphemeInterface
{
	void drawSkeleton(uint64_t character_ctrl);
	int getNodeContentAmount(Morpheme::NodeDef* node);
	void renderNodeAttributeType(Morpheme::NodeDef* node, int data_amount);
}