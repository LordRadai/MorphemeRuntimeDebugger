#pragma once
//#include "includes.h" //Include your stuff here
#include "../inih/ini.h"
#include "../inih/INIReader.h"
#include <windows.h>
#include <vector>

enum NodeType
{
    NodeType_NetworkInstance = 9,
    NodeType_StateMachine = 10,
    NodeType_ControlParameterFloat = 20,
    NodeType_ControlParameterVector3 = 21,
    NodeType_ControlParameterBool = 23,
    NodeType_ControlParameterInt = 24,
    NodeType_NodeAnimSyncEvents = 104,
    Nodetype_ShareChildren_105 = 105,
    NodeType_Blend2SyncEvents = 107,
    NodeType_Blend2Additive = 108,
    NodeType_Share1Child1InputCP_109,
    NodeType_ShareCreateFloatOutputAttribute_110 = 110,
    NodeType_ShareCreateFloatOutputAttribute_112 = 112,
    NodeType_Blend2Additive_2 = 114,
    NodeType_TwoBoneIK = 120,
    NodeType_LockFoot = 121,
    NodeType_ShareChildren1CompulsoryManyOptionalInputCPs_120 = 122,
    NodeType_Share1Child1InputCP = 125,
    NodeType_Freeze = 126,
    NodeType_ShareChildrenOptionalInputCPs = 129,
    NodeType_Switch = 131,
    NodeType_ShareChildren = 134,
    NodeType_ShareChildren_2 = 135,
    NodeType_ShareUpdateConnections1Child2OptionalInputCP = 136,
    NodeType_PredictiveUnevenTerrain = 138,
    NodeType_OperatorSmoothDamp = 142,
    NodeType_ShareCreateVector3OutputAttribute = 144,
    NodeType_OperatorRandomFloat = 146,
    NodeType_ShareChildren1CompulsoryManyOptionalInputCPs_150 = 150,
    NodeType_ShareChild1InputCP_151 = 151,
    NodeType_ShareChildren_153 = 153,
    NodeType_SubtractiveBlend = 170,
    NodeType_TransitSyncEvents = 400,
    NodeType_Transit = 402,
    NodeType_Share1Child1OptionalInputCP = 500,
    Unk550 = 550,
};

enum AttribType : short
{
    ATTRIB_TYPE_BOOL = 0,
    ATTRIB_TYPE_UINT = 1,
    ATTRIB_TYPE_INT = 2,
    ATTRIB_TYPE_FLOAT = 3,
    ATTRIB_TYPE_VECTOR3 = 4,
    ATTRIB_TYPE_VECTOR4 = 5,
    ATTRIB_TYPE_BOOL_ARRAY = 6,
    ATTRIB_TYPE_UINT_ARRAY = 7,
    ATTRIB_TYPE_INT_ARRAY = 8,
    ATTRIB_TYPE_FLOAT_ARRAY = 9,
    ATTRIB_TYPE_UPDATE_PLAYBACK_POS = 10,
    ATTRIB_TYPE_PLAYBACK_POS = 11,
    ATTRIB_TYPE_UPDATE_SYNC_EVENT_PLAYBACK_POS = 12,
    ATTRIB_TYPE_TRANSFORM_BUFFER = 13,
    ATTRIB_TYPE_TRAJECTORY_DELTA_TRANSFORM = 14,
    ATTRIB_TYPE_TRANSFORM = 15,
    ATTRIB_TYPE_VELOCITY = 16,
    ATTRIB_TYPE_SYNC_EVENT_TRACK = 17,
    ATTRIB_TYPE_SAMPLED_EVENTS_BUFFER = 18,
    ATTRIB_TYPE_DURATION_EVENT_TRACK_SET = 19,
    ATTRIB_TYPE_RIG = 20,
    ATTRIB_TYPE_SOURCE_ANIM = 21,
    ATTRIB_TYPE_SOURCE_EVENT_TRACKS = 23,
    ATTRIB_TYPE_HEAD_LOOK_SETUP = 24,
    ATTRIB_TYPE_HEAD_LOOK_CHAIN = 25,
    ATTRIB_TYPE_GUN_AIM_SETUP = 26,
    ATTRIB_TYPE_GUN_AIM_IK_CHAIN = 27,
    ATTRIB_TYPE_TWO_BONE_IK_SETUP = 28,
    ATTRIB_TYPE_TWO_BONE_IK_CHAIN = 29,
    ATTRIB_TYPE_LOCK_FOOT_SETUP = 30,
    ATTRIB_TYPE_LOCK_FOOT_CHAIN = 31,
    ATTRIB_TYPE_LOCK_FOOT_STATE = 32,
    ATTRIB_TYPE_HIPS_IK_DEF = 33,
    ATTRIB_TYPE_HIPS_IK_ANIM_SET_DEF = 34,
    ATTRIB_TYPE_CLOSEST_ANIM_DEF = 35,
    ATTRIB_TYPE_CLOSEST_ANIM_DEF_ANIM_SET = 36,
    ATTRIB_TYPE_CLOSEST_ANIM_STATE = 37,
    ATTRIB_TYPE_STATE_MACHINE_DEF = 38,
    ATTRIB_TYPE_STATE_MACHINE = 39,
    ATTRIB_TYPE_CHARACTER_PROPERTIES = 42,
    ATTRIB_TYPE_CHARACTER_CONTROLLER_DEF = 43,
    ATTRIB_TYPE_PHYSICS_SETUP = 45,
    ATTRIB_TYPE_PHYSICS_SETUP_ANIM_SET = 46,
    ATTRIB_TYPE_PHYSICS_STATE = 47,
    ATTRIB_TYPE_PHYSICS_INITIALISATION = 48,
    ATTRIB_TYPE_PHYSICS_GROUPER_CONFIG = 49,
    ATTRIB_TYPE_FLOAT_OPERATION = 50,
    ATTRIB_TYPE_2_FLOAT_OPERATION = 51,
    ATTRIB_TYPE_SMOOTH_FLOAT_OPERATION = 52,
    ATTRIB_TYPE_RATE_OF_CHANGE_OPERATION = 53,
    ATTRIB_TYPE_RANDOM_FLOAT_OPERATION = 54,
    ATTRIB_TYPE_RANDOM_FLOAT_DEF = 55,
    ATTRIB_TYPE_NOISE_GEN_DEF = 56,
    ATTRIB_TYPE_SWITCH_DEF = 57,
    ATTRIB_TYPE_RAY_CAST_DEF = 58,
    ATTRIB_TYPE_TRANSIT_DEF = 59,
    ATTRIB_TYPE_TRANSIT_SYNC_EVENTS_DEF = 60,
    ATTRIB_TYPE_TRANSIT_SYNC_EVENTS = 61,
    ATTRIB_TYPE_DEAD_BLEND_DEF = 62,
    ATTRIB_TYPE_DEAD_BLEND_STATE = 63,
    ATTRIB_TYPE_BLEND_NXM_DEF = 65,
    ATTRIB_TYPE_ANIM_MIRRORED_MAPPING = 66,
    ATTRIB_TYPE_PLAYBACK_POS_INIT = 67,
    ATTRIB_TYPE_EMITTED_MESSAGE_MAP = 68,
    ATTRIB_TYPE_BASIC_UNEVEN_TERRAIN_SETUP = 69,
    ATTRIB_TYPE_BASIC_UNEVEN_TERRAIN_IK_SETUP = 70,
    ATTRIB_TYPE_BASIC_UNEVEN_TERRAIN_FOOT_LIFTING_TARGET = 71,
    ATTRIB_TYPE_BASIC_UNEVEN_TERRAIN_IK_STATE = 72,
    ATTRIB_TYPE_BASIC_UNEVEN_TERRAIN_CHAIN = 73,
    ATTRIB_TYPE_PREDICTIVE_UNEVEN_TERRAIN_IK_PREDICTION_STATE = 74,
    ATTRIB_TYPE_PREDICTIVE_UNEVEN_TERRAIN_FOOT_LIFTING_STATE = 75,
    ATTRIB_TYPE_PREDICTIVE_UNEVEN_TERRAIN_PREDICTION_DEF = 76,
    ATTRIB_TYPE_SCATTER_BLEND_ANALYSIS_DEF = 77,
    ATTRIB_TYPE_SCATTER_BLEND_1D_DEF = 78,
    ATTRIB_TYPE_SCATTER_BLEND_2D_DEF = 79,
    ATTRIB_TYPE_EMIT_MESSAGE_ON_CP_VALUE = 81,
    ATTRIB_TYPE_PHYSICS_INFO_DEF = 82,
    ATTRIB_TYPE_JOINT_LIMITS = 84,
    ATTRIB_TYPE_BLEND_FLAGS = 85,
    ATTRIB_TYPE_BLEND_WEIGHTS = 86,
    ATTRIB_TYPE_FEATHER_BLEND2_CHANNEL_ALPHAS = 87,
    ATTRIB_TYPE_RETARGET_STATE = 88,
    ATTRIB_TYPE_RIG_RETARGET_MAPPING = 89,
    ATTRIB_TYPE_SCALECHARACTER_STATE = 90,
    ATTRIB_TYPE_RETARGET_STORAGE_STATS = 91,
    ATTRIB_TYPE_C_C_OVERRIDE_CONDITIONS_DEF = 92,
    ATTRIB_TYPE_C_C_OVERRIDE_PROPERTIES_DEF = 93,
    ATTRIB_TYPE_C_C_OVERRIDE_CONDITIONS = 94,
};

