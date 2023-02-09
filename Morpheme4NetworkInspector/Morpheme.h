#pragma once
//#include "includes.h" //Include your stuff here
#include "Timeline.h"
#include "inih/ini.h"
#include "inih/INIReader.h"
#include <windows.h>

static class Morpheme
{
public:

    enum NodeType
    {
        NetworkInstance = 9,
        StateMachine_Node = 10,
        ControlParameterFloat = 20,
        ControlParameterInt = 24,
        ControlParameterVector3 = 21,
        ControlParameterBool = 23,
        NodeAnimSyncEvents = 104,
        Blend2SyncEvents = 107,
        Blend2Additive = 108,
        Blend2Additive_2 = 114,
        ShareUpdateConnections1Child1InputCP = 125,
        Freeze = 126,
        ShareUpdateConnectionsChildrenOptionalInputCPs = 129,
        Switch = 131,
        ShareUpdateConnectionsChildren = 134,
        ShareUpdateConnectionsChildren_2 = 135,
        ShareUpdateConnections1Child2OptionalInputCP = 136,
        PredictiveUnevenTerrain = 138,
        OperatorSmoothDamp = 142,
        Transit = 402,
        ShareUpdateConnections1Child1OptionalInputCP = 500,
        Unk550 = 550,
    };

    enum AttribType
    {};
    
    enum AttribSemantic
    {};

    enum TaskID
    {};

    enum ControlParam_ValueType
    {
        Int = 2,
        Float = 3,
        Vector3 = 4,
    };

    struct sSmStateList {
        uint32_t m_numStateMachinesNodes;
        int field1_0x4;
        short* m_stateMachineNodeIDs;
    };

    struct StringTable {
        uint32_t m_NumEntrys;
        uint32_t m_DataLenght;
        uint32_t* m_IDs;
        uint32_t* m_Offsets;
        char* m_Data;
    };

    struct NodeDef {
        NodeType m_nodeTypeID;
        byte m_flags1;
        byte m_flags2;
        uint16_t m_nodeID;
        uint16_t m_parentNodeID;
        uint16_t m_numChildNodeIDs;
        uint16_t m_numControlParamAndOpNodeIDs;
        byte field7_0xe;
        byte field8_0xf;
        uint16_t field9_0x10;
        uint16_t field10_0x12;
        int padding;
        struct NetworkDef* m_owningNetworkDef;
        short* m_childNodeIDs;
        int* m_controlParamAndOpNodeIDs;
        struct NodeDataBase* node_data;
        short field16_0x38;
        short field17_0x3a;
        int field18_0x3c;
        uint64_t field19_0x40;
        uint64_t field20_0x48;
        void* deleteFn;
        void* updateFn;
        void* unknownFn;
        void* initFn;
        void* transitFn;
        struct sMorphemeNodeDef* node_def;
        byte field27_0x80;
        byte field28_0x81;
        byte field29_0x82;
        byte field30_0x83;
        byte field31_0x84;
        byte field32_0x85;
        byte field33_0x86;
        byte field34_0x87;
        uint64_t field35_0x88;
    };

    struct NodeDataBase {
        uint32_t field0_0x0;
        uint32_t field1_0x4;
        short field2_0x8;
        short m_type;
        int padding;
    };

    struct sEventTrackEventData {
        float m_startTime;
        float m_duration;
        uint32_t m_userData;
    };

    struct EventTrackDef {
        uint32_t m_numEvents;
        uint32_t field1_0x4;
        char* m_trackName;
        uint32_t m_eventId;
        uint32_t m_trackType;
        struct sEventTrackEventData* m_trackData;
    };

    struct sEventTrack {
        int m_trackCount;
        int padding;
        struct EventTrackDef** m_tracks;
        uint64_t m_tracksEndAddr;
    };

    struct sEventTrackData {
        int field0_0x0;
        int field1_0x4;
        short field2_0x8;
        short field3_0xa;
        int pad0;
        struct sEventTrack m_eventTracks[3];
    };

    struct NodeData104 {
        struct NodeDataBase m_nodeDataBase;
        int field1_0x10;
        int field2_0x14;
        uint64_t m_animData;
        int field4_0x20;
        int field5_0x24;
        int field6_0x28;
        int field7_0x2c;
        struct sEventTrackData* m_eventTrackData;
    };

    struct AttribAddress {
        uint16_t m_owningNodeID;
        uint16_t m_targetNodeID;
        uint16_t m_semantic;
        uint16_t m_animSetIndex;
        int m_validFrame;
    };

