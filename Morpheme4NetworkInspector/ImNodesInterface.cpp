#include "ImNodesInterface.h"

void ImNodesInterface::createMorphemeNode(Morpheme::NodeDef* node)
{
	if (node->m_nodeID == -1)
		return;

	bool is_container = is_container = Morpheme::isNodeContainer(network_inspector.network, node->m_nodeID);;
	int push_amount = 0;

	ImNodes::PushColorStyle(ImNodesCol_TitleBar, 0xFF7A3A00);
	ImNodes::PushColorStyle(ImNodesCol_TitleBarHovered, 0xFF7A3A00);
	ImNodes::PushColorStyle(ImNodesCol_TitleBarSelected, 0xFF7A3A00);
	ImNodes::PushColorStyle(ImNodesCol_Pin, 0xFF0000FF);
	ImNodes::PushColorStyle(ImNodesCol_PinHovered, 0xFF0000FF);
	push_amount += 5;

	if (Morpheme::isNodeActive(network_inspector.network, node->m_nodeID))
	{
		push_amount += 1;
		ImNodes::PushColorStyle(ImNodesCol_NodeOutline, 0xFF0000FF);
	}

	if (is_container)
	{
		push_amount += 3;
		ImNodes::PushColorStyle(ImNodesCol_NodeBackground, 0xFFAB5C00);
		ImNodes::PushColorStyle(ImNodesCol_NodeBackgroundHovered, 0xFFAB5C00);
		ImNodes::PushColorStyle(ImNodesCol_NodeBackgroundSelected, 0xFFAB5C00);
	}

	switch (node->m_nodeTypeID)
	{
	case 10:
		createStateMachineNode(node);
		break;
	case 20:
	case 21:
	case 23:
	case 24:
		createCPNode(node);
		break;
	case 104:
		createAnimSyncEventNode(node);
		break;
	case 402:
		createTransitNode(node);
		break;
	default:
		int output_id = node->m_nodeID * 100000;
		int source_id = node->m_nodeID * 100000 + 1;
		int input_id = node->m_nodeID * 1000000 + 10;
		int link_id = node->m_nodeID * 10000000;
		char title[255];
		const char* node_name = Morpheme::getNodeName(network_inspector.target_character, node->m_nodeID);

		sprintf_s(title, "%s_%d", Morpheme::getNodeTypeName_Alt(network_inspector.network, node->m_nodeID), node->m_nodeID);
		if (node_name[0])
			strcpy(title, node_name);

		ImNodes::BeginNode(node->m_nodeID);

		ImNodes::BeginNodeTitleBar();
		ImGui::TextUnformatted(title);
		ImNodes::EndNodeTitleBar();

		ImNodes::BeginOutputAttribute(output_id);
		const float label_width = ImGui::CalcTextSize("Result").x;
		ImGui::Indent(ImGui::CalcTextSize(title).x - label_width);
		ImGui::TextUnformatted("Result");
		ImNodes::EndOutputAttribute();

		ImNodes::BeginInputAttribute(source_id);
		ImGui::Text("");
		ImNodes::EndInputAttribute();

		if (node->m_sourcePinCount > 0)
		{
			for (size_t i = 0; i < node->m_sourcePinCount; i++)
			{
				ImNodes::BeginInputAttribute(source_id + i + 1);
				ImGui::Text("Source %d", i + 1);
				ImNodes::EndInputAttribute();
			}
		}

		ImNodes::PushColorStyle(ImNodesCol_Pin, 0xFF00FF00);
		ImNodes::PushColorStyle(ImNodesCol_PinHovered, 0xFF00FF00);
		if (node->m_numControlParamAndOpNodeIDs > 0)
		{
			for (size_t i = 0; i < node->m_numControlParamAndOpNodeIDs; i++)
			{
				ImNodes::BeginInputAttribute(input_id + i);
				ImGui::Text("Input %d", i+1);
				ImNodes::EndInputAttribute();
			}
		}
		ImNodes::PopColorStyle();
		ImNodes::PopColorStyle();

		ImNodes::EndNode();

		if (!is_container)
		{
			if (node->m_numChildNodeIDs > 0)
			{
				for (size_t i = 0; i < node->m_numChildNodeIDs; i++)
				{
					if (node->m_childNodeIDs[i] != -1)
					{
						createMorphemeNode(Morpheme::getNetworkNode(network_inspector.network, node->m_childNodeIDs[i]));
						ImNodes::Link(link_id, getNodeOutputPinId(node->m_childNodeIDs[i]), source_id + i);
						link_id++;
					}
				}
			}
		}

		if (node->m_numControlParamAndOpNodeIDs > 0)
		{
			for (byte i = 0; i < node->m_numControlParamAndOpNodeIDs; i++)
			{
				if (node->m_controlParamAndOpNodeIDs[i] != -1)
				{
					createMorphemeNode(Morpheme::getNetworkNode(network_inspector.network, node->m_controlParamAndOpNodeIDs[i]));
					ImNodes::Link(link_id, getNodeOutputPinId(node->m_controlParamAndOpNodeIDs[i]), input_id + i);
					link_id++;
				}
			}
		}

		break;
	}
	
	for (size_t i = 0; i < push_amount; i++)
		ImNodes::PopColorStyle();
}

