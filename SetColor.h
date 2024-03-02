#pragma once
#include "afxdialogex.h"


// SetLineColor 对话框

class SetColor : public CDialogEx
{
	DECLARE_DYNAMIC(SetColor)

public:
	SetColor(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetColor();

	// getter
	int getSetRed();
	int getSetGreen();
	int getSetBlue();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Set_Color };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int mRed;
	int mGreen;
	int mBlue;
};
