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
	std::vector<ImU64> anim_assets;
	bool filter_events;

	ImU64 event_track_node;

	bool pull_tracks;
	bool clear_tracks;
	bool save_tracks;

	float animLenght;
	float trackLenght;
	float multiplier;
	const char* animFileName = "";

	MorphemeEventTrackList track_list;
	EventTrackEditor event_track_editor;
};