void ImNodesInterface::createStateMachineNode(Morpheme::NodeDef* node)
{
	if (node->m_nodeID == -1)
		return;

	ImNodes::PushColorStyle(ImNodesCol_NodeBackground, 0xFF7A3A00);
	ImNodes::PushColorStyle(ImNodesCol_NodeBackgroundHovered, 0xFF7A3A00);
	ImNodes::PushColorStyle(ImNodesCol_NodeBackgroundSelected, 0xFF7A3A00);
	ImNodes::PushColorStyle(ImNodesCol_Pin, 0x000000FF);
	ImNodes::PushColorStyle(ImNodesCol_PinHovered, 0x000000FF);

	bool is_container = is_container = Morpheme::isNodeContainer(network_inspector.network, node->m_nodeID);;

	char title[255];
	const char* node_name = Morpheme::getNodeName(network_inspector.target_character, node->m_nodeID);
	int output_id = node->m_nodeID * 100000;
	int source_id = node->m_nodeID * 100000 + 1;
	int input_id = node->m_nodeID * 1000000 + 10;
	int link_id = node->m_nodeID * 10000000;

	sprintf_s(title, "%s_%d", Morpheme::getNodeTypeName_Alt(network_inspector.network, node->m_nodeID), node->m_nodeID);
	if (node_name[0])
		strcpy(title, node_name);

	ImNodes::BeginNode(node->m_nodeID);

	ImNodes::BeginNodeTitleBar();
	ImGui::TextUnformatted(title);
	ImNodes::EndNodeTitleBar();

	ImNodes::BeginOutputAttribute(output_id, ImNodesPinShape_Triangle);
	const float label_width = ImGui::CalcTextSize("").x;
	ImGui::Indent(ImGui::CalcTextSize(title).x - label_width);
	ImGui::TextUnformatted("");
	ImNodes::EndOutputAttribute();

	ImNodes::BeginInputAttribute(source_id, ImNodesPinShape_Quad);
	ImGui::Text("");
	ImNodes::EndInputAttribute();

	ImNodes::EndNode();

	for (size_t i = 0; i < 5; i++)
		ImNodes::PopColorStyle();
}

void ImNodesInterface::createTransitNode(Morpheme::NodeDef* node)
{
	if (node->m_nodeID == -1)
		return;

	if (node->m_numChildNodeIDs == 2 && node->m_childNodeIDs[0] != -1 && node->m_childNodeIDs[1] != -1)
	{
		int output_id = node->m_nodeID * 100000;
		int source_id = node->m_nodeID * 100000 + 1;
		int input_id = node->m_nodeID * 1000000 + 10;
		int link_id = node->m_nodeID * 10000000;
		char title[255];
		const char* node_name = Morpheme::getNodeName(network_inspector.target_character, node->m_nodeID);

		sprintf_s(title, "%s_%d", Morpheme::getNodeTypeName_Alt(network_inspector.network, node->m_nodeID), node->m_nodeID);
		if (node_name[0])
			strcpy(title, node_name);

		ImNodes::BeginNode(node->m_nodeID);

		ImNodes::BeginNodeTitleBar();
		ImGui::TextUnformatted(title);
		ImNodes::EndNodeTitleBar();

		ImNodes::BeginOutputAttribute(output_id, ImNodesPinShape_TriangleFilled);
		const float label_width = ImGui::CalcTextSize("Result").x;
		ImGui::Indent(ImGui::CalcTextSize(title).x - label_width);
		ImGui::TextUnformatted("Destination");
		ImNodes::EndOutputAttribute();

		ImNodes::BeginInputAttribute(source_id, ImNodesPinShape_TriangleFilled);
		ImGui::Text("Source");
		ImNodes::EndInputAttribute();

		ImNodes::EndNode();

		//createMorphemeNode(Morpheme::getNetworkNode(network_inspector.network, node->m_childNodeIDs[0]));
		//createMorphemeNode(Morpheme::getNetworkNode(network_inspector.network, node->m_childNodeIDs[1]));
		ImNodes::Link(link_id, getNodeOutputPinId(node->m_childNodeIDs[0]), source_id);
		ImNodes::Link(link_id + 1, output_id, getNodeSourcePinId(node->m_childNodeIDs[1], 0));
	}
}

