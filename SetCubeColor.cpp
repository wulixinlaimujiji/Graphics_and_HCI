// SetCubeColor.cpp: 实现文件
//

#include "pch.h"
#include "CGWORK0619.h"
#include "afxdialogex.h"
#include "SetCubeColor.h"


// SetCubeColor 对话框

IMPLEMENT_DYNAMIC(SetCubeColor, CDialogEx)

SetCubeColor::SetCubeColor(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Set_Cube_Color, pParent)
	, mUpRed(255)
	, mUpGreen(255)
	, mUpBlue(255)
	, mDownRed(255)
	, mDownGreen(255)
	, mDownBlue(255)
	, mLeftRed(255)
	, mLeftGreen(255)
	, mLeftBlue(255)
	, mRightRed(255)
	, mRightGreen(255)
	, mRightBlue(255)
	, mFrontRed(255)
	, mFrontGreen(255)
	, mFrontBlue(255)
	, mBehindGreen(255)
	, mBehindRed(255)
	, mBehindBlue(255)
{

}

SetCubeColor::~SetCubeColor()
{
}

//getter
COLORREF SetCubeColor::getUpColor() {
	return RGB(this->mUpRed, this->mUpGreen, this->mUpBlue);
}
COLORREF SetCubeColor::getDownColor() {
	return RGB(this->mDownRed, this->mDownGreen, this->mDownBlue);
}
COLORREF SetCubeColor::getLeftColor() {
	return RGB(this->mLeftRed, this->mLeftGreen, this->mLeftBlue);
}
COLORREF SetCubeColor::getRightColor() {
	return RGB(this->mRightRed, this->mRightGreen, this->mRightBlue);
}
COLORREF SetCubeColor::getFrontColor() {
	return RGB(this->mFrontRed, this->mFrontGreen, this->mFrontBlue);
}
COLORREF SetCubeColor::getBehindColor() {
	return RGB(this->mBehindRed, this->mBehindGreen, this->mBehindBlue);
}

void SetCubeColor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mUpRed);
	DDV_MinMaxInt(pDX, mUpRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, mUpGreen);
	DDV_MinMaxInt(pDX, mUpGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, mUpBlue);
	DDV_MinMaxInt(pDX, mUpBlue, 0, 255);
	DDX_Text(pDX, IDC_EDIT4, mDownRed);
	DDV_MinMaxInt(pDX, mDownRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT5, mDownGreen);
	DDV_MinMaxInt(pDX, mDownGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT6, mDownBlue);
	DDV_MinMaxInt(pDX, mDownBlue, 0, 255);
	DDX_Text(pDX, IDC_EDIT7, mLeftRed);
	DDV_MinMaxInt(pDX, mLeftRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT8, mLeftGreen);
	DDV_MinMaxInt(pDX, mLeftGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT9, mLeftBlue);
	DDV_MinMaxInt(pDX, mLeftBlue, 0, 255);
	DDX_Text(pDX, IDC_EDIT10, mRightRed);
	DDV_MinMaxInt(pDX, mRightRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT11, mRightGreen);
	DDV_MinMaxInt(pDX, mRightGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT12, mRightBlue);
	DDV_MinMaxInt(pDX, mRightBlue, 0, 255);
	DDX_Text(pDX, IDC_EDIT13, mFrontRed);
	DDV_MinMaxInt(pDX, mFrontRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT14, mFrontGreen);
	DDV_MinMaxInt(pDX, mFrontGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT15, mFrontBlue);
	DDV_MinMaxInt(pDX, mFrontBlue, 0, 255);
	DDX_Text(pDX, IDC_EDIT16, mBehindRed);
	DDV_MinMaxInt(pDX, mBehindRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT17, mBehindGreen);
	DDV_MinMaxInt(pDX, mBehindGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT18, mBehindBlue);
	DDV_MinMaxInt(pDX, mBehindBlue, 0, 255);
}


BEGIN_MESSAGE_MAP(SetCubeColor, CDialogEx)
END_MESSAGE_MAP()


// SetCubeColor 消息处理程序
