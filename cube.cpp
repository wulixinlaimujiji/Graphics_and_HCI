#include "pch.h"
#include "cube.h"

/* 立方体 */

// 构造函数
Cube::Cube(COLORREF lineColor, vector<COLORREF> flatColors) {
	this->mPoints.push_back({ 500 , 300, 0 });
	this->mPoints.push_back({ 1000 , 300, 0 });
	this->mPoints.push_back({ 1000 , 800, 0 });
	this->mPoints.push_back({ 500 , 800, 0 });
	this->mPoints.push_back({ 500 , 300, 500 });
	this->mPoints.push_back({ 1000 , 300, 500 });
	this->mPoints.push_back({ 1000 , 800, 500 });
	this->mPoints.push_back({ 500 , 800, 500 });
	this->mFacePoints = { {4, 5, 6, 7}, { 0, 3, 2, 1 }, { 0, 4, 7, 3 }, { 1, 2, 6, 5 }, { 2, 3, 7, 6 }, { 0, 1, 5, 4 } };
	this->mLineColor = lineColor;
	this->mFlatColors = flatColors;
	this->mTranslationStepSize = 1;
	this->mRotationAngle = 10;
	this->mSightDiameter = 1200;
	this->mSightDistance = 800;
	this->mEyePoint = { 0, 0, this->mSightDiameter };
}

// getter和setter
vector<Point> Cube::getPoints() {
	return this->mPoints;
}
void Cube::setPoints(vector<Point> points) {
	this->mPoints = points;
}
COLORREF Cube::getLineColor() {
	return this->mLineColor;
}
void Cube::setLineColor(COLORREF lineColor) {
	this->mLineColor = lineColor;
}
vector<COLORREF> Cube::getFlatColors() {
	return this->mFlatColors;
}
void Cube::setWhiteColor() {
	for (int i = 0; i < 6; i++) {
		this->mFlatColors[i] = RGB(255, 255, 255);
	}
}
void Cube::setFlatColors(vector<COLORREF> flatColors) {
	this->mFlatColors = flatColors;
}
int Cube::getTranslationStepSize() {
	return this->mTranslationStepSize;
}
void Cube::setTranslationStepSize(int translationStepSize) {
	this->mTranslationStepSize = translationStepSize;
}
int Cube::getRotationAngle() {
	return this->mRotationAngle;
}
void Cube::setRotationAngle(int rotationAngle) {
	this->mRotationAngle = rotationAngle;
}

// 平移和旋转
void Cube::Translate(int axis, int direction) {
	// 沿x轴
	if (axis == 1) {
		for (auto& point : this->mPoints) {
			point.x += direction * this->mTranslationStepSize;
		}
	}
	// 沿y轴
	else if (axis == 2) {
		for (auto& point : this->mPoints) {
			point.y += direction * this->mTranslationStepSize;
		}
	}
	// 沿z轴
	else {
		for (auto& point : this->mPoints) {
			point.z += direction * this->mTranslationStepSize;
		}
	}
}
void Cube::Rotate(int axis, int direction) {
	double arc = direction * (this->mRotationAngle * 3.1415926) / 180;
	Point temp_point;
	// 绕x轴
	if (axis == 1) {
		for (auto& point : this->mPoints) {
			temp_point.y = point.y;
			temp_point.z = point.z;
			point.y = temp_point.y * cos(arc) - temp_point.z * sin(arc);
			point.z = temp_point.y * sin(arc) + temp_point.z * cos(arc);
		}
	}
	// 绕y轴
	else if (axis == 2) {
		for (auto& point : this->mPoints) {
			temp_point.x = point.x;
			temp_point.z = point.z;
			point.z = temp_point.z * cos(arc) - temp_point.x * sin(arc);
			point.x = temp_point.x * cos(arc) + temp_point.z * sin(arc);
		}
	}
	// 绕z轴
	else {
		for (auto& point : this->mPoints) {
			temp_point.x = point.x;
			temp_point.y = point.y;
			point.x = temp_point.x * cos(arc) - temp_point.y * sin(arc);
			point.y = temp_point.x * sin(arc) + temp_point.y * cos(arc);
		}
	}
}

// 绘制图形（透视投影）
void Cube::DrawGraph(CDC* pDC) {

	/// 进行投影
	Point viewPoints[8]; // 观察坐标系三维点
	for (int i = 0; i < 8; i++) {
		viewPoints[i].x = this->mPoints[i].x;
		viewPoints[i].y = this->mPoints[i].y;
		viewPoints[i].z = this->mEyePoint.z - this->mPoints[i].z;
	}
	CPoint screenPoints[8]; // 屏幕坐标系二维点
	for (int i = 0; i < 8; i++) {
		screenPoints[i].x = this->mSightDistance * viewPoints[i].x / viewPoints[i].z;
		screenPoints[i].y = this->mSightDistance * viewPoints[i].y / viewPoints[i].z;
	}
	 
	/// 绘制边界
	for (int i = 0; i < 6; i++) {
		int startPoint = this->mFacePoints[i][0];;
		int endPoint = this->mFacePoints[i][3];
		DrawLine(pDC, this->mLineColor, screenPoints[startPoint].x, screenPoints[startPoint].y, screenPoints[endPoint].x, screenPoints[endPoint].y);
		for (int j = 0; j < 3; j++) {
			startPoint = this->mFacePoints[i][j];
			endPoint = this->mFacePoints[i][j+1];
			DrawLine(pDC, this->mLineColor, screenPoints[startPoint].x, screenPoints[startPoint].y, screenPoints[endPoint].x, screenPoints[endPoint].y);
		}
	}
	
	/// 填充各面
	//for (int i = 0; i < 6; i++) {
	//	CBrush newBrush(this->mFlatColors[i]);
	//	CBrush* oldBrush = pDC->SelectObject(&newBrush);
	//	pDC->Rectangle(screenPoints[this->mFacePoints[i][0]].x, screenPoints[this->mFacePoints[i][0]].y, 
	//		           screenPoints[this->mFacePoints[i][2]].x, screenPoints[this->mFacePoints[i][2]].y);
	//	pDC->SelectObject(oldBrush);
	//	newBrush.DeleteObject();
	//	oldBrush->DeleteObject();
	//}
}