void ImNodesInterface::createAnimSyncEventNode(Morpheme::NodeDef* node)
{
	int output_id = node->m_nodeID * 100000;
	int source_id = node->m_nodeID * 100000 + 1;
	int input_id = node->m_nodeID * 1000000 + 10;
	int link_id = node->m_nodeID * 10000000;
	char title[255];

	sprintf_s(title, "%s_%d", Morpheme::getAnimNameFromAnimNode(node), node->m_nodeID);

	ImNodes::BeginNode(node->m_nodeID);

	ImNodes::BeginNodeTitleBar();
	ImGui::TextUnformatted(title);
	ImNodes::EndNodeTitleBar();

	ImNodes::BeginOutputAttribute(output_id);
	const float label_width = ImGui::CalcTextSize("Result").x;
	ImGui::Indent(ImGui::CalcTextSize(title).x - label_width);
	ImGui::TextUnformatted("Result");
	ImNodes::EndOutputAttribute();

	ImNodes::PushColorStyle(ImNodesCol_Pin, 0x0000FF00);
	ImNodes::PushColorStyle(ImNodesCol_PinHovered, 0x0000FF00);
	ImNodes::BeginInputAttribute(source_id);
	ImGui::TextUnformatted("");
	ImNodes::EndInputAttribute();
	ImNodes::PopColorStyle();
	ImNodes::PopColorStyle();

	ImNodes::EndNode();
}

void ImNodesInterface::createCPNode(Morpheme::NodeDef* node)
{
	ImNodes::PushColorStyle(ImNodesCol_TitleBar, 0xFF3C3C3C);
	ImNodes::PushColorStyle(ImNodesCol_TitleBarHovered, 0xFF3C3C3C);
	ImNodes::PushColorStyle(ImNodesCol_TitleBarSelected, 0xFF3C3C3C);

	ImNodes::PushColorStyle(ImNodesCol_NodeBackground, 0xFF282828);
	ImNodes::PushColorStyle(ImNodesCol_NodeBackgroundHovered, 0xFF282828);
	ImNodes::PushColorStyle(ImNodesCol_NodeBackgroundSelected, 0xFF282828);

	ImNodes::PushColorStyle(ImNodesCol_Pin, 0xFF00FF00);
	ImNodes::PushColorStyle(ImNodesCol_PinHovered, 0xFF00FF00);

	int output_id = node->m_nodeID * 100000;
	int source_id = node->m_nodeID * 100000 + 1;
	int input_id = node->m_nodeID * 1000000 + 10;
	int link_id = node->m_nodeID * 10000000;
	char title[255];
	const char* node_name = Morpheme::getNodeName(network_inspector.target_character, node->m_nodeID);

	sprintf_s(title, "%s_%d", Morpheme::getNodeTypeName_Alt(network_inspector.network, node->m_nodeID), node->m_nodeID);
	if (node_name[0])
		strcpy(title, node_name);

	ImNodes::BeginNode(node->m_nodeID);

	ImNodes::BeginNodeTitleBar();
	ImGui::TextUnformatted(title);
	ImNodes::EndNodeTitleBar();

	ImNodes::BeginOutputAttribute(output_id);
	const float label_width = ImGui::CalcTextSize("Result").x;
	ImGui::Indent(ImGui::CalcTextSize(title).x - label_width);
	ImGui::TextUnformatted("Result");
	ImNodes::EndOutputAttribute();

	ImNodes::PushColorStyle(ImNodesCol_Pin, 0x0000FF00);
	ImNodes::PushColorStyle(ImNodesCol_PinHovered, 0x0000FF00);
	ImNodes::BeginInputAttribute(source_id);
	ImGui::TextUnformatted("");
	ImNodes::EndInputAttribute();
	ImNodes::PopColorStyle();
	ImNodes::PopColorStyle();

	ImNodes::EndNode();

	for (size_t i = 0; i < 8; i++)
		ImNodes::PopColorStyle();
}

inline int ImNodesInterface::getNodeInputPinId(int node, int index)
{
	return (node * 1000000 + 10 + index);
}

inline int ImNodesInterface::getNodeOutputPinId(int node)
{
	return (node * 100000);
}

inline int ImNodesInterface::getNodeSourcePinId(int node, int index)
{
	return (node * 100000 + 1 + index);
}

inline int ImNodesInterface::getNodeLinkPinId(int node, int index)
{
	return (node * 10000000 + index);
}

bool ImNodesInterface::linkMorphemeNodes(int link_id, int src_id, int dst_id)
{
	if (src_id == -1 || dst_id != -1)
		return false;

	ImNodes::Link(link_id, src_id, dst_id);
	return true;
}
