#pragma once
#include "includes.h"
#include "Morpheme.h"

namespace ImNodesInterface
{
	void createMorphemeNode(Morpheme::NodeDef* node);
	void createStateMachineNode(Morpheme::NodeDef* node);
	void createTransitNode(Morpheme::NodeDef* node);
	int getNodeInputId(int node, int index);
	int getNodeOutputId(int node);
	int getNodeSourceId(int node);
}