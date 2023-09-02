#include "Morpheme.h"
#include "../common.h"
#include "../Debug/Debug.h"
#include "../MathHelper/MathHelper.h"

const char* Morpheme::getStringFromStringTable(StringTable* string_table, int id)
{
	if (id > string_table->m_NumEntrys)
	{	
		printf_s("[ERR, MorphemeSystem] ID %d is OOB. Maximum is %d\n", id, string_table->m_NumEntrys);
		return NULL;
	}

	return (string_table->m_Data + string_table->m_Offsets[id]);
}

const char* Morpheme::getNetworkNodeName(uint64_t character_ctrl, int id)
{
	if (character_ctrl && *(uint64_t*)(character_ctrl + 0xF8))
	{
		const char* string;
		uint64_t tmp = *(uint64_t*)(character_ctrl + 0xF8);
		tmp = *(uint64_t*)(tmp + 0x28);
		tmp = *(uint64_t*)(tmp + 0x20);
		tmp = *(uint64_t*)(tmp);
		StringTable* node_names = *(StringTable**)(tmp + 0xC8);

		string = getStringFromStringTable(node_names, id);

		printf_s("%s\n", string);

		return string;
	}

	return NULL; 
}

const char* Morpheme::getNetworkMessageName(uint64_t character_ctrl, int id)
{
	if (character_ctrl && *(uint64_t*)(character_ctrl + 0xF8))
	{
		const char* string;
		uint64_t tmp = *(uint64_t*)(character_ctrl + 0xF8);
		tmp = *(uint64_t*)(tmp + 0x28);
		tmp = *(uint64_t*)(tmp + 0x20);
		tmp = *(uint64_t*)(tmp);
		StringTable* message_names = *(StringTable**)(tmp + 0xD0);

		string = getStringFromStringTable(message_names, id);

		printf_s("%s\n", string);

		return string;
	}

	return NULL;
}

const char* Morpheme::getNetworkEventTrackName(uint64_t character_ctrl, int id)
{
	if (character_ctrl && *(uint64_t*)(character_ctrl + 0xF8))
	{
		const char* string;
		uint64_t tmp = *(uint64_t*)(character_ctrl + 0xF8);
		tmp = *(uint64_t*)(tmp + 0x28);
		tmp = *(uint64_t*)(tmp + 0x20);
		tmp = *(uint64_t*)(tmp);
		StringTable* event_track_names = *(StringTable**)(tmp + 0xD8);

		string = getStringFromStringTable(event_track_names, id);

		printf_s("%s\n", string);

		return string;
	}

	return NULL;
}

Morpheme::Network* Morpheme::getNetwork(uint64_t character_ctrl)
{
	if (!character_ctrl)
		return NULL;

	if (*(uint64_t*)(character_ctrl + 0xF8) == NULL)
		return NULL;

	uint64_t chr_motion_ctrl = *(uint64_t*)(character_ctrl + 0xF8);

	if (*(uint64_t*)(chr_motion_ctrl + 0x28) == NULL)
		return NULL;
	
	uint64_t morpheme_motion_ctrl = *(uint64_t*)(chr_motion_ctrl + 0x28);

	if (*(Network**)(morpheme_motion_ctrl + 0x20) == NULL)
		return NULL;

	Network* network = *(Network**)(morpheme_motion_ctrl + 0x20);

	return network;
}

Morpheme::NodeDef* Morpheme::getNetworkNode(Network* network, short node_id)
{
	if (!network || !doesNodeExist(network, node_id))
		return NULL;

	return network->m_networkDef->m_nodes[node_id];
}