    struct TaskParameter {
        struct AttribAddress m_attribAddress;
        uint32_t m_taskParamFlags;
        uint16_t m_lifespan;
        uint16_t m_numDependents;
        uint32_t field4_0x14;
        struct Task* field5_0x18;
    };

    struct Task {
        uint64_t field0_0x0;
        struct Task* m_dependantTask;
        int field2_0x10;
        int field3_0x14;
        int m_taskId;
        byte field5_0x1c;
        byte field6_0x1d;
        byte field7_0x1e;
        byte field8_0x1f;
        uint16_t m_owningNodeId;
        short field10_0x22;
        short node_type;
        short field12_0x26;
        short field13_0x28;
        short field14_0x2a;
        short field15_0x2c;
        short field16_0x2e;
        uint32_t field17_0x30;
        struct TaskParameter m_params;
        byte field19_0x54;
        byte field20_0x55;
        byte field21_0x56;
        byte field22_0x57;
        byte field23_0x58;
        byte field24_0x59;
        byte field25_0x5a;
        byte field26_0x5b;
        byte field27_0x5c;
        byte field28_0x5d;
        byte field29_0x5e;
        byte field30_0x5f;
        byte field31_0x60;
        byte field32_0x61;
        byte field33_0x62;
        byte field34_0x63;
        byte field35_0x64;
        byte field36_0x65;
        byte field37_0x66;
        byte field38_0x67;
        byte field39_0x68;
        byte field40_0x69;
        byte field41_0x6a;
        byte field42_0x6b;
        byte field43_0x6c;
        byte field44_0x6d;
        byte field45_0x6e;
        byte field46_0x6f;
        byte field47_0x70;
        byte field48_0x71;
        byte field49_0x72;
        byte field50_0x73;
        byte field51_0x74;
        byte field52_0x75;
        byte field53_0x76;
        byte field54_0x77;
        byte field55_0x78;
        byte field56_0x79;
        byte field57_0x7a;
        byte field58_0x7b;
        byte field59_0x7c;
        byte field60_0x7d;
        byte field61_0x7e;
        byte field62_0x7f;
        byte field63_0x80;
        byte field64_0x81;
        byte field65_0x82;
        byte field66_0x83;
        byte field67_0x84;
        byte field68_0x85;
        byte field69_0x86;
        byte field70_0x87;
        byte field71_0x88;
        byte field72_0x89;
        byte field73_0x8a;
        byte field74_0x8b;
        byte field75_0x8c;
        byte field76_0x8d;
        byte field77_0x8e;
        byte field78_0x8f;
        byte field79_0x90;
        byte field80_0x91;
        byte field81_0x92;
        byte field82_0x93;
        byte field83_0x94;
        byte field84_0x95;
        byte field85_0x96;
        byte field86_0x97;
        byte field87_0x98;
        byte field88_0x99;
        byte field89_0x9a;
        byte field90_0x9b;
        byte field91_0x9c;
        byte field92_0x9d;
        byte field93_0x9e;
        byte field94_0x9f;
        byte field95_0xa0;
        byte field96_0xa1;
        byte field97_0xa2;
        byte field98_0xa3;
        byte field99_0xa4;
        byte field100_0xa5;
        byte field101_0xa6;
        byte field102_0xa7;
        byte field103_0xa8;
        byte field104_0xa9;
        byte field105_0xaa;
        byte field106_0xab;
        byte field107_0xac;
        byte field108_0xad;
        byte field109_0xae;
        byte field110_0xaf;
        byte field111_0xb0;
        byte field112_0xb1;
        byte field113_0xb2;
        byte field114_0xb3;
        byte field115_0xb4;
        byte field116_0xb5;
        byte field117_0xb6;
        byte field118_0xb7;
        byte field119_0xb8;
        byte field120_0xb9;
        byte field121_0xba;
        byte field122_0xbb;
        byte field123_0xbc;
        byte field124_0xbd;
        byte field125_0xbe;
        byte field126_0xbf;
        byte field127_0xc0;
        byte field128_0xc1;
        byte field129_0xc2;
        byte field130_0xc3;
        byte field131_0xc4;
        byte field132_0xc5;
        byte field133_0xc6;
        byte field134_0xc7;
        byte field135_0xc8;
        byte field136_0xc9;
        byte field137_0xca;
        byte field138_0xcb;
        byte field139_0xcc;
        byte field140_0xcd;
        byte field141_0xce;
        byte field142_0xcf;
        byte field143_0xd0;
        byte field144_0xd1;
        byte field145_0xd2;
        byte field146_0xd3;
        byte field147_0xd4;
        byte field148_0xd5;
        byte field149_0xd6;
        byte field150_0xd7;
        byte field151_0xd8;
        byte field152_0xd9;
        byte field153_0xda;
        byte field154_0xdb;
        byte field155_0xdc;
        byte field156_0xdd;
        byte field157_0xde;
        byte field158_0xdf;
        byte field159_0xe0;
        byte field160_0xe1;
        byte field161_0xe2;
        byte field162_0xe3;
        byte field163_0xe4;
        byte field164_0xe5;
        byte field165_0xe6;
        byte field166_0xe7;
        byte field167_0xe8;
        byte field168_0xe9;
        byte field169_0xea;
        byte field170_0xeb;
        byte field171_0xec;
        byte field172_0xed;
        byte field173_0xee;
        byte field174_0xef;
        byte field175_0xf0;
        byte field176_0xf1;
        byte field177_0xf2;
        byte field178_0xf3;
        byte field179_0xf4;
        byte field180_0xf5;
        byte field181_0xf6;
        byte field182_0xf7;
        byte field183_0xf8;
        byte field184_0xf9;
        byte field185_0xfa;
        byte field186_0xfb;
        byte field187_0xfc;
        byte field188_0xfd;
        byte field189_0xfe;
        byte field190_0xff;
        byte field191_0x100;
        byte field192_0x101;
        byte field193_0x102;
        byte field194_0x103;
        byte field195_0x104;
        byte field196_0x105;
        byte field197_0x106;
        byte field198_0x107;
        byte field199_0x108;
        byte field200_0x109;
        byte field201_0x10a;
        byte field202_0x10b;
        byte field203_0x10c;
        byte field204_0x10d;
        byte field205_0x10e;
        byte field206_0x10f;
        byte field207_0x110;
        byte field208_0x111;
        byte field209_0x112;
        byte field210_0x113;
        byte field211_0x114;
        byte field212_0x115;
        byte field213_0x116;
        byte field214_0x117;
        byte field215_0x118;
        byte field216_0x119;
        byte field217_0x11a;
        byte field218_0x11b;
        byte field219_0x11c;
        byte field220_0x11d;
        byte field221_0x11e;
        byte field222_0x11f;
        byte field223_0x120;
        byte field224_0x121;
        byte field225_0x122;
        byte field226_0x123;
        byte field227_0x124;
        byte field228_0x125;
        byte field229_0x126;
        byte field230_0x127;
        byte field231_0x128;
        byte field232_0x129;
        byte field233_0x12a;
        byte field234_0x12b;
        byte field235_0x12c;
        byte field236_0x12d;
        byte field237_0x12e;
        byte field238_0x12f;
        byte field239_0x130;
        byte field240_0x131;
        byte field241_0x132;
        byte field242_0x133;
        byte field243_0x134;
        byte field244_0x135;
        byte field245_0x136;
        byte field246_0x137;
        byte field247_0x138;
        byte field248_0x139;
        byte field249_0x13a;
        byte field250_0x13b;
        byte field251_0x13c;
        byte field252_0x13d;
        byte field253_0x13e;
        byte field254_0x13f;
        byte field255_0x140;
        byte field256_0x141;
        byte field257_0x142;
        byte field258_0x143;
        byte field259_0x144;
        byte field260_0x145;
        byte field261_0x146;
        byte field262_0x147;
    };

