#include "TimeActEditor.h"
#include "../TaeTemplate/TaeTemplate.h"
#include "../inih/INIReader.h"
#include "../Debug/Debug.h"
#include "../common.h"

TimeActEditor::TimeActTrack::TimeActTrack(int eventId)
{
	this->m_source = NULL;
	this->m_eventGroup = eventId;
}

TimeActEditor::TimeActTrack::TimeActTrack(sEventGroup* src)
{
	this->m_source = src;
	this->m_count = src->group_count;

	this->m_eventGroup = *src->group_id;

	for (size_t i = 0; i < src->group_count; i++)
	{
		this->m_event.push_back(Event{ MathHelper::TimeToFrame(src->tae_data[i]->start_time, 30), MathHelper::TimeToFrame(src->tae_data[i]->end_time - src->tae_data[i]->start_time, 30), (int)src->tae_data[i]->event_data->value,  new TimeActEventData });
		this->m_event.back().m_args->GetData(src->tae_data[i]->event_data->args, *src->group_id, src->tae_data[i]->event_data->value);
	}
}

void TimeActEditor::TimeActTrack::SaveTimeActTrack()
{
	this->m_source->group_count = this->m_count;
	*this->m_source->group_id = this->m_eventGroup;

	for (size_t i = 0; i < this->m_count; i++)
	{
		this->m_source->tae_data[i]->start_time = MathHelper::FrameToTime(this->m_event[i].m_frameStart, 30);
		this->m_source->tae_data[i]->end_time = MathHelper::FrameToTime(this->m_event[i].m_frameStart + this->m_event[i].m_duration, 30);
		this->m_source->tae_data[i]->event_data->value = this->m_event[i].m_value;

		this->m_event[i].m_args->SaveData(this->m_source->tae_data[i]->event_data->args);
	}
}

bool TimeActEditor::TimeActTrack::IsEventActive(int idx, int frame)
{
	if ((frame >= this->m_event[idx].m_frameStart) && frame <= (this->m_event[idx].m_duration + this->m_event[idx].m_frameStart))
		return true;

	return false;
}

int TimeActEditor::GetFrameMin() const
{
	return m_frameMin;
}

int TimeActEditor::GetFrameMax() const
{
	return m_frameMax;
}

int TimeActEditor::GetTrackCount() const { return (int)m_tracks.size(); }

TimeActEditor::TimeActEditor() 
{
	this->m_source = nullptr;

	INIReader reader(".//MorphemeRuntimeDebugger//res//color//timeact.ini");

	if (reader.ParseError() < 0) 
	{
		Debug::Alert(Debug::LVL_ERROR, "TimeActEditor.cpp", "Failed to load timeact.ini\n");

		this->m_colors.m_trackColor = { 0.33f, 0.33f, 0.33f, 1.f };
		this->m_colors.m_trackColorInactive = { 0.33f, 0.33f, 0.33f, 1.f };
		this->m_colors.m_trackColorActive = { 0.f, 0.4f, 0.8f, 1.f };
		this->m_colors.m_trackBoundingBox = { 0.f, 0.f, 0.f, 1.f };
		this->m_colors.m_trackBoundingBoxActive = { 1.f, 1.f, 0.f, 1.f };
		this->m_colors.m_trackTextColor = { 1.f, 1.f, 1.f, 1.f };
		this->m_colors.m_cursorColor = { 0.f, 0.f, 0.f, 1.f };
	}

	this->m_colors.m_trackColor = { (float)reader.GetReal("Track", "r", 0.33f), (float)reader.GetReal("Track", "g", 0.33f), (float)reader.GetReal("Track", "b", 0.33f), (float)reader.GetReal("Track", "a", 1.f) };
	this->m_colors.m_trackColorInactive = { (float)reader.GetReal("TrackInactive", "r", 0.33f), (float)reader.GetReal("TrackInactive", "g", 0.33f), (float)reader.GetReal("TrackInactive", "b", 0.33f), (float)reader.GetReal("TrackInactive", "a", 1.f) };
	this->m_colors.m_trackColorActive = { (float)reader.GetReal("TrackActive", "r", 0.f), (float)reader.GetReal("TrackActive", "g", 0.4f), (float)reader.GetReal("TrackActive", "b", 0.8f), (float)reader.GetReal("TrackActive", "a", 1.f) };
	this->m_colors.m_trackBoundingBox = { (float)reader.GetReal("TrackBoundingBox", "r", 0.f), (float)reader.GetReal("TrackBoundingBox", "g", 0.f), (float)reader.GetReal("TrackBoundingBox", "b", 0.f), (float)reader.GetReal("TrackBoundingBox", "a", 1.f) };
	this->m_colors.m_trackBoundingBoxActive = { (float)reader.GetReal("TrackActiveBoundingBox", "r", 1.f), (float)reader.GetReal("TrackActiveBoundingBox", "g", 1.f), (float)reader.GetReal("TrackActiveBoundingBox", "b", 0.f), (float)reader.GetReal("TrackActiveBoundingBox", "a", 1.f) };
	this->m_colors.m_trackTextColor = { (float)reader.GetReal("TrackText", "r", 1.f), (float)reader.GetReal("TrackText", "g", 1.f), (float)reader.GetReal("TrackText", "b", 1.f), (float)reader.GetReal("TrackText", "a", 1.f) };
	this->m_colors.m_cursorColor = { (float)reader.GetReal("TrackCursor", "r", 1.f), (float)reader.GetReal("TrackCursor", "g", 1.f), (float)reader.GetReal("TrackCursor", "b", 1.f), (float)reader.GetReal("TrackCursor", "a", 1.f) };
}

std::string TimeActEditor::GetTrackName(int idx) 
{ 
	return g_taeTemplate.GetGroupName(this->m_tracks[idx].m_eventGroup);
}

std::string TimeActEditor::GetEventLabel(int idx, int event_idx, bool arguments) const
{	
	if (arguments)
		return g_taeTemplate.GetEventName(this->m_tracks[idx].m_eventGroup, this->m_tracks[idx].m_event[event_idx].m_value) + this->m_tracks[idx].m_event[event_idx].m_args->GetArgumentsAsString();

	return g_taeTemplate.GetEventName(this->m_tracks[idx].m_eventGroup, this->m_tracks[idx].m_event[event_idx].m_value);
}

void TimeActEditor::Clear()
{
	this->m_source = nullptr;
	this->m_tracks.clear();
}