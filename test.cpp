#include <windows.h>
#include "DrawShapes.h"

int wmain()
{
	while(true)
	{
		DSHAPES dShapes;
		dShapes.DrawLine(rand()%2000, rand()%2000, rand()%1000, rand()%1000, rand()%255, rand()%255, rand()%255, rand()%100);
		dShapes.DrawRec(rand()%2000, rand()%2000, rand()%100, 50, rand()%255, rand()%255, rand()%255, rand()%100);
		dShapes.FillRec(rand()%2000, rand()%2000, rand()%100, 50, rand()%255, rand()%255, rand()%255);
		dShapes.DrawEllipse(rand()%2000, rand()%2000, rand()%100, rand()%50, rand()%10, rand()%255, rand()%255, rand()%255);
		dShapes.FillEllipse(rand()%2000, rand()%2000, rand()%100, rand()%255, rand()%255, rand()%255, rand()%13);
		dShapes.DrawCurve(rand()%2000, rand()%2000, rand()%100, rand()%100, rand()%100, rand()%100, rand()%100, rand()%50, rand()%255, rand()%255, rand()%255, 10);
		dShapes.DrawLongCurve(rand()%2000, rand()%2000, rand()%100, rand()%100, rand()%100, rand()%100, rand()%50, rand()%80, rand()%10, rand()%20, rand()%30, rand()%10, rand()%10, rand()%20, rand()%255, rand()%255, rand()%255, rand()%255);
		dShapes.DrawCurve(rand()%2000, rand()%2000, rand()%200, rand()%55, rand()%55, rand()%80, rand()%85, rand()%55, rand()%255, rand()%255, rand()%255, rand()%100);
		dShapes.DrawArc(rand()%2000, rand()%2000, rand()%100, rand()%100, rand()%150, rand()%360, rand()%255, rand()%255, rand()%255, rand()%100);
		// dShapes.DrawTraingle(rand()%2000, rand()%2000, rand()%1000, rand()%900, rand()%900, rand()%300, rand()%255, rand()%255, rand()%255, rand()%100);
		// dShapes.FillTraingle(rand()%2000, rand()%2000, rand()%1000, rand()%900, rand()%900, rand()%300, rand()%255, rand()%255, 255);
	}
}




