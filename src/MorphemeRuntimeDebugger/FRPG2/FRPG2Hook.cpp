#include "FRPG2Hook.h"

void FRPG2Hook::InitHooks()
{
	pUpdateCpIntTarget = reinterpret_cast<oUpdateCPInt>((uint64_t)(g_moduleAddr)+0x4db5e0);
	if (MH_CreateHook((LPVOID*)(pUpdateCpIntTarget), &FRPG2Hook::hUpdateCpInt, (LPVOID*)(&pUpdateCpInt)) != MH_OK)
		Debug::DebuggerMessage(Debug::LVL_DEBUG, "[MH] Hook UpdateCpInt failed.\n");
	else
		Debug::DebuggerMessage(Debug::LVL_DEBUG, "[MH] Hook UpdateCpInt succeeded\n");

	if (MH_EnableHook(reinterpret_cast<void**>(pUpdateCpFloatTarget)) != MH_OK)
		Debug::DebuggerMessage(Debug::LVL_DEBUG, "[MH] UpdateCpInt failed to enable\n");
	else
		Debug::DebuggerMessage(Debug::LVL_DEBUG, "[MH] UpdateCpInt enabled\n");

	pUpdateCpFloatTarget = reinterpret_cast<oUpdateCPFloat>((uint64_t)(g_moduleAddr)+0x4db590);
	if (MH_CreateHook((LPVOID*)(pUpdateCpFloatTarget), &FRPG2Hook::hUpdateCpFloat, (LPVOID*)(&pUpdateCpFloat)) != MH_OK)
		Debug::DebuggerMessage(Debug::LVL_DEBUG, "[MH] Hook UpdateCpFloat failed.\n");
	else
		Debug::DebuggerMessage(Debug::LVL_DEBUG, "[MH] Hook UpdateCpFloat succeeded\n");

	if (MH_EnableHook(reinterpret_cast<void**>(pUpdateCpFloatTarget)) != MH_OK)
		Debug::DebuggerMessage(Debug::LVL_DEBUG, "[MH] UpdateCpFloat failed to enable\n");
	else
		Debug::DebuggerMessage(Debug::LVL_DEBUG, "[MH] UpdateCpFloat enabled\n");
}

void FRPG2Hook::hUpdateCpInt(UINT64 pMorphemeMotionCtrl, short idx, int value)
{
	if (g_morphemeDebugger.m_gameDebugFlags.m_disableCPUpdates)
		return;

	return pUpdateCpInt(pMorphemeMotionCtrl, idx, value);
}

void FRPG2Hook::hUpdateCpFloat(UINT64 pMorphemeMotionCtrl, short idx, float value)
{
	if (g_morphemeDebugger.m_gameDebugFlags.m_disableCPUpdates)
		return;

	return pUpdateCpFloat(pMorphemeMotionCtrl, idx, value);
}