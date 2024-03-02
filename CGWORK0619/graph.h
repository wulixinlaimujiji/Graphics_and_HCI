#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct DoublePoint {
	double x;
	double y;
};

/* ͼ�λ��� */
class Graph
{
// ����
public:
	// ���캯��
	Graph(vector<CPoint> points, COLORREF color);
	// getter��setter
	vector<CPoint> getPoints();
	void setPoints(vector<CPoint> points);
	COLORREF getColor();
	void setColor(COLORREF color);
	// ����ͼ��
	virtual void DrawGraph(CDC* pDC) = 0;

// ����
private:
	vector<CPoint> mPoints; // �㼯
	COLORREF mColor; // ͼ����ɫ
};

/* ���� */
class RectangleGraph : public Graph {
public:
	RectangleGraph(vector<CPoint> points, COLORREF color); // ���캯��
	void DrawGraph(CDC* pDC) override; // ����ͼ��
};

/* Բ�� */
class CircleGraph : public Graph {
public:
	CircleGraph(vector<CPoint> points, COLORREF color); // ���캯��
	void DrawGraph(CDC* pDC) override; // ����ͼ�Σ��е㻭Բ�㷨��
};

/* ����� */
class PolygonGraph : public Graph {
public:
	// ���캯��
	PolygonGraph(vector<CPoint> points, COLORREF lineColor, COLORREF areaColor);
	// getter��setter
	COLORREF getAreaColor();
	void setAreaColor(COLORREF Color);
	// ����ͼ��
	void DrawGraph(CDC* pDC) override; // ����ͼ��
	void EdgeMarkFill(CDC* pDC, vector<CPoint> points); // �߱�־�㷨
private:
	COLORREF mAreaColor; // �����ɫ
	const int mContext[16][32] = { // �������
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

/* Bezier���� */
class BezierGraph : public Graph {
public:
	BezierGraph(vector<CPoint> points, COLORREF color); // ���캯��
	void DrawGraph(CDC* pDC) override; // ����ͼ��
	void SplitBezier(CDC* pDC, vector<DoublePoint> points);// ���ѷ�
	double MaxDistance(vector<DoublePoint> points); // ���㶥�����ױߵ�������
	void DrawPoint(CDC* pDC); // ���Ʊ�ǵ�
};

// �����߶Σ�DDA �㷨��
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