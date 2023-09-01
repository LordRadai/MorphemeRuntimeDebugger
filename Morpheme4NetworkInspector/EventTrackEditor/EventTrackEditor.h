#pragma once
#include <math.h>
#include <cstddef>
#include <cstdlib>
#include <vector>
#include <string>

#include "../imgui/imgui.h"
#include "../Morpheme.h"
#include "../Math.h"

struct EventTrackEditor
{
    struct EventTrack
    {
        struct Event
        {
            int m_frameStart = 0;
            int m_duration = 0;
            int m_value = 0;
        };

        Morpheme::EventTrackDef* m_source;

        int m_signature;
        int m_numEvents;
        int m_eventId;
        Event* m_event;
        char* m_name;
        bool m_discrete;

        EventTrack(int signature, int numEvents, int eventId, Event* event, char* name, bool is_discrete);
        EventTrack(Morpheme::EventTrackDef* src, float len, bool discrete);

        void SaveEventTrackData(float len);
        bool IsEventActive(int event_idx, int frame);
    };

    Morpheme::NodeDef* m_nodeSource;

    int m_animIdx = -1;
    std::vector<EventTrack> m_eventTracks;
    int m_frameMin, m_frameMax;
    bool focused = false;

    struct EventTrackColor
    {
        ImVec4 m_trackColor;
        ImVec4 m_trackColorInactive;
        ImVec4 m_trackColorActive;
        ImVec4 m_trackBoundingBox;
        ImVec4 m_trackBoundingBoxActive;
        ImVec4 m_trackTextColor;
        ImVec4 m_cursorColor;
    } m_colors;

    EventTrackEditor();

    int GetFrameMin() const;
    int GetFrameMax() const;
    int GetTrackCount() const;

    char* GetTrackName(int idx) const;
    std::string GetEventLabel(int track_idx, int event_idx) const;

    void Clear();
};