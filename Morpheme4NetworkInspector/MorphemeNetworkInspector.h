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

	bool style_editor = false;
	bool show_demo_window = false;

	uint64_t target_character;
	std::vector<Morpheme::NodeDef*> nodes;
	bool filter_events = true;
	bool get_anim_assets;
	bool eventTrackConfig_scaleToAnim = true;

	ImU64 event_track_node;
	const char* asset_name;

	bool pull_tracks;
	bool clear_tracks;
	bool save_tracks;
};