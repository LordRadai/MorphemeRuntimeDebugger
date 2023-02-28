#pragma once
#define PI 3.14159265358979323846

#include "MorphemeNetworkInspector.h"
#include "Timeline.h"

extern HMODULE ModuleAddr;
extern uint64_t GameManagerImp;
extern uint64_t BaseB;
extern uint64_t KatanaMainApp;
extern int game_state;
extern int prev_game_state;

extern bool create_network_inspector;
extern MorphemeNetworkInspectorGUI network_inspector;
extern MorphemeEventTrackList track_list;
extern EventTrackEditor event_track_editor;
extern TimeActTrackList tae_track_list;
extern EventTrackEditor time_act_track_editor;

extern float viewMatrix[16];
extern float height, width;