enum AttribSemantic : short
{
    ATTRIB_SEMANTIC_UPDATE_TIME_POS = 0,
    ATTRIB_SEMANTIC_UPDATE_SYNC_EVENT_POS = 1,
    ATTRIB_SEMANTIC_TIME_POS = 2,
    ATTRIB_SEMANTIC_ANIM_SAMPLE_POS = 3,
    ATTRIB_SEMANTIC_FRACTION_POS = 4,
    ATTRIB_SEMANTIC_LOOPED_ON_UPDATE = 5,
    ATTRIB_SEMANTIC_TRANSFORM_BUFFER = 6,
    ATTRIB_SEMANTIC_TRAJECTORY_DELTA_TRANSFORM = 7,
    ATTRIB_SEMANTIC_TRAJECTORY_TRANSFORM = 8,
    ATTRIB_SEMANTIC_TRAJECTORY_DELTA_TRANSFORM_BUFFER = 9,
    ATTRIB_SEMANTIC_VELOCITY = 10,
    ATTRIB_SEMANTIC_TRANSFORM_RATES = 11,
    ATTRIB_SEMANTIC_SYNC_EVENT_TRACK = 12,
    ATTRIB_SEMANTIC_SAMPLED_EVENTS_BUFFER = 13,
    ATTRIB_SEMANTIC_DURATION_EVENT_TRACK_SET = 14,
    ATTRIB_SEMANTIC_LOOP = 15,
    ATTRIB_SEMANTIC_RIG = 16,
    ATTRIB_SEMANTIC_SOURCE_ANIM = 17,
    ATTRIB_SEMANTIC_START_SYNC_EVENT_INDEX = 18,
    ATTRIB_SEMANTIC_SOURCE_EVENT_TRACKS = 19,
    ATTRIB_SEMANTIC_ACTIVE_ANIM_SET_INDEX = 20,
    ATTRIB_SEMANTIC_BLEND_FLAGS = 21,
    ATTRIB_SEMANTIC_BLEND_WEIGHTS = 22,
    ATTRIB_SEMANTIC_CP_BOOL = 23,
    ATTRIB_SEMANTIC_CP_UINT = 24,
    ATTRIB_SEMANTIC_CP_PHYSICS_OBJECT_POINTER = 25,
    ATTRIB_SEMANTIC_CP_INT = 26,
    ATTRIB_SEMANTIC_CP_FLOAT = 27,
    ATTRIB_SEMANTIC_CP_VECTOR3 = 28,
    ATTRIB_SEMANTIC_CP_VECTOR4 = 29,
    ATTRIB_SEMANTIC_RIG_RETARGET_MAPPING = 30,
    ATTRIB_SEMANTIC_RETARGET_STORAGE_STATS = 31,
    ATTRIB_SEMANTIC_MIRRORED_ANIM_MAPPING = 32,
    ATTRIB_SEMANTIC_SYNC_EVENT_OFFSET = 33,
    ATTRIB_SEMANTIC_CHILD_NODE_WEIGHTS = 34,
    ATTRIB_SEMANTIC_BONE_WEIGHTS = 35,
    ATTRIB_SEMANTIC_BONE_IDS = 36,
    ATTRIB_SEMANTIC_NODE_SPECIFIC_DEF = 37,
    ATTRIB_SEMANTIC_NODE_SPECIFIC_DEF_ANIM_SET = 38,
    ATTRIB_SEMANTIC_NODE_SPECIFIC_STATE = 39,
    ATTRIB_SEMANTIC_NODE_SPECIFIC_STATE_2 = 40,
    ATTRIB_SEMANTIC_PHYSICS_RIG_DEF = 41,
    ATTRIB_SEMANTIC_PHYSICS_RIG = 42,
    ATTRIB_SEMANTIC_CHARACTER_PROPERTIES = 43,
    ATTRIB_SEMANTIC_CHARACTER_CONTROLLER_DEF = 44,
    ATTRIB_SEMANTIC_ANIM_TO_PHYSICS_MAP = 45,
    ATTRIB_SEMANTIC_PHYSICS_INITIALISATION = 46,
    ATTRIB_SEMANTIC_OUTPUT_MASK = 47,
    ATTRIB_SEMANTIC_PRE_PHYSICS_TRANSFORMS = 48,
    ATTRIB_SEMANTIC_CHARACTER_CONTROLLER_UPDATED = 49,
    ATTRIB_SEMANTIC_PHYSICS_UPDATED = 50,
    ATTRIB_SEMANTIC_ROOT_UPDATED = 51,
    ATTRIB_SEMANTIC_MERGED_PHYSICS_RIG_TRANSFORM_BUFFER = 52,
    ATTRIB_SEMANTIC_TRANSIT_COMPLETE = 53,
    ATTRIB_SEMANTIC_TRANSIT_REVERSED = 54,
    ATTRIB_SEMANTIC_DURATION_EVENT_MATCHING_OP = 55,
    ATTRIB_SEMANTIC_DEAD_BLEND_DEF = 56,
    ATTRIB_SEMANTIC_DEAD_BLEND_STATE = 57,
    ATTRIB_SEMANTIC_DEAD_BLEND_TRANSFORMS_STATE = 58,
    ATTRIB_SEMANTIC_PLAYBACK_POS_INIT = 59,
    ATTRIB_SEMANTIC_EMITTED_MESSAGES_MAP = 60,
    ATTRIB_SEMANTIC_EMITTED_MESSAGES = 61,
    ATTRIB_SEMANTIC_UNEVEN_TERRAIN_IK_SETUP = 62,
    ATTRIB_SEMANTIC_UNEVEN_TERRAIN_FOOT_LIFTING_TARGET = 63,
    ATTRIB_SEMANTIC_UNEVEN_TERRAIN_PREDICTION_DEF = 64,
    ATTRIB_SEMANTIC_UNEVEN_TERRAIN_PREDICTION_STATE = 65,
    ATTRIB_SEMANTIC_JOINT_LIMITS = 66,
    ATTRIB_SEMANTIC_RETARGET_RIG_MAP = 67,
    ATTRIB_SEMANTIC_UPDATE_TIME_POS_T_MINUS_ONE = 68,
    ATTRIB_SEMANTIC_TRAJECTORY_DELTA_T_MINUS_ONE = 69,
    ATTRIB_SEMANTIC_TRANSFORM_BUFFER_T_MINUS_ONE = 70,
    ATTRIB_SEMANTIC_TRANSFORM_BUFFER_T_MINUS_TWO = 71,
    ATTRIB_SEMANTIC_RETARGET_STATE = 72,
};

