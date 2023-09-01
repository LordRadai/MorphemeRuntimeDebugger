#pragma once
#include <fstream>
#include <Windows.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

struct Argument
{
    std::string m_name;
    std::string m_type;

    CHAR m_s8;
    UCHAR m_u8;
    SHORT m_s16;
    USHORT m_u16;
    INT m_s32;
    UINT m_u32;
    FLOAT m_f32;
    INT64 m_s64;
    UINT64 m_u64;
};

class TimeActEventData
{
public:
    int m_size;
    std::vector<Argument> m_args;

    TimeActEventData() {}
    void GetData(BYTE* mem, int group_id, int event_id);
    void SaveData(BYTE* mem);
    std::string GetArgumentsAsString();
    void ImGuiEdit();
};

struct sTaeGroupContent {
    int tae_id;
    int field1_0x4;
    struct sTaeData* tae_data;
};

struct sGroupData {
    uint32_t start_tae;
    uint32_t end_tae;
    struct sTaeGroupContent* file_data;
};

struct sTaeData {
    uint64_t* event_header;
    struct sEventGroup* event_group;
    uint64_t* event_times;
    uint64_t anim_file;
    uint32_t event_count;
    uint32_t event_group_count;
    uint32_t time_count;
};

struct sTaeFile {
    char magic[4];
    BYTE big_endian;
    BYTE field2_0x5;
    BYTE field3_0x6;
    BYTE field4_0x7;
    int version;
    int file_size;
    char* tae_file_flags;
    int is_readable;
    int field9_0x1c;
    struct sTaeFileData* tae_file_data;
};

struct sTaeFileData {
    int file_id;
    int tae_count;
    uint64_t* tae;
    struct sTaeGroup* tae_groups;
    uint64_t field4_0x18;
    int tae_count2;
    int field6_0x24;
    uint64_t field7_0x28;
    int field8_0x30;
    int field9_0x34;
    uint64_t field10_0x38;
};

struct sTaeGroup {
    uint32_t group_count;
    int field1_0x4;
    struct sGroupData* groups;
};

struct sTaeEventData
{
    int value;
    int padding;
    BYTE* args;
};

struct sTaeBuffer {
    float start_time;
    int field1_0x4;
    float end_time;
    int field3_0xc;
    sTaeEventData* event_data;
};

struct sEventGroup {
    int group_count;
    int field1_0x4;
    sTaeBuffer** tae_data;
    uint32_t* group_id;
    int field4_0x18;
    int field5_0x1c;
};

namespace TimeAct
{
    uint64_t getTimeActFile_pl(uint64_t character_ctrl);
    uint64_t getTimeActFile_sfx(uint64_t character_ctrl);
    uint64_t getTimeActFile_snd(uint64_t character_ctrl);

    sEventGroup* getEventGroup(sTaeData* tae_data, int index);
}