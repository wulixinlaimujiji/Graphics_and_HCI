#pragma once
// ״̬����
enum State {
	/* ����״̬ */
	FreeState, // ����״̬
	ClearState, // ����״̬
	/* ͼ�λ���״̬ */
	DrawRectangleState, // ���ƾ���״̬
	DrawCircleleState, // ����Բ��״̬
	SetLineColorState, // ������ɫ״̬
	/* �������״̬ */
	DrawPolygonState, // ���ƶ����״̬
	SetAreaColorState, // ������ɫ״̬
	/* ��ά�任״̬ */
	DrawCubeState, // ����������
	TranslateInXaxisDirectionState, // ��x�᷽��ƽ��״̬
	TranslateInYaxisDirectionState, // ��y�᷽��ƽ��״̬
	TranslateInZaxisDirectionState, // ��z�᷽��ƽ��״̬
	RotateAroundXaxisState, // ��x����ת״̬
	RotateAroundYaxisState, // ��y����ת״̬
	RotateAroundZaxisState, // ��z����ת״̬
	SetDataState, // ��������״̬
	/* ��������״̬ */
	DrawBezierCurveState // ����Bezier����״̬
};