/*enum TaskID
{
    TaskAnimSyncEventsUpdateTimePos = 0,
    TaskAnimSyncEventsUpdateSyncEventPos = 1,
    TaskSampleTransformsFromAnimSourceASA = 2,
    TaskSampleTransformsFromAnimSourceMBA = 3,
    TaskSampleTransformsFromAnimSourceNSA = 4,
    TaskSampleTransformsFromAnimSourceQSA = 5,
    TaskUpdateDeltaTrajectoryFromTrajectorySourceASA = 6,
    TaskUpdateDeltaTrajectoryFromTrajectorySourceMBA = 7,
    TaskUpdateDeltaTrajectoryFromTrajectorySourceNSA = 8,
    TaskUpdateDeltaTrajectoryFromTrajectorySourceQSA = 9,
    TaskUpdateDeltaTrajectoryAndTransformsFromSourceASA = 10,
    TaskUpdateDeltaTrajectoryAndTransformsFromSourceMBA = 11,
    TaskUpdateDeltaTrajectoryAndTransformsFromSourceNSA = 12,
    TaskUpdateDeltaTrajectoryAndTransformsFromSourceQSA = 13,
    TaskInitSyncEventTrackFromDiscreteEventTrack = 14,
    TaskInitUnitLengthSyncEventTrack = 15,
    TaskSampleEventsFromSourceTracks = 16,
    TaskSampleEventsFromSourceTracksIncDurationEvents = 17,
    TaskInitEventTrackDurationSetFromSource = 18,
    TaskInitEmptyEventTrackDurationSet = 19,
    TaskInitSampledEventsBuffer = 20,
    TaskBufferLastFramesTransformBuffer = 21,
    TaskBufferLastFramesTrajectoryDeltaAndTransformBuffer = 22,
    TaskBufferLastFramesTransformsZeroTrajectory = 23,
    TaskBlend2TransformBuffsAddAttAddPos = 24,
    TaskBlend2TransformBuffsAddAttInterpPos = 25,
    TaskBlend2TransformBuffsInterpAttAddPos = 26,
    TaskBlend2TransformBuffsInterpAttInterpPos = 27,
    TaskBlend2TransformBuffsSubtractAttSubtractPos = 28,
    TaskBlend2x2TransformBuffsInterpAttInterpPos = 29,
    TaskBlend2x2TrajectoryDeltaTransformsInterpAttInterpPos = 30,
    TaskBlend2x2TrajectoryDeltaTransformsInterpAttSlerpPos = 31,
    TaskBlend2x2TrajectoryDeltaAndTransformsInterpTraj = 32,
    TaskBlend2x2TrajectoryDeltaAndTransformsSlerpTraj = 33,
    TaskCombine2x2SampledEventsBuffers = 34,
    TaskCombine2x2SampledEventsBuffersAndSampleDurationEvents = 35,
    TaskBlend2x2DurationEventTrackSets = 36,
    TaskBlend2x2SyncEventTracks = 37,
    TaskTriangleBlendTransformBuffsInterpAttInterpPos = 38,
    TaskTriangleBlendTrajectoryDeltaTransformsInterpAttInterpPos = 39,
    TaskTriangleBlendTrajectoryDeltaTransformsInterpAttSlerpPos = 40,
    TaskTriangleBlendTrajectoryDeltaAndTransformsInterpTraj = 41,
    TaskTriangleBlendTrajectoryDeltaAndTransformsSlerpTraj = 42,
    TaskTriangleCombineSampledEventsBuffers = 43,
    TaskTriangleCombineSampledEventsBuffersAndSampleDurationEvents = 44,
    TaskTriangleBlendDurationEventTrackSets = 45,
    TaskTriangleBlendSyncEventTracks = 46,
    TaskBlendAllTransformBuffsInterpAttInterpPos = 47,
    TaskCombineAllSampledEventsBuffers = 48,
    TaskCombineAllSampledEventsBuffersAndSampleDurationEvents = 49,
    TaskBlendAllTrajectoryDeltaTransformsInterpAttInterpPos = 50,
    TaskBlendAllTrajectoryDeltaTransformsInterpAttSlerpPos = 51,
    TaskBlendAllTrajectoryDeltaAndTransformsSlerpTraj = 52,
    TaskBlendAllTrajectoryDeltaAndTransformsInterpTraj = 53,
    TaskBlendAllDurationEventTrackSets = 54,
    TaskBlendAllSyncEventTracks = 55,
    TaskFeatherBlend2TransformBuffsAddAttAddPos = 56,
    TaskFeatherBlend2TransformBuffsAddAttInterpPos = 57,
    TaskFeatherBlend2TransformBuffsInterpAttAddPos = 58,
    TaskFeatherBlend2TransformBuffsInterpAttInterpPos = 59,
    TaskHeadLookTransforms = 61,
    TaskHeadLookTrajectoryDeltaAndTransforms = 62,
    TaskHeadLookSetup = 63,
    TaskGunAimTransforms = 64,
    TaskGunAimTrajectoryDeltaAndTransforms = 65,
    TaskGunAimSetup = 66,
    TaskTwoBoneIKTransforms = 67,
    TaskTwoBoneIKTrajectoryDeltaAndTransforms = 68,
    TaskTwoBoneIKSetup = 69,
    TaskLockFootTransforms = 70,
    TaskHipsIKTransforms = 71,
    TaskHipsIKTrajectoryDeltaAndTransforms = 72,
    TaskRetargetTransforms = 73,
    TaskRetargetTrajectoryDeltaTransform = 74,
    TaskRetargetTrajectoryDeltaAndTransforms = 75,
    TaskLockFootTrajectoryDeltaAndTransforms = 76,
    TaskScaleCharacterTransforms = 77,
    TaskScaleCharacterDeltaTransform = 78,
    TaskScaleCharacterDeltaAndTransforms = 79,
    TaskBasicUnevenTerrainIKSetup = 80,
    TaskBasicUnevenTerrainFootLiftingTarget = 81,
    TaskBasicUnevenTerrainTransforms1 = 82,
    TaskBasicUnevenTerrainTransforms2 = 83,
    TaskPredictiveUnevenTerrainIKSetup = 84,
    TaskPredictiveUnevenTerrainFootLiftingTarget = 85,
    TaskPredictiveUnevenTerrainTransforms1 = 86,
    TaskPredictiveUnevenTerrainTransforms2 = 87,
    TaskCombine2SampledEventsBuffers = 88,
    TaskCombine2SampledEventsBuffersAndSampleDurationEvents = 89,
    TaskBlend2DurationEventTrackSets = 90,
    TaskBlend2TrajectoryDeltaTransformsAddAttAddPos = 91,
    TaskBlend2TrajectoryDeltaTransformsAddAttInterpPos = 92,
    TaskBlend2TrajectoryDeltaTransformsAddAttSlerpPos = 93,
    TaskBlend2TrajectoryDeltaTransformsInterpAttAddPos = 94,
    TaskBlend2TrajectoryDeltaTransformsInterpAttInterpPos = 95,
    TaskBlend2TrajectoryDeltaTransformsInterpAttSlerpPos = 96,
    TaskBlend2TrajectoryDeltaTransformsSubtractAttSubtractPos = 97,
    TaskBlend2TrajectoryDeltaTransformsSubtractAttSlerpPos = 98,
    TaskBlend2TrajectoryAndTransformsAddAttAddPosSlerpTraj = 99,
    TaskBlend2TrajectoryAndTransformsAddAttInterpPosSlerpTraj = 100,
    TaskBlend2TrajectoryAndTransformsInterpAttAddPosSlerpTraj = 101,
    TaskBlend2TrajectoryAndTransformsInterpAttInterpPosSlerpTraj = 102,
    TaskBlend2TrajectoryAndTransformsSubtractAttSubtractPosSlerpTraj = 103,
    TaskBlend2TrajectoryAndTransformsAddAttAddPosInterpTraj = 104,
    TaskBlend2TrajectoryAndTransformsAddAttInterpPosInterpTraj = 105,
    TaskBlend2TrajectoryAndTransformsInterpAttAddPosInterpTraj = 106,
    TaskBlend2TrajectoryAndTransformsInterpAttInterpPosInterpTraj = 107,
    TaskBlend2TrajectoryAndTransformsSubtractAttSubtractPosInterpTraj = 108,
    TaskBlend2TransformsAddAttAddPosPassDestTraj = 109,
    TaskBlend2TransformsAddAttInterpPosPassDestTraj = 110,
    TaskBlend2TransformsInterpAttAddPosPassDestTraj = 111,
    TaskBlend2TransformsInterpAttInterpPosPassDestTraj = 112,
    TaskBlend2TransformsAddAttAddPosPassSourceTraj = 113,
    TaskBlend2TransformsAddAttInterpPosPassSourceTraj = 114,
    TaskBlend2TransformsInterpAttAddPosPassSourceTraj = 115,
    TaskBlend2TransformsInterpAttInterpPosPassSourceTraj = 116,
    TaskFeatherBlend2TrajectoryDeltaTransformsAddAttAddPos = 117,
    TaskFeatherBlend2TrajectoryDeltaTransformsAddAttInterpPos = 118,
    TaskFeatherBlend2TrajectoryDeltaTransformsAddAttSlerpPos = 119,
    TaskFeatherBlend2TrajectoryDeltaTransformsInterpAttAddPos = 120,
    TaskFeatherBlend2TrajectoryDeltaTransformsInterpAttInterpPos = 121,
    TaskFeatherBlend2TrajectoryDeltaTransformsInterpAttSlerpPos = 122,
    TaskFeatherBlend2TrajectoryDeltaAndTransformsAddAttAddPosSlerpTraj = 123,
    TaskFeatherBlend2TrajectoryDeltaAndTransformsAddAttInterpPosSlerpTraj = 124,
    TaskFeatherBlend2TrajectoryDeltaAndTransformsInterpAttAddPosSlerpTraj = 125,
    TaskFeatherBlend2TrajectoryDeltaAndTransformsInterpAttInterpPosSlerpTraj = 126,
    TaskFeatherBlend2TrajectoryDeltaAndTransformsAddAttAddPosInterpTraj = 127,
    TaskFeatherBlend2TrajectoryDeltaAndTransformsAddAttInterpPosInterpTraj = 128,
    TaskFeatherBlend2TrajectoryDeltaAndTransformsInterpAttAddPosInterpTraj = 129,
    TaskFeatherBlend2TrajectoryDeltaAndTransformsInterpAttInterpPosInterpTraj = 130,
    TaskBlend2SyncEventsUpdateTimeViaTimePos = 131,
    TaskBlend2SyncEventsUpdateTimeViaSyncEventPos = 132,
    TaskBlend2SyncEventTracks = 133,
    TaskScaleUpdateTime = 134,
    TaskScaleUpdateSyncEventTrack = 135,
    TaskSetUpdateTimeViaControlParam = 136,
    TaskFilterTransforms = 137,
    TaskFilterTrajectoryDelta = 138,
    TaskFilterTrajectoryDeltaAndTransforms = 139,
    TaskApplyBindPoseTransforms = 140,
    TaskApplyBindPoseTrajectoryDeltaAndTransforms = 141,
    TaskApplyGlobalTimeUpdateTimePos = 142,
    TaskGetBindPoseTransforms = 143,
    TaskMirrorTransforms = 144,
    TaskMirrorTrajectoryDelta = 145,
    TaskMirrorTrajectoryDeltaAndTransforms = 146,
    TaskMirrorSampledEvents = 147,
    TaskMirrorSampledAndSampleDurationEvents = 148,
    TaskMirrorSyncEventsAndOffset = 149,
    TaskMirrorDurationEvents = 150,
    TaskMirrorUpdateTimeViaSyncEventPos = 151,
    TaskMirrorUpdateTimeViaTimePos = 152,
    TaskClosestAnimTransforms = 153,
    TaskClosestAnimTrajectoryDelta = 154,
    TaskClosestAnimTrajectoryDeltaAndTransforms = 155,
    TaskNetworkUpdateCharacterController = 166,
    TaskNetworkUpdatePhysics = 167,
    TaskNetworkUpdateRoot = 168,
    TaskNetworkMergePhysicsRigTransformBuffers = 169,
    TaskNetworkDummyTask = 170,
    TaskEmptyTask = 171,
    TaskTransitUpdateTimePos = 172,
    TaskTransitDeadBlendUpdateTimePos = 173,
    TaskTransitSyncEventsUpdateTimeViaSyncEventPos = 174,
    TaskTransitSyncEventsUpdateTimeViaTimePos = 175,
    TaskTransitSyncEventsBlendSyncEventTracks = 176,
    TaskTransitSyncEventsPassThroughSyncEventTrack = 177,
    TaskDeadBlendCacheState = 178,
    TaskAnimDeadBlendTransformBuffs = 180,
    TaskAnimDeadBlendTrajectoryDeltaAndTransformBuffs = 181,
    TaskDeadBlendTrajectory = 182,
    TaskOutputSmoothTransformsTransforms = 184,
    TaskOutputSmoothTransformsTrajectoryDeltaAndTransforms = 185,
    TaskScaleToDuration = 186,
    TaskScaleToDurationSyncEventTrack = 187,
    TaskPassThroughTransformsExtractJointInfoObjectSpace = 201,
    TaskPassThroughTransformsExtractJointInfoLocalSpace = 202,
    TaskPassThroughTransformsExtractJointInfoObjectSpaceJointSelect = 203,
    TaskPassThroughTransformsExtractJointInfoLocalSpaceJointSelect = 204,
    TaskPassThroughTrajectoryDeltaAndTransformsExtractJointInfoObjectSpace = 205,
    TaskPassThroughTrajectoryDeltaAndTransformsExtractJointInfoLocalSpace = 206,
    TaskPassThroughTrajectoryDeltaAndTransformsExtractJointInfoObjectSpaceJointSelect = 207,
    TaskPassThroughTrajectoryDeltaAndTransformsExtractJointInfoLocalSpaceJointSelect = 208,
    TaskSampledEventsBufferEmitMessageAndPassThrough = 209,
    TaskCreateReferenceToInputAttribTypeUpdatePlaybackPos = 216,
    TaskCreateReferenceToInputAttribTypeUpdateSyncEventPlaybackPos = 217,
    TaskCreateReferenceToInputAttribTypePlaybackPos = 218,
    TaskCreateReferenceToInputAttribTypePlaybackPos = 219,
    TaskCreateReferenceToInputAttribTypePlaybackPos = 220,
    TaskCreateReferenceToInputAttribTypeTransformBuffer = 222,
    TaskCreateReferenceToInputAttribTypeTrajectoryDeltaTransform = 223,
    TaskCreateReferenceToInputAttribTypeTransform = 224,
    TaskCreateReferenceToInputAttribTypeTransformBuffer = 225,
    TaskCreateReferenceToInputAttribTypeSyncEventTrack = 228,
    TaskCreateReferenceToInputAttribTypeSampledEvents = 229,
    TaskCreateReferenceToInputAttribTypeDurationEventTrackSet = 230,
    TaskCreateReferenceToInputAttribTypeFloat = 243,
    TaskCreateReferenceToInputAttribTypeFloat = 244,
    TaskCreateReferenceToInputAttribTypeVector4 = 245,
    TaskCreateReferenceToInputAttribTypeUIntArray = 252,
    TaskCreateReferenceToInputAttribTypeBoolArray = 263
};*/

