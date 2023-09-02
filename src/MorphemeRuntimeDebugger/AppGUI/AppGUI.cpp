#include "AppGUI.h"
#include "../Debug/Debug.h"
#include "../FRPG2/FRPG2.h"
#include "../ImNodesInterface/ImNodesInterface.h"
#include "../MorphemeInterface/MorphemeInterface.h"
#include "../imsequencer/ImSequencer.h"

AppGUI::AppGUI()
{
	this->m_selectedIndex = -1;
}

AppGUI::~AppGUI()
{
	this->m_selectedIndex = -1;
}

void AppGUI::GUIStyle()
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
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.f, 0.f, 0.f, 0.f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.f, 0.f, 0.f, 0.f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.f, 0.f, 0.f, 0.f);
	colors[ImGuiCol_Tab] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
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

std::string getTaeCategoryTooltip(int category)
{
	INIReader reader(".//MorphemeRuntimeDebugger//res//tooltip//timeact//group.ini");

	char default_info[255];
	sprintf_s(default_info, "No specific information is known for this category\n");

	if (reader.ParseError() < 0)
	{
		Debug::DebuggerMessage(Debug::LVL_ERROR, "Failed to load group.ini\n");
		return std::string(default_info);
	}

	std::string category_str = std::to_string(category);

	return reader.GetString(category_str, "tooltip", std::string(default_info));
}

std::string getTaeEventTooltip(int event_id)
{
	INIReader reader(".//MorphemeRuntimeDebugger//res//tooltip//timeact//event.ini");

	char default_info[255];
	sprintf_s(default_info, "No specific information is known for this event\n");

	if (reader.ParseError() < 0)
	{
		Debug::DebuggerMessage(Debug::LVL_ERROR, "Failed to load event.ini\n");
		return std::string(default_info);
	}

	std::string category_str = std::to_string(event_id);

	return reader.GetString(category_str, "tooltip", std::string(default_info));
}

std::string getEventTrackCategoryTooltip(int category)
{
	INIReader reader(".//MorphemeRuntimeDebugger//res//tooltip//eventrack//group.ini");

	char default_info[255];
	sprintf_s(default_info, "No specific information is known for this category\n");

	if (reader.ParseError() < 0)
	{
		Debug::DebuggerMessage(Debug::LVL_ERROR, "Failed to load group.ini\n");
		return std::string(default_info);
	}

	std::string category_str = std::to_string(category);

	return reader.GetString(category_str, "tooltip", std::string(default_info));
}

std::string getEventTrackEventTooltip(int event_id)
{
	INIReader reader(".//MorphemeRuntimeDebugger//res//tooltip//eventrack//event.ini");

	char default_info[255];
	sprintf_s(default_info, "No specific information is known for this event\n");

	if (reader.ParseError() < 0)
	{
		Debug::DebuggerMessage(Debug::LVL_ERROR, "Failed to load event.ini\n");
		return std::string(default_info);
	}

	std::string category_str = std::to_string(event_id);

	return reader.GetString(category_str, "tooltip", std::string(default_info));
}

