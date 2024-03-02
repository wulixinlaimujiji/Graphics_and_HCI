#pragma once
#include "afxdialogex.h"


// SetPolygonColor 对话框

class SetPolygonColor : public CDialogEx
{
	DECLARE_DYNAMIC(SetPolygonColor)

public:
	SetPolygonColor(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetPolygonColor();
	// getter
	COLORREF getLineColor();
	COLORREF getAreaColor();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Set_Polygon_Color };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int mLineRed;
	int mLineGreen;
	int mLineBlue;
	int mAreaRed;
	int mAreaGreen;
	int mAreaBlue;
};