namespace Morpheme
{
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

    struct NodeDataContent_Bool
    {
        bool attrib_bool;
    };

    struct NodeDataContent_FloatArray
    {
        int size;
        int padding;
        float* flt_array;
    };

    struct NodeDataContent_SourceAnim
    {
        uint64_t nsa_data;
        uint64_t lVar18;
        int iVar20;
        float fVar24;
        int iVar28;
        int iVar2C;
        int iVar30;
        int iVar34;
        float fVar38;
        float fVar3C;
        float fVar40;
        float fVar44;
        int iVar48;
        int iVar4C;
        int iVar50;
        int iVar54;
        float fVar58;
        float fVar5C;
        uint64_t lVar60;
        int iVar68;
        int iVar6C;
        int iVar70;
        int iVar74;
        int iVar78;
        BYTE bVar7C;
        BYTE bvar7D;
        BYTE bVar7E;
        BYTE bVar7F;
        float track_start;
        float track_lenght;
        float anim_lenght;
        int iVar8C;
        BYTE bVar90;
        BYTE padding[15];
    };

    struct NodeDataContentBase 
    {
        int field0_0x0;
        int field1_0x4;
        short field2_0x8;
        AttribType m_type;
        int padding;
        uint64_t data_start;
    };

    struct NodeDataBase
    {
        NodeDataContentBase* content;
        int size;
        int alignment;
        int iVar0;
        int iVar1;
    };

