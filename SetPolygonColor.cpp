// SetPolygonColor.cpp: 实现文件
//

#include "pch.h"
#include "CGWORK0619.h"
#include "afxdialogex.h"
#include "SetPolygonColor.h"


// SetPolygonColor 对话框

IMPLEMENT_DYNAMIC(SetPolygonColor, CDialogEx)

SetPolygonColor::SetPolygonColor(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Set_Polygon_Color, pParent)
	, mLineRed(0)
	, mLineGreen(0)
	, mLineBlue(0)
	, mAreaRed(255)
	, mAreaGreen(255)
	, mAreaBlue(255)
{

}

SetPolygonColor::~SetPolygonColor()
{
}

COLORREF SetPolygonColor::getLineColor() {
	return RGB(this->mLineRed, this->mLineGreen, this->mLineBlue);
}
COLORREF SetPolygonColor::getAreaColor() {
	return RGB(this->mAreaRed, this->mAreaGreen, this->mAreaBlue);
}

void SetPolygonColor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mLineRed);
	DDV_MinMaxInt(pDX, mLineRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, mLineGreen);
	DDV_MinMaxInt(pDX, mLineGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, mLineBlue);
	DDV_MinMaxInt(pDX, mLineBlue, 0, 255);
	DDX_Text(pDX, IDC_EDIT4, mAreaRed);
	DDV_MinMaxInt(pDX, mAreaRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT5, mAreaGreen);
	DDV_MinMaxInt(pDX, mAreaGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT6, mAreaBlue);
	DDV_MinMaxInt(pDX, mAreaBlue, 0, 255);
}


BEGIN_MESSAGE_MAP(SetPolygonColor, CDialogEx)
END_MESSAGE_MAP()


// SetPolygonColor 消息处理程序
