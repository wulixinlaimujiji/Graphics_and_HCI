
// CGWORK0619View.h: CCGWORK0619View 类的接口
//

#pragma once
#include "graph.h"
#include "cube.h"
#include "state.h"
#include "SetColor.h"
#include "SetPolygonColor.h"
#include "SetCubeColor.h"
#include "SetCubeData.h"

class CCGWORK0619View : public CView
{
protected: // 仅从序列化创建
	CCGWORK0619View() noexcept;
	DECLARE_DYNCREATE(CCGWORK0619View)

// 特性
public:
	CCGWORK0619Doc* GetDocument() const;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCGWORK0619View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 自定义变量
protected:
	int mState; // 当前功能
	/* 颜色相关 */
	COLORREF mLineColor; // 边颜色
	COLORREF mAreaColor; // 填充颜色
	/* 图形相关 */
	RectangleGraph* mRectangleGraph; // 正在绘制的矩形
	vector<RectangleGraph*> mRectangleGraphs; // 矩形集合
	CircleGraph* mCircleGraph; // 正在绘制的圆形
	vector<CircleGraph*> mCircleGraphs; // 圆形集合
	PolygonGraph* mPolygonGraph; // 正在绘制的多边形
	vector<PolygonGraph*> mPolygonGraphs; // 多边形集合
	Cube* mCube; // 立方体
	BezierGraph* mBezierGraph; // 正在绘制的Bezier曲线
	vector<BezierGraph*> mBezierGraphs; // Bezier曲线集合
	/* 鼠标相关 */
	bool mMousePress; // 鼠标左键是否按下
	vector<CPoint> mMousePos; // 鼠标按下和松开的位置
	CPoint mCursorPos; // 鼠标当前位置
	

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	/* 系统监控 */
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); // 按下鼠标
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point); // 松开鼠标
	afx_msg void OnMouseMove(UINT nFlags, CPoint point); // 移动鼠标
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags); // 按下键盘
	afx_msg void OnClear(); // 清屏
	/* 图形绘制 */
	afx_msg void OnDrawRectangle(); // 绘制矩形
	afx_msg void OnDrawCircle(); // 绘制圆形
	afx_msg void OnSetLineColor(); // 设置颜色
	/* 区域填充 */
	afx_msg void OnDrawPolygon(); // 绘制多边形
	afx_msg void OnSetAreaColor(); // 设置颜色
	/* 三维变换 */
	afx_msg void OnDrawCube(); // 绘制立方体
	afx_msg void OnTranslateInXaxisDirection(); // 沿x轴方向平移
	afx_msg void OnTranslateInYaxisDirection(); // 沿y轴方向平移
	afx_msg void OnTranslateInZaxisDirection(); // 沿z轴方向平移
	afx_msg void OnRotateAroundXaxis(); // 绕x轴旋转
	afx_msg void OnRotateAroundYaxis(); // 绕y轴旋转
	afx_msg void OnRotateAroundZaxis(); // 绕z轴旋转
	afx_msg void OnSetData(); // 设置数据
	/* 绘制曲线 */
	afx_msg void OnDrawBezierCurve(); // 绘制Bezier曲线
};

#ifndef _DEBUG  // CGWORK0619View.cpp 中的调试版本
inline CCGWORK0619Doc* CCGWORK0619View::GetDocument() const
   { return reinterpret_cast<CCGWORK0619Doc*>(m_pDocument); }
#endif