std::vector<Morpheme::NodeDef*> Morpheme::getNetworkAllNodesType(uint64_t character_ctrl, NodeType node_type)
{
	Network* network = getNetwork(character_ctrl);
	std::vector<Morpheme::NodeDef*> nodes;

	Debug::DebuggerMessage(Debug::LVL_DEBUG, "CharacterCtrl: %llX, Network: %llX\n", character_ctrl, network);

	if (!network)
		return nodes;

	for (size_t i = 0; i < network->m_networkDef->m_numNodes; i++)
	{
		if (node_type == NodeType::NodeType_NodeAnimSyncEvents && g_morphemeDebugger.m_networkConfig.filter_events)
		{
			if (network->m_networkDef->m_nodes[i]->m_nodeTypeID == node_type)
			{
				NodeData104* node_data = (NodeData104*)network->m_networkDef->m_nodes[i]->node_data;

				uint32_t event_track_count = node_data->m_eventTrackData->m_eventTracks[0].m_trackCount + node_data->m_eventTrackData->m_eventTracks[1].m_trackCount + node_data->m_eventTrackData->m_eventTracks[2].m_trackCount;
				if (event_track_count > 0)
					nodes.push_back(network->m_networkDef->m_nodes[i]);
			}
		}	
		else if (network->m_networkDef->m_nodes[i]->m_nodeTypeID == node_type)
			nodes.push_back(network->m_networkDef->m_nodes[i]);
	}

	return nodes;
}

const char* Morpheme::getAnimNameFromAnimNode(NodeDef* node)
{
	if (node->m_nodeTypeID != NodeType::NodeType_NodeAnimSyncEvents)
	{
		Debug::DebuggerMessage(Debug::LVL_ERROR, "Node %d is not an Animation node\n", node->m_nodeID);
		return NULL;
	}

	NodeData104* node_data = (NodeData104*)node->node_data;
	uint64_t nsa_file = (uint64_t)node_data->m_animData;

	nsa_file = *(uint64_t*)(nsa_file + 0x10);

	const char* animFileName = (const char*)(*(uint64_t*)(nsa_file - 0x8) + 0xD);

	return animFileName;
}

std::vector<Morpheme::NodeDef*> Morpheme::getNetworkControlParameterNodes(uint64_t character_ctrl)
{
	std::vector<Morpheme::NodeDef*> cp_nodes;

	for (size_t i = 0; i < g_morphemeDebugger.network->m_networkDef->m_numNodes; i++)
		if (g_morphemeDebugger.network->m_networkDef->m_nodes[i]->m_nodeTypeID == NodeType::NodeType_ControlParameterFloat || g_morphemeDebugger.network->m_networkDef->m_nodes[i]->m_nodeTypeID == NodeType::NodeType_ControlParameterInt || g_morphemeDebugger.network->m_networkDef->m_nodes[i]->m_nodeTypeID == NodeType::NodeType_ControlParameterVector3 || g_morphemeDebugger.network->m_networkDef->m_nodes[i]->m_nodeTypeID == NodeType::NodeType_ControlParameterBool)
			cp_nodes.push_back(g_morphemeDebugger.network->m_networkDef->m_nodes[i]);

	return cp_nodes;
}

const char* Morpheme::stringTableLookup(StringTable* table, short id)
{
	if (id != -1)
	{
		const char* names = table->m_Data;
		return names + table->m_Offsets[id];
	}
	return "";
}

const char* Morpheme::getNodeName(uint64_t character_ctrl, short node_id)
{
	Morpheme::Network* network = Morpheme::getNetwork(character_ctrl);

	if (doesNodeExist(network, node_id))
	{
		StringTable* string_table = network->m_networkDef->m_nodeIDNamesTable;
		return stringTableLookup(string_table, node_id);
	}

	return "";
}

const char* Morpheme::getMessageName(uint64_t character_ctrl, short message_id)
{
	if (message_id != -1)
	{
		Morpheme::Network* network = Morpheme::getNetwork(character_ctrl);

		StringTable* string_table = network->m_networkDef->m_requestIDNamesTable;
		return stringTableLookup(string_table, message_id);
	}

	return "";
}

Morpheme::NodeBin* Morpheme::getNetworkNodeBin(Network* network, short node_id)
{
	if (doesNodeExist(network, node_id))
		return &network->m_nodeBins[node_id];
	
	return NULL;
}