    struct sControlParamContainerValue
    {
        uint64_t m_allocator;
        short field8_0x2;
        short m_dataType;
        int field10_0xC;
        DWORD m_value[4];
    };

    struct sControlParamContainer {
        byte field0_0x0;
        byte field1_0x1;
        byte field2_0x2;
        byte field3_0x3;
        byte field4_0x4;
        byte field5_0x5;
        byte field6_0x6;
        byte field7_0x7;
        sControlParamContainerValue* m_controlParamData;
        byte field9_0x10;
        byte field10_0x11;
        byte field11_0x12;
        byte field12_0x13;
    };

    struct sMorphemeNodeDef {
        int node_type;
        byte field1_0x4;
        byte field2_0x5;
        short field3_0x6;
        byte* array;
    };

    struct sMessageDef {
        int message_id;
        int field1_0x4;
        int node_count;
        int field3_0xc;
        short* node_array;
    };

    struct NodeBin {
        uint32_t m_lastFrameUpdate;
        uint32_t field1_0x4;
        struct NodeBinEntry* m_attributes;
        uint32_t field3_0x10;
        uint32_t field4_0x14;
        struct Task* m_queuedTask;
        struct sControlParamContainer* m_controlParamContainer;
        int field7_0x28;
        int field8_0x2c;
    };

