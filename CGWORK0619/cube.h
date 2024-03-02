#pragma once
#include "graph.h"
using namespace std;

struct Point {
	int x;
	int y;
	int z;
};

/* 立方体 */
class Cube {
public:
	// 构造函数
	Cube(COLORREF lineColor, vector<COLORREF> flatColors);
	// getter和setter
	vector<Point> getPoints();
	void setPoints(vector<Point> points);
	COLORREF getLineColor();
	void setLineColor(COLORREF lineColor);
	vector<COLORREF> getFlatColors();
	void setFlatColors(vector<COLORREF> flatColors);
	void setWhiteColor();
	int getTranslationStepSize();
	void setTranslationStepSize(int translationStepSize);
	int getRotationAngle();
	void setRotationAngle(int rotationAngle);
	// 平移和旋转
	void Translate(int axis, int direction);
	void Rotate(int axis, int direction);
	// 绘制图形（透视投影）
	void DrawGraph(CDC* pDC);

private:
	vector<Point> mPoints; // 顶点位置
	vector<vector<int>> mFacePoints; // 面顶点号（前后左右上下）
	COLORREF mLineColor; // 边颜色
	vector<COLORREF> mFlatColors; // 各面颜色
	int mTranslationStepSize; // 平移步长
	int mRotationAngle; // 旋转角度
	Point mEyePoint; // 视点
	int mSightDiameter; // 视径
	int mSightDistance; // 视距
};