    struct sNodeData
    {
        NodeDataBase data[10];
    };

    struct NodeDef {
        NodeType m_nodeTypeID;
        BYTE m_flags1;
        BYTE m_flags2;
        short m_nodeID;
        short m_parentNodeID;
        uint16_t m_numChildNodeIDs;
        uint16_t field7_0xc;
        BYTE m_numControlParamAndOpNodeIDs;
        BYTE field8_0xf;
        uint16_t field9_0x10;
        uint16_t field10_0x12;
        int padding;
        struct NetworkDef* m_owningNetworkDef;
        short* m_childNodeIDs;
        int* m_controlParamAndOpNodeIDs;
        sNodeData* node_data;
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
        BYTE field27_0x80;
        BYTE field28_0x81;
        BYTE field29_0x82;
        BYTE field30_0x83;
        BYTE field31_0x84;
        BYTE field32_0x85;
        BYTE field33_0x86;
        BYTE field34_0x87;
        uint64_t field35_0x88;
    };

    struct sEventTrackEventData {
        float m_startTime;
        float m_duration;
        int m_userData;
    };

    struct EventTrackDef {
        uint32_t m_numEvents;
        uint32_t field1_0x4;
        char* m_trackName;
        uint32_t m_eventId;
        uint32_t m_trackType;
        sEventTrackEventData* m_trackData;
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
        NodeDataContentBase* m_nodeDataBase;
        int size;
        int alignment;
        int iVar0;
        int iVar1;
        NodeDataContentBase* m_animData;
        int size_1;
        int alignment_1;
        int iVar0_1;
        int iVar1_1;
        sEventTrackData* m_eventTrackData;
        int size_2;
        int alignment_2;
        int iVar0_2;
        int iVar1_2;
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
        BYTE field5_0x1c;
        BYTE field6_0x1d;
        BYTE field7_0x1e;
        BYTE field8_0x1f;
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
        BYTE field19_0x54;
        BYTE field20_0x55;
        BYTE field21_0x56;
        BYTE field22_0x57;
        BYTE field23_0x58;
        BYTE field24_0x59;
        BYTE field25_0x5a;
        BYTE field26_0x5b;
        BYTE field27_0x5c;
        BYTE field28_0x5d;
        BYTE field29_0x5e;
        BYTE field30_0x5f;
        BYTE field31_0x60;
        BYTE field32_0x61;
        BYTE field33_0x62;
        BYTE field34_0x63;
        BYTE field35_0x64;
        BYTE field36_0x65;
        BYTE field37_0x66;
        BYTE field38_0x67;
        BYTE field39_0x68;
        BYTE field40_0x69;
        BYTE field41_0x6a;
        BYTE field42_0x6b;
        BYTE field43_0x6c;
        BYTE field44_0x6d;
        BYTE field45_0x6e;
        BYTE field46_0x6f;
        BYTE field47_0x70;
        BYTE field48_0x71;
        BYTE field49_0x72;
        BYTE field50_0x73;
        BYTE field51_0x74;
        BYTE field52_0x75;
        BYTE field53_0x76;
        BYTE field54_0x77;
        BYTE field55_0x78;
        BYTE field56_0x79;
        BYTE field57_0x7a;
        BYTE field58_0x7b;
        BYTE field59_0x7c;
        BYTE field60_0x7d;
        BYTE field61_0x7e;
        BYTE field62_0x7f;
        BYTE field63_0x80;
        BYTE field64_0x81;
        BYTE field65_0x82;
        BYTE field66_0x83;
        BYTE field67_0x84;
        BYTE field68_0x85;
        BYTE field69_0x86;
        BYTE field70_0x87;
        BYTE field71_0x88;
        BYTE field72_0x89;
        BYTE field73_0x8a;
        BYTE field74_0x8b;
        BYTE field75_0x8c;
        BYTE field76_0x8d;
        BYTE field77_0x8e;
        BYTE field78_0x8f;
        BYTE field79_0x90;
        BYTE field80_0x91;
        BYTE field81_0x92;
        BYTE field82_0x93;
        BYTE field83_0x94;
        BYTE field84_0x95;
        BYTE field85_0x96;
        BYTE field86_0x97;
        BYTE field87_0x98;
        BYTE field88_0x99;
        BYTE field89_0x9a;
        BYTE field90_0x9b;
        BYTE field91_0x9c;
        BYTE field92_0x9d;
        BYTE field93_0x9e;
        BYTE field94_0x9f;
        BYTE field95_0xa0;
        BYTE field96_0xa1;
        BYTE field97_0xa2;
        BYTE field98_0xa3;
        BYTE field99_0xa4;
        BYTE field100_0xa5;
        BYTE field101_0xa6;
        BYTE field102_0xa7;
        BYTE field103_0xa8;
        BYTE field104_0xa9;
        BYTE field105_0xaa;
        BYTE field106_0xab;
        BYTE field107_0xac;
        BYTE field108_0xad;
        BYTE field109_0xae;
        BYTE field110_0xaf;
        BYTE field111_0xb0;
        BYTE field112_0xb1;
        BYTE field113_0xb2;
        BYTE field114_0xb3;
        BYTE field115_0xb4;
        BYTE field116_0xb5;
        BYTE field117_0xb6;
        BYTE field118_0xb7;
        BYTE field119_0xb8;
        BYTE field120_0xb9;
        BYTE field121_0xba;
        BYTE field122_0xbb;
        BYTE field123_0xbc;
        BYTE field124_0xbd;
        BYTE field125_0xbe;
        BYTE field126_0xbf;
        BYTE field127_0xc0;
        BYTE field128_0xc1;
        BYTE field129_0xc2;
        BYTE field130_0xc3;
        BYTE field131_0xc4;
        BYTE field132_0xc5;
        BYTE field133_0xc6;
        BYTE field134_0xc7;
        BYTE field135_0xc8;
        BYTE field136_0xc9;
        BYTE field137_0xca;
        BYTE field138_0xcb;
        BYTE field139_0xcc;
        BYTE field140_0xcd;
        BYTE field141_0xce;
        BYTE field142_0xcf;
        BYTE field143_0xd0;
        BYTE field144_0xd1;
        BYTE field145_0xd2;
        BYTE field146_0xd3;
        BYTE field147_0xd4;
        BYTE field148_0xd5;
        BYTE field149_0xd6;
        BYTE field150_0xd7;
        BYTE field151_0xd8;
        BYTE field152_0xd9;
        BYTE field153_0xda;
        BYTE field154_0xdb;
        BYTE field155_0xdc;
        BYTE field156_0xdd;
        BYTE field157_0xde;
        BYTE field158_0xdf;
        BYTE field159_0xe0;
        BYTE field160_0xe1;
        BYTE field161_0xe2;
        BYTE field162_0xe3;
        BYTE field163_0xe4;
        BYTE field164_0xe5;
        BYTE field165_0xe6;
        BYTE field166_0xe7;
        BYTE field167_0xe8;
        BYTE field168_0xe9;
        BYTE field169_0xea;
        BYTE field170_0xeb;
        BYTE field171_0xec;
        BYTE field172_0xed;
        BYTE field173_0xee;
        BYTE field174_0xef;
        BYTE field175_0xf0;
        BYTE field176_0xf1;
        BYTE field177_0xf2;
        BYTE field178_0xf3;
        BYTE field179_0xf4;
        BYTE field180_0xf5;
        BYTE field181_0xf6;
        BYTE field182_0xf7;
        BYTE field183_0xf8;
        BYTE field184_0xf9;
        BYTE field185_0xfa;
        BYTE field186_0xfb;
        BYTE field187_0xfc;
        BYTE field188_0xfd;
        BYTE field189_0xfe;
        BYTE field190_0xff;
        BYTE field191_0x100;
        BYTE field192_0x101;
        BYTE field193_0x102;
        BYTE field194_0x103;
        BYTE field195_0x104;
        BYTE field196_0x105;
        BYTE field197_0x106;
        BYTE field198_0x107;
        BYTE field199_0x108;
        BYTE field200_0x109;
        BYTE field201_0x10a;
        BYTE field202_0x10b;
        BYTE field203_0x10c;
        BYTE field204_0x10d;
        BYTE field205_0x10e;
        BYTE field206_0x10f;
        BYTE field207_0x110;
        BYTE field208_0x111;
        BYTE field209_0x112;
        BYTE field210_0x113;
        BYTE field211_0x114;
        BYTE field212_0x115;
        BYTE field213_0x116;
        BYTE field214_0x117;
        BYTE field215_0x118;
        BYTE field216_0x119;
        BYTE field217_0x11a;
        BYTE field218_0x11b;
        BYTE field219_0x11c;
        BYTE field220_0x11d;
        BYTE field221_0x11e;
        BYTE field222_0x11f;
        BYTE field223_0x120;
        BYTE field224_0x121;
        BYTE field225_0x122;
        BYTE field226_0x123;
        BYTE field227_0x124;
        BYTE field228_0x125;
        BYTE field229_0x126;
        BYTE field230_0x127;
        BYTE field231_0x128;
        BYTE field232_0x129;
        BYTE field233_0x12a;
        BYTE field234_0x12b;
        BYTE field235_0x12c;
        BYTE field236_0x12d;
        BYTE field237_0x12e;
        BYTE field238_0x12f;
        BYTE field239_0x130;
        BYTE field240_0x131;
        BYTE field241_0x132;
        BYTE field242_0x133;
        BYTE field243_0x134;
        BYTE field244_0x135;
        BYTE field245_0x136;
        BYTE field246_0x137;
        BYTE field247_0x138;
        BYTE field248_0x139;
        BYTE field249_0x13a;
        BYTE field250_0x13b;
        BYTE field251_0x13c;
        BYTE field252_0x13d;
        BYTE field253_0x13e;
        BYTE field254_0x13f;
        BYTE field255_0x140;
        BYTE field256_0x141;
        BYTE field257_0x142;
        BYTE field258_0x143;
        BYTE field259_0x144;
        BYTE field260_0x145;
        BYTE field261_0x146;
        BYTE field262_0x147;
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
        BYTE field0_0x0;
        BYTE field1_0x1;
        BYTE field2_0x2;
        BYTE field3_0x3;
        BYTE field4_0x4;
        BYTE field5_0x5;
        BYTE field6_0x6;
        BYTE field7_0x7;
        sControlParamContainerValue* m_controlParamData;
        BYTE field9_0x10;
        BYTE field10_0x11;
        BYTE field11_0x12;
        BYTE field12_0x13;
    };

