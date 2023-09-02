#include <sstream>
#include "TimeAct.h"
#include "../Debug/Debug.h"
#include "../common.h"
#include "../TaeTemplate/TaeTemplate.h"
#include "../StringHelper/StringHelper.h"

void TimeActEventData::GetData(BYTE* mem, int group_id, int event_id)
{
	for (int group_idx = 0; group_idx < g_taeTemplate.m_groups.size(); group_idx++)
	{
		if (g_taeTemplate.m_groups[group_idx].m_id == group_id)
		{
			for (int event_idx = 0; event_idx < g_taeTemplate.m_groups[group_idx].m_events.size(); event_idx++)
			{
				if (g_taeTemplate.m_groups[group_idx].m_events[event_idx].m_id == event_id)
				{
					for (int arg_idx = 0; arg_idx < g_taeTemplate.m_groups[group_idx].m_events[event_idx].m_args.size(); arg_idx++)
					{
						BYTE* currentArg = mem + (BYTE)this->m_size;

						this->m_args.push_back(Argument());
						this->m_args[arg_idx].m_type = g_taeTemplate.m_groups[group_idx].m_events[event_idx].m_args[arg_idx].m_type;
						this->m_args[arg_idx].m_name = g_taeTemplate.m_groups[group_idx].m_events[event_idx].m_args[arg_idx].m_name;

						std::string arg_type = this->m_args[arg_idx].m_type;

						if (arg_type.compare("s8") == 0)
						{
							this->m_size += 1;

							this->m_args[arg_idx].m_s8 = *(CHAR*)(currentArg);
						}
						else if (arg_type.compare("u8") == 0)
						{
							this->m_size += 1;

							this->m_args[arg_idx].m_u8 = *(UCHAR*)(currentArg);
						}
						else if (arg_type.compare("s16") == 0)
						{
							this->m_size += 2;

							this->m_args[arg_idx].m_s16 = *(SHORT*)(currentArg);
						}
						else if (arg_type.compare("u16") == 0)
						{
							this->m_size += 2;

							this->m_args[arg_idx].m_u16 = *(USHORT*)(currentArg);
						}
						else if (arg_type.compare("s32") == 0)
						{
							this->m_size += 4;

							this->m_args[arg_idx].m_s32 = *(INT*)(currentArg);
						}
						else if (arg_type.compare("u32") == 0)
						{
							this->m_size += 4;

							this->m_args[arg_idx].m_u32 = *(UINT*)(currentArg);
						}
						else if (arg_type.compare("f32") == 0)
						{
							this->m_size += 4;

							this->m_args[arg_idx].m_f32 = *(FLOAT*)(currentArg);
						}
						else if (arg_type.compare("s64") == 0)
						{
							this->m_size += 8;

							this->m_args[arg_idx].m_s64 = *(INT64*)(currentArg);
						}
						else if (arg_type.compare("u64") == 0)
						{
							this->m_size += 8;

							this->m_args[arg_idx].m_u64 = *(UINT64*)(currentArg);
						}
					}

					break;
				}
			}

			break;
		}
	}
}

void TimeActEventData::SaveData(BYTE* mem)
{
	BYTE* currentArg = mem;

	for (size_t i = 0; i < this->m_args.size(); i++)
	{
		std::string arg_type = this->m_args[i].m_type;

		if (arg_type.compare("s8") == 0)
		{
			*(CHAR*)(currentArg) = this->m_args[i].m_s8;
			currentArg += 1;
		}
		else if (arg_type.compare("u8") == 0)
		{
			*(UCHAR*)(currentArg) = this->m_args[i].m_u8;
			currentArg += 1;
		}
		else if (arg_type.compare("s16") == 0)
		{
			*(SHORT*)(currentArg) = this->m_args[i].m_s16;
			currentArg += 2;
		}
		else if (arg_type.compare("u16") == 0)
		{
			*(USHORT*)(currentArg) = this->m_args[i].m_u16;
			currentArg += 2;
		}
		else if (arg_type.compare("s32") == 0)
		{
			*(INT*)(currentArg) = this->m_args[i].m_s32;
			currentArg += 4;
		}
		else if (arg_type.compare("u32") == 0)
		{
			*(UINT*)(currentArg) = this->m_args[i].m_u32;
			currentArg += 4;
		}
		else if (arg_type.compare("f32") == 0)
		{
			*(FLOAT*)(currentArg) = this->m_args[i].m_f32;
			currentArg += 4;
		}
		else if (arg_type.compare("s64") == 0)
		{
			*(INT64*)(currentArg) = this->m_args[i].m_s64;
			currentArg += 8;
		}
		else if (arg_type.compare("u64") == 0)
		{
			*(UINT64*)(currentArg) = this->m_args[i].m_u64;
			currentArg += 8;
		}
	}
}

