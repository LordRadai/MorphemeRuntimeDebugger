#include "MorphemeInterface.h"
#include "Debug.h"
#include "common.h"

enum CharacterType : byte
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

	if (vfunction_8 == ((uint64_t)ModuleAddr + 0x37D380))
		return PLAYER;

	else if (vfunction_8 == ((uint64_t)ModuleAddr + 0x39E400))
		return ENEMY;

	else if (vfunction_8 == ((uint64_t)ModuleAddr + 0x44BB20))
		return BOSS;

	else if (*(uint64_t*)(*(uint64_t*)(character_ctrl)) != ((uint64_t)ModuleAddr + 0x3234B0))
		return DEMO;
}

void MorphemeInterface::drawSkeleton(uint64_t character_ctrl)
{
	RGBA bone_col = RGBA(255, 0, 0, 255);
	CharacterType character_type = getCharacterType(character_ctrl);
	uint64_t character_rigid_body;

	if (*(uint64_t*)(character_ctrl + 0xE0) == NULL)
		return;

	uint64_t action_ctrl = *(uint64_t*)(character_ctrl + 0xE0);

	switch (character_type)
	{
	case PLAYER:
		if (*(uint64_t*)(action_ctrl + 0x1F8) == NULL)
			return;

		character_rigid_body = *(uint64_t*)(action_ctrl + 0x1F8);
		break;
	case ENEMY:
		if (*(uint64_t*)(action_ctrl + 0x1B8) == 0)
			return;

		character_rigid_body = *(uint64_t*)(action_ctrl + 0x1B8);
		break;
	case BOSS:
		if (*(uint64_t*)(action_ctrl + 0x180) == 0)
			return;

		character_rigid_body = *(uint64_t*)(action_ctrl + 0x180);
		break;
	case DEMO:
		break;
	default:
		Debug::debuggerMessage(Debug::LVL_ERROR, "Unknown Character Type %d\n", character_type);
		return;
	}

	bool is_custom_shape = *(int*)(character_rigid_body + 0x5E0);
	uint64_t hkp_rigid_body;
	Matrix4 bone_pos;

	if (!is_custom_shape)
	{
		for (size_t i = 0; i < 11; i++)
		{
			if (*(uint64_t*)(character_rigid_body + 0x80 + (byte)i * 0x80))
			{
				hkp_rigid_body = *(uint64_t*)(character_rigid_body + 0x80 + (byte)i * 0x80);
				float* bone_matrix = *(float**)(hkp_rigid_body + 0x30);
				//bone_pos = *(Matrix4*)(hkp_rigid_body + 0x30);
				bone_pos = Matrix4();

				bone_pos.m[0][0] = bone_matrix[0];
				bone_pos.m[1][0] = bone_matrix[1];
				bone_pos.m[2][0] = bone_matrix[2];
				bone_pos.m[3][0] = bone_matrix[3];

				bone_pos.m[0][1] = bone_matrix[4];
				bone_pos.m[1][1] = bone_matrix[5];
				bone_pos.m[2][1] = bone_matrix[6];
				bone_pos.m[3][1] = bone_matrix[7];

				bone_pos.m[0][2] = bone_matrix[8];
				bone_pos.m[1][2] = bone_matrix[9];
				bone_pos.m[2][2] = bone_matrix[10];
				bone_pos.m[3][2] = bone_matrix[11];

				bone_pos.m[0][3] = bone_matrix[12];
				bone_pos.m[1][3] = bone_matrix[13];
				bone_pos.m[2][3] = bone_matrix[14];
				bone_pos.m[3][3] = bone_matrix[15];

				Debug::debuggerMessage(Debug::LVL_DEBUG, "Bone %d\n", i);
				Debug::debuggerMessage(Debug::LVL_DEBUG, "Bone Pos: (%.3f, %.3f, %.3f, %.3f)\n", bone_pos.m[0][0], bone_pos.m[0][1], bone_pos.m[0][2], bone_pos.m[0][3]);
				Debug::debuggerMessage(Debug::LVL_DEBUG, "Bone Pos: (%.3f, %.3f, %.3f, %.3f)\n", bone_pos.m[1][0], bone_pos.m[1][1], bone_pos.m[1][2], bone_pos.m[1][3]);
				Debug::debuggerMessage(Debug::LVL_DEBUG, "Bone Pos: (%.3f, %.3f, %.3f, %.3f)\n", bone_pos.m[2][0], bone_pos.m[2][1], bone_pos.m[2][2], bone_pos.m[2][3]);
				Debug::debuggerMessage(Debug::LVL_DEBUG, "Bone Pos: (%.3f, %.3f, %.3f, %.3f)\n", bone_pos.m[3][0], bone_pos.m[3][1], bone_pos.m[3][2], bone_pos.m[3][3]);

				Renderer::DrawBone(bone_pos, bone_pos, 1, &bone_col);
			}
		}
	}
	/*else
	{
		if (*(uint64_t*)(character_rigid_body + 0x618))
		{
			uint64_t px_keyframed_rigid_body = *(uint64_t*)(character_rigid_body + 0x618);

			if (*(uint64_t*)(px_keyframed_rigid_body + 0x60))
			{
				short rigid_bodies_count = *(short*)(px_keyframed_rigid_body + 0x58);
				uint64_t rigid_bodies = *(uint64_t*)(px_keyframed_rigid_body + 0x60);

				for (size_t i = 0; i < rigid_bodies_count; i++)
				{
					if (*(uint64_t*)(rigid_bodies + (byte)i * 0x8) && i != rigid_bodies_count)
					{
						hkp_rigid_body = *(uint64_t*)(rigid_bodies + (byte)i * 0x8);
						bone_pos = *(Matrix4*)(hkp_rigid_body + 0x30);

						Renderer::DrawBone(bone_pos, bone_pos, 1, &bone_col);
					}
				}
			}
		}
	}*/
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