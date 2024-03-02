
// CGWORK0619View.cpp: CCGWORK0619View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CGWORK0619.h"
#endif

#include "CGWORK0619Doc.h"
#include "CGWORK0619View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCGWORK0619View

IMPLEMENT_DYNCREATE(CCGWORK0619View, CView)

BEGIN_MESSAGE_MAP(CCGWORK0619View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_On_Draw_Rectangle, &CCGWORK0619View::OnDrawRectangle)
	ON_COMMAND(ID_On_Draw_Circle, &CCGWORK0619View::OnDrawCircle)
	ON_COMMAND(ID_On_Set_Line_Color, &CCGWORK0619View::OnSetLineColor)
	ON_COMMAND(ID_On_Draw_Polygon, &CCGWORK0619View::OnDrawPolygon)
	ON_COMMAND(ID_On_Set_Area_Color, &CCGWORK0619View::OnSetAreaColor)
	ON_COMMAND(ID_On_Draw_Cube, &CCGWORK0619View::OnDrawCube)
	ON_COMMAND(ID_On_Translate_In_Xaxis_Direction, &CCGWORK0619View::OnTranslateInXaxisDirection)
	ON_COMMAND(ID_On_Translate_In_Yaxis_Direction, &CCGWORK0619View::OnTranslateInYaxisDirection)
	ON_COMMAND(ID_On_Translate_In_Zaxis_Direction, &CCGWORK0619View::OnTranslateInZaxisDirection)
	ON_COMMAND(ID_On_Rotate_Around_Xaxis, &CCGWORK0619View::OnRotateAroundXaxis)
	ON_COMMAND(ID_On_Rotate_Around_Yaxis, &CCGWORK0619View::OnRotateAroundYaxis)
	ON_COMMAND(ID_On_Rotate_Around_Zaxis, &CCGWORK0619View::OnRotateAroundZaxis)
	ON_COMMAND(ID_On_Set_Data, &CCGWORK0619View::OnSetData)
	ON_COMMAND(ID_On_Draw_Bezier_Curve, &CCGWORK0619View::OnDrawBezierCurve)
	ON_COMMAND(ID_Clear, &CCGWORK0619View::OnClear)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CCGWORK0619View 构造/析构

CCGWORK0619View::CCGWORK0619View() noexcept
{
	// TODO: 在此处添加构造代码
	this->mCube = nullptr;
	// 鼠标位置初始化
	this->mMousePos.resize(2);
	// 线颜色默认为黑色
	this->mLineColor = RGB(0, 0, 0);
	// 填充颜色默认为黑色
	this->mAreaColor = RGB(0, 0, 0);
}

CCGWORK0619View::~CCGWORK0619View()
{
}

BOOL CCGWORK0619View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCGWORK0619View 绘图

void CCGWORK0619View::OnDraw(CDC* /*pDC*/)
{
	CCGWORK0619Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC* pDC = this->GetDC();
	for (auto& rectangle : this->mRectangleGraphs) {
		rectangle->DrawGraph(pDC);
	}
	for (auto& circle : this->mCircleGraphs) {
		circle->DrawGraph(pDC);
	}
	for (auto& polygon : this->mPolygonGraphs) {
		polygon->DrawGraph(pDC);
	}
	if (this->mCube) {
		this->mCube->DrawGraph(pDC);
	}
	for (auto& bezier : this->mBezierGraphs) {
		bezier->DrawPoint(pDC);
		bezier->DrawGraph(pDC);
	}
	this->ReleaseDC(pDC);
}


// CCGWORK0619View 打印

BOOL CCGWORK0619View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCGWORK0619View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCGWORK0619View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCGWORK0619View 诊断

#ifdef _DEBUG
void CCGWORK0619View::AssertValid() const
{
	CView::AssertValid();
}

void CCGWORK0619View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGWORK0619Doc* CCGWORK0619View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGWORK0619Doc)));
	return (CCGWORK0619Doc*)m_pDocument;
}
#endif //_DEBUG


// CCGWORK0619View 消息处理程序

