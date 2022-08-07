//#include "olcConsoleGameEngine.h"
//using namespace std;
//
//// Define some coordinates
//
//const float MY_PI = 3.14159f;
//
//
//// The point
//struct vector3d
//{
//	float x, y, z;
//};
//
//// The shape that holds tree points.
//struct triangle
//{
//	vector3d v[3];
//};
//
//// The group of triangles
//struct mesh
//{
//	vector<triangle> sector;
//};
//
//// The matrix
//
//struct matrix
//{
//	float p[4][4] = { 0 };
//};
//
//// ===========================
//
//
//class olcEngine : public olcConsoleGameEngine
//{
//public:
//	olcEngine()
//	{
//		m_sAppName = L"3D Engine";
//	}
//
//	// The cube that we are going to draw.
//private:
//	mesh meshCube;
//	matrix project;
//
//	float fTheta;
//
//	void MultiplMatrix(vector3d& i, vector3d& o, matrix& m)
//	{
//		o.x = i.x * m.p[0][0] + i.y * m.p[1][0] + i.z * m.p[2][0] + m.p[3][0];
//		o.y = i.x * m.p[0][1] + i.y * m.p[1][1] + i.z * m.p[2][1] + m.p[3][1];
//		o.z = i.x * m.p[0][2] + i.y * m.p[1][2] + i.z * m.p[2][2] + m.p[3][2];
//
//		// Remember that the final element of the input vector is one
//
//		float w = i.x * m.p[0][3] + i.y * m.p[1][3] + i.z * m.p[2][3] + m.p[3][3];
//
//		if (w != 0.0f)
//		{
//			o.x /= w;
//			o.y /= w; 
//			o.z /= w;
//		}
//	}
//
//
//public:
//	bool OnUserCreate() override
//	{
//		meshCube.sector =
//		{
//			// South
//			{ 0.0f, 0.0f, 0.0f,    0.0f,1.0f,0.0f,    1.0f,1.0f,0.0f},
//			{ 0.0f, 0.0f, 0.0f,    1.0f,1.0f,0.0f,    1.0f,0.0f,0.0f},
//
//			// East
//			{ 1.0f, 0.0f, 0.0f,    1.0f,1.0f,0.0f,    1.0f,1.0f,1.0f},
//			{ 1.0f, 0.0f, 0.0f,    1.0f,1.0f,1.0f,    1.0f,0.0f,1.0f},
//
//			// North
//			{ 1.0f, 0.0f, 1.0f,    1.0f,1.0f,1.0f,    0.0f,1.0f,1.0f},
//			{ 1.0f, 0.0f, 1.0f,    0.0f,1.0f,1.0f,    0.0f,0.0f,1.0f},
//
//			// West
//			{ 0.0f, 0.0f, 1.0f,    0.0f,1.0f,1.0f,    0.0f,1.0f,1.0f},
//			{ 0.0f, 0.0f, 1.0f,    0.0f,1.0f,0.0f,    0.0f,0.0f,0.0f},
//
//			// Top
//			{ 0.0f, 1.0f, 0.0f,    0.0f,1.0f,1.0f,    1.0f,1.0f,1.0f},
//			{ 0.0f, 1.0f, 0.0f,    1.0f,1.0f,1.0f,    1.0f,1.0f,0.0f},
//
//			// Bottom
//			{ 1.0f, 0.0f, 1.0f,    0.0f,0.0f,1.0f,    0.0f,0.0f,0.0f},
//			{ 1.0f, 0.0f, 1.0f,    0.0f,0.0f,0.0f,    1.0f,0.0f,0.0f},
//
//		};
//
//		float fNear = 0.1f;
//		float fFar = 1000.0f;
//		float fFoV = 90.0f;
//		float aspectRatio = ((float)ScreenWidth() /  (float)ScreenHeight());
//
//		float fFoVRad = 1.0f / tanf(fFoV * 0.5f / 180.0f * MY_PI);
//
//		project.p[0][0] = aspectRatio * fFoVRad;
//		project.p[1][1] = fFoVRad;
//
//		project.p[2][2] = fFar / (fFar - fNear);
//		project.p[3][2] = (-fFar * fNear) / (fFar - fNear);
//
//		project.p[2][3] = 1.0f;
//		project.p[3][3] = 0.0f;
//
//
//		// This return true to indicate
//		// To continue running
//		return true;
//	}
//
//	bool OnUserUpdate(float fElapsedTime) override
//	{
//		//Clean the screen
//
//		Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLACK);
//
//		matrix rotationZ, rotationX;
//		fTheta += 1.0f * fElapsedTime;
//
//		//Rotation in Z
//		rotationZ.p[0][0] = cosf(fTheta);
//		rotationZ.p[0][1] = sinf(fTheta);
//		rotationZ.p[1][0] = -sinf(fTheta);
//		rotationZ.p[1][1] = cosf(fTheta);
//		rotationZ.p[2][2] = 1;
//		rotationZ.p[3][3] = 1;
//
//		rotationX.p[0][0] = 1;
//		rotationX.p[1][1] = cosf(fTheta * 0.5f);
//		rotationX.p[1][2] = sinf(fTheta * 0.5f);
//		rotationX.p[2][1] = -sinf(fTheta * 0.5f);
//		rotationX.p[2][2] = cosf(fTheta * 0.5f);
//		rotationX.p[3][3] = 1;
//
//
//
//
//		//Draw the triangles
//		for (auto sector : meshCube.sector)
//		{
//			triangle projectedOne, translate, rotatedZ, rotatedX;
//
//			MultiplMatrix(sector.v[0], rotatedZ.v[0], rotationZ);
//			MultiplMatrix(sector.v[1], rotatedZ.v[1], rotationZ);
//			MultiplMatrix(sector.v[2], rotatedZ.v[2], rotationZ);
//
//
//			MultiplMatrix(rotatedZ.v[0], rotatedX.v[0], rotationX);
//			MultiplMatrix(rotatedZ.v[1], rotatedX.v[1], rotationX);
//			MultiplMatrix(rotatedZ.v[2], rotatedX.v[2], rotationX);
//
//
//			translate = rotatedX;
//
//			translate.v[0].z = rotatedX.v[0].z + 3.0f;
//			translate.v[1].z = rotatedX.v[1].z + 3.0f;
//			translate.v[2].z = rotatedX.v[2].z + 3.0f;
//
//
//			// Transform each vertice of the triangle
//			MultiplMatrix(translate.v[0], projectedOne.v[0], project);
//			MultiplMatrix(translate.v[1], projectedOne.v[1], project);
//			MultiplMatrix(translate.v[2], projectedOne.v[2], project);
//
//			// Scale into view
//			projectedOne.v[0].x += 1.0f; projectedOne.v[0].y += 1.0f;
//			projectedOne.v[1].x += 1.0f; projectedOne.v[1].y += 1.0f;
//			projectedOne.v[2].x += 1.0f; projectedOne.v[2].y += 1.0f;
//
//			projectedOne.v[0].x *= 0.5f * (float)ScreenWidth();
//			projectedOne.v[0].y *= 0.5f * (float)ScreenHeight();
//
//			projectedOne.v[1].x *= 0.5f * (float)ScreenWidth();
//			projectedOne.v[1].y *= 0.5f * (float)ScreenHeight();
//
//			projectedOne.v[2].x *= 0.5f * (float)ScreenWidth();
//			projectedOne.v[2].y *= 0.5f * (float)ScreenHeight();
//
//			//Draw the triangle with a foreground white
//
//			DrawTriangle(projectedOne.v[0].x, projectedOne.v[0].y,
//				projectedOne.v[1].x, projectedOne.v[1].y,
//				projectedOne.v[2].x, projectedOne.v[2].y,
//				PIXEL_SOLID, FG_WHITE
//			);
//
//			return true;
//		}
//	}
//};
//
//
//int main()
//{
//	olcEngine mini;
//
//	// Constructs the window, we pass the width,height, font(width) and font(height)
//	if (mini.ConstructConsole(256, 240, 4, 4))
//		mini.Start();
//	
//	return 0;
//}