    struct NodeBinEntry {
        struct NodeBinEntry* m_next;
        struct AttribDataHandle* m_attribDataHandle;
        uint32_t format_size;
        uint32_t format_alignment;
        int field4_0x18;
        int field5_0x1c;
        short m_owningNodeID;
        short m_targetNodeID;
        short m_semantic;
        short m_animSetIndex;
        int m_validFrame;
        int field11_0x2c;
        struct MorphemeAllocator* m_allocator;
        uint16_t m_lifespan;
    };

    struct NodeConnections {
        byte flags_1;
        byte flags_2;
        short m_activeParentNodeId;
        int field3_0x4;
        short* m_activeChildNodeIDs;
        short m_maxNumActiveChildNodes;
        short m_numActiveChildNodes;
        int field7_0x14;
    };

    struct AttribDataHandle {
        struct MorphemeAllocator* m_allocator;
        short field1_0x8;
        short m_type;
        int padding;
        short m_activeStateID;
        short m_targetStateID;
        float field6_0x14;
        byte field7_0x18;
        byte field8_0x19;
        byte field9_0x1a;
        byte field10_0x1b;
        int field11_0x1c;
    };

    struct NetworkDef {
        struct NodeDef network_node_def;
        uint32_t m_numNodes;
        uint32_t field2_0x94;
        struct NodeDef** m_nodes;
        short field4_0xa0;
        short field5_0xa2;
        int field6_0xa4;
        uint64_t field7_0xa8;
        struct sSmStateList* sm_state_list;
        uint64_t field9_0xb8;
        struct sSmStateList* sm_unk_list;
        struct StringTable* m_nodeIDNamesTable;
        struct StringTable* m_requestIDNamesTable;
        struct StringTable* m_eventTrackIDNamesTable;
        uint64_t field14_0xe0;
        uint64_t field15_0xe8;
        uint64_t field16_0xf0;
        int message_count;
        int field18_0xfc;
        struct sMessageDef** message_def;
        int node_type_count;
        int field21_0x10c;
        struct sMorphemeNodeDef** node_def_list;
        int field23_0x118;
        int field24_0x11c;
        int field25_0x120;
        int field26_0x124;
        int field27_0x128;
        int field28_0x12c;
        uint64_t field29_0x130;
        uint64_t field30_0x138;
    };

	struct sStateMachineNode
	{
		sStateMachineNode* child_node;
		uint64_t node_data;
		int iVar10;
		int iVar14;
		int iVar18;
		int iVar1C;
		uint16_t offset;
		uint16_t sVar22;
		uint16_t node_type;
		uint16_t sVar26;
		int current_node;
	};

    struct TaskQueue {
        struct Task** m_tasks;
        uint32_t m_numQueuedTasks;
        uint32_t m_numUnprocessedTasks;
        byte field3_0x10;
        byte field4_0x11;
        byte field5_0x12;
        byte field6_0x13;
        byte field7_0x14;
        byte field8_0x15;
        byte field9_0x16;
        byte field10_0x17;
        struct Network* m_owningNetwork;
    };

    struct MorphemeAllocator {
        struct vtable* _vfptr;
        byte field1_0x8;
        byte field2_0x9;
        byte field3_0xa;
        byte field4_0xb;
        byte field5_0xc;
        byte field6_0xd;
        byte field7_0xe;
        byte field8_0xf;
        uint64_t field9_0x10;
        byte field10_0x30;
        byte field11_0x31;
        byte field12_0x32;
        byte field13_0x33;
        byte field14_0x34;
        byte field15_0x35;
        byte field16_0x36;
        byte field17_0x37;
        uint64_t field18_0x38;
        uint64_t field19_0x40;
        uint64_t field20_0x48;
        uint64_t field21_0x50;
        uint64_t field22_0x58;
        uint64_t field23_0x60;
        uint64_t field24_0x68;
        uint64_t field25_0x70;
    };