/* 系统监控 */
// 按下鼠标
void CCGWORK0619View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	/// 设置鼠标状态
	SetCapture(); // 跟踪鼠标
	this->mMousePress = true; // 鼠标为按下状态

	/// 根据状态做出反应
	switch (this->mState) {

		/* 图形绘制状态 */
		case State::DrawRectangleState: // 绘制矩形状态
		{
			// 记录按下的位置
			this->mMousePos[0] = point;
			this->mMousePos[1] = point;
			// 创建矩形
			this->mRectangleGraph = new RectangleGraph(this->mMousePos, this->mLineColor);
			this->mRectangleGraphs.push_back((this->mRectangleGraph));
			break;
		}
		case State::DrawCircleleState: // 绘制圆形状态
		{
			// 记录按下的位置
			this->mMousePos[0] = point;
			this->mMousePos[1] = point;
			// 创建圆形
			this->mCircleGraph = new CircleGraph(this->mMousePos, this->mLineColor);
			this->mCircleGraphs.push_back((this->mCircleGraph));
			break;
		}

		/* 区域填充状态 */
		case State::DrawPolygonState: // 绘制多边形状态
		{
			// 记录按下的位置
			this->mMousePos.push_back(point);
			// 创建多边形并加入多边形集合
			if (this->mMousePos.size() == 1) {
				this->mPolygonGraph = new PolygonGraph(this->mMousePos, this->mLineColor, this->mAreaColor);
				this->mPolygonGraphs.push_back((this->mPolygonGraph));
			}
			// 更新多边形
			else {
				CDC* pDC = this->GetDC();

				// 擦除
				if (this->mMousePos.size() > 2) {
					this->mPolygonGraph->setColor(RGB(255, 255, 255));
					this->mPolygonGraph->DrawGraph(pDC);
				}
				// 绘制
				this->mPolygonGraph->setPoints(this->mMousePos);
				this->mPolygonGraph->setColor(this->mLineColor);
				this->mPolygonGraph->DrawGraph(pDC);

				this->ReleaseDC(pDC);
			}
			break;
		}

		/* 绘制曲线状态 */
		case State::DrawBezierCurveState: // 绘制Bezier曲线状态
		{
			this->mMousePos.push_back(point);
			// 创建曲线
			if (this->mMousePos.size() == 1) {
				this->mBezierGraph = new BezierGraph(this->mMousePos, this->mLineColor);
				this->mBezierGraphs.push_back((this->mBezierGraph));
			}
			// 绘制曲线
			CDC* pDC = this->GetDC();
			this->mBezierGraph->setPoints(this->mMousePos);
			this->mBezierGraph->DrawGraph(pDC);
			this->ReleaseDC(pDC);
			if (this->mMousePos.size() == 4) {
				this->mBezierGraph = nullptr;
				this->mMousePos.clear();
			}
			break;
		}
	}
	CView::OnLButtonDown(nFlags, point);
}
// 松开鼠标
void CCGWORK0619View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	/// 设置鼠标状态
	ReleaseCapture(); // 释放鼠标
	this->mMousePress = false; // 鼠标为松开状态

	/// 根据状态做出反应
	switch (this->mState) {
		/* 图形绘制状态 */
		case State::DrawRectangleState: // 绘制矩形状态
		{
			this->mMousePos[1] = point;
			this->mRectangleGraph->setPoints(this->mMousePos);
			this->mRectangleGraph = nullptr;
			break;
		}
		case State::DrawCircleleState: // 绘制圆形状态
		{
			this->mMousePos[1] = point;
			this->mCircleGraph->setPoints(this->mMousePos);
			this->mCircleGraph = nullptr;
			break;
		}
	}
	CView::OnLButtonUp(nFlags, point);
}
// 移动鼠标
void CCGWORK0619View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	//确保鼠标为按下状态
	if (this->mMousePress) {
		/// 根据状态做出反应
		switch (this->mState) {
			/* 图形绘制状态 */
			case State::DrawRectangleState: // 绘制矩形状态
			{
				CDC* pDC = this->GetDC();

				// 擦除
				this->mRectangleGraph->setColor(RGB(255, 255, 255));
				this->mRectangleGraph->DrawGraph(pDC);
				// 绘制
				this->mMousePos[1] = point;
				this->mRectangleGraph->setPoints(this->mMousePos);
				this->mRectangleGraph->setColor(this->mLineColor);
				this->mRectangleGraph->DrawGraph(pDC);

				this->ReleaseDC(pDC);
				break;
			}
			case State::DrawCircleleState: // 绘制圆形状态
			{
				CDC* pDC = this->GetDC();

				// 擦除
				this->mCircleGraph->setColor(RGB(255, 255, 255));
				this->mCircleGraph->DrawGraph(pDC);
				// 绘制
				this->mMousePos[1] = point;
				this->mCircleGraph->setPoints(this->mMousePos);
				this->mCircleGraph->setColor(this->mLineColor);
				this->mCircleGraph->DrawGraph(pDC);

				this->ReleaseDC(pDC);
				break;
			}
		}
	}
	CView::OnMouseMove(nFlags, point);
}
// 按下键盘
void CCGWORK0619View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	// 根据状态做出反应
	int axis = 0;
	int direction = 0;
	switch (this->mState) {
		case State::DrawPolygonState:
		{
			if (nChar == 'Q') {
				this->mMousePos.clear();
				// 创建多边形并加入多边形集合
				this->mPolygonGraph = new PolygonGraph(this->mMousePos, this->mLineColor, this->mAreaColor);
				this->mPolygonGraphs.push_back((this->mPolygonGraph));
			}
			break;
		}
		/* 三维变换状态 */
		case State::TranslateInXaxisDirectionState: // 沿x轴方向平移状态
		{
			// 判断方向
			axis = 1;
			if (nChar == 'A') {
				direction = 1;
			} else if (nChar == 'L') {
				direction = -1;
			}

			CDC* pDC = this->GetDC();
			// 擦除
			vector<COLORREF> colors = this->mCube->getFlatColors();
			this->mCube->setWhiteColor();
			this->mCube->setLineColor(RGB(255, 255, 255));
			this->mCube->DrawGraph(pDC);
			// 绘制
			this->mCube->Translate(axis, direction);
			this->mCube->setFlatColors(colors);
			this->mCube->setLineColor(this->mLineColor);
			this->mCube->DrawGraph(pDC);

			this->ReleaseDC(pDC);
			break;
		}
		case State::TranslateInYaxisDirectionState: // 沿y轴方向平移状态
		{
			// 判断方向
			axis = 2;
			if (nChar == 'A') {
				direction = 1;
			}
			else if (nChar == 'L') {
				direction = -1;
			}

			CDC* pDC = this->GetDC();
			// 擦除
			vector<COLORREF> colors = this->mCube->getFlatColors();
			this->mCube->setWhiteColor();
			this->mCube->setLineColor(RGB(255, 255, 255));
			this->mCube->DrawGraph(pDC);
			// 绘制
			this->mCube->Translate(axis, direction);
			this->mCube->setFlatColors(colors);
			this->mCube->setLineColor(this->mLineColor);
			this->mCube->DrawGraph(pDC);

			this->ReleaseDC(pDC);
			break;
		}
		case State::TranslateInZaxisDirectionState: // 沿z轴方向平移状态
		{
			// 判断方向
			axis = 3;
			if (nChar == 'A') {
				direction = 1;
			}
			else if (nChar == 'L') {
				direction = -1;
			}

			CDC* pDC = this->GetDC();
			// 擦除
			vector<COLORREF> colors = this->mCube->getFlatColors();
			this->mCube->setWhiteColor();
			this->mCube->setLineColor(RGB(255, 255, 255));
			this->mCube->DrawGraph(pDC);
			// 绘制
			this->mCube->Translate(axis, direction);
			this->mCube->setFlatColors(colors);
			this->mCube->setLineColor(this->mLineColor);
			this->mCube->DrawGraph(pDC);

			this->ReleaseDC(pDC);
			break;
		}
		case State::RotateAroundXaxisState: // 绕x轴旋转状态
		{
			// 判断方向
			axis = 1;
			if (nChar == 'A') {
				direction = 1;
			}
			else if (nChar == 'L') {
				direction = -1;
			}

			CDC* pDC = this->GetDC();
			// 擦除
			vector<COLORREF> colors = this->mCube->getFlatColors();
			this->mCube->setWhiteColor();
			this->mCube->setLineColor(RGB(255, 255, 255));
			this->mCube->DrawGraph(pDC);
			// 绘制
			this->mCube->Rotate(axis, direction);
			this->mCube->setFlatColors(colors);
			this->mCube->setLineColor(this->mLineColor);
			this->mCube->DrawGraph(pDC);

			this->ReleaseDC(pDC);
			break;
		}
		case State::RotateAroundYaxisState: // 绕y轴旋转状态
		{
			// 判断方向
			axis = 2;
			if (nChar == 'A') {
				direction = 1;
			}
			else if (nChar == 'L') {
				direction = -1;
			}

			CDC* pDC = this->GetDC();
			// 擦除	
			vector<COLORREF> colors = this->mCube->getFlatColors();
			this->mCube->setWhiteColor();
			this->mCube->setLineColor(RGB(255, 255, 255));
			this->mCube->DrawGraph(pDC);
			// 绘制
			this->mCube->Rotate(axis, direction);
			this->mCube->setFlatColors(colors);
			this->mCube->setLineColor(this->mLineColor);
			this->mCube->DrawGraph(pDC);

			this->ReleaseDC(pDC);
			break;
		}
		case State::RotateAroundZaxisState: // 绕z轴旋转状态
		{
			// 判断方向
			axis = 3;
			if (nChar == 'A') {
				direction = 1;
			}
			else if (nChar == 'L') {
				direction = -1;
			}

			CDC* pDC = this->GetDC();
			// 擦除
			vector<COLORREF> colors = this->mCube->getFlatColors();
			this->mCube->setWhiteColor();
			this->mCube->setLineColor(RGB(255, 255, 255));
			this->mCube->DrawGraph(pDC);
			// 绘制
			this->mCube->Rotate(axis, direction);
			this->mCube->setFlatColors(colors);
			this->mCube->setLineColor(this->mLineColor);
			this->mCube->DrawGraph(pDC);

			this->ReleaseDC(pDC);
			break;
		}
	}
	//this->Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
