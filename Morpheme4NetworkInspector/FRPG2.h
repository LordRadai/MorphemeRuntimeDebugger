#pragma once
#include "includes.h"
#include "Morpheme.h"
#include "TimeAct.h"

namespace FRPG2
{
	void assignFunctionAddr();
	uint64_t getPlayerCtrl();
	uint64_t getLockedTargetCharacterCtrl();
}

typedef int(__fastcall* oSendMessage)(Morpheme::Network* network, Morpheme::sMorphemeMessage message_data);
typedef sTaeData*(__fastcall* oTaeLookup)(uint64_t TimeActData, uint32_t tae_id);

extern oSendMessage sendMessage;
extern oTaeLookup taeLookup;