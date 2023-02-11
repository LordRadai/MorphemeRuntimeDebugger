#include "MorphemeNetworkInspector.h"
#include "FRPG2.h"
#include "Morpheme.h"
#include "ImNodesInterface.h"

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
		if (ImGui::BeginMenu("Options"))
		{
			if (ImGui::MenuItem("Scale Track Lenght", NULL, &network_config.eventTrackConfig_scaleToAnim)) { network_config.eventTrackConfig_scaleToAnim != network_config.eventTrackConfig_scaleToAnim; }

			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Edit"))
		{
			if (ImGui::MenuItem("Style Editor", NULL, &style_editor)) { style_editor != style_editor; }
			if (ImGui::MenuItem("Demo Window", NULL, &show_demo_window)) { show_demo_window != show_demo_window; }

			ImGui::EndMenu();
		}

		ImGui::EndMenuBar();
	}

	ImGui::Begin("Network");
	{
		ImGui::PushItemWidth(200);
		ImGui::InputPtr("Target", &target_character, ImGuiInputTextFlags_CharsHexadecimal);
		ImGui::PopItemWidth();

		if (ImGui::Button("Player"))
			target_character = FRPG2::getPlayerCtrl();

		ImGui::SameLine();
		if (ImGui::Button("Locked Target"))
			target_character = FRPG2::getLockedTargetCharacterCtrl();

		if (ImGui::Button("Get Network"))
			get_network = true;

		ImGui::SameLine();
		if (ImGui::Button("Clear Network"))
			NetworkCleanup();

		ImGui::Separator();

		ImGui::BeginTabBar("network tab bar");
		if (ImGui::BeginTabItem("Network"))
		{
			ImGui::BeginTabBar("node editor tab bar");
			if (ImGui::BeginTabItem("Main"))
			{
				ImNodes::BeginNodeEditor();
				ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_BottomRight);

				if (network)
				{
					for (size_t i = 0; i < network->m_networkDef->network_node_def.m_numChildNodeIDs; i++)
					{
						ImNodesInterface::createMorphemeNode(Morpheme::getNetworkNode(network, network->m_networkDef->network_node_def.m_childNodeIDs[i]));
					}
				}
				ImNodes::EndNodeEditor();

				ImGui::EndTabItem();			
			}
			if (ImGui::BeginTabItem("Node Inspector"))
			{
				ImGui::InputShort("Node ID", &imnodes_data.node_to_inspect, 0, 0, ImGuiInputTextFlags_None);
				if (ImGui::Button("Get Node")) { imnodes_data.is_inspect = true; }

				ImNodes::BeginNodeEditor();
				ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_BottomRight);

				if (imnodes_data.is_inspect)
				{
					imnodes_data.is_inspect = false;

					imnodes_data.node_def = Morpheme::getNetworkNode(network, imnodes_data.node_to_inspect);
				}

				if (imnodes_data.node_def && imnodes_data.node_def->m_numChildNodeIDs > 0)
				{
					for (size_t i = 0; i < imnodes_data.node_def->m_numChildNodeIDs; i++)
						ImNodesInterface::createMorphemeNode(Morpheme::getNetworkNode(network, imnodes_data.node_def->m_childNodeIDs[i]));
				}
				ImNodes::EndNodeEditor();

				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
			
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("EventTrack"))
		{
			static char categoryInfo[100], valueInfo[255];
			static int selectedEntry = -1;
			static int firstFrame = 0;
			static bool expanded = true;
			static int currentFrame = 0;

			float trackLenght;
			float animLenght;
			float multiplier = 1;

			ImGui::PushItemWidth(200);
			ImGui::InputPtr("Node Pointer", &network_data.anim_events.event_track_node, ImGuiInputTextFlags_CharsHexadecimal);
			ImGui::PopItemWidth();

			if (ImGui::Button("Pull Tracks"))
				pull_tracks = true;

			if (pull_tracks && network_data.anim_events.event_track_node)
			{
				pull_tracks = false;

				selectedEntry = -1;
				event_track_editor.Clear();

				Morpheme::NodeDef* anim_sync_node = (Morpheme::NodeDef*)(network_data.anim_events.event_track_node);

				if (anim_sync_node->m_nodeTypeID == Morpheme::NodeType::NodeAnimSyncEvents)
				{
					Morpheme::NodeData104* node_data = (Morpheme::NodeData104*)anim_sync_node->node_data;

					if (node_data->m_animData && node_data->m_eventTrackData)
					{
						uint64_t nsaFile = node_data->m_animData;

						float trackLenght = *(float*)(nsaFile + 0x84);
						float animLenght = *(float*)(nsaFile + 0x88);

						float multiplier = 1;
						event_track_editor.mFrameMin = 0;
						event_track_editor.mFrameMax = Math::timeToFrame(trackLenght, 60);

						if (network_config.eventTrackConfig_scaleToAnim)
						{
							multiplier = animLenght / trackLenght;
							event_track_editor.mFrameMax = Math::timeToFrame(animLenght, 60);
						}

						network_data.anim_events.asset_name = Morpheme::getAnimNameFromAnimNode(anim_sync_node);

						uint32_t event_track_count = node_data->m_eventTrackData->m_eventTracks[0].m_trackCount + node_data->m_eventTrackData->m_eventTracks[1].m_trackCount + node_data->m_eventTrackData->m_eventTracks[2].m_trackCount;

						if (event_track_count == 0)
							MessageBoxA(NULL, "Animation does not have any EventTrack associated with it", "Morpheme Network Inspector", MB_ICONINFORMATION);

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
					MessageBoxA(NULL, "Provided node is not of the right type\n", "Morpheme Network Inspector", MB_ICONERROR);
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

			/*if (currentFrame < event_track_editor.mFrameMin)
				currentFrame = event_track_editor.mFrameMin;*/

			if (event_track_editor.GetItemCount())
				ImGui::Text(network_data.anim_events.asset_name);

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

				ImGui::DragFloat("Start Time", &startTime, 1 / 60, 0, Math::frameToTime(event_track_editor.mFrameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);
				ImGui::DragFloat("End Time", &duration, 1 / 60, 0, Math::frameToTime(event_track_editor.mFrameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);
				ImGui::PopItemWidth();

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

	ImGui::Begin("Resources");
	{
		ImGui::BeginTabBar("resources tab bar");
		if (ImGui::BeginTabItem("Assets"))
		{
			ImGui::SameLine(); ImGui::Checkbox("Only Anims with Events", &network_config.filter_events);

			static ImGuiTextFilter filter;
			ImGui::Text("Filter:");
			filter.Draw("##asset searchbar", 340.f);
			//Assets Window
			ImGui::BeginChild("Assets");
			{
				for (size_t i = 0; i < network_data.anim_events.anim_nodes.size(); i++)
				{
					const char* anim_name = Morpheme::getAnimNameFromAnimNode(network_data.anim_events.anim_nodes[i]);

					if (filter.PassFilter(anim_name))
					{
						ImGui::PushID(i);
						//if (ImGui::Button("Load Tracks")) { event_track_node = (ImU64)nodes[i]; pull_tracks = true; }
						if (ImGui::Selectable(anim_name))
						{
							network_data.anim_events.asset_name = anim_name;
							network_data.anim_events.event_track_node = (ImU64)network_data.anim_events.anim_nodes[i];
							pull_tracks = true;
						}
						ImGui::PopID();
					}
				}

			}
			ImGui::EndChild();

			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::End();

	ImGui::Begin("Nodes");
	{
		for (size_t i = 0; i < network_data.nodes.size(); i++)
		{
			ImVec4 node_col = ImGui::GetStyleColorVec4(ImGuiCol_Header);
			ImVec4 node_col_active = ImGui::GetStyleColorVec4(ImGuiCol_HeaderActive);
			ImVec4 node_col_hovered = ImGui::GetStyleColorVec4(ImGuiCol_HeaderHovered);

			if (Morpheme::isNodeContainer(network, network_data.nodes[i]->m_nodeID))
			{
				node_col = ImVec4(0.2f, 0.2f, 1.0f, 1.0f);
				node_col_active = ImVec4(0.39f, 0.39f, 1.0f, 1.0f);
				node_col_hovered = ImVec4(0.27f, 0.27f, 1.0f, 1.0f);
			}

			ImGui::PushStyleColor(ImGuiCol_Header, node_col);
			ImGui::PushStyleColor(ImGuiCol_HeaderActive, node_col_active);
			ImGui::PushStyleColor(ImGuiCol_HeaderHovered, node_col_hovered);

			char buf[255];
			sprintf_s(buf, "[%d] %s (%s)", network_data.nodes[i]->m_nodeID, network_data.node_names[i], Morpheme::getNodeTypeName_Alt(network, network_data.nodes[i]->m_nodeID));

			if (ImGui::CollapsingHeader(buf))
			{
				ImGui::PushItemWidth(100);
				ImGui::PushID(i);
				ImGui::InputInt("Node Type", (int*)& network_data.nodes[i]->m_nodeTypeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
				ImGui::InputByte("Flag 1", (char*)&network_data.nodes[i]->m_flags1, 0, 0, ImGuiInputTextFlags_ReadOnly);
				ImGui::InputByte("Flag 2", (char*)&network_data.nodes[i]->m_flags2, 0, 0, ImGuiInputTextFlags_ReadOnly);
				ImGui::InputShort("Node ID", (short*)&network_data.nodes[i]->m_nodeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
				ImGui::InputShort("Parent Node ID", (short*)&network_data.nodes[i]->m_parentNodeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
				ImGui::InputShort("Child Count", (short*)&network_data.nodes[i]->m_numChildNodeIDs, 0, 0, ImGuiInputTextFlags_ReadOnly);
				ImGui::InputByte("Input Count", (char*)&network_data.nodes[i]->m_numControlParamAndOpNodeIDs, 0, 0, ImGuiInputTextFlags_ReadOnly);
				if (network_data.nodes[i]->m_numChildNodeIDs > 0)
				{
					if (ImGui::TreeNode("Child Nodes"))
					{
						for (size_t j = 0; j < network_data.nodes[i]->m_numChildNodeIDs; j++)
						{
							ImVec4 child_col = ImGui::GetStyleColorVec4(ImGuiCol_Text);

							if (Morpheme::isNodeContainer(network, network_data.nodes[i]->m_childNodeIDs[j]))
								child_col = ImVec4(0.39f, 0.58f, 1.0f, 1.0f);

							ImGui::PushStyleColor(ImGuiCol_Text, child_col);
							char id[255];
							sprintf_s(id, "child %d", j);

							char child_name[255];
							sprintf_s(child_name, "%s (%s)", Morpheme::getNodeName(target_character, network_data.nodes[i]->m_childNodeIDs[j]), Morpheme::getNodeTypeName_Alt(network, network_data.nodes[i]->m_childNodeIDs[j]));
							ImGui::PushID(id);
							ImGui::InputShort(child_name, (short*)&network_data.nodes[i]->m_childNodeIDs[j], 0, 0, ImGuiInputTextFlags_ReadOnly);
							ImGui::PopID();
							ImGui::PopStyleColor(1);
						}
						ImGui::TreePop();
					}
				}
				if (network_data.nodes[i]->m_numControlParamAndOpNodeIDs > 0)
				{
					if (ImGui::TreeNode("Inputs"))
					{
						for (byte j = 0; j < network_data.nodes[i]->m_numControlParamAndOpNodeIDs; j++)
						{
							ImVec4 input_col = ImGui::GetStyleColorVec4(ImGuiCol_Text);

							if (Morpheme::isNodeContainer(network, network_data.nodes[i]->m_controlParamAndOpNodeIDs[j]))
								input_col = ImVec4(0.2f, 0.2f, 1.0f, 1.0f);

							ImGui::PushStyleColor(ImGuiCol_Text, input_col);
							char id[255];
							sprintf_s(id, "input %d", j);

							char input_name[255] = "";
							sprintf_s(input_name, "%s (%s)", Morpheme::getNodeName(target_character, network_data.nodes[i]->m_controlParamAndOpNodeIDs[j]), Morpheme::getNodeTypeName_Alt(network, network_data.nodes[i]->m_controlParamAndOpNodeIDs[j]));
							ImGui::PushID(id);
							ImGui::InputInt(input_name, &network_data.nodes[i]->m_controlParamAndOpNodeIDs[j], 0, 0, ImGuiInputTextFlags_ReadOnly);
							ImGui::PopID();
							ImGui::PopStyleColor(1);
						}
						ImGui::TreePop();
					}
				}
				
				ImGui::PopItemWidth();
				ImGui::InputPtr("Node Data", (uint64_t*)&network_data.nodes[i]->node_data, ImGuiInputTextFlags_ReadOnly | ImGuiInputTextFlags_CharsHexadecimal);
				ImGui::PopID();
			}

			ImGui::PopStyleColor(3);
		}
	}
	ImGui::End();

	ImGui::Begin("Controls");
	{
		ImGui::BeginTabBar("controls tab");
		if (ImGui::BeginTabItem("Parameters"))
		{
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Messages"))
		{
			for (size_t i = 0; i < network_data.messages.message_defs.size(); i++)
			{
				ImGui::PushID(i);
				if (ImGui::CollapsingHeader(network_data.messages.message_names[i]))
				{
					ImGui::InputInt("Message ID", &network_data.messages.message_defs[i]->message_id, 0, 0, ImGuiInputTextFlags_ReadOnly);
					ImGui::InputInt("Node Count", &network_data.messages.message_defs[i]->node_count, 0, 0, ImGuiInputTextFlags_ReadOnly);

					ImGui::PushItemWidth(100);
					if (network_data.messages.message_defs[i]->node_count > 0 && ImGui::TreeNode("Nodes"))
					{
						for (size_t j = 0; j < network_data.messages.message_defs[i]->node_count; j++)
						{
							char label[255];

							sprintf_s(label, "%s (%s)", Morpheme::getNodeName(target_character, network_data.messages.message_defs[i]->node_array[j]), Morpheme::getNodeTypeName_Alt(network, network_data.messages.message_defs[i]->node_array[j]));

							ImGui::InputShort(label, &network_data.messages.message_defs[i]->node_array[j], 0, 0, ImGuiInputTextFlags_ReadOnly);
						}
						ImGui::TreePop();
					}
					ImGui::PopItemWidth();
				}			
				ImGui::PopID();
			}
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Preview"))
		{
			static const ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_None;
			ImGuiID dockSpace = ImGui::GetID("PreviewWindowDockspace");
			ImGui::DockSpace(dockSpace, ImVec2(0.0f, 0.0f), dockspaceFlags);

			ImGui::Begin("Control Parameters");
			if (ImGui::CollapsingHeader("Ungrouped"))
			{
				for (size_t i = 0; i < network_data.control_params.cp_nodes.size(); i++)
				{
					char input_id[255];
					//char slider_id[255];

					sprintf_s(input_id, "input %d", i);
					//sprintf_s(slider_id, "slider %d", i);

					ImGui::Text(network_data.control_params.cp_names[i]);
					DWORD* value = network_data.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_value;

					switch (network_data.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_dataType)
					{
					case 0:
						ImGui::PushID(input_id);
						ImGui::DragByte("", (char*)(value), 0, 0, 1,"%d");
						ImGui::PopID();
						break;
					case 2:
						ImGui::PushID(input_id);
						ImGui::DragInt("", (int*)(value), 0, -10000, 10000, "%d");
						ImGui::PopID();
						break;
					case 3:
						ImGui::PushID(input_id);
						ImGui::DragFloat("", (float*)(value), 0, -10000, 10000, "%.3f");
						ImGui::PopID();
						break;
					case 4:
						ImGui::PushID(input_id);
						ImGui::DragFloat("X", (float*)&network_data.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_value[0], 0, -10000, 1000, "%.3f");
						ImGui::DragFloat("Y", (float*)&network_data.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_value[1], 0, -10000, 1000, "%.3f");
						ImGui::DragFloat("Z", (float*)&network_data.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_value[2], 0, -10000, 1000, "%.3f");
						ImGui::PopID();
						break;
					default:
						char buf[50];
						sprintf_s(buf, "Unknown CP type %d (%d)\n", network_data.control_params.cp_nodes[i]->m_nodeTypeID, network_data.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_dataType);
						ImGui::Text(buf);
						break;
					}
				}
			}
			ImGui::End();

			ImGui::Begin("Messages");
			{
				for (size_t i = 0; i < network_data.messages.message_names.size(); i++)
				{
					ImVec4 text_col = ImVec4(1, 1, 1, 1);

					for (size_t j = 0; j < network_data.messages.message_defs[i]->node_count; j++)
						if (Morpheme::isNodeActive(network, network_data.messages.message_defs[i]->node_array[j]))
							text_col = ImVec4(1.0f, 0.7f, 0.0f, 1.0f);

					ImGui::PushStyleColor(ImGuiCol_Text, text_col);
					if (ImGui::Button(network_data.messages.message_names[i], ImVec2(ImGui::GetWindowWidth(), 0.0f)))
					{
						Morpheme::sMorphemeMessage message_data = Morpheme::sMorphemeMessage::sMorphemeMessage(network_data.messages.message_ids[i]);

						sendMessage(network, message_data);
					}

					ImGui::PopStyleColor(1);
				}
			}
			ImGui::End();

			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::End();
}

void MorphemeNetworkInspectorGUI::ProcessVariables()
{
	if (target_character && (*(int*)(target_character + 0x8) != 1) && (*(int*)(target_character + 0x8) != 2))
	{
		target_character = NULL;
		NetworkCleanup();
	}

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

	if (get_network)
	{
		NetworkCleanup();

		get_network = false;
		network_tasks.get_nodes = true;
		network_tasks.get_anim_assets = true;
		network_tasks.get_control_params = true;
		network_tasks.get_messages = true;

		network = Morpheme::getNetwork(target_character);
		if (network == NULL)
			MessageBoxA(NULL, "Network not found\n", "Morpheme Network Inspector", MB_ICONINFORMATION);
	}

	if (network)
	{
		if (network_tasks.get_nodes)
		{
			network_data.node_names.clear();
			network_data.nodes.clear();

			for (size_t i = 0; i < network->m_networkDef->m_numNodes; i++)
			{
				network_data.nodes.push_back(Morpheme::getNetworkNode(network, network->m_networkDef->m_nodes[i]->m_nodeID));
				network_data.node_names.push_back(Morpheme::getNodeName(target_character, network->m_networkDef->m_nodes[i]->m_nodeID));
			}
		}

		if (network_tasks.get_anim_assets)
		{
			network_data.anim_events.anim_nodes.clear();
			network_data.anim_events.anim_nodes = Morpheme::getNetworkAllNodesType(target_character, Morpheme::NodeType::NodeAnimSyncEvents);

			if (network_data.anim_events.anim_nodes.size() == 0)
				MessageBoxA(NULL, "There are no of the specified type\n", "Morpheme Network Inspector", MB_ICONINFORMATION);

			network_tasks.get_anim_assets = false;
		}

		if (network_tasks.get_control_params)
		{
			network_tasks.get_control_params = false;

			network_data.control_params.cp_nodes.clear();
			network_data.control_params.cp_bins.clear();
			network_data.control_params.cp_names.clear();

			network_data.control_params.cp_nodes = Morpheme::getNetworkControlParameterNodes(target_character);

			for (size_t i = 0; i < network_data.control_params.cp_nodes.size(); i++)
			{
				network_data.control_params.cp_bins.push_back(Morpheme::getNodeBin(target_character, network_data.control_params.cp_nodes[i]->m_nodeID));
				network_data.control_params.cp_names.push_back(Morpheme::getNodeName(target_character, network_data.control_params.cp_nodes[i]->m_nodeID));
			}
		}

		if (network_tasks.get_messages)
		{
			network_tasks.get_messages = false;

			network_data.messages.message_ids.clear();
			network_data.messages.message_names.clear();
			network_data.messages.message_defs.clear();

			network_data.messages.message_defs = Morpheme::getMessageDefs(target_character);

			for (size_t i = 0; i < network->m_networkDef->m_requestIDNamesTable->m_NumEntrys; i++)
			{
				network_data.messages.message_ids.push_back(network->m_networkDef->m_requestIDNamesTable->m_IDs[i]);
				network_data.messages.message_names.push_back(Morpheme::getMessageName(target_character, network->m_networkDef->m_requestIDNamesTable->m_IDs[i]));
			}
		}
	}
}

void MorphemeNetworkInspectorGUI::Dockspace(ImGuiID dockSpace)
{
}

void MorphemeNetworkInspectorGUI::NetworkCleanup()
{
	network_data.node_names.clear();
	network_data.nodes.clear();

	network_data.anim_events.anim_nodes.clear();

	network_data.control_params.cp_nodes.clear();
	network_data.control_params.cp_bins.clear();
	network_data.control_params.cp_names.clear();

	network_data.messages.message_ids.clear();
	network_data.messages.message_names.clear();
	network_data.messages.message_defs.clear();
}