    struct sMorphemeNodeDef {
        int node_type;
        BYTE field1_0x4;
        BYTE field2_0x5;
        short field3_0x6;
        BYTE* array;
    };

    struct sMessageDef {
        int message_id;
        int field1_0x4;
        int node_count;
        int field3_0xc;
        short* node_array;
    };

    struct AttribDataHandle {
        struct MorphemeAllocator* m_allocator;
        short field1_0x8;
        AttribType m_type;
        int padding;
        short m_activeStateID;
        short m_targetStateID;
        float field6_0x14;
        float field7_0x18;
        BYTE field8_0x19;
        BYTE field9_0x1a;
        BYTE field10_0x1b;
        int field11_0x1c;
    };

    struct NodeBinEntry {
        NodeBinEntry* m_next;
        AttribDataHandle* m_attribDataHandle;
        uint32_t format_size;
        uint32_t format_alignment;
        int field4_0x18;
        int field5_0x1c;
        short m_owningNodeID;
        short m_targetNodeID;
        AttribSemantic m_semantic;
        short m_animSetIndex;
        int m_validFrame;
        int field11_0x2c;
        struct MorphemeAllocator* m_allocator;
        uint16_t m_lifespan;
    };

    struct NodeBin {
        uint32_t m_lastFrameUpdate;
        uint32_t field1_0x4;
        NodeBinEntry* m_attributes;
        uint32_t field3_0x10;
        uint32_t field4_0x14;
        struct Task* m_queuedTask;
        struct sControlParamContainer* m_controlParamContainer;
        int field7_0x28;
        int field8_0x2c;
    };