std::vector<Morpheme::sMessageDef*> Morpheme::getMessageDefs(uint64_t character_ctrl)
{
	Morpheme::Network* network = Morpheme::getNetwork(character_ctrl);
	std::vector<sMessageDef*> message_defs;

	for (size_t i = 0; i < network->m_networkDef->message_count; i++)
		message_defs.push_back(network->m_networkDef->message_def[i]);

	return message_defs;
}

bool Morpheme::isNodeActive(Network* network, short node_id)
{
	if (doesNodeExist(network, node_id))
		if ((network->m_nodeConnections[node_id]->flags_1 & 2) >> 1)
			return true;

	return false;
}

bool Morpheme::isNodeContainer(Network* network, short node_id)
{
	if (doesNodeExist(network, node_id))
		if ((network->m_networkDef->m_nodes[node_id]->m_flags1 & 16) >> 4)
			return true;

	return false;
}

bool Morpheme::isNodeConnectedToOutput(Network* network, short node_id)
{
	if (doesNodeExist(network, node_id))
		if ((network->m_networkDef->m_nodes[node_id]->m_flags2 & 64) >> 6)
			return true;

	return false;
}


const char* Morpheme::getNodeTypeName_Alt(Morpheme::Network* network, short node_id)
{
	if (network)
	{
		if (doesNodeExist(network, node_id))
		{
			int node_type = network->m_networkDef->m_nodes[node_id]->m_nodeTypeID;

			switch (node_type)
			{
			case 9:
				return "Network";
			case 10:
				return "StateMachine";
			case 20:
				return "CP_Float";
			case 21:
				return "CP_Vector3";
			case 23:
				return "CP_Bool";
			case 24:
				return "CP_Int";
			case 104:
				return "AnimSyncEvents";
			case 105:
				return "ShareChildren_105";
			case 107:
				return "Blend2SyncEvents";
			case 108:
				return "Blend2Additive_108";
			case 109:
				return "Share1Child1InputCP_109";
			case 110:
				return "ShareCreateFloatOutputAttribute_110";
			case 112:
				return "ShareCreateFloatOutputAttribute_112";
			case 114:
				return "Blend2Additive_114";
			case 120:
				return "TwoBoneIK";
			case 121:
				return "LockFoot";
			case 122:
				return "ShareChildren1CompulsoryManyOptionalInputCPs_120";
			case 125:
				return "Share1Child1InputCP_125";
			case 126:
				return "Freeze";
			case 129:
				return "ShareChildrenOptionalInputCPs";
			case 131:
				return "Switch";
			case 134:
				return "ShareChildren_134";
			case 135:
				return "ShareChildren_135";
			case 136:
				return "Share1Child2OptionalInputCP";
			case 138:
				return "PredictiveUnevenTerrain";
			case 142:
				return "OperatorSmoothDamp";
			case 144:
				return "ShareCreateVector3OutputAttribute";
			case 146:
				return "OperatorRandomFloat";
			case 150:
				return "ShareChildren1CompulsoryManyOptionalInputCPs_150";
			case 151:
				return "ShareChild1InputCP_151";
			case 153:
				return "ShareChildren_153";
			case 170:
				return "SubtractiveBlend";
			case 400:
				return "TransitSyncEvents";
			case 402:
				return "Transit";
			case 500:
				return "Share1Child1OptionalInputCP";
			default:
				char name[255];
				sprintf_s(name, "NodeType_%d", node_type);
				return name;
			}
		}
	}

	return "";
}

const char* Morpheme::getNodeTypeName(Morpheme::Network* network, short node_id)
{
	INIReader node_type(".//MorphemeRuntimeDebugger//res//NodeType.ini");

	if (node_type.ParseError() < 0)
	{
		MessageBoxA(NULL, "Failed to load NodeType.ini", "MorphemeNetworkInspector", MB_ICONERROR);

		return "";
	}
	char typeID_unk[32];
	char typeID[4];
	sprintf_s(typeID, "%d", network->m_networkDef->m_nodes[node_id]->m_nodeTypeID);
	sprintf_s(typeID_unk, "NodeType_%d", network->m_networkDef->m_nodes[node_id]->m_nodeTypeID);

	std::string typeName = node_type.GetString("NodeType", typeID, typeID_unk);

	return typeName.c_str();
}

