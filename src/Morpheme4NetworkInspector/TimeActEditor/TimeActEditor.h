#pragma once
#include <math.h>
#include <cstddef>
#include <cstdlib>
#include <vector>
#include <string>

#include "../imgui/imgui.h"
#include "../TimeAct.h"
#include "../Math.h"

struct TimeActEditor
{
    struct TimeActTrack
    {
        struct Event
        {
            int m_frameStart = 0;
            int m_duration = 0;
            int m_value = 0;

            TimeActEventData* m_args = nullptr;
        };

        sEventGroup* m_source;
        int m_count;
        int m_eventGroup;
        std::vector<Event> m_event;
        char m_name[50];

        TimeActTrack(int eventId);
        TimeActTrack(sEventGroup* src);

        void SaveTimeActTrack();
        bool IsEventActive(int idx, int frame);
    };

    sTaeGroupContent* m_source;

    std::vector<TimeActTrack> m_tracks;
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

    TimeActEditor();

    int GetFrameMin() const;
    int GetFrameMax() const;
    int GetTrackCount() const;

    std::string GetTrackName(int idx);
    std::string GetEventLabel(int idx, int event_idx) const;

    void Clear();
};
