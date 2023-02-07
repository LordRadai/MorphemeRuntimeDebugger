#include "Morpheme.h"
#include "common.h"

void Morpheme::loadControlParameters()
{

}

void Morpheme::disableMorphemeUpdates(bool state)
{
	if (state)
	{

	}
	else
	{

	}
}

int Morpheme::LoadEventTracks(sEventTrackData* track_base, MorphemeEventTrackList* track_list)
{
	if (!track_base)
		return 0;

	int track_count = 0;
	int index_subBlend = 0;
	int index_subGeneric = 0;
	int index_subUnk = 0;

	if (track_base->m_eventTracks[0].m_trackCount > 0)
	{
		track_count = track_base->m_eventTracks[0].m_trackCount;

		track_list->parent = (uint64_t)track_base;
		track_list->count_discrete = track_count;
		track_list->tracks_discrete = new MorphemeEventTrack[track_count];

		for (int i = 0; i < track_count; i++)
		{
			track_list->tracks_discrete[i].parentId = -1;
			track_list->tracks_discrete[i].childId = -1;
			track_list->tracks_discrete[i].eventCount = track_base->m_eventTracks[0].m_tracks[i]->m_numEvents;
			track_list->tracks_discrete[i].eventId = track_base->m_eventTracks[0].m_tracks[i]->m_eventId;

			track_list->tracks_discrete[i].trackName = track_base->m_eventTracks[0].m_tracks[i]->m_trackName;

			track_list->tracks_discrete[i].startTime = track_base->m_eventTracks[0].m_tracks[i]->m_trackData[0].m_startTime;
			track_list->tracks_discrete[i].duration = track_base->m_eventTracks[0].m_tracks[i]->m_trackData[0].m_duration;
			track_list->tracks_discrete[i].value = track_base->m_eventTracks[0].m_tracks[i]->m_trackData[0].m_userData;
			track_list->tracks_discrete[i].is_discrete = true;
		}

		track_list->count_discreteSub = track_list->getSubTrackcount_discrete();
		track_list->tracks_discreteSub = new MorphemeEventTrack[track_list->count_discreteSub];

		for (int i = 0; i < track_count; i++)
		{
			for (size_t j = 1; j < track_list->tracks_discrete[i].eventCount; j++)
			{
				if (index_subBlend < track_list->count_discreteSub)
				{
					track_list->tracks_discreteSub[index_subBlend].parentId = i;
					track_list->tracks_discreteSub[index_subBlend].childId = j;
					track_list->tracks_discreteSub[index_subBlend].eventCount = 1;
					track_list->tracks_discreteSub[index_subBlend].eventId = track_list->tracks_discrete[i].eventId;
					track_list->tracks_discreteSub[index_subBlend].trackName = track_list->tracks_discrete[i].trackName;

					track_list->tracks_discreteSub[index_subBlend].startTime = track_base->m_eventTracks[0].m_tracks[i]->m_trackData[j].m_startTime;
					track_list->tracks_discreteSub[index_subBlend].duration = track_base->m_eventTracks[0].m_tracks[i]->m_trackData[j].m_duration;
					track_list->tracks_discreteSub[index_subBlend].value = track_base->m_eventTracks[0].m_tracks[i]->m_trackData[j].m_userData;
					track_list->tracks_discreteSub[index_subBlend].is_discrete = true;
					index_subBlend++;
				}
			}		
		}
	}

	if (track_base->m_eventTracks[1].m_trackCount > 0)
	{
		printf_s("[INFO, MorphemeSystem] This EventTrack has tracks of an unknown type\n");

		track_count = track_base->m_eventTracks[1].m_trackCount;

		track_list->parent = (uint64_t)track_base;
		track_list->count_unk = track_count;
		track_list->tracks_unk = new MorphemeEventTrack[track_count];

		for (int i = 0; i < track_count; i++)
		{
			track_list->tracks_unk[i].parentId = -1;
			track_list->tracks_unk[i].childId = -1;
			track_list->tracks_unk[i].eventCount = track_base->m_eventTracks[1].m_tracks[i]->m_numEvents;
			track_list->tracks_unk[i].eventId = track_base->m_eventTracks[1].m_tracks[i]->m_eventId;

			track_list->tracks_unk[i].trackName = track_base->m_eventTracks[1].m_tracks[i]->m_trackName;

			track_list->tracks_unk[i].startTime = track_base->m_eventTracks[1].m_tracks[i]->m_trackData[0].m_startTime;
			track_list->tracks_unk[i].duration = track_base->m_eventTracks[1].m_tracks[i]->m_trackData[0].m_duration;
			track_list->tracks_unk[i].value = track_base->m_eventTracks[1].m_tracks[i]->m_trackData[0].m_userData;
			track_list->tracks_unk[i].is_discrete = false;
		}

		track_list->count_unkSub = track_list->getSubTrackcount_unk();
		track_list->tracks_unkSub = new MorphemeEventTrack[track_list->count_timedSub];

		for (int i = 0; i < track_count; i++)
		{
			for (size_t j = 1; j < track_list->tracks_unk[i].eventCount; j++)
			{
				if (index_subUnk < track_list->count_unkSub)
				{
					track_list->tracks_unkSub[index_subUnk].parentId = i;
					track_list->tracks_unkSub[index_subUnk].childId = j;
					track_list->tracks_unkSub[index_subUnk].eventCount = 1;
					track_list->tracks_unkSub[index_subUnk].eventId = track_list->tracks_timed[i].eventId;
					track_list->tracks_unkSub[index_subUnk].trackName = track_list->tracks_timed[i].trackName;

					track_list->tracks_unkSub[index_subUnk].startTime = track_base->m_eventTracks[1].m_tracks[i]->m_trackData[j].m_startTime;
					track_list->tracks_unkSub[index_subUnk].duration = track_base->m_eventTracks[1].m_tracks[i]->m_trackData[j].m_duration;
					track_list->tracks_unkSub[index_subUnk].value = track_base->m_eventTracks[1].m_tracks[i]->m_trackData[j].m_userData;
					track_list->tracks_unkSub[index_subUnk].is_discrete = false;
					index_subUnk++;
				}
			}
		}
	}

	if (track_base->m_eventTracks[2].m_trackCount > 0)
	{
		track_count = track_base->m_eventTracks[2].m_trackCount;

		track_list->parent = (uint64_t)track_base;
		track_list->count_timed = track_count;
		track_list->tracks_timed = new MorphemeEventTrack[track_count];

		for (int i = 0; i < track_count; i++)
		{
			track_list->tracks_timed[i].parentId = -1;
			track_list->tracks_timed[i].childId = -1;
			track_list->tracks_timed[i].eventCount = track_base->m_eventTracks[2].m_tracks[i]->m_numEvents;
			track_list->tracks_timed[i].eventId = track_base->m_eventTracks[2].m_tracks[i]->m_eventId;

			track_list->tracks_timed[i].trackName = track_base->m_eventTracks[2].m_tracks[i]->m_trackName;

			track_list->tracks_timed[i].startTime = track_base->m_eventTracks[2].m_tracks[i]->m_trackData[0].m_startTime;
			track_list->tracks_timed[i].duration = track_base->m_eventTracks[2].m_tracks[i]->m_trackData[0].m_duration;
			track_list->tracks_timed[i].value = track_base->m_eventTracks[2].m_tracks[i]->m_trackData[0].m_userData;
			track_list->tracks_timed[i].is_discrete = false;
		}

		track_list->count_timedSub = track_list->getSubTrackcount_timed();
		track_list->tracks_timedSub = new MorphemeEventTrack[track_list->count_timedSub];

		for (int i = 0; i < track_count; i++)
		{
			for (size_t j = 1; j < track_list->tracks_timed[i].eventCount; j++)
			{
				if (index_subGeneric < track_list->count_timedSub)
				{
					track_list->tracks_timedSub[index_subGeneric].parentId = i;
					track_list->tracks_timedSub[index_subGeneric].childId = j;
					track_list->tracks_timedSub[index_subGeneric].eventCount = 1;
					track_list->tracks_timedSub[index_subGeneric].eventId = track_list->tracks_timed[i].eventId;
					track_list->tracks_timedSub[index_subGeneric].trackName = track_list->tracks_timed[i].trackName;

					track_list->tracks_timedSub[index_subGeneric].startTime = track_base->m_eventTracks[2].m_tracks[i]->m_trackData[j].m_startTime;
					track_list->tracks_timedSub[index_subGeneric].duration = track_base->m_eventTracks[2].m_tracks[i]->m_trackData[j].m_duration;
					track_list->tracks_timedSub[index_subGeneric].value = track_base->m_eventTracks[2].m_tracks[i]->m_trackData[j].m_userData;
					track_list->tracks_timedSub[index_subGeneric].is_discrete = false;
					index_subGeneric++;
				}
			}
		}
	}

	return track_count;
}

