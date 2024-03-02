#include "pch.h"
#include "graph.h"

/* ͼ�λ��� */
// ���캯��
Graph::Graph(vector<CPoint> points, COLORREF color) {
	this->mPoints = points;
	this->mColor = color;
}
// getter��setter
vector<CPoint> Graph::getPoints() {
	return this->mPoints;
}
void Graph::setPoints(vector<CPoint> points) {
	this->mPoints = points;
}
COLORREF Graph::getColor() {
	return this->mColor;
}
void Graph::setColor(COLORREF color) {
	this->mColor = color;
}

/* ���� */
// ���캯��
RectangleGraph::RectangleGraph(vector<CPoint> points, COLORREF color) : Graph(points, color) {
}
// ���ƾ���
void RectangleGraph::DrawGraph(CDC* pDC) {
	///��ȡ������
	vector<CPoint> points = this->getPoints();
	CPoint point1 = points[0];
	CPoint point2 = points[1];

	/// �����߶�
	DrawLine(pDC, this->getColor(), point1.x, point1.y, point1.x, point2.y);
	DrawLine(pDC, this->getColor(), point1.x, point1.y, point2.x, point1.y);
	DrawLine(pDC, this->getColor(), point1.x, point2.y, point2.x, point2.y);
	DrawLine(pDC, this->getColor(), point2.x, point1.y, point2.x, point2.y);
}

/* Բ�� */
// ���캯��
CircleGraph::CircleGraph(vector<CPoint> points, COLORREF color) : Graph(points, color) {
}
// ����ͼ�Σ��е㻭Բ�㷨��
void CircleGraph::DrawGraph(CDC* pDC) {	
	///��ȡ������
	vector<CPoint> points = this->getPoints();
	CPoint CenterOfCircle = points[0]; // Բ��
	CPoint Circumference = points[1]; // Բ�ϵ�

	/// ����Բ�İ뾶
	double temp1 = CenterOfCircle.x - Circumference.x;
	double temp2 = CenterOfCircle.y - Circumference.y;
	double radius = sqrt((temp1 * temp1) + (temp2 * temp2)); // Բ�뾶

	/// ����Բ
	double x = radius;
	int y = 0;
	int error = 1 - radius;

	while (x >= y)
	{
		// ���öԳ�λ�õ�������ɫ���Խ��ƻ���Բ��
		pDC->SetPixel(CenterOfCircle.x + x, CenterOfCircle.y + y, this->getColor());
		pDC->SetPixel(CenterOfCircle.x - x, CenterOfCircle.y + y, this->getColor());
		pDC->SetPixel(CenterOfCircle.x + x, CenterOfCircle.y - y, this->getColor());
		pDC->SetPixel(CenterOfCircle.x - x, CenterOfCircle.y - y, this->getColor());
		pDC->SetPixel(CenterOfCircle.x + y, CenterOfCircle.y + x, this->getColor());
		pDC->SetPixel(CenterOfCircle.x - y, CenterOfCircle.y + x, this->getColor());
		pDC->SetPixel(CenterOfCircle.x + y, CenterOfCircle.y - x, this->getColor());
		pDC->SetPixel(CenterOfCircle.x - y, CenterOfCircle.y - x, this->getColor());

		y++;
		if (error <= 0)
			error += 2 * y + 1;
		else
		{
			x--;
			error += 2 * (y - x) + 1;
		}
	}
}

