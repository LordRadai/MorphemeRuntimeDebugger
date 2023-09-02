#include "MorphemeInterface.h"
#include "../Debug/Debug.h"
#include "../common.h"

enum CharacterType : BYTE
{
	PLAYER = 0,
	ENEMY = 1,
	BOSS = 2,
	DEMO = 3,
};

CharacterType getCharacterType(uint64_t character_ctrl)
{
	uint64_t action_ctrl = *(uint64_t*)(character_ctrl + 0xE0);
	uint64_t vfunction_8 = *(uint64_t*)(*(uint64_t*)(action_ctrl)+0x8);

	if (vfunction_8 == ((uint64_t)g_moduleAddr + 0x37D380))
		return PLAYER;

	else if (vfunction_8 == ((uint64_t)g_moduleAddr + 0x39E400))
		return ENEMY;

	else if (vfunction_8 == ((uint64_t)g_moduleAddr + 0x44BB20))
		return BOSS;

	else if (*(uint64_t*)(*(uint64_t*)(character_ctrl)) != ((uint64_t)g_moduleAddr + 0x3234B0))
		return DEMO;
}

int MorphemeInterface::getNodeContentAmount(Morpheme::NodeDef* node)
{
	if (node)
	{
		switch (node->m_nodeTypeID)
		{
		case NodeType_NodeAnimSyncEvents:
			return 3;
		case NodeType_Switch:
			return 2;
		case NodeType_Share1Child1InputCP:
			return 2;
		default:
			return 0;
		}
	}
}

void MorphemeInterface::renderNodeAttributeType(Morpheme::NodeDef* node, int data_amount)
{
	if (!node || !node->node_data)
		return;

	for (size_t i = 0; i < data_amount; i++)
	{
		switch (node->node_data->data[i].content->m_type)
		{
		case ATTRIB_TYPE_BOOL:
		{
			Morpheme::NodeDataContent_Bool* node_content_data_bool = (Morpheme::NodeDataContent_Bool*)&node->node_data->data[i].content->data_start;

			ImGui::InputByte("Flag", (char*)&node_content_data_bool->attrib_bool, 0, 0, ImGuiInputTextFlags_None);
			break;
		}
		case ATTRIB_TYPE_FLOAT_ARRAY:
		{
			Morpheme::NodeDataContent_FloatArray* node_content_data_flt_array = (Morpheme::NodeDataContent_FloatArray*)&node->node_data->data[i].content->data_start;

			if (node_content_data_flt_array->size >= 0)
			{
				for (size_t i = 0; i < node_content_data_flt_array->size; i++)
				{
					char label[256];
					sprintf(label, "Float %d", i);

					ImGui::PushID(i);
					ImGui::InputFloat(label, &node_content_data_flt_array->flt_array[i], 0, 0, "%.3f");
					ImGui::PopID();
				}
			}
			break;
		}
		default:
			break;
		}
	}

}