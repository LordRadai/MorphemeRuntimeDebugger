#include "MorphemeNetworkInspector.h"
#include "FRPG2.h"
#include "Morpheme.h"

MorphemeNetworkInspectorGUI::MorphemeNetworkInspectorGUI()
{
	bool style_editor = false;
	bool show_demo_window = false;
}

MorphemeNetworkInspectorGUI::~MorphemeNetworkInspectorGUI()
{
	bool style_editor = false;
	bool show_demo_window = false;
}

void MorphemeNetworkInspectorGUI::GUIStyle()
{
	ImGuiStyle* style = &ImGui::GetStyle();
	style->WindowBorderSize = 1;
	style->FrameBorderSize = 0;
	style->PopupBorderSize = 1;
	style->TabBorderSize = 0;

	style->WindowRounding = 0;
	style->ChildRounding = 0;
	style->FrameRounding = 0;
	style->PopupRounding = 0;
	style->ScrollbarRounding = 9;
	style->GrabRounding = 0;
	style->TabRounding = 0;
	style->WindowMenuButtonPosition = ImGuiDir_Left;

	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
	colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	colors[ImGuiCol_Separator] = ImVec4(0.47f, 0.47f, 0.47f, 0.39f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.51f, 0.51f, 0.51f, 0.39f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	colors[ImGuiCol_Tab] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_DockingPreview] = ImVec4(0.26f, 0.59f, 0.98f, 0.70f);
	colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

void MorphemeNetworkInspectorGUI::RenderGUI(const char* title)
{
	ProcessVariables();

	ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y));
	ImGui::SetNextWindowPos(ImGui::GetMainViewport()->Pos);
	ImGui::Begin(title, NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoBringToFrontOnFocus);

	static const ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_None;
	ImGuiID dockSpace = ImGui::GetID("MainWindowDockspace");
	ImGui::DockSpace(dockSpace, ImVec2(0.0f, 0.0f), dockspaceFlags);

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("Edit"))
		{
			if (ImGui::MenuItem("Style Editor", NULL, &style_editor)) { style_editor != style_editor; }
			if (ImGui::MenuItem("Demo Window", NULL, &show_demo_window)) { show_demo_window != show_demo_window; }

			ImGui::EndMenu();
		}

		ImGui::EndMenuBar();
	}

	ImGui::Begin("Resources");
	{
		ImGui::PushItemWidth(200);
		ImGui::InputPtr("Target", &target_character, ImGuiInputTextFlags_CharsHexadecimal);

		if (ImGui::Button("Player"))
			target_character = FRPG2::getPlayerCtrl();

		ImGui::SameLine();
		if (ImGui::Button("Locked Target"))
			target_character = FRPG2::getLockedTargetCharacterCtrl();

		ImGui::BeginTabBar("resources tab bar");
		if (ImGui::BeginTabItem("Assets"))
		{
			std::vector<Morpheme::NodeDef*> nodes;
			if (ImGui::Button("Get Animations"))
			{
				anim_assets.clear();
				nodes = Morpheme::getNetworkAllNodesType(target_character, Morpheme::NodeType::NodeAnimSyncEvents);

				if (nodes.size() == 0)
					printf_s("[INFO] There are no nodes with the specified type\n");

				for (size_t i = 0; i < nodes.size(); i++)
					anim_assets.push_back((ImU64)nodes[i]);
			}
			ImGui::SameLine(); ImGui::Checkbox("Filter", &filter_events);

			//Assets Window
			ImGui::BeginChild("Assets");
			ImGui::BeginMenuBar();
			ImGui::EndMenuBar();
			if (ImGui::BeginTable("split", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_NoSavedSettings))
			{
				for (size_t i = 0; i < anim_assets.size(); i++)
				{
					ImGui::PushID(i);
					char label[32];
					sprintf(label, "Pull Tracks");
					ImGui::Text(Morpheme::getAnimNameFromAnimNode((Morpheme::NodeDef*)anim_assets[i]));
					ImGui::TableNextColumn();
					if (ImGui::Button(label)) { event_track_node = anim_assets[i]; pull_tracks = true; }
					ImGui::TableNextColumn();
					ImGui::PopID();
				}

				ImGui::EndTable();
			}
			ImGui::EndChild();

			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::End();

	ImGui::Begin("Network");
	{
		ImGui::BeginTabBar("network tab bar");
		if (ImGui::BeginTabItem("EventTrack"))
		{
			static char categoryInfo[100], valueInfo[255];
			static int selectedEntry = -1;
			static int firstFrame = 0;
			static bool expanded = true;
			static int currentFrame = 0;

			ImGui::PushItemWidth(200);
			ImGui::InputPtr("Node Pointer", &event_track_node, ImGuiInputTextFlags_CharsHexadecimal);

			if (ImGui::Button("Pull Tracks"))
				pull_tracks = true;

			if (pull_tracks && event_track_node)
			{
				pull_tracks = false;

				selectedEntry = -1;
				event_track_editor.Clear();

				Morpheme::NodeDef* anim_sync_node = (Morpheme::NodeDef*)(event_track_node);

				if (anim_sync_node->m_nodeTypeID == Morpheme::NodeType::NodeAnimSyncEvents)
				{
					Morpheme::NodeData104* node_data = (Morpheme::NodeData104*)anim_sync_node->node_data;

					if (node_data->m_animData && node_data->m_eventTrackData)
					{
						uint64_t nsaFile = node_data->m_animData;

						trackLenght = *(float*)(nsaFile + 0x84);
						animLenght = *(float*)(nsaFile + 0x88);

						multiplier = 1;
						event_track_editor.mFrameMin = 0;
						event_track_editor.mFrameMax = Math::timeToFrame(trackLenght, 60);

						/*if (morpheme_scaleTracks)
						{
							multiplier = animLenght / trackLenght;
							event_track_editor.mFrameMax = Math::timeToFrame(animLenght, 60);
						}*/

						animFileName = Morpheme::getAnimNameFromAnimNode(anim_sync_node);
						printf_s("%s\n", animFileName);

						uint32_t event_track_count = node_data->m_eventTrackData->m_eventTracks[0].m_trackCount + node_data->m_eventTrackData->m_eventTracks[1].m_trackCount + node_data->m_eventTrackData->m_eventTracks[2].m_trackCount;

						if (event_track_count == 0)
							printf_s("Animation does not have any EventTrack associated with it\n");

						if (event_track_count > 0 && Morpheme::LoadEventTracks(node_data->m_eventTrackData, &track_list) != 0)
						{
							int id = 0;

							for (size_t i = 0; i < track_list.count_discrete; i++)
							{
								event_track_editor.LoadTrackName(id, track_list.tracks_discrete[i]);
								event_track_editor.AddMorphemeEventTrack(id, track_list.tracks_discrete[i], multiplier);

								if (track_list.tracks_discrete[i].eventCount > 1)
								{
									for (size_t j = 0; j < track_list.count_discreteSub; j++)
									{
										if (track_list.tracks_discreteSub[j].parentId == i)
										{
											event_track_editor.LoadTrackName(id, track_list.tracks_discreteSub[j]);
											event_track_editor.AddMorphemeEventTrack(id, track_list.tracks_discreteSub[j], multiplier);

											id++;
										}
									}
								}
								else
									id++;
							}

							for (size_t i = 0; i < track_list.count_unk; i++)
							{
								event_track_editor.LoadTrackName(id, track_list.tracks_unk[i]);
								event_track_editor.AddMorphemeEventTrack(id, track_list.tracks_unk[i], multiplier);

								if (track_list.tracks_unk[i].eventCount > 1)
								{
									for (size_t j = 0; j < track_list.count_unkSub; j++)
									{
										if (track_list.tracks_unkSub[j].parentId == i)
										{
											event_track_editor.LoadTrackName(id, track_list.tracks_unkSub[j]);
											event_track_editor.AddMorphemeEventTrack(id, track_list.tracks_unkSub[j], multiplier);

											id++;
										}
									}
								}
								else
									id++;
							}

							for (size_t i = 0; i < track_list.count_timed; i++)
							{
								event_track_editor.LoadTrackName(id, track_list.tracks_timed[i]);
								event_track_editor.AddMorphemeEventTrack(id, track_list.tracks_timed[i], multiplier);

								if (track_list.tracks_timed[i].eventCount > 1)
								{
									for (size_t j = 0; j < track_list.count_timedSub; j++)
									{
										if (track_list.tracks_timedSub[j].parentId == i)
										{
											event_track_editor.LoadTrackName(id, track_list.tracks_timedSub[j]);
											event_track_editor.AddMorphemeEventTrack(id, track_list.tracks_timedSub[j], multiplier);

											id++;
										}
									}
								}
								else
									id++;
							}
						}
					}
				}
				else
					printf_s("[ERROR, MorphemeSystem] Provided node is not of the right type (NodeType: %d)\n", anim_sync_node->m_nodeTypeID);
			}

			ImGui::SameLine();
			if (ImGui::Button("Clear Tracks") && event_track_editor.GetItemCount())
				clear_tracks = true;

			if (clear_tracks)
			{
				selectedEntry = -1;
				clear_tracks = false;

				event_track_editor.Clear();
				Morpheme::ClearTrackList(&track_list);
			}

			ImGui::SameLine();
			if (ImGui::Button("Save Tracks") && event_track_editor.GetItemCount())
				save_tracks = true;

			if (save_tracks)
			{
				save_tracks = false;

				Morpheme::SaveEventTracks(&track_list);
			}

			if (currentFrame < event_track_editor.mFrameMin)
				currentFrame = event_track_editor.mFrameMin;

			if (event_track_editor.GetItemCount())
				ImGui::Text(animFileName);

			ImSequencer::Sequencer(&event_track_editor, &currentFrame, &expanded, &selectedEntry, &firstFrame, ImSequencer::SEQUENCER_EDIT_STARTEND | ImSequencer::SEQUENCER_CHANGE_FRAME);

			if (selectedEntry != -1)
			{
				EventTrackEditor::EventTrack& item = event_track_editor.myItems[selectedEntry];
				float startTime = Math::frameToTime(item.mFrameStart, 60);
				float duration = Math::frameToTime(item.mFrameEnd, 60);

				ImGui::Text("%s", event_track_editor.trackNames[item.id]);
				ImGui::PushItemWidth(100);
				ImGui::InputInt("Event ID", &item.eventId, 1, 0);
				if (ImGui::IsItemHovered())
				{
					//Morpheme::getCategoryInfo(item.eventId, categoryInfo);

					//ImGui::Text("Event ID");
					ImGui::Text(categoryInfo);
				}

				ImGui::InputInt("Event Value", &item.value, 1, 0);
				if (ImGui::IsItemHovered())
				{
					//Morpheme::getValueInfo(item.eventId, item.value, valueInfo);

					ImGui::Text("Info");
					ImGui::Separator();

					ImGui::Text(valueInfo);
				}

				ImGui::DragFloat("Start Time", &startTime, 1 / 60, 0, Math::frameToTime(event_track_editor.mFrameMax, 60), "%.3f");
				ImGui::DragFloat("End Time", &duration, 1 / 60, 0, Math::frameToTime(event_track_editor.mFrameMax, 60), "%.3f");
				ImGui::PopItemWidth();

				item.mFrameStart = Math::timeToFrame(startTime, 60);
				item.mFrameEnd = Math::timeToFrame(duration, 60);

				//printf_s("Selected: %d\n", selectedEntry);

				if (selectedEntry < track_list.count_discrete)
				{
					//printf_s("Saving Blend Track %d\n", selectedEntry);
					item.SaveTrackData(&track_list.tracks_discrete[selectedEntry], multiplier);
				}
				if (track_list.count_discrete <= selectedEntry && selectedEntry < track_list.count_discrete + track_list.count_discreteSub)
				{
					//printf_s("Saving Blend Sub Track %d\n", selectedEntry);
					item.SaveTrackData(&track_list.tracks_discreteSub[selectedEntry - track_list.count_discrete], multiplier);
				}
				if (track_list.count_discrete + track_list.count_discreteSub <= selectedEntry && selectedEntry < track_list.count_discrete + track_list.count_discreteSub + track_list.count_timed)
				{
					//printf_s("Saving Generic Track %d\n", selectedEntry);
					item.SaveTrackData(&track_list.tracks_timed[selectedEntry - (track_list.count_discrete + track_list.count_discreteSub)], multiplier);
				}
				if (track_list.count_discrete + track_list.count_discreteSub + track_list.count_timed <= selectedEntry && selectedEntry < track_list.count_discrete + track_list.count_discreteSub + track_list.count_timed + track_list.count_timedSub)
				{
					//printf_s("Saving Generic Sub Track %d\n", selectedEntry);
					item.SaveTrackData(&track_list.tracks_timedSub[selectedEntry - (track_list.count_discrete + track_list.count_discreteSub + track_list.count_timed)], multiplier);
				}
			}

			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::End();

	ImGui::Begin("Network Interfaces");
	{
		ImGui::BeginTabBar("interfaces tab bar");
		if (ImGui::BeginTabItem("Control Parameters"))
		{
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Messages"))
		{
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::End();
}

void MorphemeNetworkInspectorGUI::ProcessVariables()
{
	if (style_editor)
	{
		ImGui::Begin("Style Editor", &style_editor);
		ImGui::ShowStyleEditor();
		ImGui::End();
	}

	if (show_demo_window)
	{
		ImGui::ShowDemoWindow(&show_demo_window);
	}
}

void MorphemeNetworkInspectorGUI::Dockspace(ImGuiID dockSpace)
{
}