    struct NodeConnections {
        BYTE flags_1;
        BYTE flags_2;
        short m_activeParentNodeId;
        int field3_0x4;
        short* m_activeChildNodeIDs;
        short m_maxNumActiveChildNodes;
        short m_numActiveChildNodes;
        int field7_0x14;
    };

    struct NetworkDef {
        NodeDef network_node_def;
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
        BYTE field3_0x10;
        BYTE field4_0x11;
        BYTE field5_0x12;
        BYTE field6_0x13;
        BYTE field7_0x14;
        BYTE field8_0x15;
        BYTE field9_0x16;
        BYTE field10_0x17;
        struct Network* m_owningNetwork;
    };

    struct MorphemeAllocator {
        struct vtable* _vfptr;
        BYTE field1_0x8;
        BYTE field2_0x9;
        BYTE field3_0xa;
        BYTE field4_0xb;
        BYTE field5_0xc;
        BYTE field6_0xd;
        BYTE m_numControlParamAndOpNodeIDs;
        BYTE field8_0xf;
        uint64_t field9_0x10;
        BYTE field10_0x30;
        BYTE field11_0x31;
        BYTE field12_0x32;
        BYTE field13_0x33;
        BYTE field14_0x34;
        BYTE field15_0x35;
        BYTE field16_0x36;
        BYTE field17_0x37;
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
        BYTE field44_0xcc;
        BYTE field45_0xcd;
        BYTE field46_0xce;
        BYTE field47_0xcf;
        struct MorphemeChrCtrl* morpheme_chr_ctrl;
        struct sUnkMorphemeNetStruct** field49_0xd8;
        int field50_0xe0;
        int field51_0xe4;
        struct MorphemeAllocator* morpheme_allocator;
        uint32_t field53_0xf0;
        char field54_0xf4;
        BYTE field55_0xf5;
        BYTE field56_0xf6;
        BYTE field57_0xf7;
        BYTE field58_0xf8;
        BYTE field59_0xf9;
        BYTE field60_0xfa;
        BYTE field61_0xfb;
        uint32_t field62_0xfc;
        BYTE* field63_0x100;
        int field64_0x108;
        int field65_0x10c;
        BYTE field66_0x110;
        BYTE field67_0x111;
        BYTE field68_0x112;
        BYTE field69_0x113;
        BYTE field70_0x114;
        BYTE field71_0x115;
        BYTE field72_0x116;
        BYTE field73_0x117;
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

