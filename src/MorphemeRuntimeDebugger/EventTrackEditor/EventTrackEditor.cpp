#include "EventTrackEditor.h"
#include "../Debug/Debug.h"
#include "../inih/INIReader.h"

EventTrackEditor::EventTrack::EventTrack(int signature, int numEvents, int eventId, Event* event, char* name, bool is_discrete)
{
    this->m_source = NULL;

    this->m_signature = signature;
    this->m_numEvents = numEvents;
    this->m_eventId = eventId;

    this->m_name = new char[50];
    strcpy(this->m_name, name);

    this->m_discrete = is_discrete;

    this->m_event = new Event[this->m_numEvents];

    for (size_t i = 0; i < numEvents; i++)
    {
        this->m_event[i].m_frameStart = event[i].m_frameStart;
        this->m_event[i].m_duration = event[i].m_duration;
        this->m_event[i].m_value = event[i].m_value;
    }
}

EventTrackEditor::EventTrack::EventTrack(Morpheme::EventTrackDef* src, float len, bool discrete)
{
    this->m_source = src;
    this->m_signature = 0;
    this->m_numEvents = src->m_numEvents;
    this->m_eventId = src->m_eventId;
    this->m_name = src->m_trackName;

    this->m_discrete = discrete;

    this->m_event = new Event[this->m_numEvents];

    for (size_t i = 0; i < src->m_numEvents; i++)
    {
        this->m_event[i].m_frameStart = MathHelper::TimeToFrame(src->m_trackData[i].m_startTime * len, 60);
        this->m_event[i].m_duration = MathHelper::TimeToFrame(src->m_trackData[i].m_duration * len, 60);
        this->m_event[i].m_value = src->m_trackData[i].m_userData;
    }
}

void EventTrackEditor::EventTrack::SaveEventTrackData(float len)
{
    this->m_source->m_numEvents = this->m_numEvents;
    this->m_source->m_eventId = this->m_eventId;
    
    for (int i = 0; i < this->m_numEvents; i++)
    {
        this->m_source->m_trackData[i].m_startTime = MathHelper::FrameToTime(this->m_event[i].m_frameStart, 60) / len;
        this->m_source->m_trackData[i].m_duration = MathHelper::FrameToTime(this->m_event[i].m_duration, 60) / len;
        this->m_source->m_trackData[i].m_userData = this->m_event[i].m_value;
    }
}

bool EventTrackEditor::EventTrack::IsEventActive(int event_idx, int frame)
{
    if (!this->m_discrete)
    {
        if ((frame >= this->m_event[event_idx].m_frameStart) && frame <= (this->m_event[event_idx].m_duration + this->m_event[event_idx].m_frameStart))
            return true;
    }
    else
    {
        if (frame == this->m_event[event_idx].m_frameStart)
            return true;
    }

    return false;
}


int EventTrackEditor::GetFrameMin() const
{
    return m_frameMin;
}

int EventTrackEditor::GetFrameMax() const
{
    return m_frameMax;
}

int EventTrackEditor::GetTrackCount() const { return (int)m_eventTracks.size(); }

char* EventTrackEditor::GetTrackName(int idx) const { return m_eventTracks[idx].m_name; }

std::string EventTrackEditor::GetEventLabel(int track_idx, int event_idx) const
{
    return std::to_string(this->m_eventTracks[track_idx].m_event[event_idx].m_value);
}

EventTrackEditor::EventTrackEditor() 
{
    this->m_nodeSource = nullptr;

    INIReader reader(".//MorphemeRuntimeDebugger//res//color//eventrack.ini");

    if (reader.ParseError() < 0)
    {
        Debug::Alert(Debug::LVL_ERROR, "EventTrackEditor.cpp", "Failed to load eventrack.ini\n");

        this->m_colors.m_trackColor = { 0.31f, 0.31f, 0.91f, 1.f };
        this->m_colors.m_trackColorInactive = { 0.22f, 0.22f, 0.44f, 1.f };
        this->m_colors.m_trackColorActive = { 0.39f, 0.39f, 1.f, 1.f };
        this->m_colors.m_trackBoundingBox = { 0.f, 0.f, 0.f, 1.f };
        this->m_colors.m_trackBoundingBoxActive = { 0.f, 0.f, 0.f, 1.f };
        this->m_colors.m_trackTextColor = { 1.f, 1.f, 1.f, 1.f };
        this->m_colors.m_cursorColor = { 0.f, 0.f, 0.f, 0.f };
    }

    this->m_colors.m_trackColor = { (float)reader.GetReal("Track", "r", 0.31f), (float)reader.GetReal("Track", "g", 0.31f), (float)reader.GetReal("Track", "b", 0.91f), (float)reader.GetReal("Track", "a", 1.f) };
    this->m_colors.m_trackColorInactive = { (float)reader.GetReal("TrackInactive", "r", 0.22f), (float)reader.GetReal("TrackInactive", "g", 0.22f), (float)reader.GetReal("TrackInactive", "b", 0.44f), (float)reader.GetReal("TrackInactive", "a", 1.f) };
    this->m_colors.m_trackColorActive = { (float)reader.GetReal("TrackActive", "r", 0.39f), (float)reader.GetReal("TrackActive", "g", 0.39f), (float)reader.GetReal("TrackActive", "b", 1.f), (float)reader.GetReal("TrackActive", "a", 1.f) };
    this->m_colors.m_trackBoundingBox = { (float)reader.GetReal("TrackBoundingBox", "r", 0.f), (float)reader.GetReal("TrackBoundingBox", "g", 0.f), (float)reader.GetReal("TrackBoundingBox", "b", 0.f), (float)reader.GetReal("TrackBoundingBox", "a", 1.f) };
    this->m_colors.m_trackBoundingBoxActive = { (float)reader.GetReal("TrackActiveBoundingBox", "r", 0.f), (float)reader.GetReal("TrackActiveBoundingBox", "g", 0.f), (float)reader.GetReal("TrackActiveBoundingBox", "b", 0.f), (float)reader.GetReal("TrackActiveBoundingBox", "a", 1.f) };
    this->m_colors.m_trackTextColor = { (float)reader.GetReal("TrackText", "r", 1.f), (float)reader.GetReal("TrackText", "g", 1.f), (float)reader.GetReal("TrackText", "b", 1.f), (float)reader.GetReal("TrackText", "a", 1.f) };
    this->m_colors.m_cursorColor = { (float)reader.GetReal("TrackCursor", "r", 0.f), (float)reader.GetReal("TrackCursor", "g", 0.f), (float)reader.GetReal("TrackCursor", "b", 0.f), (float)reader.GetReal("TrackCursor", "a", 0.f) };
}

void EventTrackEditor::Clear()
{
    this->m_eventTracks.clear();
}