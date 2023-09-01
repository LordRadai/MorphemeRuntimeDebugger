#include "Renderer.h"
#include "Debug.h"

void Renderer::DrawStrokeText(int x, int y, RGBA* color, const char* str)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = std::string(str);
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}

void Renderer::DrawNewText(int x, int y, RGBA* color, const char* str)
{
	ImFont a;
	ImGuiIO& io = ImGui::GetIO();
	//ImFont* pFont = io.Fonts->AddFontFromFileTTF("/Font/00270 Regular.ttf", 10.0f);
	//a.FontSize = 5.f;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = std::string(str);
	ImGui::GetBackgroundDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}

void Renderer::DrawOverlayText(int x, int y, RGBA* color, const char* str)
{
	ImFont a;
	ImGuiIO& io = ImGui::GetIO();
	//ImFont* pFont = io.Fonts->AddFontFromFileTTF("/Font/00270 Regular.ttf", 10.0f);
	//a.FontSize = 5.f;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = std::string(str);
	ImGui::GetForegroundDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}

void Renderer::DrawRect(int x, int y, int w, int h, RGBA* color, int thickness)
{
	ImGui::GetBackgroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0, thickness);
}

void Renderer::DrawFilledRect(int x, int y, int w, int h, RGBA* color)
{
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y - 1), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 0, 0);
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y + 1), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 0, 0);
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x - 1, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 0, 0);
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x + 1, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 0, 0);
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0);
}

void Renderer::DrawFilledRectIMCol(int x, int y, int w, int h, ImU32 col)
{
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), col, 0, 0);
}

void Renderer::DrawCircleFilled(int x, int y, int radius, RGBA* color, int segments)
{
	ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), segments);
}

void Renderer::DrawCircle(int x, int y, int radius, RGBA* color, int segments)
{
	ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), segments);
}

void Renderer::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, RGBA* color, float thickne)
{
	ImGui::GetBackgroundDrawList()->AddTriangle(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), thickne);
}

void Renderer::DrawTriangleFilled(int x1, int y1, int x2, int y2, int x3, int y3, RGBA* color)
{
	ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)));
}

void Renderer::DrawLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
{
	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), thickness);
}

void Renderer::DrawCornerBox(int x, int y, int w, int h, int borderPx, RGBA* color)
{
	Renderer::DrawFilledRect(x + borderPx, y, w / 3, borderPx, color); //top 
	Renderer::DrawFilledRect(x + w - w / 3 + borderPx, y, w / 3, borderPx, color); //top 
	Renderer::DrawFilledRect(x, y, borderPx, h / 3, color); //left 
	Renderer::DrawFilledRect(x, y + h - h / 3 + borderPx * 2, borderPx, h / 3, color); //left 
	Renderer::DrawFilledRect(x + borderPx, y + h + borderPx, w / 3, borderPx, color); //bottom 
	Renderer::DrawFilledRect(x + w - w / 3 + borderPx, y + h + borderPx, w / 3, borderPx, color); //bottom 
	Renderer::DrawFilledRect(x + w + borderPx, y, borderPx, h / 3, color);//right 
	Renderer::DrawFilledRect(x + w + borderPx, y + h - h / 3 + borderPx * 2, borderPx, h / 3, color);//right 
}