//清屏
void CCGWORK0619View::OnClear()
{
	// TODO: 在此添加命令处理程序代码
	
	this->mRectangleGraph = nullptr;
	this->mRectangleGraphs.clear();
	this->mCircleGraph = nullptr;
	this->mCircleGraphs.clear();
	this->mPolygonGraph = nullptr;
	this->mPolygonGraphs.clear();
	delete this->mCube;
	this->mCube = nullptr;
	this->mBezierGraph = nullptr;
	this->mBezierGraphs.clear();
	this->mMousePos.clear();
	if (this->mState == DrawCircleleState || this->mState == DrawRectangleState) {
		this->mMousePos.resize(2);
	}
	Invalidate();
}
/* 图形绘制 */
// 绘制矩形
void CCGWORK0619View::OnDrawRectangle()
{
	// TODO: 在此添加命令处理程序代码
	this->mState = State::DrawRectangleState; // 设置状态
	this->mMousePos.clear();
	this->mMousePos.resize(2);
}
// 绘制圆形
void CCGWORK0619View::OnDrawCircle()
{
	// TODO: 在此添加命令处理程序代码
	this->mState = State::DrawCircleleState; // 设置状态
	this->mMousePos.clear();
	this->mMousePos.resize(2);
}
// 设置颜色
void CCGWORK0619View::OnSetLineColor()
{
	// TODO: 在此添加命令处理程序代码

	// 设置状态
	this->mState = State::SetLineColorState;

	// 获取新颜色
	SetColor setColor;
	if (setColor.DoModal() == IDOK) {
		int red = setColor.getSetRed();
		int green = setColor.getSetGreen();
		int blue = setColor.getSetBlue();
		this->mLineColor = RGB(red, green, blue);
	}
}
/* 区域填充 */
// 绘制多边形
void CCGWORK0619View::OnDrawPolygon()
{
	// TODO: 在此添加命令处理程序代码
	this->mState = State::DrawPolygonState; // 设置状态
	this->mMousePos.clear();
}
// 设置颜色
void CCGWORK0619View::OnSetAreaColor()
{
	// TODO: 在此添加命令处理程序代码
	
	// 设置状态
	this->mState = State::SetAreaColorState;

	// 获取新颜色
	SetPolygonColor setPolygonColor;
	if (setPolygonColor.DoModal() == IDOK) {
		this->mLineColor = setPolygonColor.getLineColor();
		this->mAreaColor = setPolygonColor.getAreaColor();
	}
}
/* 三维变换 */
// 绘制立方体
void CCGWORK0619View::OnDrawCube()
{
	// TODO: 在此添加命令处理程序代码
	
	// 设置状态
	this->mState = State::DrawCubeState;
	// 清空
	if (this->mCube) {
		delete this->mCube;
		this->mCube = nullptr;
		Invalidate();
	}
	// 获取各面颜色
	SetCubeColor setCubeColor;
	vector<COLORREF> colors;
	if (setCubeColor.DoModal() == IDOK) {
		colors.push_back(setCubeColor.getFrontColor());
		colors.push_back(setCubeColor.getBehindColor());
		colors.push_back(setCubeColor.getLeftColor());
		colors.push_back(setCubeColor.getRightColor());
		colors.push_back(setCubeColor.getUpColor());
		colors.push_back(setCubeColor.getDownColor());
	}

	// 创建并绘制立方体
	this->mCube = new Cube(this->mLineColor, colors);
	CDC* pDC = this->GetDC();
	this->mCube->DrawGraph(pDC);
	this->ReleaseDC(pDC);
}
// 沿x轴方向平移
void CCGWORK0619View::OnTranslateInXaxisDirection()
{
	// TODO: 在此添加命令处理程序代码
	this->mState = State::TranslateInXaxisDirectionState; // 设置状态
}
// 沿y轴方向平移
void CCGWORK0619View::OnTranslateInYaxisDirection()
{
	// TODO: 在此添加命令处理程序代码
	this->mState = State::TranslateInYaxisDirectionState; // 设置状态
}
// 沿z轴方向平移
void CCGWORK0619View::OnTranslateInZaxisDirection()
{
	// TODO: 在此添加命令处理程序代码
	this->mState = State::TranslateInZaxisDirectionState; // 设置状态
}
// 绕x轴旋转
void CCGWORK0619View::OnRotateAroundXaxis()
{
	// TODO: 在此添加命令处理程序代码
	this->mState = State::RotateAroundXaxisState; // 设置状态
}
// 绕y轴旋转
void CCGWORK0619View::OnRotateAroundYaxis()
{
	// TODO: 在此添加命令处理程序代码
	this->mState = State::RotateAroundYaxisState; // 设置状态
}
// 绕z轴旋转
void CCGWORK0619View::OnRotateAroundZaxis()
{
	// TODO: 在此添加命令处理程序代码
	this->mState = State::RotateAroundZaxisState; // 设置状态
}
// 设置数据
void CCGWORK0619View::OnSetData()
{
	// TODO: 在此添加命令处理程序代码

	// 设置状态
	this->mState = State::SetDataState;

	// 获取新数据
	SetCubeData setCubeData;
	if (setCubeData.DoModal() == IDOK) {
		this->mCube->setTranslationStepSize(setCubeData.getTranslationStepSize());
		this->mCube->setRotationAngle(setCubeData.getRotationAngle());
	}
}
/* 绘制曲线 */
// 绘制Bezier曲线
void CCGWORK0619View::OnDrawBezierCurve()
{
	// TODO: 在此添加命令处理程序代码
	this->mState = State::DrawBezierCurveState; // 设置状态
	this->mMousePos.clear();
}
