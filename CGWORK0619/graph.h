#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct DoublePoint {
	double x;
	double y;
};

/* 图形基类 */
class Graph
{
// 方法
public:
	// 构造函数
	Graph(vector<CPoint> points, COLORREF color);
	// getter和setter
	vector<CPoint> getPoints();
	void setPoints(vector<CPoint> points);
	COLORREF getColor();
	void setColor(COLORREF color);
	// 绘制图形
	virtual void DrawGraph(CDC* pDC) = 0;

// 变量
private:
	vector<CPoint> mPoints; // 点集
	COLORREF mColor; // 图形颜色
};

/* 矩形 */
class RectangleGraph : public Graph {
public:
	RectangleGraph(vector<CPoint> points, COLORREF color); // 构造函数
	void DrawGraph(CDC* pDC) override; // 绘制图形
};

/* 圆形 */
class CircleGraph : public Graph {
public:
	CircleGraph(vector<CPoint> points, COLORREF color); // 构造函数
	void DrawGraph(CDC* pDC) override; // 绘制图形（中点画圆算法）
};

/* 多边形 */
class PolygonGraph : public Graph {
public:
	// 构造函数
	PolygonGraph(vector<CPoint> points, COLORREF lineColor, COLORREF areaColor);
	// getter和setter
	COLORREF getAreaColor();
	void setAreaColor(COLORREF Color);
	// 绘制图形
	void DrawGraph(CDC* pDC) override; // 绘制图形
	void EdgeMarkFill(CDC* pDC, vector<CPoint> points); // 边标志算法
private:
	COLORREF mAreaColor; // 填充颜色
	const int mContext[16][32] = { // 填充内容
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
};

/* Bezier曲线 */
class BezierGraph : public Graph {
public:
	BezierGraph(vector<CPoint> points, COLORREF color); // 构造函数
	void DrawGraph(CDC* pDC) override; // 绘制图形
	void SplitBezier(CDC* pDC, vector<DoublePoint> points);// 分裂法
	double MaxDistance(vector<DoublePoint> points); // 计算顶点距离底边的最大距离
	void DrawPoint(CDC* pDC); // 绘制标记点
};

// 绘制线段（DDA 算法）
static void DrawLine(CDC* pDC, COLORREF color, int x1, int y1, int x2, int y2) {
	double dx, dy, e, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	e = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= e;
	dy /= e;
	x = x1;
	y = y1;
	for (int i = 1; i <= e; i++)
	{
		pDC->SetPixel((int)(x + 0.5), (int)(y + 0.5), color);
		x += dx;
		y += dy;
	}
}