    struct Network {
        struct NetworkDef* m_networkDef;
        struct TaskQueue* m_taskQueue;
        uint64_t field2_0x10;
        struct NodeBin* m_nodeBins;
        struct NodeConnections** m_nodeConnections;
        uint32_t current_frame_number;
        int field6_0x2c;
        int field7_0x30;
        int field8_0x34;
        int field9_0x38;
        int field10_0x3c;
        int field11_0x40;
        int field12_0x44;
        int field13_0x48;
        int field14_0x4c;
        int field15_0x50;
        int field16_0x54;
        int field17_0x58;
        int field18_0x5c;
        int field19_0x60;
        int field20_0x64;
        int field21_0x68;
        uint32_t field22_0x6c;
        int field23_0x70;
        int field24_0x74;
        int field25_0x78;
        int field26_0x7c;
        int field27_0x80;
        int field28_0x84;
        int field29_0x88;
        int field30_0x8c;
        int field31_0x90;
        int field32_0x94;
        int field33_0x98;
        int field34_0x9c;
        int field35_0xa0;
        int field36_0xa4;
        int field37_0xa8;
        int field38_0xac;
        int field39_0xb0;
        uint32_t field40_0xb4;
        struct NodeBinEntry* field41_0xb8;
        uint16_t* field42_0xc0;
        uint32_t field43_0xc8;
        byte field44_0xcc;
        byte field45_0xcd;
        byte field46_0xce;
        byte field47_0xcf;
        struct MorphemeChrCtrl* morpheme_chr_ctrl;
        struct sUnkMorphemeNetStruct** field49_0xd8;
        int field50_0xe0;
        int field51_0xe4;
        struct MorphemeAllocator* morpheme_allocator;
        uint32_t field53_0xf0;
        char field54_0xf4;
        byte field55_0xf5;
        byte field56_0xf6;
        byte field57_0xf7;
        byte field58_0xf8;
        byte field59_0xf9;
        byte field60_0xfa;
        byte field61_0xfb;
        uint32_t field62_0xfc;
        byte* field63_0x100;
        int field64_0x108;
        int field65_0x10c;
        byte field66_0x110;
        byte field67_0x111;
        byte field68_0x112;
        byte field69_0x113;
        byte field70_0x114;
        byte field71_0x115;
        byte field72_0x116;
        byte field73_0x117;
        char** field74_0x118;
        uint64_t field75_0x120;
        uint32_t field76_0x128;
        uint32_t field77_0x12c;
    };

    struct sMorphemeMessage
    {
        sMorphemeMessage(uint32_t msg_id)
        {
            field0_0x0 = 0;
            field1_0x4 = 0;
            field2_0x8 = 0;
            message_id = msg_id;
            field5_0x10 = 10;
            field6_0x14 = 1;
        }

        int field0_0x0;
        int field1_0x4;
        int field2_0x8;
        int message_id;
        int field5_0x10;
        int field6_0x14;
    };

	static void loadControlParameters();

    static int LoadEventTracks(sEventTrackData* track_base, MorphemeEventTrackList* track_list);

	static void ClearTrackList(MorphemeEventTrackList* track_list);

    static void SaveEventTracks(MorphemeEventTrackList* track_list);

	static void disableMorphemeUpdates(bool state);

	static const char* getStringFromStringTable(StringTable* string_table, int id);

	static const char* getNetworkNodeName(uint64_t character_ctrl, int id);

	static const char* getNetworkMessageName(uint64_t character_ctrl, int id);

	static const char* getNetworkEventTrackName(uint64_t character_ctrl, int id);

	static void getNetworkAllNodesName(uint64_t character_ctrl);

	static void getNetworkAllMessagesName(uint64_t character_ctrl);

	static void getNetworkAllEventTracksName(uint64_t character_ctrl);

	static void getNetworkAllNames(uint64_t character_ctrl);

	static void printBoneList(uint64_t character_ctrl);

	//static void loadBoneData(uint64_t character_ctrl, sBoneData buffer[]);

	static void getCategoryInfo(int category_id, char buffer[]);

	static void getValueInfo(int category, int value, char buffer[]);

    static NodeDef* getNetworkNode(Network* network, short node_id);

    static Network* getNetwork(uint64_t character_ctrl);

    static std::vector<NodeDef*> getNetworkAllNodesType(uint64_t character_ctrl, NodeType node_type);

    static const char* getAnimNameFromAnimNode(NodeDef* node);

    static std::vector<NodeDef*> getNetworkControlParameterNodes(uint64_t character_ctrl);

    static const char* stringTableLookup(StringTable* table, short id);

    static const char* getNodeName(uint64_t character_ctrl, short node_id);

    static const char* getMessageName(uint64_t character_ctrl, short message_id);

    static NodeBin* getNodeBin(uint64_t character_ctrl, short node_id);

    static std::vector<sMessageDef*> getMessageDefs(uint64_t character_ctrl);

    static bool isNodeActive(Network* network, short node_id);

    static bool isNodeContainer(Network* network, short node_id);

    static const char* getNodeTypeName_Alt(Morpheme::Network* network, short node_id);

    static const char* getNodeTypeName(Morpheme::Network* network, short node_id);
};