void Morpheme::ClearTrackList(MorphemeEventTrackList* track_list)
{
	track_list->parent = 0;
	track_list->count_discrete = 0;
	track_list->count_timed = 0;
	delete[] track_list->tracks_discrete;
	delete[] track_list->tracks_timed;
	delete[] track_list->tracks_discreteSub;
	delete[] track_list->tracks_timedSub;
}

void Morpheme::SaveEventTracks(MorphemeEventTrackList* track_list)
{
	sEventTrackData* track_base;
	uint64_t track_data;
	uint64_t* list;
	int index_subBlend = 0;
	int index_subGeneric = 0;

	if (!track_list)
	{
		printf_s("[ERROR, MorphemeSyste] EventTrack save task failed. Input is nullptr\n");
		return;
	}

	if (track_list->parent)
	{
		track_base = (sEventTrackData*)track_list->parent;

		if (track_list->count_discrete > 0)
		{
			for (int i = 0; i < track_list->count_discrete; i++)
			{
				track_base->m_eventTracks[0].m_tracks[i]->m_numEvents = track_list->tracks_discrete[i].eventCount;
				track_base->m_eventTracks[0].m_tracks[i]->m_eventId = track_list->tracks_discrete[i].eventId;

				track_base->m_eventTracks[0].m_tracks[i]->m_trackData[0].m_startTime = track_list->tracks_discrete[i].startTime;
				track_base->m_eventTracks[0].m_tracks[i]->m_trackData[0].m_duration = track_list->tracks_discrete[i].duration;
				track_base->m_eventTracks[0].m_tracks[i]->m_trackData[0].m_userData = track_list->tracks_discrete[i].value;

				for (size_t j = 1; j < track_list->tracks_discrete[i].eventCount; j++)
				{
					if (index_subBlend < track_list->count_discreteSub)
					{
						track_base->m_eventTracks[0].m_tracks[i]->m_trackData[j].m_startTime = track_list->tracks_discreteSub[index_subBlend].startTime;
						track_base->m_eventTracks[0].m_tracks[i]->m_trackData[j].m_duration = track_list->tracks_discreteSub[index_subBlend].duration;
						track_base->m_eventTracks[0].m_tracks[i]->m_trackData[j].m_userData = track_list->tracks_discreteSub[index_subBlend].value;
						index_subBlend++;
					}
				}
			}
		}

		if (track_list->count_timed > 0)
		{	
			for (int i = 0; i < track_list->count_timed; i++)
			{

				track_base->m_eventTracks[2].m_tracks[i]->m_numEvents = track_list->tracks_timed[i].eventCount;
				track_base->m_eventTracks[2].m_tracks[i]->m_eventId = track_list->tracks_timed[i].eventId;

				track_base->m_eventTracks[2].m_tracks[i]->m_trackData[0].m_startTime = track_list->tracks_timed[i].startTime;
				track_base->m_eventTracks[2].m_tracks[i]->m_trackData[0].m_duration = track_list->tracks_timed[i].duration;
				track_base->m_eventTracks[2].m_tracks[i]->m_trackData[0].m_userData = track_list->tracks_timed[i].value;

				for (size_t j = 1; j < track_list->tracks_timed[i].eventCount; j++)
				{
					if (index_subGeneric < track_list->count_timedSub)
					{
						track_base->m_eventTracks[2].m_tracks[i]->m_trackData[j].m_startTime = track_list->tracks_timedSub[index_subGeneric].startTime;
						track_base->m_eventTracks[2].m_tracks[i]->m_trackData[j].m_duration = track_list->tracks_timedSub[index_subGeneric].duration;
						track_base->m_eventTracks[2].m_tracks[i]->m_trackData[j].m_userData = track_list->tracks_timedSub[index_subGeneric].value;
						index_subGeneric++;
					}
				}
			}
		}
	}
}

