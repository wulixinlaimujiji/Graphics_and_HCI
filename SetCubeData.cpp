// SetCubeData.cpp: 实现文件
//

#include "pch.h"
#include "CGWORK0619.h"
#include "afxdialogex.h"
#include "SetCubeData.h"


// SetCubeData 对话框

IMPLEMENT_DYNAMIC(SetCubeData, CDialogEx)

SetCubeData::SetCubeData(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Set_Cube_Data, pParent)
	, mTranslationStepSize(1)
	, mRotationAngle(10)
{

}

SetCubeData::~SetCubeData()
{
}

// getter
int SetCubeData::getTranslationStepSize() {
	return this->mTranslationStepSize;
}
int SetCubeData::getRotationAngle() {
	return this->mRotationAngle;
}

void SetCubeData::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Translation_Step_Size, mTranslationStepSize);
	DDX_Text(pDX, IDC_Rotation_Angle, mRotationAngle);
	DDV_MinMaxInt(pDX, mRotationAngle, 0, 360);
}


BEGIN_MESSAGE_MAP(SetCubeData, CDialogEx)
END_MESSAGE_MAP()


// SetCubeData 消息处理程序