void Renderer::DrawBox3D(Vector3 top, Vector3 bottom, float angle, float width, int thickness, RGBA* color)
{
	float height3D = abs(top.y - bottom.y);
	Vector3 b1, b2, b3, b4, t1, t2, t3, t4;

	b1.y = b2.y = b3.y = b4.y = bottom.y;

	b1.x = bottom.x + (cos(angle + IM_PI / 4) * width);
	b1.z = bottom.z + (sin(angle + IM_PI / 4) * width);

	b2.x = bottom.x + (cos(angle + 3 * (IM_PI / 4)) * width);
	b2.z = bottom.z + (sin(angle + 3 * (IM_PI / 4)) * width);

	b3.x = bottom.x + (cos(angle + 5 * (IM_PI / 4)) * width);
	b3.z = bottom.z + (sin(angle + 5 * (IM_PI / 4)) * width);

	b4.x = bottom.x + (cos(angle + 7 * (IM_PI / 4)) * width);
	b4.z = bottom.z + (sin(angle + 7 * (IM_PI / 4)) * width);

	t1.x = b1.x;
	t1.y = b1.y + height3D;
	t1.z = b1.z;

	t2.x = b2.x;
	t2.y = b2.y + height3D;
	t2.z = b2.z;

	t3.x = b3.x;
	t3.y = b3.y + height3D;
	t3.z = b3.z;

	t4.x = b4.x;
	t4.y = b4.y + height3D;
	t4.z = b4.z;

	ScreenPoint b1_2, b2_2, b3_2, b4_2, t1_2, t2_2, t3_2, t4_2;

	if (Math::worldToScreen(b1, &b1_2) && Math::worldToScreen(b2, &b2_2) && Math::worldToScreen(b3, &b3_2) && Math::worldToScreen(b4, &b4_2) && Math::worldToScreen(t1, &t1_2) && Math::worldToScreen(t2, &t2_2) && Math::worldToScreen(t3, &t3_2) && Math::worldToScreen(t4, &t4_2))
	{
		Renderer::DrawLine(t1_2.x, t1_2.y, b1_2.x, b1_2.y, color, thickness);
		Renderer::DrawLine(t2_2.x, t2_2.y, b2_2.x, b2_2.y, color, thickness);
		Renderer::DrawLine(t3_2.x, t3_2.y, b3_2.x, b3_2.y, color, thickness);
		Renderer::DrawLine(t4_2.x, t4_2.y, b4_2.x, b4_2.y, color, thickness);

		Renderer::DrawLine(t1_2.x, t1_2.y, t2_2.x, t2_2.y, color, thickness);
		Renderer::DrawLine(t2_2.x, t2_2.y, t3_2.x, t3_2.y, color, thickness);
		Renderer::DrawLine(t3_2.x, t3_2.y, t4_2.x, t4_2.y, color, thickness);
		Renderer::DrawLine(t4_2.x, t4_2.y, t1_2.x, t1_2.y, color, thickness);

		Renderer::DrawLine(b1_2.x, b1_2.y, b2_2.x, b2_2.y, color, thickness);
		Renderer::DrawLine(b2_2.x, b2_2.y, b3_2.x, b3_2.y, color, thickness);
		Renderer::DrawLine(b3_2.x, b3_2.y, b4_2.x, b4_2.y, color, thickness);
		Renderer::DrawLine(b4_2.x, b4_2.y, b1_2.x, b1_2.y, color, thickness);
	}
}

void Renderer::DrawBone(Matrix4 start, Matrix4 end, int thickness, RGBA* color)
{
	Matrix4 start_transp, end_transp;
	Vector3 start_pos, end_pos;
	ScreenPoint start_sp, end_sp;

	start_transp = start.transpose();
	end_transp = end.transpose();

	start_pos.x = 0;
	start_pos.y = 0;
	start_pos.z = 0;

	end_pos.x = 0;
	end_pos.y = 1;
	end_pos.z = 0;

	start_pos = start.operator*(start_pos);
	end_pos = end.operator*(end_pos);

	Debug::DebuggerMessage(Debug::LVL_DEBUG, "Start: (%.3f, %.3f, %.3f)\n", start_pos.x, start_pos.y, start_pos.z);
	Debug::DebuggerMessage(Debug::LVL_DEBUG, "End: (%.3f, %.3f, %.3f)\n", end_pos.x, end_pos.y, end_pos.z);

	if (Math::worldToScreen(start_pos, &start_sp) && Math::worldToScreen(end_pos, &end_sp))
	{
		Debug::DebuggerMessage(Debug::LVL_DEBUG, "SP Start: (%d, %d)\n", start_sp.x, start_sp.y);
		Debug::DebuggerMessage(Debug::LVL_DEBUG, "SP End: (%d, %d)\n", end_sp.x, end_sp.y);

		Renderer::DrawCircleFilled(start_sp.x, start_sp.y, 2, color, 200);
		Renderer::DrawLine(start_sp.x, start_sp.y, end_sp.x, end_sp.y, color, thickness);
	}
}