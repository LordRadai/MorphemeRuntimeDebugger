#pragma once
#include "includes.h"
#include "Morpheme.h"

namespace ImNodesInterface
{
	void createMorphemeNode(Morpheme::NodeDef* node);
	void createStateMachineNode(Morpheme::NodeDef* node);
	void createCPNode(Morpheme::NodeDef* node);
	void createTransitNode(Morpheme::NodeDef* node);
	void createAnimSyncEventNode(Morpheme::NodeDef* node);

	inline int getNodeInputPinId(int node, int index);
	inline int getNodeOutputPinId(int node);
	inline int getNodeSourcePinId(int node, int index);
	inline int getNodeLinkPinId(int node, int index);

	bool linkMorphemeNodes(int link_id, int src_id, int dst_id);
}