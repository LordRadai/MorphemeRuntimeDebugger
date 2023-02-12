#pragma once
#include <windows.h>
#include <thread>
#include <io.h>
#include <stdarg.h>
#include <strsafe.h>
#include <d3d11.h>
#include <dxgi.h>
#include <XInput.h>
#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include <DirectXMath.h>
#include <vector>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_internal.h"
#include "imnodes/imnodes.h"
#include "imnodes/imnodes_internal.h"
#include "Timeline.h"
#include "Morpheme.h"

class MorphemeNetworkInspectorGUI
{
public:
	MorphemeNetworkInspectorGUI();
	~MorphemeNetworkInspectorGUI();
	void GUIStyle();
	void RenderGUI(const char* title);
	void ProcessVariables();
	void Dockspace(ImGuiID dockSpace);
	void NetworkCleanup();

	bool style_editor = false;
	bool show_demo_window = false;

	uint64_t target_character;
	bool get_network;
	Morpheme::Network* network;

	struct ControlParameters
	{
		std::vector<Morpheme::NodeDef*> cp_nodes;
		std::vector<Morpheme::NodeBin*> cp_bins;
		std::vector<const char*> cp_names;
	};

	struct AnimEventTrack
	{
		std::vector<Morpheme::NodeDef*> anim_nodes;
		ImU64 event_track_node;
		const char* asset_name;
		float mult;
	};

	struct Messages
	{
		std::vector<int> message_ids;
		std::vector<const char*> message_names;
		std::vector<Morpheme::sMessageDef*> message_defs;
	};

	struct GetNetworkTask
	{
		bool get_nodes;
		bool get_anim_assets;
		bool get_control_params;
		bool get_messages;
	};

	struct NetworkSettings
	{
		bool filter_events = true;
		bool eventTrackConfig_scaleToAnim = true;
	};

	struct ImNodesData
	{
		std::vector<ImVec2> occupied_positions;
		std::vector<int> node_ids;
		std::vector<ImVec2> node_position;
		short node_to_inspect;
		bool is_inspect;
		Morpheme::NodeDef* node_def;
	};

	struct NetworkData
	{
		ControlParameters control_params;
		AnimEventTrack anim_events;
		Messages messages;
		ImNodesData imnodes_data;
		std::vector<const char*> node_names;
		std::vector<Morpheme::NodeDef*> nodes;
	};

	GetNetworkTask network_tasks;
	NetworkData network_data;
	NetworkSettings network_config;

	bool pull_tracks;
	bool clear_tracks;
	bool save_tracks;
};