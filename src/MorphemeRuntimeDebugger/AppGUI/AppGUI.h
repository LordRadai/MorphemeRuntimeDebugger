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

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx11.h"
#include "../imgui/imgui_internal.h"
#include "../imnodes/imnodes.h"
#include "../imnodes/imnodes_internal.h"
#include "../Morpheme/Morpheme.h"
#include "../TimeAct/TimeAct.h"

class AppGUI
{
public:
	AppGUI();
	~AppGUI();
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

	struct View
	{
		bool attributes = true;
		bool nodes = true;
	};

	struct ControlParameters
	{
		std::vector<Morpheme::NodeDef*> cp_nodes;
		std::vector<Morpheme::NodeBin*> cp_bins;
		std::vector<const char*> cp_names;
	};

	struct AnimTimeAct
	{
		uint64_t pl_tae;
		uint64_t sfx_tae;
		uint64_t snd_tae;

		uint32_t current_tae;
	};

	struct AnimEventTrack
	{
		std::vector<Morpheme::NodeDef*> anim_nodes;
		ImU64 event_track_node;
		const char* asset_name;
		AnimTimeAct anim_tae;
		float anim_len;
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
		Morpheme::NodeDef* selected_node;

		short parent_id;
		Morpheme::NodeDef* parent_node;

		ImNodesEditorContext* current_editor;
		std::vector<ImNodesEditorContext*> editors;
	};

	struct NetworkData
	{
		ControlParameters control_params;
		AnimEventTrack anim_events;
		Messages messages;
		ImNodesData imnodes_data;
		std::vector<const char*> node_names;
		std::vector<Morpheme::NodeDef*> nodes;
		bool is_load = false;
		bool is_save = false;
	};

	struct GameDebug
	{
		bool* m_disableAi;
		bool m_disableCPUpdates;
	} m_gameDebugFlags;

	View m_view;
	GetNetworkTask m_networkTasks;
	NetworkData m_networkData;
	NetworkSettings m_networkConfig;

	bool m_clearNetwork = false;
	bool m_loadTracks;
	bool m_clearTracks;
	bool m_saveTracks;
	int m_selectedIndex;
};