    struct SkeletonBoneData
    {
        short parent_bone;
        short child_bone[3];
        const char* bone_name;
    };

    struct SkeletonMap
    {
        int bone_count;
        SkeletonBoneData* bones;
    };

	const char* getStringFromStringTable(StringTable* string_table, int id);

	const char* getNetworkNodeName(uint64_t character_ctrl, int id);

	const char* getNetworkMessageName(uint64_t character_ctrl, int id);

	const char* getNetworkEventTrackName(uint64_t character_ctrl, int id);

    NodeDef* getNetworkNode(Network* network, short node_id);

    Network* getNetwork(uint64_t character_ctrl);

    std::vector<NodeDef*> getNetworkAllNodesType(uint64_t character_ctrl, NodeType node_type);

    const char* getAnimNameFromAnimNode(NodeDef* node);

    std::vector<NodeDef*> getNetworkControlParameterNodes(uint64_t character_ctrl);

    const char* stringTableLookup(StringTable* table, short id);

    const char* getNodeName(uint64_t character_ctrl, short node_id);

    const char* getMessageName(uint64_t character_ctrl, short message_id);

    NodeBin* getNetworkNodeBin(Morpheme::Network* network, short node_id);

    std::vector<sMessageDef*> getMessageDefs(uint64_t character_ctrl);

    NodeConnections* getNetworkNodeConnections(Morpheme::Network* network, short node_id);

    bool isNodeActive(Network* network, short node_id);

    bool isNodeContainer(Network* network, short node_id);

    bool isNodeConnectedToOutput(Network* network, short node_id);

    bool doesNodeExist(Network* network, short node_id);

    const char* getNodeTypeName_Alt(Morpheme::Network* network, short node_id);

    const char* getNodeTypeName(Morpheme::Network* network, short node_id);

    uint32_t getTimeActId(Morpheme::NodeDef* node_def);

    int getCurrentAnimFrame(Morpheme::Network* network, short node_id);
};