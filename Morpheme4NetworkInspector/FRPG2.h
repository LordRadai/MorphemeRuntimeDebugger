#pragma once
#include "includes.h"
#include "Morpheme.h"

namespace FRPG2
{
	void assignFunctionAddr();
	uint64_t getPlayerCtrl();
	uint64_t getLockedTargetCharacterCtrl();
}

typedef int(__fastcall* oSendMessage)(Morpheme::Network* network, Morpheme::sMorphemeMessage message_data);

extern oSendMessage sendMessage;