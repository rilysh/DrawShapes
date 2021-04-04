// Basic library to draw shapes on desktop window.
// Author: Sofia Knyazeva
// Public Domain (Unlicense License) => Date: 04 April 2021

#ifndef __H_DRAWSHAPES__
#if defined(__GNUC__ )||(__GNUG__)
_Pragma("GCC diagnostic push")
_Pragma("GCC diagnostic ignored \"-Wunused-parameter\"")
_Pragma("GCC diagnostic pop")
#include <windows.h>
#include <gdiplus.h>
#endif
#ifdef _MSV_VER
#pragma warning(disable:4384)
#include <windows.h>
#ifndef __GDIPLUS__
#include <gdiplus.h>
#endif
#endif
#define Smooth Gdiplus::SmoothingModeHighQuality

class DSHAPES
{
	public:
	
	void DrawLine(int x1, int y1, int x2, int y2, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw); // Pen Color and Size
		gf.SetSmoothingMode(Smooth);
		gf.DrawLine(&pen, x1, y1, x2, y2);
		// Don't shutdown Gdiplus else your program will crash unexpectedly next line will not execute.
	}
	
	void DrawRec(int x1, int y1, int x2, int y2, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		// Create a rect function that enables everything in one line and quickly.
		Gdiplus::Rect rect(x1, y1, x2, y2);
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw); // Pen Color and Size
		gf.SetSmoothingMode(Smooth);
		
		gf.DrawRectangle(&pen, rect);
	}
	
	// Fill the retangle
	
	void FillRec(int x1, int y1, int x2, int y2, int r, int g, int b)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Rect rect(x1, y1, x2, y2);
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		gf.FillRectangle(&brush, rect);
	}
	
	void DrawEllipse(int x1, int y1, int x2, int y2, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		Gdiplus::Rect rect(x1, y1, x2, y2);
		gf.SetSmoothingMode(Smooth);
		gf.DrawEllipse(&pen, rect);
	}
	
	void FillEllipse(int x1, int y1, int x2, int y2, int r, int g, int b)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Rect rect(x1, y1, x2, y2);
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		gf.FillEllipse(&brush, rect);
	}
	
	void DrawCurve(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		 Gdiplus::Point point_1(p1, p2);
		 Gdiplus::Point point_2(p3, p4);
		 Gdiplus::Point point_3(p5, p6);
		 Gdiplus::Point point_4(p7, p8);
		
		Gdiplus::Point everyPoint[4] = {
			point_1,
			point_2,
			point_3,
			point_4
		};
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		gf.SetSmoothingMode(Smooth);
		gf.DrawCurve(&pen, everyPoint, 4);
	}
	
	void DrawLongCurve(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, int p13, int p14, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		Gdiplus::Point point_4(p7, p8);
		Gdiplus::Point point_5(p9, p10);
		Gdiplus::Point point_6(p11, p12);
		Gdiplus::Point point_7(p13, p14);
		
		Gdiplus::Point everyPoint[7] = {
			point_1,
			point_2,
			point_3,
			point_4,
			point_5,
			point_6,
			point_7
		};
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		gf.SetSmoothingMode(Smooth);
		gf.DrawClosedCurve(&pen, everyPoint, 7);
	}
	
	void DrawBeziers(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, int p13, int p14, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		Gdiplus::Point point_4(p7, p8);
		Gdiplus::Point point_5(p9, p10);
		Gdiplus::Point point_6(p11, p12);
		Gdiplus::Point point_7(p13, p14);
		
		Gdiplus::Point everyPoint[7] = {
			point_1,
			point_2,
			point_3,
			point_4,
			point_5,
			point_6,
			point_7
		};
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		gf.SetSmoothingMode(Smooth);
		gf.DrawBeziers(&pen, everyPoint, 7);
	}
	
	void DrawArc(int p1, int p2, int p3, int p4, int p5, int p6, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::REAL x = p1;
		Gdiplus::REAL y = p2;
		Gdiplus::REAL width = p3;
		Gdiplus::REAL height = p4;
		Gdiplus::REAL angle = p5;
		Gdiplus::REAL skip = p6;
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		gf.SetSmoothingMode(Smooth);
		gf.DrawArc(&pen, x, y, width, height, angle, skip);
	}
	
	void DrawTraingle(int p1, int p2, int p3, int p4, int p5, int p6, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		
		Gdiplus::Point everyPoint[3] = {
			point_1,
			point_2,
			point_3
		};
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		gf.SetSmoothingMode(Smooth);
		gf.DrawPolygon(&pen, everyPoint, 3);
	}
	
	void FillTraingle(int p1, int p2, int p3, int p4, int p5, int p6, int r, int g, int b)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		
		Gdiplus::Point everyPoint[3] = {
			point_1,
			point_2,
			point_3
		};
		
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		gf.FillPolygon(&brush, everyPoint, 3);
	}
	
	void DrawCircle(int width, int height, int radius, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		
		gf.SetSmoothingMode(Smooth);
		gf.DrawEllipse(&pen, width-radius, height-radius, radius+radius, radius+radius);
	}
	
	void FillCircle(int width, int height, int radius, int r, int g, int b)
	{
		HDC hdc = GetDC(GetDesktopWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		gf.SetSmoothingMode(Smooth);
		gf.FillEllipse(&brush, width-radius, height-radius, radius+radius, radius+radius);
	}
	
};

#endif