const char* Morpheme::getStringFromStringTable(StringTable* string_table, int id)
{
	//printf_s("String Table: %llx\n", string_table);
	//printf_s("\tm_numEntrys: %d\n", string_table->m_NumEntrys);

	if (id > string_table->m_NumEntrys)
	{	
		printf_s("[ERR, MorphemeSystem] ID %d is OOB. Maximum is %d\n", id, string_table->m_NumEntrys);
		return NULL;
	}

	//printf_s("Offset: %d\n", string_table->m_Offsets[id]);

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

void Morpheme::getNetworkAllNodesName(uint64_t character_ctrl)
{
	if (character_ctrl && *(uint64_t*)(character_ctrl + 0xF8))
	{
		FILE* fp;
		char filename[50];
		const char* string;
		uint64_t tmp = *(uint64_t*)(character_ctrl + 0xF8);
		tmp = *(uint64_t*)(tmp + 0x28);
		tmp = *(uint64_t*)(tmp + 0x20);
		tmp = *(uint64_t*)(tmp);
		StringTable* node_names = *(StringTable**)(tmp + 0xC8);

		sprintf(filename, ".//DebugManager//out//Nodes_c%i.txt", *(int*)(character_ctrl + 0x28));
		if (fp = fopen(filename, "w"))
		{
			for (size_t i = 0; i < node_names->m_NumEntrys; i++)
			{
				string = getStringFromStringTable(node_names, i);

				if (string)
					fprintf_s(fp, "%i:%s\n", node_names->m_IDs[i], string);
			}

			fclose(fp);
		}
		else
			MessageBoxA(NULL, "Write to file failed. Couldn't find 'out' folder.", "AppDebugManager", MB_ICONERROR);
	}
}

void Morpheme::getNetworkAllMessagesName(uint64_t character_ctrl)
{
	if (character_ctrl && *(uint64_t*)(character_ctrl + 0xF8))
	{
		FILE* fp;
		char filename[50];
		const char* string;
		uint64_t tmp = *(uint64_t*)(character_ctrl + 0xF8);
		tmp = *(uint64_t*)(tmp + 0x28);
		tmp = *(uint64_t*)(tmp + 0x20);
		tmp = *(uint64_t*)(tmp);
		StringTable* message_names = *(StringTable**)(tmp + 0xD0);

		sprintf(filename, ".//DebugManager//out//Messages_c%i.txt", *(int*)(character_ctrl + 0x28));
		if (fp = fopen(filename, "w"))
		{
			for (size_t i = 0; i < message_names->m_NumEntrys; i++)
			{
				string = getStringFromStringTable(message_names, i);

				if (string)
					fprintf_s(fp, "%i:%s\n", message_names->m_IDs[i], string);
			}

			fclose(fp);
		}
		else
			MessageBoxA(NULL, "Write to file failed. Couldn't find 'out' folder.", "AppDebugManager", MB_ICONERROR);
	}
}

void Morpheme::getNetworkAllEventTracksName(uint64_t character_ctrl)
{
	if (character_ctrl && *(uint64_t*)(character_ctrl + 0xF8))
	{
		FILE* fp;
		char filename[50];
		const char* string;
		uint64_t tmp = *(uint64_t*)(character_ctrl + 0xF8);
		tmp = *(uint64_t*)(tmp + 0x28);
		tmp = *(uint64_t*)(tmp + 0x20);
		tmp = *(uint64_t*)(tmp);
		StringTable* event_track_names = *(StringTable**)(tmp + 0xD8);

		sprintf(filename, ".//DebugManager//out//EventTrackTypes_c%i.txt", *(int*)(character_ctrl + 0x28));
		if (fp = fopen(filename, "w"))
		{
			for (size_t i = 0; i < event_track_names->m_NumEntrys; i++)
			{
				string = getStringFromStringTable(event_track_names, i);

				if (string)
					fprintf_s(fp, "%i:%s\n", event_track_names->m_IDs[i], string);
			}

			fclose(fp);
		}
		else
			MessageBoxA(NULL, "Write to file failed. Couldn't find 'out' folder.", "AppDebugManager", MB_ICONERROR);
	}
}

void Morpheme::getNetworkAllNames(uint64_t character_ctrl)
{
	getNetworkAllNodesName(character_ctrl);
	getNetworkAllMessagesName(character_ctrl);
	getNetworkAllEventTracksName(character_ctrl);
}

/*
void Morpheme::printBoneList(uint64_t character_ctrl)
{
	if (character_ctrl == 0)
		return;

	FILE* fp;
	char filename[255];

	int bone_count = *(int*)(*(uint64_t*)(character_ctrl + 0xF0) + 0x90);
	//printf_s("[%llX] Bone Count: %d\n", character_ctrl, bone_count);

	uint64_t character_model_ctrl = *(uint64_t*)(character_ctrl + 0xF0);
	uint64_t mdl_skeleton = *(uint64_t*)(character_model_ctrl + 0x88);
	uint64_t morpheme_skeleton = *(uint64_t*)(mdl_skeleton + 0x20);
	uint64_t bone_data = morpheme_skeleton;

	sprintf(filename, ".//DebugManager//out//skeleton//c%d_skeleton.txt", *(int*)(character_ctrl + 0x2C));
	if (fp = fopen(filename, "w"))
	{
		for (size_t i = 0; i < bone_count; i++)
		{
			bone_data = morpheme_skeleton + (byte)i * 0x10;

			short bone_id = *(int*)(bone_data + 0x4);
			char* bone_name = new char[255];
			StringParser::convertString(*(char**)(bone_data + 0x8), bone_name);

			//printf_s("[%d] %s\n", (int)i, bone_name);
			fprintf_s(fp, "%d:%s\n", (int)i, bone_name);

			delete[] bone_name;
		}

		fclose(fp);
	}
	else
		MessageBoxA(NULL, "Write to file failed. Couldn't find 'out/skeleton' folder.", "AppDebugManager", MB_ICONERROR);	
}

void Morpheme::loadBoneData(uint64_t character_ctrl, sBoneData buffer[])
{
	if (character_ctrl)
	{
		uint64_t character_model_ctrl = *(uint64_t*)(character_ctrl + 0xF0);
		uint64_t mdl_skeleton = *(uint64_t*)(character_model_ctrl + 0x88);
		int bone_count = *(uint64_t*)(character_model_ctrl + 0x90);

		uint64_t morpheme_skeleton;

		for (size_t i = 0; i < bone_count; i++)
		{
			morpheme_skeleton = *(uint64_t*)(mdl_skeleton + 0x20) + (byte)i * 0x10;

			buffer[i].unk00 = *(short*)(morpheme_skeleton);
			buffer[i].unk02 = *(short*)(morpheme_skeleton + 0x2);
			buffer[i].unk04 = *(short*)(morpheme_skeleton + 0x4);
			buffer[i].unk06 = *(short*)(morpheme_skeleton + 0x6);
			StringParser::convertString(*(char**)(morpheme_skeleton + 0x8), buffer[i].name);
		}
	}
}

void Morpheme::getCategoryInfo(int category_id, char buffer[])
{
	INIReader reader(".//DebugManager//res//morpheme//EventTrack//morpheme_events.ini");

	if (reader.ParseError() < 0)
	{
		MessageBoxA(NULL, "Failed to load morpheme_events.ini", "AppDebugManager", MB_ICONERROR);

		strcpy(buffer, "Unknown Event");
		return;
	}

	char event_id[32];

	sprintf(event_id, "%d", category_id);

	std::string name = reader.GetString("EventTrackCategory", event_id, "Unknown Event");

	strcpy(buffer, name.c_str());

	return;
}

void Morpheme::getValueInfo(int category, int value, char buffer[])
{
	INIReader reader(".//DebugManager//res//morpheme//EventTrack//morpheme_events.ini");

	if (reader.ParseError() < 0)
	{
		MessageBoxA(NULL, "Failed to load morpheme_events.ini", "AppDebugManager", MB_ICONERROR);

		strcpy(buffer, "Unknown Event");
		return;
	}

	char section[32];
	char event_id[32];
	char event_unk[32];

	sprintf(section, "Value%d", category);
	sprintf(event_id, "%d", value);
	sprintf(event_unk, "Unknown Event %d", value);

	std::string name = reader.GetString(section, event_id, event_unk);

	strcpy(buffer, name.c_str());

	return;
}*/

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
	if (!network)
		return NULL;

	return network->m_networkDef->m_nodes[node_id];
}

std::vector<Morpheme::NodeDef*> Morpheme::getNetworkAllNodesType(uint64_t character_ctrl, NodeType node_type)
{
	Network* network = getNetwork(character_ctrl);
	std::vector<Morpheme::NodeDef*> nodes;

	if (!network)
		return nodes;

	for (size_t i = 0; i < network->m_networkDef->m_numNodes; i++)
	{
		if (node_type == NodeType::NodeAnimSyncEvents && network_inspector.filter_events)
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
	if (node->m_nodeTypeID != NodeType::NodeAnimSyncEvents)
	{
		printf_s("[ERR, MorphemeSystem] Node %d is not an Animation node\n", node->m_nodeID);
		return NULL;
	}

	NodeData104* node_data = (NodeData104*)node->node_data;
	uint64_t nsa_file = node_data->m_animData;

	nsa_file = *(uint64_t*)(nsa_file + 0x10);

	const char* animFileName = (const char*)(*(uint64_t*)(nsa_file - 0x8) + 0xD);

	return animFileName;
}