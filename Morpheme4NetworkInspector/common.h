#pragma once
#include "MorphemeNetworkInspector.h"
#include "Timeline.h"

extern HMODULE ModuleAddr;
extern uint64_t GameManagerImp;
extern uint64_t BaseB;
extern uint64_t KatanaMainApp;

extern bool create_network_inspector;
extern MorphemeNetworkInspectorGUI network_inspector;
extern MorphemeEventTrackList track_list;
extern EventTrackEditor event_track_editor;