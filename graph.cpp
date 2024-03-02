#include "pch.h"
#include "graph.h"

/* 图形基类 */
// 构造函数
Graph::Graph(vector<CPoint> points, COLORREF color) {
	this->mPoints = points;
	this->mColor = color;
}
// getter和setter
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

/* 矩形 */
// 构造函数
RectangleGraph::RectangleGraph(vector<CPoint> points, COLORREF color) : Graph(points, color) {
}
// 绘制矩形
void RectangleGraph::DrawGraph(CDC* pDC) {
	///获取点坐标
	vector<CPoint> points = this->getPoints();
	CPoint point1 = points[0];
	CPoint point2 = points[1];

	/// 绘制线段
	DrawLine(pDC, this->getColor(), point1.x, point1.y, point1.x, point2.y);
	DrawLine(pDC, this->getColor(), point1.x, point1.y, point2.x, point1.y);
	DrawLine(pDC, this->getColor(), point1.x, point2.y, point2.x, point2.y);
	DrawLine(pDC, this->getColor(), point2.x, point1.y, point2.x, point2.y);
}

/* 圆形 */
// 构造函数
CircleGraph::CircleGraph(vector<CPoint> points, COLORREF color) : Graph(points, color) {
}
// 绘制图形（中点画圆算法）
void CircleGraph::DrawGraph(CDC* pDC) {	
	///获取点坐标
	vector<CPoint> points = this->getPoints();
	CPoint CenterOfCircle = points[0]; // 圆心
	CPoint Circumference = points[1]; // 圆上点

	/// 计算圆的半径
	double temp1 = CenterOfCircle.x - Circumference.x;
	double temp2 = CenterOfCircle.y - Circumference.y;
	double radius = sqrt((temp1 * temp1) + (temp2 * temp2)); // 圆半径

	/// 绘制圆
	double x = radius;
	int y = 0;
	int error = 1 - radius;

	while (x >= y)
	{
		// 设置对称位置的像素颜色，以近似绘制圆形
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

/* 多边形 */
// 构造函数
PolygonGraph::PolygonGraph(vector<CPoint> points, COLORREF lineColor, COLORREF areaColor) : Graph(points, lineColor) {
	this->mAreaColor = areaColor;
}
// getter和setter
COLORREF PolygonGraph::getAreaColor() {
	return this->mAreaColor;
}
void PolygonGraph::setAreaColor(COLORREF color) {
	this->mAreaColor = color;
}
// 绘制多边形
void PolygonGraph::DrawGraph(CDC* pDC) {
	/// 获取顶点
	vector<CPoint> points = this->getPoints();
	/// 绘制边线
	for (int i = 0; i < points.size() - 1; i++) {
		DrawLine(pDC, this->getColor(), points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
	}
	DrawLine(pDC, this->getColor(), points[points.size() - 1].x, points[points.size() - 1].y, points[0].x, points[0].y);
	/// 填充区域
	if (points.size() > 2) {	
		EdgeMarkFill(pDC, points);
	}
	/// 绘制边线
	for (int i = 0; i < points.size() - 1; i++) {
		DrawLine(pDC, this->getColor(), points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
	}
	DrawLine(pDC, this->getColor(), points[points.size() - 1].x, points[points.size() - 1].y, points[0].x, points[0].y);
}
// 边标志算法
void PolygonGraph::EdgeMarkFill(CDC* pDC, vector<CPoint> points) {
	/// 寻找边界
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
	/// 边界像素打标志
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
	/// 填充像素内部
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

/* Bezier曲线 */
 // 构造函数
BezierGraph::BezierGraph(vector<CPoint> points, COLORREF color) : Graph(points, color) {
}
// 绘制图形
void BezierGraph::DrawGraph(CDC* pDC) {
	vector<CPoint> points = this->getPoints();
	// 绘制标记点
	this->DrawPoint(pDC);
	// 绘制直线
	for (int i = 0; i < points.size() - 1; i++) {
		DrawLine(pDC, RGB(0, 0, 0), points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
	}
	// 绘制曲线
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
// 分裂法
void BezierGraph::SplitBezier(CDC* pDC, vector<DoublePoint> points) {
	// 若四个控制点之间的最大距离小于epsilon，认为足够接近，直接绘制一条线段
	const double epsilon = 0.01;
	if (MaxDistance(points) < epsilon) {
		DrawLine(pDC, this->getColor(), points[0].x, points[0].y, points[3].x, points[3].y);
	}
	// 若距离不够小，则继续拆分曲线
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
// 计算顶点距离底边的最大距离
double BezierGraph::MaxDistance(vector<DoublePoint> points) {
	// 计算两个矢量的叉积
	double s1 = (points[0].x - points[1].x) * (points[0].y - points[1].y) +
		        (points[1].x - points[3].x) * (points[1].y - points[3].y) +
		        (points[3].x - points[0].x) * (points[3].y - points[0].y);
	double s2 = (points[0].x - points[2].x) * (points[0].y - points[2].y) +
		        (points[2].x - points[3].x) * (points[2].y - points[3].y) +
				(points[3].x - points[0].x) * (points[3].y - points[0].y);
	// 计算两个矢量之间的距离
	double distance = sqrt((points[0].x - points[3].x) * (points[0].x - points[3].x) +
						   (points[0].y - points[3].y) * (points[0].y - points[3].y)
						  );
	// 计算两个矢量的投影长度的绝对值，并返回最大值
	double h1 = fabs(s1 / distance);
	double h2 = fabs(s2 / distance);
	return max(h1, h2);
}
// 绘制标记点
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
