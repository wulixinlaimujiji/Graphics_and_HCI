#pragma once
// 状态常量
enum State {
	/* 其他状态 */
	FreeState, // 自由状态
	ClearState, // 清屏状态
	/* 图形绘制状态 */
	DrawRectangleState, // 绘制矩形状态
	DrawCircleleState, // 绘制圆形状态
	SetLineColorState, // 设置颜色状态
	/* 区域填充状态 */
	DrawPolygonState, // 绘制多边形状态
	SetAreaColorState, // 设置颜色状态
	/* 三维变换状态 */
	DrawCubeState, // 绘制立方体
	TranslateInXaxisDirectionState, // 沿x轴方向平移状态
	TranslateInYaxisDirectionState, // 沿y轴方向平移状态
	TranslateInZaxisDirectionState, // 沿z轴方向平移状态
	RotateAroundXaxisState, // 绕x轴旋转状态
	RotateAroundYaxisState, // 绕y轴旋转状态
	RotateAroundZaxisState, // 绕z轴旋转状态
	SetDataState, // 设置数据状态
	/* 绘制曲线状态 */
	DrawBezierCurveState // 绘制Bezier曲线状态
};