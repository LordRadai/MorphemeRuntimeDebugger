#include "MorphemeNetworkInspector.h"
#include "Debug.h"
#include "FRPG2.h"
#include "Morpheme.h"
#include "ImNodesInterface.h"
#include "MorphemeInterface.h"

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

		/*
		if (ImGui::BeginMenu("Debug"))
		{
			//if (ImGui::MenuItem("Show Skeleton", NULL, &show_skeleton)) { show_skeleton != show_skeleton; }
			ImGui::EndMenu();
		}*/

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

		ImGui::InputShort("Node ID", &network_data.imnodes_data.node_to_inspect, 0, 0, ImGuiInputTextFlags_None);
		if (ImGui::Button("Get Node")) { network_data.imnodes_data.is_inspect = true; }
		
		ImGui::SameLine();
		if (ImGui::Button("Save Editor State")) { network_data.is_save = true; }

		if (!clear_network && network && network_data.imnodes_data.node_def)
		{ 
			if (network_data.imnodes_data.node_def->m_parentNodeID != -1 && network_data.imnodes_data.node_def->m_nodeTypeID != NodeType_NetworkInstance);
			{
				char label[256];
				Morpheme::NodeDef* temp = network_data.imnodes_data.node_def;

				do
				{
					if (temp->m_parentNodeID == -1)
						break;

					network_data.imnodes_data.parent_node = Morpheme::getNetworkNode(network, temp->m_parentNodeID);
					network_data.imnodes_data.parent_id = temp->m_parentNodeID;

					if (network_data.imnodes_data.parent_node->m_nodeTypeID == NodeType_StateMachine || network_data.imnodes_data.parent_node->m_nodeTypeID == NodeType_NetworkInstance)
						break;

					temp = network_data.imnodes_data.parent_node;

				} while (true);

				if (network_data.imnodes_data.parent_id != -1 && temp->m_parentNodeID != -1)
				{
					const char* node_name = Morpheme::getNodeName(target_character, network_data.imnodes_data.parent_id);

					sprintf(label, "%d", network_data.imnodes_data.parent_id);

					if (node_name != "")
						sprintf(label, "%s", node_name);

					if (ImGui::Button(label))
					{
						network_data.imnodes_data.node_to_inspect = network_data.imnodes_data.node_def->m_parentNodeID;
						network_data.imnodes_data.is_inspect = true;
					}
				}
			}

			ImNodes::BeginNodeEditor();
			ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_BottomRight);

			if (network_data.imnodes_data.node_def->m_numChildNodeIDs > 0)
			{
				char ini_file[256];
				char folder_name[256];
				sprintf_s(folder_name, ".//MorphemeNetworkInspector//networks//c%d//", *(int*)(target_character + 0x28));
				CreateDirectoryA(folder_name, NULL);

				sprintf(ini_file, ".//MorphemeNetworkInspector//networks//c%d//c%d_%d.ini", *(int*)(target_character + 0x28), *(int*)(target_character + 0x28), network_data.imnodes_data.node_def->m_nodeID);

				//ImNodesInterface::createOutputNode();

				for (size_t i = 0; i < network_data.imnodes_data.node_def->m_numChildNodeIDs; i++)
					ImNodesInterface::createMorphemeNode(Morpheme::getNetworkNode(network, network_data.imnodes_data.node_def->m_childNodeIDs[i]));
				
				if (network_data.is_save)
				{
					network_data.is_save = false;
					ImNodes::SaveCurrentEditorStateToIniFile(ini_file);
				}

				if (network_data.is_load)
				{
					ImNodes::LoadCurrentEditorStateFromIniFile(ini_file);
					network_data.is_load = false;
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

	ImGui::Begin("Attributes");
	{
		if (!clear_network && network_data.imnodes_data.selected_node != NULL)
		{
			char buf[255];
			sprintf_s(buf, "[%d] %s (%s)", network_data.imnodes_data.selected_node->m_nodeID, Morpheme::getNodeName(target_character, network_data.imnodes_data.selected_node->m_nodeID), Morpheme::getNodeTypeName_Alt(network, network_data.imnodes_data.selected_node->m_nodeID));

			ImGui::Text(buf);

			ImGui::PushItemWidth(100);
			ImGui::InputInt("Node Type", (int*)&network_data.imnodes_data.selected_node->m_nodeTypeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputByte("Flag 1", (char*)&network_data.imnodes_data.selected_node->m_flags1, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputByte("Flag 2", (char*)&network_data.imnodes_data.selected_node->m_flags2, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputShort("Node ID", (short*)&network_data.imnodes_data.selected_node->m_nodeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputShort("Parent Node ID", (short*)&network_data.imnodes_data.selected_node->m_parentNodeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputShort("Child Count", (short*)&network_data.imnodes_data.selected_node->m_numChildNodeIDs, 0, 0, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputByte("Input Count", (char*)&network_data.imnodes_data.selected_node->m_numControlParamAndOpNodeIDs, 0, 0, ImGuiInputTextFlags_ReadOnly);
			if (network_data.imnodes_data.selected_node->m_numChildNodeIDs > 0)
			{
				if (ImGui::TreeNode("Child Nodes"))
				{
					for (size_t j = 0; j < network_data.imnodes_data.selected_node->m_numChildNodeIDs; j++)
					{
						ImVec4 child_col = ImGui::GetStyleColorVec4(ImGuiCol_Text);

						if (Morpheme::isNodeContainer(network, network_data.imnodes_data.selected_node->m_childNodeIDs[j]))
							child_col = ImVec4(0.39f, 0.58f, 1.0f, 1.0f);

						ImGui::PushStyleColor(ImGuiCol_Text, child_col);
						char id[255];
						sprintf_s(id, "child %d", j);

						char child_name[255];
						sprintf_s(child_name, "%s (%s)", Morpheme::getNodeName(target_character, network_data.imnodes_data.selected_node->m_childNodeIDs[j]), Morpheme::getNodeTypeName_Alt(network, network_data.imnodes_data.selected_node->m_childNodeIDs[j]));
						ImGui::PushID(id);
						ImGui::InputShort(child_name, (short*)&network_data.imnodes_data.selected_node->m_childNodeIDs[j], 0, 0, ImGuiInputTextFlags_ReadOnly);
						ImGui::PopID();
						ImGui::PopStyleColor(1);
					}
					ImGui::TreePop();
				}
			}
			if (network_data.imnodes_data.selected_node->m_numControlParamAndOpNodeIDs > 0)
			{
				if (ImGui::TreeNode("Inputs"))
				{
					for (byte j = 0; j < network_data.imnodes_data.selected_node->m_numControlParamAndOpNodeIDs; j++)
					{
						ImVec4 input_col = ImGui::GetStyleColorVec4(ImGuiCol_Text);

						if (Morpheme::isNodeContainer(network, network_data.imnodes_data.selected_node->m_controlParamAndOpNodeIDs[j]))
							input_col = ImVec4(0.2f, 0.2f, 1.0f, 1.0f);

						ImGui::PushStyleColor(ImGuiCol_Text, input_col);
						char id[255];
						sprintf_s(id, "input %d", j);

						char input_name[255] = "";
						sprintf_s(input_name, "%s (%s)", Morpheme::getNodeName(target_character, network_data.imnodes_data.selected_node->m_controlParamAndOpNodeIDs[j]), Morpheme::getNodeTypeName_Alt(network, network_data.imnodes_data.selected_node->m_controlParamAndOpNodeIDs[j]));
						ImGui::PushID(id);
						ImGui::InputInt(input_name, &network_data.imnodes_data.selected_node->m_controlParamAndOpNodeIDs[j], 0, 0, ImGuiInputTextFlags_ReadOnly);
						ImGui::PopID();
						ImGui::PopStyleColor(1);
					}
					ImGui::TreePop();
				}
			}

			ImGui::PopItemWidth();
			ImGui::InputPtr("Node Data", (uint64_t*)&network_data.imnodes_data.selected_node->node_data, ImGuiInputTextFlags_ReadOnly | ImGuiInputTextFlags_CharsHexadecimal);
			ImGui::Separator();
			MorphemeInterface::renderNodeAttributeType(network_data.imnodes_data.selected_node, MorphemeInterface::getNodeContentAmount(network_data.imnodes_data.selected_node));
		}
	}
		
	ImGui::End();

	ImGui::Begin("Nodes");
	{
		if (!clear_network && network)
		{
			for (size_t i = 0; i < network_data.nodes.size(); i++)
			{
				if (network_data.nodes[i])
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
						ImGui::InputInt("Node Type", (int*)&network_data.nodes[i]->m_nodeTypeID, 0, 0, ImGuiInputTextFlags_ReadOnly);
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

	ImGui::SetNextWindowSize(ImVec2(200, 500));
	ImGui::Begin("EventTrack");
	{
		static char categoryInfo[100], valueInfo[255];
		static int selectedEntry = -1;
		static int selectedEntry_tae = -1;
		static int firstFrame = 0;
		static int firstFrame_tae = 0;
		static bool expanded = true;
		static bool expanded_tae = true;
		static int currentFrame = -1;
		static int currentFrame_tae = -1;

		float trackLenght;
		float animLenght;

		ImGui::PushItemWidth(200);
		ImGui::InputPtr("Node Pointer", &network_data.anim_events.event_track_node, ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_EnterReturnsTrue);
		ImGui::PopItemWidth();

		if (ImGui::Button("Pull Tracks"))
			pull_tracks = true;

		if (!clear_network && pull_tracks && network_data.anim_events.event_track_node)
		{
			pull_tracks = false;

			selectedEntry = -1;
			selectedEntry_tae = -1;
			clear_tracks = false;

			event_track_editor.Clear();
			Morpheme::ClearTrackList(&track_list);

			time_act_track_editor.Clear();
			TimeAct::clearTrackList(&tae_track_list);

			Morpheme::NodeDef* anim_sync_node = (Morpheme::NodeDef*)(network_data.anim_events.event_track_node);

			network_data.anim_events.anim_tae.current_tae = Morpheme::getTimeActId(anim_sync_node);

			if (anim_sync_node->m_nodeTypeID == NodeType_NodeAnimSyncEvents)
			{
				Morpheme::NodeData104* node_data = (Morpheme::NodeData104*)anim_sync_node->node_data;

				if (node_data->m_animData && node_data->m_eventTrackData)
				{
					uint64_t nsaFile = (uint64_t)node_data->m_animData;

					trackLenght = *(float*)(nsaFile + 0x84);
					animLenght = *(float*)(nsaFile + 0x88);

					network_data.anim_events.anim_len = animLenght;
					network_data.anim_events.mult = 1;
					event_track_editor.mFrameMin = 0;
					event_track_editor.mFrameMax = Math::timeToFrame(trackLenght, 60);

					if (network_config.eventTrackConfig_scaleToAnim)
					{
						network_data.anim_events.mult = animLenght / trackLenght;
						event_track_editor.mFrameMax = Math::timeToFrame(animLenght, 60);
					}

					network_data.anim_events.asset_name = Morpheme::getAnimNameFromAnimNode(anim_sync_node);

					uint32_t event_track_count = node_data->m_eventTrackData->m_eventTracks[0].m_trackCount + node_data->m_eventTrackData->m_eventTracks[1].m_trackCount + node_data->m_eventTrackData->m_eventTracks[2].m_trackCount;

					if (event_track_count > 0 && Morpheme::LoadEventTracks(node_data->m_eventTrackData, &track_list) > 0)
					{
						int id = 0;

						for (size_t i = 0; i < track_list.count_discrete; i++)
						{
							event_track_editor.LoadTrackName(id, track_list.tracks_discrete[i]);
							event_track_editor.AddMorphemeEventTrack(id, &track_list.tracks_discrete[i], network_data.anim_events.mult);

							if (track_list.tracks_discrete[i].eventCount > 1)
							{
								for (size_t j = 0; j < track_list.count_discreteSub; j++)
								{
									if (track_list.tracks_discreteSub[j].parentId == i)
									{
										event_track_editor.LoadTrackName(id, track_list.tracks_discreteSub[j]);
										event_track_editor.AddMorphemeEventTrack(id, &track_list.tracks_discreteSub[j], network_data.anim_events.mult);

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
							event_track_editor.AddMorphemeEventTrack(id, &track_list.tracks_unk[i], network_data.anim_events.mult);

							if (track_list.tracks_unk[i].eventCount > 1)
							{
								for (size_t j = 0; j < track_list.count_unkSub; j++)
								{
									if (track_list.tracks_unkSub[j].parentId == i)
									{
										event_track_editor.LoadTrackName(id, track_list.tracks_unkSub[j]);
										event_track_editor.AddMorphemeEventTrack(id, &track_list.tracks_unkSub[j], network_data.anim_events.mult);

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
							event_track_editor.AddMorphemeEventTrack(id, &track_list.tracks_timed[i], network_data.anim_events.mult);

							if (track_list.tracks_timed[i].eventCount > 1)
							{
								for (size_t j = 0; j < track_list.count_timedSub; j++)
								{
									if (track_list.tracks_timedSub[j].parentId == i)
									{
										event_track_editor.LoadTrackName(id, track_list.tracks_timedSub[j]);
										event_track_editor.AddMorphemeEventTrack(id, &track_list.tracks_timedSub[j], network_data.anim_events.mult);

										id++;
									}
								}
							}
							else
								id++;
						}
					}
					else
						MessageBoxA(NULL, "Animation does not have any EventTrack associated with it", "Morpheme Network Inspector", MB_ICONINFORMATION);

					time_act_track_editor.mFrameMin = 0;
					time_act_track_editor.mFrameMax = Math::timeToFrame(trackLenght, 60);

					if (network_config.eventTrackConfig_scaleToAnim)
					{
						network_data.anim_events.mult = animLenght / trackLenght;
						time_act_track_editor.mFrameMax = Math::timeToFrame(animLenght, 60);
					}

					if (event_track_count > 0 && TimeAct::loadTimeActTrack(taeLookup(network_data.anim_events.anim_tae.pl_tae, network_data.anim_events.anim_tae.current_tae), &tae_track_list) > 0)
					{
						int id = 0;

						for (size_t i = 0; i < tae_track_list.count; i++)
						{
							time_act_track_editor.AddTimeActTrack(id, &tae_track_list.tracks[i], 1);

							if (tae_track_list.tracks[i].tae_count > 1)
							{
								for (size_t j = 0; j < tae_track_list.countSub; j++)
								{
									if (tae_track_list.tracksSub[j].parentId == i)
									{
										time_act_track_editor.AddTimeActTrack(id, &tae_track_list.tracksSub[j], 1);

										id++;
									}
								}
							}
							else
								id++;
						}
					}
					else
						MessageBoxA(NULL, "Animation does not have any TimeAct entry associated with it", "Morpheme Network Inspector", MB_ICONINFORMATION);
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
			selectedEntry_tae = -1;
			clear_tracks = false;

			event_track_editor.Clear();
			Morpheme::ClearTrackList(&track_list);

			time_act_track_editor.Clear();
			TimeAct::clearTrackList(&tae_track_list);
		}

		ImGui::SameLine();
		if (ImGui::Button("Save Tracks") && event_track_editor.GetItemCount())
			save_tracks = true;

		if (save_tracks)
		{
			save_tracks = false;

			Morpheme::SaveEventTracks(&track_list);
			TimeAct::saveTimeActTrack(&tae_track_list);
		}

		if (event_track_editor.GetItemCount())
			ImGui::Text(network_data.anim_events.asset_name);

		if (network_data.anim_events.event_track_node)
		{
			Morpheme::NodeDef* anim_sync_node = (Morpheme::NodeDef*)(network_data.anim_events.event_track_node);
			Morpheme::NodeData104* node_data = (Morpheme::NodeData104*)anim_sync_node->node_data;

			if (anim_sync_node)
				currentFrame = Morpheme::getCurrentAnimFrame(network, anim_sync_node->m_nodeID);

			currentFrame_tae = currentFrame + Math::timeToFrame(*(float*)(node_data->m_animData + 0x80), 60);

			Debug::debuggerMessage(Debug::LVL_DEBUG, "Current Time (EventTrack): %.3f\n", Math::frameToTime(currentFrame, 60));
			Debug::debuggerMessage(Debug::LVL_DEBUG, "Current Time (TAE): %.3f\n", Math::frameToTime(currentFrame_tae, 60));
		}

		ImGui::BeginTabBar("event track tab bar");
		if (ImGui::BeginTabItem("Event Track"))
		{
			ImGui::BeginChild("sequencer");
			ImSequencer::Sequencer(&event_track_editor, &currentFrame, &expanded, &selectedEntry, &firstFrame, ImSequencer::SEQUENCER_EDIT_STARTEND /*| ImSequencer::SEQUENCER_LOOP_EVENTS*/);
			ImGui::EndChild();

			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("TimeAct"))
		{
			ImGui::BeginChild("tae sequencer");
			ImSequencer::Sequencer(&time_act_track_editor, &currentFrame_tae, &expanded_tae, &selectedEntry_tae, &firstFrame_tae, ImSequencer::SEQUENCER_EDIT_STARTEND);
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();

		ImGui::Begin("Event Data");
		ImGui::BeginTabBar("event data tab bar");

		if (ImGui::BeginTabItem("EventTrack"))
		{
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

				item.SaveEventTrackData(item.morpheme_track, network_data.anim_events.mult);
			}
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("TimeAct"))
		{
			if (selectedEntry_tae != -1)
			{
				EventTrackEditor::EventTrack& item = time_act_track_editor.myItems[selectedEntry_tae];
				float startTime = Math::frameToTime(item.mFrameStart, 60);
				float duration = Math::frameToTime(item.mFrameEnd, 60);

				ImGui::Text(item.trackName);
				ImGui::PushItemWidth(100);
				ImGui::InputInt("Group ID", &item.eventId, 1, 0);

				ImGui::InputInt("Event ID", &item.value, 1, 0);

				ImGui::DragFloat("Start Time", &startTime, 1 / 60, 0, Math::frameToTime(time_act_track_editor.mFrameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);
				ImGui::DragFloat("End Time", &duration, 1 / 60, 0, Math::frameToTime(time_act_track_editor.mFrameMax, 60), "%.3f", ImGuiSliderFlags_ReadOnly);
				
				if (item.time_act_track->tae_def.arg_count > 0)
				{
					ImGui::Text("Arguments");
					int data_size = 0;
					for (size_t i = 0; i < item.time_act_track->tae_def.arg_count; i++)
					{
						uint64_t arg = (item.time_act_track->args + (byte)data_size);
						//Debug::debuggerMessage(Debug::LVL_INFO, "Arguments: %llX\n", item.time_act_track->args);
						//Debug::debuggerMessage(Debug::LVL_INFO, "Argument %d: %llX\n", i, arg);
						Debug::debuggerMessage(Debug::LVL_INFO, "Argument Name: %s\n", item.time_act_track->tae_def.arg_names[i].name);
						ImGui::PushID(i);
						switch (item.time_act_track->tae_def.arg_type[i])
						{
						case 0:
							//bool
							data_size += 1;
							ImGui::InputByte(item.time_act_track->tae_def.arg_names[i].name, (char*)arg, 0, 0, ImGuiInputTextFlags_None);
							break;
						case 1:
							//int8
							data_size += 1;
							ImGui::InputByte(item.time_act_track->tae_def.arg_names[i].name, (char*)arg, 0, 0, ImGuiInputTextFlags_None);
							break;
						case 2:
							//int16
							data_size += 2;
							ImGui::InputShort(item.time_act_track->tae_def.arg_names[i].name, (short*)arg, 0, 0, ImGuiInputTextFlags_None);
							break;
						case 3:
							//int32
							ImGui::InputInt(item.time_act_track->tae_def.arg_names[i].name, (int*)arg, 0, 0);
							data_size += 4;
							break;
						case 4:
							//float
							data_size += 4;
							ImGui::InputFloat(item.time_act_track->tae_def.arg_names[i].name, (float*)arg, 0, 0, "%.3f");
							break;
						default:
							Debug::debuggerMessage(Debug::LVL_WARN, "Unknown arg type in tae_def.ini: %d\n", item.time_act_track->tae_def.arg_type[i]);
							break;
						}
						ImGui::PopID();
					}
				}
				ImGui::PopItemWidth();

				item.SaveTaeTrackData(item.time_act_track, 1);
			}

			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();

		ImGui::End();
	}
	ImGui::End();
}

void MorphemeNetworkInspectorGUI::ProcessVariables()
{
	if (game_state != 30)
	{
		if (game_state != prev_game_state)
			Debug::debuggerMessage(Debug::LVL_INFO, "Game State changed: %d -> %d. Performing Network Cleanup\n", prev_game_state, game_state);

		target_character = NULL;
		NetworkCleanup();
	}

	if (target_character && (*(int*)(target_character + 0x8) != 1) && (*(int*)(target_character + 0x8) != 2))
	{
		Debug::debuggerMessage(Debug::LVL_ERROR, "Target Character is not a member of CharacterCtrl. Performing Network Cleanup.\n", game_state);

		target_character = NULL;
		NetworkCleanup();
	}

	if (target_character && show_skeleton)
	{
		//MorphemeInterface::drawSkeleton(target_character);
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
		clear_network = false;
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
			network_tasks.get_nodes = false;
			network_data.nodes.clear();
			network_data.node_names.clear();

			Debug::debuggerMessage(Debug::LVL_DEBUG, "Num Nodes: %d\n", network->m_networkDef->m_numNodes);
			for (size_t i = 0; i < network->m_networkDef->m_numNodes; i++)
			{
				network_data.nodes.push_back(Morpheme::getNetworkNode(network, network->m_networkDef->m_nodes[i]->m_nodeID));
				network_data.node_names.push_back(Morpheme::getNodeName(target_character, network->m_networkDef->m_nodes[i]->m_nodeID));
			}
		}

		if (network_tasks.get_anim_assets)
		{
			network_data.anim_events.anim_nodes.clear();
			network_data.anim_events.anim_nodes = Morpheme::getNetworkAllNodesType(target_character, NodeType_NodeAnimSyncEvents);

			if (network_data.anim_events.anim_nodes.size() == 0)
				MessageBoxA(NULL, "There are no Animation nodes", "Morpheme Network Inspector", MB_ICONINFORMATION);

			network_data.anim_events.anim_tae.pl_tae = TimeAct::getTimeActFile_pl(target_character);
			network_data.anim_events.anim_tae.sfx_tae = TimeAct::getTimeActFile_sfx(target_character);
			network_data.anim_events.anim_tae.snd_tae = TimeAct::getTimeActFile_snd(target_character);

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
				network_data.control_params.cp_bins.push_back(Morpheme::getNetworkNodeBin(network, network_data.control_params.cp_nodes[i]->m_nodeID));
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

		if (network_data.imnodes_data.is_inspect)
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

			network_data.is_load = true;
			network_data.imnodes_data.is_inspect = false;
			network_data.imnodes_data.node_ids.clear();
			network_data.imnodes_data.node_position.clear();
			network_data.imnodes_data.occupied_positions.clear();
			network_data.imnodes_data.editors.clear();
			network_data.imnodes_data.node_def = NULL;

			if (Morpheme::doesNodeExist(network, network_data.imnodes_data.node_to_inspect))
				network_data.imnodes_data.node_def = Morpheme::getNetworkNode(network, network_data.imnodes_data.node_to_inspect);
			else
				MessageBoxA(NULL, "The specified node is not present in this network", "MorphemeNetworkInspector", MB_ICONINFORMATION);
		}
	}
}

void MorphemeNetworkInspectorGUI::Dockspace(ImGuiID dockSpace)
{
}

void MorphemeNetworkInspectorGUI::NetworkCleanup()
{
	clear_network = true;
	network = NULL;

	network_tasks.get_nodes = false;
	network_tasks.get_anim_assets = false;
	network_tasks.get_control_params = false;
	network_tasks.get_messages = false;

	network_data.node_names.clear();
	network_data.nodes.clear();

	network_data.anim_events.anim_nodes.clear();

	network_data.control_params.cp_nodes.clear();
	network_data.control_params.cp_bins.clear();
	network_data.control_params.cp_names.clear();

	network_data.messages.message_ids.clear();
	network_data.messages.message_names.clear();
	network_data.messages.message_defs.clear();

	network_data.imnodes_data.is_inspect = false;
	network_data.imnodes_data.node_ids.clear();
	network_data.imnodes_data.node_position.clear();
	network_data.imnodes_data.occupied_positions.clear();
	network_data.imnodes_data.node_to_inspect = 0;
	network_data.imnodes_data.node_def = NULL;

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