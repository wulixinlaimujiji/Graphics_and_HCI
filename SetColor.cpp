// SetLineColor.cpp: 实现文件
//

#include "pch.h"
#include "CGWORK0619.h"
#include "afxdialogex.h"
#include "SetColor.h"


// SetLineColor 对话框

IMPLEMENT_DYNAMIC(SetColor, CDialogEx)

SetColor::SetColor(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Set_Color, pParent)
	, mRed(0)
	, mGreen(0)
	, mBlue(0)
{

}

SetColor::~SetColor()
{
}

// getter
int SetColor::getSetRed() {
	return this->mRed;
}
int SetColor::getSetGreen() {
	return this->mGreen;
}
int SetColor::getSetBlue() {
	return this->mBlue;
}

void SetColor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Red, mRed);
	DDV_MinMaxInt(pDX, mRed, 0, 255);
	DDX_Text(pDX, IDC_Green, mGreen);
	DDV_MinMaxInt(pDX, mGreen, 0, 255);
	DDX_Text(pDX, IDC_Blue, mBlue);
	DDV_MinMaxInt(pDX, mBlue, 0, 255);
}


BEGIN_MESSAGE_MAP(SetColor, CDialogEx)
END_MESSAGE_MAP()


// SetLineColor 消息处理程序
