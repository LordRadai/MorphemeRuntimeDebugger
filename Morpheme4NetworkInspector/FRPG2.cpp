#include "FRPG2.h"

uint64_t FRPG2::getPlayerCtrl()
{
	if (!GameManagerImp)
		return NULL;

	if (*(uint64_t*)(GameManagerImp + 0xD0))
		return *(uint64_t*)(GameManagerImp + 0xD0);

	return NULL;
}

uint64_t FRPG2::getLockedTargetCharacterCtrl()
{
	if (!GameManagerImp)
		return NULL;

	if (*(uint64_t*)(GameManagerImp + 0x20) == NULL)
		return NULL;

	uint64_t camera_manager = *(uint64_t*)(GameManagerImp + 0x20);

	if (*(uint64_t*)(camera_manager + 0x28) == NULL)
		return NULL;

	uint64_t ingame_camera_operator = *(uint64_t*)(camera_manager + 0x28);

	if (*(uint64_t*)(ingame_camera_operator + 0xB0) == NULL)
		return NULL;

	uint64_t operators = *(uint64_t*)(ingame_camera_operator + 0xB0);

	if (*(uint64_t*)(operators + 0x18) == NULL)
		return NULL;

	uint64_t ex_follow_camera_operator = *(uint64_t*)(operators + 0x18);

	if (*(uint64_t*)(ex_follow_camera_operator + 0xC0))
		return *(uint64_t*)(ex_follow_camera_operator + 0xC0);

	return NULL;
}

void FRPG2::assignFunctionAddr()
{
	sendMessage = (oSendMessage)((uint64_t)ModuleAddr + 0x5EBE70);
	taeLookup = (oTaeLookup)((uint64_t)ModuleAddr + 0xB3F3C0);
}