bool Morpheme::doesNodeExist(Network* network, short node_id)
{
	if (node_id != -1 && network)
	{
		if (node_id <= network->m_networkDef->m_numNodes)
			return true;
	}
	
	Debug::DebuggerMessage(Debug::LVL_INFO, "Node %d is not present in the current Network\n", node_id);
	return false;
}

uint32_t Morpheme::getTimeActId(Morpheme::NodeDef* node_def)
{
	if (node_def->m_nodeTypeID == NodeType::NodeType_NodeAnimSyncEvents)
	{
		Morpheme::NodeData104* node_data = (Morpheme::NodeData104*)node_def->node_data;

		for (size_t i = 0; i < node_data->m_eventTrackData->m_eventTracks[2].m_trackCount; i++)
		{
			if (node_data->m_eventTrackData->m_eventTracks[2].m_tracks[i]->m_eventId == 1000)
				return node_data->m_eventTrackData->m_eventTracks[2].m_tracks[i]->m_trackData[0].m_userData;
		}	
		MessageBoxA(NULL, "Animation has no TAE associated to it", "MorphemeNetworkInspector", MB_ICONINFORMATION);
		return 0;
	}
	
	MessageBoxA(NULL, "Node is not an animation node", "MorphemeNetworkInspector", MB_ICONERROR);
	return 0;
}

Morpheme::NodeConnections* Morpheme::getNetworkNodeConnections(Morpheme::Network* network, short node_id)
{
	if (doesNodeExist(network, node_id))
		return network->m_nodeConnections[node_id];

	return NULL;
}

int Morpheme::getCurrentAnimFrame(Morpheme::Network* network, short node_id)
{
	if (network)
	{
		if (doesNodeExist(network, node_id))
		{
			NodeDef* node_def = getNetworkNode(network, node_id);

			if (node_def && node_def->m_nodeTypeID != NodeType_NodeAnimSyncEvents)
			{
				Debug::DebuggerMessage(Debug::LVL_ERROR, "Node %d is not an animation node\n", node_def->m_nodeID);
				return 0;
			}

			int current_frame = 0;

			Morpheme::NodeData104* node_data = (Morpheme::NodeData104*)node_def->node_data;

			uint64_t nsaFile = (uint64_t)node_data->m_animData;

			float track_len = *(float*)(nsaFile + 0x84);
			float anim_len = *(float*)(nsaFile + 0x88);

			float current_time = 0;
			float mult = 1;

			NodeBin* node_bin = getNetworkNodeBin(network, node_id);

			if (node_bin && node_bin->m_attributes)
			{
				for (NodeBinEntry* current_bin_entry = node_bin->m_attributes; current_bin_entry != NULL; current_bin_entry = current_bin_entry->m_next)
				{
					if (current_bin_entry->m_semantic == ATTRIB_SEMANTIC_FRACTION_POS)
					{
						current_time = (float)current_bin_entry->m_attribDataHandle->field7_0x18;
						//Debug::DebuggerMessage(Debug::LVL_DEBUG, "UpdateTimePos = (%.3f, %.3f, %.3f, %.3f)\n", *(float*)&current_bin_entry->m_attribDataHandle->m_activeStateID, current_bin_entry->m_attribDataHandle->field6_0x14, current_bin_entry->m_attribDataHandle->field7_0x18, *(float*)&current_bin_entry->m_attribDataHandle->field11_0x1c);
						break;
					}
				}

				if (g_morphemeDebugger.m_networkConfig.eventTrackConfig_scaleToAnim)
					mult = anim_len / track_len;

				current_time *= mult;
				current_frame = MathHelper::TimeToFrame(current_time, 60);
			}

			return current_frame;
		}
	}
	
	return 0;
}