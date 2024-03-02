#pragma once
#include "afxdialogex.h"


// SetCubeColor 对话框

class SetCubeColor : public CDialogEx
{
	DECLARE_DYNAMIC(SetCubeColor)

public:
	SetCubeColor(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetCubeColor();
	//getter
	COLORREF getUpColor();
	COLORREF getDownColor();
	COLORREF getLeftColor();
	COLORREF getRightColor();
	COLORREF getFrontColor();
	COLORREF getBehindColor();
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Set_Cube_Color };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int mUpRed;
	int mUpGreen;
	int mUpBlue;

	int mDownRed;
	int mDownGreen;
	int mDownBlue;

	int mLeftRed;
	int mLeftGreen;
	int mLeftBlue;

	int mRightRed;
	int mRightGreen;
	int mRightBlue;

	int mFrontRed;
	int mFrontGreen;
	int mFrontBlue;

	int mBehindGreen;
	int mBehindRed;
	int mBehindBlue;
};