std::string TimeActEventData::GetArgumentsAsString()
{
	if (this->m_args.size() == 0)
		return "";

	std::string arg_str = "(";

	for (size_t i = 0; i < this->m_args.size(); i++)
	{
		std::string arg_type = this->m_args[i].m_type;

		if (arg_type.compare("s8") == 0)
			arg_str += std::to_string(this->m_args[i].m_s8);
		else if (arg_type.compare("u8") == 0)
			arg_str += std::to_string(this->m_args[i].m_u8);
		else if (arg_type.compare("s16") == 0)
			arg_str += std::to_string(this->m_args[i].m_s16);
		else if (arg_type.compare("u16") == 0)
			arg_str += std::to_string(this->m_args[i].m_u16);
		else if (arg_type.compare("s32") == 0)
			arg_str += std::to_string(this->m_args[i].m_s32);
		else if (arg_type.compare("u32") == 0)
			arg_str += std::to_string(this->m_args[i].m_u32);
		else if (arg_type.compare("f32") == 0)
			arg_str += StringHelper::FloatToString(this->m_args[i].m_f32);
		else if (arg_type.compare("s64") == 0)
			arg_str += std::to_string(this->m_args[i].m_s64);
		else if (arg_type.compare("u64") == 0)
			arg_str += std::to_string(this->m_args[i].m_u64);

		if (i < this->m_args.size() - 1)
			arg_str += ", ";
	}

	arg_str += ")\n";

	return arg_str;
}

void TimeActEventData::ImGuiEdit()
{
	ImGui::Text("Arguments");

	for (size_t i = 0; i < this->m_args.size(); i++)
	{
		std::string arg_type = this->m_args[i].m_type;

		ImGui::PushID(i);
		if (arg_type.compare("s8") == 0)
			ImGui::InputByte(this->m_args[i].m_name.c_str(), &this->m_args[i].m_s8, 0, 0, 0);
		else if (arg_type.compare("u8") == 0)
			ImGui::InputUByte(this->m_args[i].m_name.c_str(), &this->m_args[i].m_u8, 0, 0, 0);
		else if (arg_type.compare("s16") == 0)
			ImGui::InputShort(this->m_args[i].m_name.c_str(), &this->m_args[i].m_s16, 0, 0, 0);
		else if (arg_type.compare("u16") == 0)
			ImGui::InputUShort(this->m_args[i].m_name.c_str(), &this->m_args[i].m_u16, 0, 0, 0);
		else if (arg_type.compare("s32") == 0)
			ImGui::InputInt(this->m_args[i].m_name.c_str(), &this->m_args[i].m_s32, 0, 0, 0);
		else if (arg_type.compare("u32") == 0)
			ImGui::InputUInt(this->m_args[i].m_name.c_str(), &this->m_args[i].m_u32, 0, 0, 0);
		else if (arg_type.compare("f32") == 0)
			ImGui::InputFloat(this->m_args[i].m_name.c_str(), &this->m_args[i].m_f32, 0, 0, 0);
		else if (arg_type.compare("s64") == 0)
			ImGui::InputInt64(this->m_args[i].m_name.c_str(), &this->m_args[i].m_s64, 0, 0, 0);
		else if (arg_type.compare("u64") == 0)
			ImGui::InputUInt64(this->m_args[i].m_name.c_str(), &this->m_args[i].m_u64, 0, 0, 0);
		ImGui::PopID();
	}
}

uint64_t TimeAct::getTimeActFile_pl(uint64_t character_ctrl)
{
	if (character_ctrl == NULL)
		return NULL;

	if (*(uint64_t*)(character_ctrl + 0x58))
	{
		uint64_t chr_res = *(uint64_t*)(character_ctrl + 0x58);

		return *(uint64_t*)(chr_res + 0x48);
	}

	return NULL;
}

uint64_t TimeAct::getTimeActFile_sfx(uint64_t character_ctrl)
{
	if (character_ctrl == NULL)
		return NULL;

	if (character_ctrl == NULL)
		return NULL;

	if (*(uint64_t*)(character_ctrl + 0x58))
	{
		uint64_t chr_res = *(uint64_t*)(character_ctrl + 0x58);

		return *(uint64_t*)(chr_res + 0x50);
	}

	return NULL;
}

uint64_t TimeAct::getTimeActFile_snd(uint64_t character_ctrl)
{
	if (character_ctrl == NULL)
		return NULL;

	if (*(uint64_t*)(character_ctrl + 0x58))
	{
		uint64_t chr_res = *(uint64_t*)(character_ctrl + 0x58);

		return *(uint64_t*)(chr_res + 0x58);
	}

	return NULL;
}

sEventGroup* TimeAct::getEventGroup(sTaeData* tae_data, int index)
{
	return &tae_data->event_group[index];
}