void AppGUI::RenderGUI(const char* title)
{
	ProcessVariables();

	ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y));
	ImGui::SetNextWindowPos(ImGui::GetMainViewport()->Pos);
	ImGui::Begin(title, NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus);

	static const ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_None;
	ImGuiID dockSpace = ImGui::GetID("MainWindowDockspace");
	ImGui::DockSpace(dockSpace, ImVec2(0.0f, 0.0f), dockspaceFlags);

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("Options"))
		{
			if (m_gameDebugFlags.m_disableAi && g_gameState == 30)
			{
				if (ImGui::MenuItem("Disable AI", NULL, m_gameDebugFlags.m_disableAi)) { *m_gameDebugFlags.m_disableAi != *m_gameDebugFlags.m_disableAi; }
			}

			if (ImGui::MenuItem("Disable CP Updates", NULL, &m_gameDebugFlags.m_disableCPUpdates)) { m_gameDebugFlags.m_disableCPUpdates != m_gameDebugFlags.m_disableCPUpdates; }

			ImGui::EndMenu();
		}

		/*
		if (ImGui::BeginMenu("Edit"))
		{
			if (ImGui::MenuItem("Style Editor", NULL, &style_editor)) { style_editor != style_editor; }
			if (ImGui::MenuItem("Demo Window", NULL, &show_demo_window)) { show_demo_window != show_demo_window; }

			ImGui::EndMenu();
		}
		*/

		ImGui::EndMenuBar();
	}
	ImGui::End();

	ImGui::Begin("Network");
	{
		ImGui::PushItemWidth(200);
		ImGui::InputPtr("Target", &target_character, ImGuiInputTextFlags_CharsHexadecimal);
		ImGui::PopItemWidth();

		if (ImGui::Button("Player"))
		{
			NetworkCleanup();
			target_character = FRPG2::getPlayerCtrl();
		}

		ImGui::SameLine();
		if (ImGui::Button("Locked Target"))
		{
			NetworkCleanup();
			target_character = FRPG2::getLockedTargetCharacterCtrl();
		}

		if (ImGui::Button("Get Network"))
		{
			NetworkCleanup();
			get_network = true;
		}

		ImGui::SameLine();
		if (ImGui::Button("Clear Network"))
			NetworkCleanup();

		ImGui::Separator();

		ImGui::InputShort("Node ID", &m_networkData.imnodes_data.node_to_inspect, 0, 0, ImGuiInputTextFlags_None);
		if (ImGui::Button("Get Node")) { m_networkData.imnodes_data.is_inspect = true; }
		
		ImGui::SameLine();
		if (ImGui::Button("Save Editor State")) { m_networkData.is_save = true; }

		if (!m_clearNetwork && network && m_networkData.imnodes_data.node_def)
		{ 
			if (m_networkData.imnodes_data.node_def->m_parentNodeID != -1 && m_networkData.imnodes_data.node_def->m_nodeTypeID != NodeType_NetworkInstance);
			{
				char label[256];
				Morpheme::NodeDef* temp = m_networkData.imnodes_data.node_def;

				do
				{
					if (temp->m_parentNodeID == -1)
						break;

					m_networkData.imnodes_data.parent_node = Morpheme::getNetworkNode(network, temp->m_parentNodeID);
					m_networkData.imnodes_data.parent_id = temp->m_parentNodeID;

					if (m_networkData.imnodes_data.parent_node->m_nodeTypeID == NodeType_StateMachine || m_networkData.imnodes_data.parent_node->m_nodeTypeID == NodeType_NetworkInstance)
						break;

					temp = m_networkData.imnodes_data.parent_node;

				} while (true);

				if (m_networkData.imnodes_data.parent_id != -1 && temp->m_parentNodeID != -1)
				{
					const char* node_name = Morpheme::getNodeName(target_character, m_networkData.imnodes_data.parent_id);

					sprintf(label, "%d", m_networkData.imnodes_data.parent_id);

					if (node_name != "")
						sprintf(label, "%s", node_name);

					ImGui::PushID(m_networkData.imnodes_data.parent_id);
					if (ImGui::Button(label))
					{
						m_networkData.imnodes_data.node_to_inspect = m_networkData.imnodes_data.node_def->m_parentNodeID;
						m_networkData.imnodes_data.is_inspect = true;
					}
					ImGui::PopID();
				}
			}

			ImNodes::BeginNodeEditor();
			ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_BottomRight);

			if (m_networkData.imnodes_data.node_def->m_numChildNodeIDs > 0)
			{
				char ini_file[256];
				char folder_name[256];
				sprintf_s(folder_name, ".//MorphemeRuntimeDebugger//networks//c%d//", *(int*)(target_character + 0x28));
				CreateDirectoryA(folder_name, NULL);

				sprintf(ini_file, ".//MorphemeRuntimeDebugger//networks//c%d//c%d_%d.ini", *(int*)(target_character + 0x28), *(int*)(target_character + 0x28), m_networkData.imnodes_data.node_def->m_nodeID);

				//ImNodesInterface::createOutputNode();

				for (size_t i = 0; i < m_networkData.imnodes_data.node_def->m_numChildNodeIDs; i++)
					ImNodesInterface::createMorphemeNode(Morpheme::getNetworkNode(network, m_networkData.imnodes_data.node_def->m_childNodeIDs[i]));
				
				if (m_networkData.is_save)
				{
					m_networkData.is_save = false;
					ImNodes::SaveCurrentEditorStateToIniFile(ini_file);
				}

				if (m_networkData.is_load)
				{
					ImNodes::LoadCurrentEditorStateFromIniFile(ini_file);
					m_networkData.is_load = false;
				}
			}

			ImNodes::EndNodeEditor();
		}

	}
	ImGui::End();

	ImGui::Begin("Resources");
	{
		ImGui::BeginTabBar("resources tab bar");
		if (ImGui::BeginTabItem("Assets"))
		{
			ImGui::SameLine(); ImGui::Checkbox("Only Anims with Events", &m_networkConfig.filter_events);

			static ImGuiTextFilter filter;
			ImGui::Text("Filter:");
			filter.Draw("##asset searchbar", 340.f);

			//Assets Window
			ImGui::BeginChild("Assets");
			{
				if (m_networkData.anim_events.anim_nodes.size() == 0)
					m_selectedIndex = -1;

				for (int i = 0; i < m_networkData.anim_events.anim_nodes.size(); i++)
				{
					const char* anim_name = Morpheme::getAnimNameFromAnimNode(m_networkData.anim_events.anim_nodes[i]);
					bool selected = (m_selectedIndex == i);

					if (filter.PassFilter(anim_name))
					{
						ImGui::PushID(i);
						ImGui::Selectable(anim_name, &selected);

						if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
						{
							m_selectedIndex = i;

							if (ImGui::IsMouseDoubleClicked(0))
							{
								m_networkData.anim_events.asset_name = anim_name;
								m_networkData.anim_events.event_track_node = (ImU64)m_networkData.anim_events.anim_nodes[i];
								m_loadTracks = true;
							}
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

	ImGui::Begin("Attributes");
	{
		if (!m_clearNetwork && m_networkData.imnodes_data.selected_node != NULL)
		{
			char buf[255];
			sprintf_s(buf, "[%d] %s (%s)", m_networkData.imnodes_data.selected_node->m_nodeID, Morpheme::getNodeName(target_character, m_networkData.imnodes_data.selected_node->m_nodeID), Morpheme::getNodeTypeName_Alt(network, m_networkData.imnodes_data.selected_node->m_nodeID));

			ImGui::Text(buf);

			ImGui::PushItemWidth(100);
			ImGui::InputInt("Node Type", (int*)&m_networkData.imnodes_data.selected_node->m_nodeTypeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputByte("Flag 1", (char*)&m_networkData.imnodes_data.selected_node->m_flags1, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputByte("Flag 2", (char*)&m_networkData.imnodes_data.selected_node->m_flags2, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputShort("Node ID", (short*)&m_networkData.imnodes_data.selected_node->m_nodeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputShort("Parent Node ID", (short*)&m_networkData.imnodes_data.selected_node->m_parentNodeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputShort("Child Count", (short*)&m_networkData.imnodes_data.selected_node->m_numChildNodeIDs, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputByte("Input Count", (char*)&m_networkData.imnodes_data.selected_node->m_numControlParamAndOpNodeIDs, 0, 0, ImGuiInputTextFlags_ReadOnly);
			if (m_networkData.imnodes_data.selected_node->m_numChildNodeIDs > 0)
			{
				if (ImGui::TreeNode("Child Nodes"))
				{
					for (size_t j = 0; j < m_networkData.imnodes_data.selected_node->m_numChildNodeIDs; j++)
					{
						ImVec4 child_col = ImGui::GetStyleColorVec4(ImGuiCol_Text);

						if (Morpheme::isNodeContainer(network, m_networkData.imnodes_data.selected_node->m_childNodeIDs[j]))
							child_col = ImVec4(0.39f, 0.58f, 1.0f, 1.0f);

						ImGui::PushStyleColor(ImGuiCol_Text, child_col);
						char id[255];
						sprintf_s(id, "child %d", j);

						char child_name[255];
						sprintf_s(child_name, "%s (%s)", Morpheme::getNodeName(target_character, m_networkData.imnodes_data.selected_node->m_childNodeIDs[j]), Morpheme::getNodeTypeName_Alt(network, m_networkData.imnodes_data.selected_node->m_childNodeIDs[j]));
						ImGui::PushID(id);
						ImGui::InputShort(child_name, (short*)&m_networkData.imnodes_data.selected_node->m_childNodeIDs[j], 0, 0, ImGuiInputTextFlags_ReadOnly);
						ImGui::PopID();
						ImGui::PopStyleColor(1);
					}
					ImGui::TreePop();
				}
			}
			if (m_networkData.imnodes_data.selected_node->m_numControlParamAndOpNodeIDs > 0)
			{
				if (ImGui::TreeNode("Inputs"))
				{
					for (BYTE j = 0; j < m_networkData.imnodes_data.selected_node->m_numControlParamAndOpNodeIDs; j++)
					{
						ImVec4 input_col = ImGui::GetStyleColorVec4(ImGuiCol_Text);

						if (Morpheme::isNodeContainer(network, m_networkData.imnodes_data.selected_node->m_controlParamAndOpNodeIDs[j]))
							input_col = ImVec4(0.2f, 0.2f, 1.0f, 1.0f);

						ImGui::PushStyleColor(ImGuiCol_Text, input_col);
						char id[255];
						sprintf_s(id, "input %d", j);

						char input_name[255] = "";
						sprintf_s(input_name, "%s (%s)", Morpheme::getNodeName(target_character, m_networkData.imnodes_data.selected_node->m_controlParamAndOpNodeIDs[j]), Morpheme::getNodeTypeName_Alt(network, m_networkData.imnodes_data.selected_node->m_controlParamAndOpNodeIDs[j]));
						ImGui::PushID(id);
						ImGui::InputInt(input_name, &m_networkData.imnodes_data.selected_node->m_controlParamAndOpNodeIDs[j], 0, 0, ImGuiInputTextFlags_ReadOnly);
						ImGui::PopID();
						ImGui::PopStyleColor(1);
					}
					ImGui::TreePop();
				}
			}

			ImGui::PopItemWidth();
			ImGui::InputPtr("Node Data", (uint64_t*)&m_networkData.imnodes_data.selected_node->node_data, ImGuiInputTextFlags_ReadOnly | ImGuiInputTextFlags_CharsHexadecimal);
			ImGui::Separator();
			MorphemeInterface::renderNodeAttributeType(m_networkData.imnodes_data.selected_node, MorphemeInterface::getNodeContentAmount(m_networkData.imnodes_data.selected_node));
		}
	}
		
	ImGui::End();

	ImGui::Begin("Nodes");
	{
		if (!m_clearNetwork && network)
		{
			for (size_t i = 0; i < m_networkData.nodes.size(); i++)
			{
				if (m_networkData.nodes[i])
				{
					ImVec4 node_col = ImGui::GetStyleColorVec4(ImGuiCol_Header);
					ImVec4 node_col_active = ImGui::GetStyleColorVec4(ImGuiCol_HeaderActive);
					ImVec4 node_col_hovered = ImGui::GetStyleColorVec4(ImGuiCol_HeaderHovered);

					if (Morpheme::isNodeContainer(network, m_networkData.nodes[i]->m_nodeID))
					{
						node_col = ImVec4(0.2f, 0.2f, 1.0f, 1.0f);
						node_col_active = ImVec4(0.39f, 0.39f, 1.0f, 1.0f);
						node_col_hovered = ImVec4(0.27f, 0.27f, 1.0f, 1.0f);
					}

					ImGui::PushStyleColor(ImGuiCol_Header, node_col);
					ImGui::PushStyleColor(ImGuiCol_HeaderActive, node_col_active);
					ImGui::PushStyleColor(ImGuiCol_HeaderHovered, node_col_hovered);

					char buf[255];
					sprintf_s(buf, "[%d] %s (%s)", m_networkData.nodes[i]->m_nodeID, m_networkData.node_names[i], Morpheme::getNodeTypeName_Alt(network, m_networkData.nodes[i]->m_nodeID));

					if (ImGui::CollapsingHeader(buf))
					{
						ImGui::PushItemWidth(100);
						ImGui::PushID(i);
						ImGui::InputInt("Node Type", (int*)&m_networkData.nodes[i]->m_nodeTypeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
						ImGui::InputByte("Flag 1", (char*)&m_networkData.nodes[i]->m_flags1, 0, 0, ImGuiInputTextFlags_ReadOnly);
						ImGui::InputByte("Flag 2", (char*)&m_networkData.nodes[i]->m_flags2, 0, 0, ImGuiInputTextFlags_ReadOnly);
						ImGui::InputShort("Node ID", (short*)&m_networkData.nodes[i]->m_nodeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
						ImGui::InputShort("Parent Node ID", (short*)&m_networkData.nodes[i]->m_parentNodeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
						ImGui::InputShort("Child Count", (short*)&m_networkData.nodes[i]->m_numChildNodeIDs, 0, 0, ImGuiInputTextFlags_ReadOnly);
						ImGui::InputByte("Input Count", (char*)&m_networkData.nodes[i]->m_numControlParamAndOpNodeIDs, 0, 0, ImGuiInputTextFlags_ReadOnly);
						if (m_networkData.nodes[i]->m_numChildNodeIDs > 0)
						{
							if (ImGui::TreeNode("Child Nodes"))
							{
								for (size_t j = 0; j < m_networkData.nodes[i]->m_numChildNodeIDs; j++)
								{
									ImVec4 child_col = ImGui::GetStyleColorVec4(ImGuiCol_Text);

									if (Morpheme::isNodeContainer(network, m_networkData.nodes[i]->m_childNodeIDs[j]))
										child_col = ImVec4(0.39f, 0.58f, 1.0f, 1.0f);

									ImGui::PushStyleColor(ImGuiCol_Text, child_col);
									char id[255];
									sprintf_s(id, "child %d", j);

									char child_name[255];
									sprintf_s(child_name, "%s (%s)", Morpheme::getNodeName(target_character, m_networkData.nodes[i]->m_childNodeIDs[j]), Morpheme::getNodeTypeName_Alt(network, m_networkData.nodes[i]->m_childNodeIDs[j]));
									ImGui::PushID(id);
									ImGui::InputShort(child_name, (short*)&m_networkData.nodes[i]->m_childNodeIDs[j], 0, 0, ImGuiInputTextFlags_ReadOnly);
									ImGui::PopID();
									ImGui::PopStyleColor(1);
								}
								ImGui::TreePop();
							}
						}
						if (m_networkData.nodes[i]->m_numControlParamAndOpNodeIDs > 0)
						{
							if (ImGui::TreeNode("Inputs"))
							{
								for (BYTE j = 0; j < m_networkData.nodes[i]->m_numControlParamAndOpNodeIDs; j++)
								{
									ImVec4 input_col = ImGui::GetStyleColorVec4(ImGuiCol_Text);

									if (Morpheme::isNodeContainer(network, m_networkData.nodes[i]->m_controlParamAndOpNodeIDs[j]))
										input_col = ImVec4(0.2f, 0.2f, 1.0f, 1.0f);

									ImGui::PushStyleColor(ImGuiCol_Text, input_col);
									char id[255];
									sprintf_s(id, "input %d", j);

									char input_name[255] = "";
									sprintf_s(input_name, "%s (%s)", Morpheme::getNodeName(target_character, m_networkData.nodes[i]->m_controlParamAndOpNodeIDs[j]), Morpheme::getNodeTypeName_Alt(network, m_networkData.nodes[i]->m_controlParamAndOpNodeIDs[j]));
									ImGui::PushID(id);
									ImGui::InputInt(input_name, &m_networkData.nodes[i]->m_controlParamAndOpNodeIDs[j], 0, 0, ImGuiInputTextFlags_ReadOnly);
									ImGui::PopID();
									ImGui::PopStyleColor(1);
								}
								ImGui::TreePop();
							}
						}

						ImGui::PopItemWidth();
						ImGui::InputPtr("Node Data", (uint64_t*)&m_networkData.nodes[i]->node_data, ImGuiInputTextFlags_ReadOnly | ImGuiInputTextFlags_CharsHexadecimal);
						ImGui::PopID();
					}

					ImGui::PopStyleColor(3);
				}
			}
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
			for (size_t i = 0; i < m_networkData.messages.message_defs.size(); i++)
			{
				ImGui::PushID(i);
				if (ImGui::CollapsingHeader(m_networkData.messages.message_names[i]))
				{
					ImGui::InputInt("Message ID", &m_networkData.messages.message_defs[i]->message_id, 0, 0, ImGuiInputTextFlags_ReadOnly);
					ImGui::InputInt("Node Count", &m_networkData.messages.message_defs[i]->node_count, 0, 0, ImGuiInputTextFlags_ReadOnly);

					ImGui::PushItemWidth(100);
					if (m_networkData.messages.message_defs[i]->node_count > 0 && ImGui::TreeNode("Nodes"))
					{
						for (size_t j = 0; j < m_networkData.messages.message_defs[i]->node_count; j++)
						{
							char label[255];

							sprintf_s(label, "%s (%s)", Morpheme::getNodeName(target_character, m_networkData.messages.message_defs[i]->node_array[j]), Morpheme::getNodeTypeName_Alt(network, m_networkData.messages.message_defs[i]->node_array[j]));

							ImGui::InputShort(label, &m_networkData.messages.message_defs[i]->node_array[j], 0, 0, ImGuiInputTextFlags_ReadOnly);
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
			ImGui::BeginTabBar("preview");

			if (ImGui::BeginTabItem("Control Parameters"))
			{
				if (ImGui::CollapsingHeader("Ungrouped"))
				{
					for (size_t i = 0; i < m_networkData.control_params.cp_nodes.size(); i++)
					{
						char input_id[255];

						sprintf_s(input_id, "input %d", i);

						ImGui::Text(m_networkData.control_params.cp_names[i]);
						DWORD* value = m_networkData.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_value;

						switch (m_networkData.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_dataType)
						{
						case 0:
							ImGui::PushID(input_id);
							ImGui::DragByte("", (char*)(value), 0, 0, 1, "%d");
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
							ImGui::DragFloat("X", (float*)&m_networkData.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_value[0], 0, -10000, 1000, "%.3f");
							ImGui::DragFloat("Y", (float*)&m_networkData.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_value[1], 0, -10000, 1000, "%.3f");
							ImGui::DragFloat("Z", (float*)&m_networkData.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_value[2], 0, -10000, 1000, "%.3f");
							ImGui::PopID();
							break;
						default:
							char buf[50];
							sprintf_s(buf, "Unknown CP type %d (%d)\n", m_networkData.control_params.cp_nodes[i]->m_nodeTypeID, m_networkData.control_params.cp_bins[i]->m_controlParamContainer->m_controlParamData->m_dataType);
							ImGui::Text(buf);
							break;
						}
					}
				}

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Messages"))
			{
				for (size_t i = 0; i < m_networkData.messages.message_names.size(); i++)
				{
					ImVec4 text_col = ImVec4(1, 1, 1, 1);

					for (size_t j = 0; j < m_networkData.messages.message_defs[i]->node_count; j++)
						if (Morpheme::isNodeActive(network, m_networkData.messages.message_defs[i]->node_array[j]))
							text_col = ImVec4(1.0f, 0.7f, 0.0f, 1.0f);

					ImGui::PushStyleColor(ImGuiCol_Text, text_col);
					if (ImGui::Button(m_networkData.messages.message_names[i], ImVec2(ImGui::GetWindowWidth(), 0.0f)))
					{
						Morpheme::sMorphemeMessage message_data = Morpheme::sMorphemeMessage::sMorphemeMessage(m_networkData.messages.message_ids[i]);

						sendMessage(network, message_data);
					}

					ImGui::PopStyleColor(1);
				}

				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();

			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::End();

	ImGui::SetNextWindowSize(ImVec2(200, 500));
	ImGui::Begin("AnimNode");
	{
		static bool expanded = true;
		static char categoryInfo[100], valueInfo[255];
		static int selectedEntry = -1;
		static int selectedEvent = -1;
		static int firstFrame = 0;
		static int currentFrame = -1;

		static int selectedEntry_taePl = -1;
		static int selectedEvent_taePl = -1;
		static int selectedEntry_taeSfx = -1;
		static int selectedEvent_taeSfx = -1;
		static int selectedEntry_taeSnd = -1;
		static int selectedEvent_taeSnd = -1;

		static int firstFrame_tae = 0;
		static int currentFrame_tae = -1;

		ImGui::PushItemWidth(200);
		ImGui::InputPtr("Node Pointer", &m_networkData.anim_events.event_track_node, ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_EnterReturnsTrue);
		ImGui::PopItemWidth();

		if (ImGui::Button("Load Tracks"))
			m_loadTracks = true;

		ImGui::SameLine();
		if (ImGui::Button("Clear Tracks") && g_eventTrackEditor.GetTrackCount())
			m_clearTracks = true;

		ImGui::SameLine();
		if (ImGui::Button("Save Tracks") && g_eventTrackEditor.GetTrackCount())
			m_saveTracks = true;

		if (g_eventTrackEditor.GetTrackCount())
			ImGui::Text(m_networkData.anim_events.asset_name);

		if (m_networkData.anim_events.event_track_node)
		{
			Morpheme::NodeDef* anim_sync_node = (Morpheme::NodeDef*)(m_networkData.anim_events.event_track_node);
			Morpheme::NodeData104* node_data = (Morpheme::NodeData104*)anim_sync_node->node_data;

			if (anim_sync_node)
				currentFrame = Morpheme::getCurrentAnimFrame(network, anim_sync_node->m_nodeID);

			currentFrame_tae = currentFrame + MathHelper::TimeToFrame(*(float*)(node_data->m_animData + 0x80), 60);

			Debug::DebuggerMessage(Debug::LVL_DEBUG, "Current Time (EventTrack): %.3f\n", MathHelper::FrameToTime(currentFrame, 60));
			Debug::DebuggerMessage(Debug::LVL_DEBUG, "Current Time (TAE): %.3f\n", MathHelper::FrameToTime(currentFrame_tae, 60));
		}

		if (g_eventTrackEditor.GetTrackCount())
		{
			selectedEntry = -1;
			selectedEvent = -1;
		}

		if (g_timeActEditorPl.GetTrackCount() == 0)
		{
			selectedEntry_taePl = -1;
			selectedEvent_taePl = -1;

			selectedEntry_taeSfx = -1;
			selectedEvent_taeSfx = -1;

			selectedEntry_taeSnd = -1;
			selectedEvent_taeSnd = -1;
		}

		if (ImGui::BeginTabBar("editor_tab"))
		{
			if (ImGui::BeginTabItem("Event Track"))
			{
				ImGui::BeginChild("sequencer");
				ImSequencer::Sequencer(&g_eventTrackEditor, &currentFrame, &selectedEntry, &selectedEvent, &expanded, true, &firstFrame, ImSequencer::EDITOR_EVENT_EDIT_STARTEND | ImSequencer::EDITOR_MARK_ACTIVE_EVENTS);
				ImGui::EndChild();

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("TimeAct"))
			{
				ImGui::BeginTabBar("time_act_editors");
				if (ImGui::BeginTabItem("Pl"))
				{
					ImGui::BeginChild("tae sequencer");
					ImSequencer::Sequencer(&g_timeActEditorPl, &currentFrame, &selectedEntry_taePl, &selectedEvent_taePl, &expanded, true, &firstFrame_tae, ImSequencer::EDITOR_EVENT_EDIT_STARTEND | ImSequencer::EDITOR_MARK_ACTIVE_EVENTS);
					ImGui::EndChild();

					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Sfx"))
				{
					ImGui::BeginChild("tae sequencer");
					ImSequencer::Sequencer(&g_timeActEditorSfx, &currentFrame, &selectedEntry_taeSfx, &selectedEvent_taeSfx, &expanded, true, &firstFrame_tae, ImSequencer::EDITOR_EVENT_EDIT_STARTEND | ImSequencer::EDITOR_MARK_ACTIVE_EVENTS);
					ImGui::EndChild();

					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem("Snd"))
				{
					ImGui::BeginChild("tae sequencer");
					ImSequencer::Sequencer(&g_timeActEditorSnd, &currentFrame, &selectedEntry_taeSnd, &selectedEvent_taeSnd, &expanded, true, &firstFrame_tae, ImSequencer::EDITOR_EVENT_EDIT_STARTEND | ImSequencer::EDITOR_MARK_ACTIVE_EVENTS);
					ImGui::EndChild();

					ImGui::EndTabItem();
				}
				ImGui::EndTabBar();

				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}

		ImGui::Begin("Event Data");
		if (ImGui::BeginTabBar("data_tab"))
		{
			if (ImGui::BeginTabItem("EventTrack"))
			{
				if (selectedEntry != -1 && selectedEvent)
				{
					EventTrackEditor::EventTrack& track = g_eventTrackEditor.m_eventTracks[selectedEntry];
					float startTime = MathHelper::FrameToTime(track.m_event[selectedEvent].m_frameStart, 60);
					float duration = MathHelper::FrameToTime(track.m_event[selectedEvent].m_duration, 60);

					ImGui::Text("%s", track.m_name);
					ImGui::PushItemWidth(100);
					ImGui::InputInt("Event ID", &track.m_eventId, 1, 0);
					if (ImGui::IsItemHovered())
					{
						ImGui::Text("Info");
						ImGui::Separator();

						ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionWidth());
						ImGui::Text(getEventTrackCategoryTooltip(track.m_eventId).c_str());
						ImGui::PopTextWrapPos();
					}

					ImGui::InputInt("Event Value", &track.m_event[selectedEvent].m_value, 1, 0);
					if (ImGui::IsItemHovered())
					{
						ImGui::Text("Info");
						ImGui::Separator();

						ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionWidth());
						ImGui::Text(getEventTrackEventTooltip(track.m_event[selectedEvent].m_value).c_str());
						ImGui::PopTextWrapPos();
					}

					ImGui::DragFloat("Start Time", &startTime, 1 / 60, 0, MathHelper::FrameToTime(g_eventTrackEditor.m_frameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);
					ImGui::DragFloat("End Time", &duration, 1 / 60, 0, MathHelper::FrameToTime(g_eventTrackEditor.m_frameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);
					ImGui::PopItemWidth();
				}
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("TimeAct"))
			{
				ImGui::BeginTabBar("time_act_data");
				if (ImGui::BeginTabItem("Pl"))
				{
					int selectedEntryTae = selectedEntry_taePl;
					int selectedEventTae = selectedEvent_taePl;

					if (selectedEntryTae != -1 && selectedEventTae != -1)
					{
						TimeActEditor::TimeActTrack& track = g_timeActEditorPl.m_tracks[selectedEntryTae];
						float startTime = MathHelper::FrameToTime(track.m_event[selectedEventTae].m_frameStart, 60);
						float duration = MathHelper::FrameToTime(track.m_event[selectedEventTae].m_duration, 60);

						ImGui::Text(g_timeActEditorPl.GetEventLabel(selectedEntryTae, selectedEventTae, false).c_str());
						ImGui::PushItemWidth(100);
						ImGui::InputInt("Group ID", &track.m_eventGroup, 1, 0);
						if (ImGui::IsItemHovered())
						{
							ImGui::Text("Info");
							ImGui::Separator();

							ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionWidth());
							ImGui::Text(getTaeCategoryTooltip(track.m_eventGroup).c_str());
							ImGui::PopTextWrapPos();
						}

						ImGui::InputInt("Event ID", &track.m_event[selectedEventTae].m_value, 1, 0);
						if (ImGui::IsItemHovered())
						{
							ImGui::Text("Info");
							ImGui::Separator();

							ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionWidth());
							ImGui::Text(getTaeEventTooltip(track.m_event[selectedEventTae].m_value).c_str());
							ImGui::PopTextWrapPos();
						}

						ImGui::DragFloat("Start Time", &startTime, 1 / 60, 0, MathHelper::FrameToTime(g_timeActEditorPl.m_frameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);
						ImGui::DragFloat("End Time", &duration, 1 / 60, 0, MathHelper::FrameToTime(g_timeActEditorPl.m_frameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);

						track.m_event[selectedEventTae].m_args->ImGuiEdit();

						ImGui::PopItemWidth();
					}

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("Sfx"))
				{
					int selectedEntryTae = selectedEntry_taeSfx;
					int selectedEventTae = selectedEvent_taeSfx;

					if (selectedEntryTae != -1 && selectedEventTae != -1)
					{
						TimeActEditor::TimeActTrack& track = g_timeActEditorSfx.m_tracks[selectedEntryTae];
						float startTime = MathHelper::FrameToTime(track.m_event[selectedEventTae].m_frameStart, 60);
						float duration = MathHelper::FrameToTime(track.m_event[selectedEventTae].m_duration, 60);

						ImGui::Text(g_timeActEditorSfx.GetEventLabel(selectedEntryTae, selectedEventTae, false).c_str());
						ImGui::PushItemWidth(100);
						ImGui::InputInt("Group ID", &track.m_eventGroup, 1, 0);
						if (ImGui::IsItemHovered())
						{
							ImGui::Text("Info");
							ImGui::Separator();

							ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionWidth());
							ImGui::Text(getTaeCategoryTooltip(track.m_eventGroup).c_str());
							ImGui::PopTextWrapPos();
						}

						ImGui::InputInt("Event ID", &track.m_event[selectedEventTae].m_value, 1, 0);
						if (ImGui::IsItemHovered())
						{
							ImGui::Text("Info");
							ImGui::Separator();

							ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionWidth());
							ImGui::Text(getTaeEventTooltip(track.m_event[selectedEventTae].m_value).c_str());
							ImGui::PopTextWrapPos();
						}

						ImGui::DragFloat("Start Time", &startTime, 1 / 60, 0, MathHelper::FrameToTime(g_timeActEditorPl.m_frameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);
						ImGui::DragFloat("End Time", &duration, 1 / 60, 0, MathHelper::FrameToTime(g_timeActEditorPl.m_frameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);

						track.m_event[selectedEventTae].m_args->ImGuiEdit();

						ImGui::PopItemWidth();
					}

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("Snd"))
				{
					int selectedEntryTae = selectedEntry_taeSnd;
					int selectedEventTae = selectedEvent_taeSnd;

					if (selectedEntryTae != -1 && selectedEventTae != -1)
					{
						TimeActEditor::TimeActTrack& track = g_timeActEditorSnd.m_tracks[selectedEntryTae];
						float startTime = MathHelper::FrameToTime(track.m_event[selectedEventTae].m_frameStart, 60);
						float duration = MathHelper::FrameToTime(track.m_event[selectedEventTae].m_duration, 60);

						ImGui::Text(g_timeActEditorSnd.GetEventLabel(selectedEntryTae, selectedEventTae, false).c_str());
						ImGui::PushItemWidth(100);
						ImGui::InputInt("Group ID", &track.m_eventGroup, 1, 0);
						if (ImGui::IsItemHovered())
						{
							ImGui::Text("Info");
							ImGui::Separator();

							ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionWidth());
							ImGui::Text(getTaeCategoryTooltip(track.m_eventGroup).c_str());
							ImGui::PopTextWrapPos();
						}

						ImGui::InputInt("Event ID", &track.m_event[selectedEventTae].m_value, 1, 0);
						if (ImGui::IsItemHovered())
						{
							ImGui::Text("Info");
							ImGui::Separator();

							ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionWidth());
							ImGui::Text(getTaeEventTooltip(track.m_event[selectedEventTae].m_value).c_str());
							ImGui::PopTextWrapPos();
						}

						ImGui::DragFloat("Start Time", &startTime, 1 / 60, 0, MathHelper::FrameToTime(g_timeActEditorPl.m_frameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);
						ImGui::DragFloat("End Time", &duration, 1 / 60, 0, MathHelper::FrameToTime(g_timeActEditorPl.m_frameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);

						track.m_event[selectedEventTae].m_args->ImGuiEdit();

						ImGui::PopItemWidth();
					}

					ImGui::EndTabItem();
				}

				ImGui::EndTabBar();

				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		ImGui::End();
	}
	ImGui::End();
}

void AppGUI::ProcessVariables()
{
	if (m_loadTracks && m_networkData.anim_events.event_track_node)
	{
		m_loadTracks = false;
		m_clearTracks = false;

		g_eventTrackEditor.Clear();
		g_timeActEditorPl.Clear();

		Morpheme::NodeDef* anim_sync_node = (Morpheme::NodeDef*)(m_networkData.anim_events.event_track_node);

		m_networkData.anim_events.anim_tae.current_tae = Morpheme::getTimeActId(anim_sync_node);

		if (anim_sync_node->m_nodeTypeID == NodeType_NodeAnimSyncEvents)
		{
			Morpheme::NodeData104* node_data = (Morpheme::NodeData104*)anim_sync_node->node_data;

			if (node_data->m_animData && node_data->m_eventTrackData)
			{
				uint64_t nsaFile = (uint64_t)node_data->m_animData;

				int trackLenght = *(float*)(nsaFile + 0x84);
				int animLenght = *(float*)(nsaFile + 0x88);

				m_networkData.anim_events.anim_len = animLenght;
				m_networkData.anim_events.mult = 1;
				g_eventTrackEditor.m_frameMin = 0;
				g_eventTrackEditor.m_frameMax = MathHelper::TimeToFrame(trackLenght, 60);

				if (m_networkConfig.eventTrackConfig_scaleToAnim)
				{
					m_networkData.anim_events.mult = animLenght / trackLenght;
					g_eventTrackEditor.m_frameMax = MathHelper::TimeToFrame(animLenght, 60);
				}

				m_networkData.anim_events.asset_name = Morpheme::getAnimNameFromAnimNode(anim_sync_node);

				uint32_t event_track_count = node_data->m_eventTrackData->m_eventTracks[0].m_trackCount + node_data->m_eventTrackData->m_eventTracks[1].m_trackCount + node_data->m_eventTrackData->m_eventTracks[2].m_trackCount;

				if (event_track_count > 0)
				{
					g_eventTrackEditor.m_eventTracks.reserve(event_track_count);

					for (int i = 0; i < node_data->m_eventTrackData->m_eventTracks[0].m_trackCount; i++)
						g_eventTrackEditor.m_eventTracks.push_back(EventTrackEditor::EventTrack(node_data->m_eventTrackData->m_eventTracks[0].m_tracks[i], m_networkData.anim_events.mult, true));

					for (int i = 0; i < node_data->m_eventTrackData->m_eventTracks[1].m_trackCount; i++)
						g_eventTrackEditor.m_eventTracks.push_back(EventTrackEditor::EventTrack(node_data->m_eventTrackData->m_eventTracks[1].m_tracks[i], m_networkData.anim_events.mult, false));

					for (int i = 0; i < node_data->m_eventTrackData->m_eventTracks[2].m_trackCount; i++)
						g_eventTrackEditor.m_eventTracks.push_back(EventTrackEditor::EventTrack(node_data->m_eventTrackData->m_eventTracks[2].m_tracks[i], m_networkData.anim_events.mult, false));

					int id = 0;
				}
				else
					MessageBoxA(NULL, "Animation does not have any EventTrack associated with it", "Morpheme Network Inspector", MB_ICONINFORMATION);

				g_timeActEditorPl.m_frameMin;
				g_timeActEditorPl.m_frameMax = MathHelper::TimeToFrame(trackLenght, 60);

				g_timeActEditorSfx.m_frameMin;
				g_timeActEditorSfx.m_frameMax = MathHelper::TimeToFrame(trackLenght, 60);

				g_timeActEditorSnd.m_frameMin;
				g_timeActEditorSnd.m_frameMax = MathHelper::TimeToFrame(trackLenght, 60);

				if (m_networkConfig.eventTrackConfig_scaleToAnim)
				{
					m_networkData.anim_events.mult = animLenght / trackLenght;
					g_timeActEditorPl.m_frameMax = MathHelper::TimeToFrame(animLenght, 60);
					g_timeActEditorSfx.m_frameMax = MathHelper::TimeToFrame(animLenght, 60);
					g_timeActEditorSnd.m_frameMax = MathHelper::TimeToFrame(animLenght, 60);
				}

				if (event_track_count > 0)
				{
					int id = 0;
					int tae_id = -1;

					for (int i = 0; i < node_data->m_eventTrackData->m_eventTracks[2].m_trackCount; i++)
					{
						if (node_data->m_eventTrackData->m_eventTracks[2].m_tracks[i]->m_eventId == 1000)
						{
							tae_id = node_data->m_eventTrackData->m_eventTracks[2].m_tracks[i]->m_trackData->m_userData;
							break;
						}
					}

					if (tae_id != -1)
					{
						sTaeData* taePl = taeLookup(TimeAct::getTimeActFile_pl(target_character), tae_id);
						sTaeData* taeSfx = taeLookup(TimeAct::getTimeActFile_sfx(target_character), tae_id);
						sTaeData* taeSnd = taeLookup(TimeAct::getTimeActFile_snd(target_character), tae_id);

						for (int i = 0; i < taePl->event_group_count; i++)
							g_timeActEditorPl.m_tracks.push_back(TimeActEditor::TimeActTrack(&taePl->event_group[i]));

						for (int i = 0; i < taeSfx->event_group_count; i++)
							g_timeActEditorSfx.m_tracks.push_back(TimeActEditor::TimeActTrack(&taeSfx->event_group[i]));

						for (int i = 0; i < taeSnd->event_group_count; i++)
							g_timeActEditorSnd.m_tracks.push_back(TimeActEditor::TimeActTrack(&taeSnd->event_group[i]));
					}

				}
				else
					MessageBoxA(NULL, "Animation does not have any TimeAct entry associated with it", "Morpheme Network Inspector", MB_ICONINFORMATION);
			}

		}
		else
			MessageBoxA(NULL, "Provided node is not of the right type\n", "Morpheme Network Inspector", MB_ICONERROR);
	}

	if (m_clearTracks)
	{
		m_selectedIndex = -1;
		m_clearTracks = false;

		g_eventTrackEditor.Clear();
		g_timeActEditorPl.Clear();
	}

	if (m_saveTracks)
	{
		for (int i = 0; i < g_eventTrackEditor.GetTrackCount(); i++)
			g_eventTrackEditor.m_eventTracks[i].SaveEventTrackData(m_networkData.anim_events.mult);

		for (int i = 0; i < g_timeActEditorPl.GetTrackCount(); i++)
			g_timeActEditorPl.m_tracks[i].SaveTimeActTrack();

		for (int i = 0; i < g_timeActEditorSfx.GetTrackCount(); i++)
			g_timeActEditorSfx.m_tracks[i].SaveTimeActTrack();

		for (int i = 0; i < g_timeActEditorSnd.GetTrackCount(); i++)
			g_timeActEditorSnd.m_tracks[i].SaveTimeActTrack();
	}

	if (g_gameState != 30)
	{
		if (g_gameState != g_prevGameState)
			Debug::DebuggerMessage(Debug::LVL_INFO, "Game State changed: %d -> %d. Performing Network Cleanup\n", g_prevGameState, g_gameState);

		target_character = NULL;
		NetworkCleanup();
	}

	if (target_character && (*(int*)(target_character + 0x8) != 1) && (*(int*)(target_character + 0x8) != 2))
	{
		Debug::DebuggerMessage(Debug::LVL_ERROR, "Target Character is not a member of CharacterCtrl. Performing Network Cleanup.\n", g_gameState);

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
		m_clearNetwork = false;
		get_network = false;
		m_networkTasks.get_nodes = true;
		m_networkTasks.get_anim_assets = true;
		m_networkTasks.get_control_params = true;
		m_networkTasks.get_messages = true;

		network = Morpheme::getNetwork(target_character);
		if (network == NULL)
			MessageBoxA(NULL, "Network not found\n", "Morpheme Network Inspector", MB_ICONINFORMATION);
	}

	if (network)
	{
		if (m_networkTasks.get_nodes)
		{
			m_networkTasks.get_nodes = false;
			m_networkData.nodes.clear();
			m_networkData.node_names.clear();

			Debug::DebuggerMessage(Debug::LVL_DEBUG, "Num Nodes: %d\n", network->m_networkDef->m_numNodes);
			for (size_t i = 0; i < network->m_networkDef->m_numNodes; i++)
			{
				m_networkData.nodes.push_back(Morpheme::getNetworkNode(network, network->m_networkDef->m_nodes[i]->m_nodeID));
				m_networkData.node_names.push_back(Morpheme::getNodeName(target_character, network->m_networkDef->m_nodes[i]->m_nodeID));
			}
		}

		if (m_networkTasks.get_anim_assets)
		{
			m_networkData.anim_events.anim_nodes.clear();
			m_networkData.anim_events.anim_nodes = Morpheme::getNetworkAllNodesType(target_character, NodeType_NodeAnimSyncEvents);

			if (m_networkData.anim_events.anim_nodes.size() == 0)
				MessageBoxA(NULL, "There are no Animation nodes", "Morpheme Network Inspector", MB_ICONINFORMATION);

			m_networkData.anim_events.anim_tae.pl_tae = TimeAct::getTimeActFile_pl(target_character);
			m_networkData.anim_events.anim_tae.sfx_tae = TimeAct::getTimeActFile_sfx(target_character);
			m_networkData.anim_events.anim_tae.snd_tae = TimeAct::getTimeActFile_snd(target_character);

			m_networkTasks.get_anim_assets = false;
		}

		if (m_networkTasks.get_control_params)
		{
			m_networkTasks.get_control_params = false;

			m_networkData.control_params.cp_nodes.clear();
			m_networkData.control_params.cp_bins.clear();
			m_networkData.control_params.cp_names.clear();

			m_networkData.control_params.cp_nodes = Morpheme::getNetworkControlParameterNodes(target_character);

			for (size_t i = 0; i < m_networkData.control_params.cp_nodes.size(); i++)
			{
				m_networkData.control_params.cp_bins.push_back(Morpheme::getNetworkNodeBin(network, m_networkData.control_params.cp_nodes[i]->m_nodeID));
				m_networkData.control_params.cp_names.push_back(Morpheme::getNodeName(target_character, m_networkData.control_params.cp_nodes[i]->m_nodeID));
			}
		}

		if (m_networkTasks.get_messages)
		{
			m_networkTasks.get_messages = false;

			m_networkData.messages.message_ids.clear();
			m_networkData.messages.message_names.clear();
			m_networkData.messages.message_defs.clear();

			m_networkData.messages.message_defs = Morpheme::getMessageDefs(target_character);

			for (size_t i = 0; i < network->m_networkDef->m_requestIDNamesTable->m_NumEntrys; i++)
			{
				m_networkData.messages.message_ids.push_back(network->m_networkDef->m_requestIDNamesTable->m_IDs[i]);
				m_networkData.messages.message_names.push_back(Morpheme::getMessageName(target_character, network->m_networkDef->m_requestIDNamesTable->m_IDs[i]));
			}
		}

		if (m_networkData.imnodes_data.is_inspect)
		{
			ImNodesEditorContext& editor = ImNodes::EditorContextGet();
			ImNodes::ObjectPoolReset(editor.Nodes);
			ImNodes::ObjectPoolReset(editor.Pins);
			ImNodes::ObjectPoolReset(editor.Links);
			ImNodes::ObjectPoolReset(editor.NodeLinks);

			GImNodes->HoveredNodeIdx.Reset();
			GImNodes->HoveredLinkIdx.Reset();
			GImNodes->HoveredPinIdx.Reset();
			GImNodes->DeletedLinkIdx.Reset();
			GImNodes->SnapLinkIdx.Reset();
			GImNodes->NodeLinkIdx.Reset();

			m_networkData.is_load = true;
			m_networkData.imnodes_data.is_inspect = false;
			m_networkData.imnodes_data.node_ids.clear();
			m_networkData.imnodes_data.node_position.clear();
			m_networkData.imnodes_data.occupied_positions.clear();
			m_networkData.imnodes_data.editors.clear();
			m_networkData.imnodes_data.node_def = NULL;

			if (Morpheme::doesNodeExist(network, m_networkData.imnodes_data.node_to_inspect))
				m_networkData.imnodes_data.node_def = Morpheme::getNetworkNode(network, m_networkData.imnodes_data.node_to_inspect);
			else
				MessageBoxA(NULL, "The specified node is not present in this network", "MorphemeNetworkInspector", MB_ICONINFORMATION);
		}
	}
}

void AppGUI::Dockspace(ImGuiID dockSpace)
{
}

void AppGUI::NetworkCleanup()
{
	m_clearNetwork = true;
	network = NULL;

	m_networkTasks.get_nodes = false;
	m_networkTasks.get_anim_assets = false;
	m_networkTasks.get_control_params = false;
	m_networkTasks.get_messages = false;

	m_networkData.node_names.clear();
	m_networkData.nodes.clear();

	m_networkData.anim_events.anim_nodes.clear();

	m_networkData.control_params.cp_nodes.clear();
	m_networkData.control_params.cp_bins.clear();
	m_networkData.control_params.cp_names.clear();

	m_networkData.messages.message_ids.clear();
	m_networkData.messages.message_names.clear();
	m_networkData.messages.message_defs.clear();

	m_networkData.imnodes_data.is_inspect = false;
	m_networkData.imnodes_data.node_ids.clear();
	m_networkData.imnodes_data.node_position.clear();
	m_networkData.imnodes_data.occupied_positions.clear();
	m_networkData.imnodes_data.node_to_inspect = 0;
	m_networkData.imnodes_data.node_def = NULL;

	ImNodesEditorContext& editor = ImNodes::EditorContextGet();
	ImNodes::ObjectPoolReset(editor.Nodes);
	ImNodes::ObjectPoolReset(editor.Pins);
	ImNodes::ObjectPoolReset(editor.Links);
	ImNodes::ObjectPoolReset(editor.NodeLinks);

	GImNodes->HoveredNodeIdx.Reset();
	GImNodes->HoveredLinkIdx.Reset();
	GImNodes->HoveredPinIdx.Reset();
	GImNodes->DeletedLinkIdx.Reset();
	GImNodes->SnapLinkIdx.Reset();
	GImNodes->NodeLinkIdx.Reset();
}