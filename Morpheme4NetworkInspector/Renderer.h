#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_internal.h"
#include "Math.h"

struct RGBA
{
	DWORD R;
	DWORD G;
	DWORD B;
	DWORD A;

	RGBA(int r, int g, int b, int a)
	{
		R = r;
		G = g;
		B = b;
		A = a;
	}
};

namespace Renderer
{
	static void DrawStrokeText(int x, int y, RGBA* color, const char* str);

	static void DrawNewText(int x, int y, RGBA* color, const char* str);

	static void DrawOverlayText(int x, int y, RGBA* color, const char* str);

	static void DrawRect(int x, int y, int w, int h, RGBA* color, int thickness);

	static void DrawFilledRect(int x, int y, int w, int h, RGBA* color);

	static void DrawFilledRectIMCol(int x, int y, int w, int h, ImU32 col);

	static void DrawCircleFilled(int x, int y, int radius, RGBA* color, int segments);

	static void DrawCircle(int x, int y, int radius, RGBA* color, int segments);

	static void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, RGBA* color, float thickne);

	static void DrawTriangleFilled(int x1, int y1, int x2, int y2, int x3, int y3, RGBA* color);

	static void DrawLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness);

	static void DrawCornerBox(int x, int y, int w, int h, int borderPx, RGBA* color);

	static void DrawBox3D(Vector3 top, Vector3 bottom, float angle, float width, int thickness, RGBA* color);

	void DrawBone(Matrix4 start, Matrix4 end, int thickness, RGBA* color);
}