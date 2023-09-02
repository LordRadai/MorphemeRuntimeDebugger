#pragma once
#define PI 3.14159265358979323846

#include "AppGUI/AppGUI.h"
#include "TimeActEditor/TimeActEditor.h"
#include "EventTrackEditor/EventTrackEditor.h"

class TaeTemplate;

extern HMODULE g_moduleAddr;
extern uint64_t g_gameManagerImp;
extern uint64_t g_networkManager;
extern uint64_t g_katanaMainApp;
extern int g_gameState;
extern int g_prevGameState;

extern bool g_openMorphemeDebugger;
extern AppGUI g_morphemeDebugger;
extern EventTrackEditor g_eventTrackEditor;
extern TimeActEditor g_timeActEditorPl;
extern TimeActEditor g_timeActEditorSfx;
extern TimeActEditor g_timeActEditorSnd;

extern TaeTemplate g_taeTemplate;