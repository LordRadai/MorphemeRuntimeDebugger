#include "ImNodesInterface.h"

void ImNodesInterface::createMorphemeNode(Morpheme::NodeDef* node)
{
	int push_amount = 0;

	ImNodes::PushColorStyle(ImNodesCol_TitleBar, 0xFF7A3A00);
	ImNodes::PushColorStyle(ImNodesCol_TitleBarHovered, 0xFF7A3A00);
	ImNodes::PushColorStyle(ImNodesCol_TitleBarSelected, 0xFF7A3A00);
	push_amount += 3;

	if (Morpheme::isNodeActive(network_inspector.network, node->m_nodeID))
	{
		push_amount++;
		ImNodes::PushColorStyle(ImNodesCol_NodeOutline, 0xFF0000FF);
	}

	if (Morpheme::isNodeContainer(network_inspector.network, node->m_nodeID))
	{
		push_amount++;
		ImNodes::PushColorStyle(ImNodesCol_NodeBackground, 0xFFAB5C00);
	}

	switch (node->m_nodeTypeID)
	{
	case 10:
		createStateMachineNode(node);
		break;
	case 402:
		createTransitNode(node);
		break;
	default:
		int output_id = node->m_nodeID * 100000;
		int source_id = node->m_nodeID * 100000 + 1;
		int input_id = node->m_nodeID * 100000 + 10;
		char title[255];
		const char* node_name = Morpheme::getNodeName(network_inspector.target_character, node->m_nodeID);

		sprintf_s(title, "[%d] %s", node->m_nodeID, Morpheme::getNodeTypeName_Alt(network_inspector.network, node->m_nodeID));
		if (node_name[0])
			strcpy(title, node_name);

		ImNodes::BeginNode(node->m_nodeID);

		ImNodes::BeginNodeTitleBar();
		ImGui::TextUnformatted(title);
		ImNodes::EndNodeTitleBar();

		ImNodes::BeginOutputAttribute(output_id);
		ImGui::TextUnformatted("Result");
		ImNodes::EndOutputAttribute();

		ImNodes::BeginInputAttribute(source_id);
		ImGui::TextUnformatted("Source");
		ImNodes::EndInputAttribute();

		for (size_t i = 0; i < node->m_numControlParamAndOpNodeIDs; i++)
		{
			ImNodes::BeginInputAttribute(input_id + i);
			ImNodes::EndInputAttribute();
		}

		ImNodes::EndNode();
		break;
	}
	
	for (size_t i = 0; i < push_amount; i++)
		ImNodes::PopColorStyle();
}

void ImNodesInterface::createStateMachineNode(Morpheme::NodeDef* node)
{
	ImNodes::PushColorStyle(ImNodesCol_NodeBackground, 0xFF7A3A00);

	char title[255];
	const char* node_name = Morpheme::getNodeName(network_inspector.target_character, node->m_nodeID);

	sprintf_s(title, "[%d] %s", node->m_nodeID, Morpheme::getNodeTypeName_Alt(network_inspector.network, node->m_nodeID));
	if (node_name[0])
		strcpy(title, node_name);

	ImNodes::BeginNode(node->m_nodeID);

	ImNodes::BeginNodeTitleBar();
	ImGui::TextUnformatted(title);
	ImNodes::EndNodeTitleBar();

	ImNodes::EndNode();
	ImNodes::PopColorStyle();
}

void ImNodesInterface::createTransitNode(Morpheme::NodeDef* node)
{
	int output_id = node->m_nodeID * 100000;
	int source_id = node->m_nodeID * 100000 + 1;
	int input_id = node->m_nodeID * 100000 + 10;
	char title[255];
	const char* node_name = Morpheme::getNodeName(network_inspector.target_character, node->m_nodeID);

	sprintf_s(title, "[%d] %s", node->m_nodeID, Morpheme::getNodeTypeName_Alt(network_inspector.network, node->m_nodeID));
	if (node_name[0])
		strcpy(title, node_name);

	ImNodes::BeginNode(node->m_nodeID);

	ImNodes::BeginNodeTitleBar();
	ImGui::TextUnformatted(title);
	ImNodes::EndNodeTitleBar();

	ImNodes::BeginOutputAttribute(output_id);
	ImGui::TextUnformatted("Destination");
	ImNodes::EndOutputAttribute();

	ImNodes::BeginInputAttribute(source_id);
	ImGui::TextUnformatted("Source");
	ImNodes::EndInputAttribute();

	for (size_t i = 0; i < node->m_numControlParamAndOpNodeIDs; i++)
	{
		
	}

	ImNodes::EndNode();
}

int ImNodesInterface::getNodeInputId(int node, int index)
{
	return (node * 100000 + 10 + index);
}

int ImNodesInterface::getNodeOutputId(int node)
{
	return (node * 100000);
}

int ImNodesInterface::getNodeSourceId(int node)
{
	return (node * 100000 + 1);
}
