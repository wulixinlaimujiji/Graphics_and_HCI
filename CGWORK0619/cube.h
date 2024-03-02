#pragma once
#include "graph.h"
using namespace std;

struct Point {
	int x;
	int y;
	int z;
};

/* ������ */
class Cube {
public:
	// ���캯��
	Cube(COLORREF lineColor, vector<COLORREF> flatColors);
	// getter��setter
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
	// ƽ�ƺ���ת
	void Translate(int axis, int direction);
	void Rotate(int axis, int direction);
	// ����ͼ�Σ�͸��ͶӰ��
	void DrawGraph(CDC* pDC);

private:
	vector<Point> mPoints; // ����λ��
	vector<vector<int>> mFacePoints; // �涥��ţ�ǰ���������£�
	COLORREF mLineColor; // ����ɫ
	vector<COLORREF> mFlatColors; // ������ɫ
	int mTranslationStepSize; // ƽ�Ʋ���
	int mRotationAngle; // ��ת�Ƕ�
	Point mEyePoint; // �ӵ�
	int mSightDiameter; // �Ӿ�
	int mSightDistance; // �Ӿ�
};