/* ����� */
// ���캯��
PolygonGraph::PolygonGraph(vector<CPoint> points, COLORREF lineColor, COLORREF areaColor) : Graph(points, lineColor) {
	this->mAreaColor = areaColor;
}
// getter��setter
COLORREF PolygonGraph::getAreaColor() {
	return this->mAreaColor;
}
void PolygonGraph::setAreaColor(COLORREF color) {
	this->mAreaColor = color;
}
// ���ƶ����
void PolygonGraph::DrawGraph(CDC* pDC) {
	/// ��ȡ����
	vector<CPoint> points = this->getPoints();
	/// ���Ʊ���
	for (int i = 0; i < points.size() - 1; i++) {
		DrawLine(pDC, this->getColor(), points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
	}
	DrawLine(pDC, this->getColor(), points[points.size() - 1].x, points[points.size() - 1].y, points[0].x, points[0].y);
	/// �������
	if (points.size() > 2) {	
		EdgeMarkFill(pDC, points);
	}
	/// ���Ʊ���
	for (int i = 0; i < points.size() - 1; i++) {
		DrawLine(pDC, this->getColor(), points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
	}
	DrawLine(pDC, this->getColor(), points[points.size() - 1].x, points[points.size() - 1].y, points[0].x, points[0].y);
}
// �߱�־�㷨
void PolygonGraph::EdgeMarkFill(CDC* pDC, vector<CPoint> points) {
	/// Ѱ�ұ߽�
	int MinX = INT_MAX, MinY = INT_MAX;
	int MaxX = INT_MIN, MaxY = INT_MIN;
	for (auto& point : points) {
		if (MinX > point.x) {
			MinX = point.x;
		}
		if (MaxX < point.x) {
			MaxX = point.x;
		}
		if (MinY > point.y) {
			MinY = point.y;
		}
		if (MaxY < point.y) {
			MaxY = point.y;
		}
	}
	/// �߽����ش��־
	bool** MASK = new bool* [MaxY + 3];
	for (int i = 0; i < MaxY + 3; i++) {
		MASK[i] = new bool[MaxX + 3];
	}
	for (int i = 0; i < MaxY; i++) {
		for (int j = 0; j < MaxX; j++) {
			MASK[i][j] = false;
		}
	}
	for (int i = 0; i < points.size(); i++) {
		CPoint p1 = points[i];
		CPoint p2 = points[(i + 1) % points.size()];
		if (p1.y > p2.y) {
			int temp_x = p1.x;
			int temp_y = p1.y;
			p1.x = p2.x; 
			p2.x = temp_x;
			p1.y = p2.y;
			p2.y = temp_y;
		}
		double xs = p1.x;
		double dxs = (double)(p2.x - p1.x) / (p2.y - p1.y);
		double dys = abs(p2.y - p1.y) / (p2.y - p1.y);
		for (int ys = p1.y; ys != p2.y; ys += dys) {
			int Ixs = int(xs + 0.5);
			for (int x0 = Ixs; x0 <= MaxX; x0++) {
				MASK[ys][x0] = !MASK[ys][x0];
			}
			xs += dxs*dys;
		}
	}
	/// ��������ڲ�
	for (int y = MinY; y < MaxY - 1; y++) {
		for (int x = MinX; x < MaxX - 1; x++) {
			if (MASK[y][x] && this->mContext[y % 16][x % 32] == 1) {
				pDC->SetPixel(x, y, this->mAreaColor);
			}
			else {
				pDC->SetPixel(x, y, RGB(255,255,255));
			}
		}
	}

}

/* Bezier���� */
 // ���캯��
BezierGraph::BezierGraph(vector<CPoint> points, COLORREF color) : Graph(points, color) {
}
// ����ͼ��
void BezierGraph::DrawGraph(CDC* pDC) {
	vector<CPoint> points = this->getPoints();
	// ���Ʊ�ǵ�
	this->DrawPoint(pDC);
	// ����ֱ��
	for (int i = 0; i < points.size() - 1; i++) {
		DrawLine(pDC, RGB(0, 0, 0), points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
	}
	// ��������
	if (points.size() == 4) {
		vector<DoublePoint> doublePoints;
		doublePoints.resize(4);
		for (int i = 0; i < 4; i++) {
			doublePoints[i].x = points[i].x;
			doublePoints[i].y = points[i].y;
		}
		SplitBezier(pDC, doublePoints);
	}
}
// ���ѷ�
void BezierGraph::SplitBezier(CDC* pDC, vector<DoublePoint> points) {
	// ���ĸ����Ƶ�֮���������С��epsilon����Ϊ�㹻�ӽ���ֱ�ӻ���һ���߶�
	const double epsilon = 0.01;
	if (MaxDistance(points) < epsilon) {
		DrawLine(pDC, this->getColor(), points[0].x, points[0].y, points[3].x, points[3].y);
	}
	// �����벻��С��������������
	else {
		vector<DoublePoint> R = points;
		vector<DoublePoint> Q;
		for (int i = 0; i < 3; i++) {
			Q.push_back(R[0]);
			for (int j = 0; j < 3 - i; j++) {
				R[j].x = (R[j].x + R[j + 1].x) / 2;
				R[j].y = (R[j].y + R[j + 1].y) / 2;
			}	
		}
		Q.push_back(R[0]);
		SplitBezier(pDC, Q);
		SplitBezier(pDC, R);
	}
}
// ���㶥�����ױߵ�������
double BezierGraph::MaxDistance(vector<DoublePoint> points) {
	// ��������ʸ���Ĳ��
	double s1 = (points[0].x - points[1].x) * (points[0].y - points[1].y) +
		        (points[1].x - points[3].x) * (points[1].y - points[3].y) +
		        (points[3].x - points[0].x) * (points[3].y - points[0].y);
	double s2 = (points[0].x - points[2].x) * (points[0].y - points[2].y) +
		        (points[2].x - points[3].x) * (points[2].y - points[3].y) +
				(points[3].x - points[0].x) * (points[3].y - points[0].y);
	// ��������ʸ��֮��ľ���
	double distance = sqrt((points[0].x - points[3].x) * (points[0].x - points[3].x) +
						   (points[0].y - points[3].y) * (points[0].y - points[3].y)
						  );
	// ��������ʸ����ͶӰ���ȵľ���ֵ�����������ֵ
	double h1 = fabs(s1 / distance);
	double h2 = fabs(s2 / distance);
	return max(h1, h2);
}
// ���Ʊ�ǵ�
void BezierGraph::DrawPoint(CDC* pDC) {
	vector<CPoint> points = this->getPoints();
	for (auto& point : points) {
		CBrush newBrush;
		newBrush.CreateSolidBrush(RGB(0, 0, 0));
		CBrush* oldBrush = pDC->SelectObject(&newBrush);
		pDC->Rectangle(point.x - 2.5, point.y-2.5, point.x + 2.5, point.y+2.5);
		pDC->SelectObject(oldBrush);
		newBrush.DeleteObject();
		oldBrush->DeleteObject();
	}
}
