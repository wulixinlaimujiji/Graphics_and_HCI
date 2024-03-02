#pragma once
#include "afxdialogex.h"


// SetCubeData 对话框

class SetCubeData : public CDialogEx
{
	DECLARE_DYNAMIC(SetCubeData)

public:
	SetCubeData(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetCubeData();

	// getter
	int getTranslationStepSize();
	int getRotationAngle();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Set_Cube_Data };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	int mTranslationStepSize; // 平移步长
	int mRotationAngle; // 旋转角度
};
