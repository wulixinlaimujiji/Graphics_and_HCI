# Graphics_and_HCI
### 吉林大学软件学院2021级图形学与人机交互
题目：简单图形绘制应用程序的实现（详见“[软件学院图形学与人机交互实验课题目[23-24-1].pdf](https://github.com/wulixinlaimujiji/Graphics_and_HCI/blob/master/%E8%BD%AF%E4%BB%B6%E5%AD%A6%E9%99%A2%E5%9B%BE%E5%BD%A2%E5%AD%A6%E4%B8%8E%E4%BA%BA%E6%9C%BA%E4%BA%A4%E4%BA%92%E5%AE%9E%E9%AA%8C%E8%AF%BE%E9%A2%98%E7%9B%AE%5B23-24-1%5D.pdf)”）

## 程序功能
### 1 图形绘制
#### 1.1 绘制矩形
选择此菜单项后，可利用鼠标在视图区绘制矩形
#### 1.2 绘制圆形
选择此菜单项后，可利用鼠标在视图区绘制圆形
#### 1.3 设置颜色
选择此菜单项后，显示对话框，在此对话框中设置绘制的矩形和圆形的颜色（可以分别设置RGB三颜色分量值），默认颜色为黑色<br>

### 2 区域填充
#### 2.1 绘制多边形
选择后可用鼠标绘制用学号后四位做内部填充的多边形
#### 2.2 设置颜色
选择此菜单项后，显示对话框，在对话框中设置绘制多边形中填充的学号的颜色和边界颜色（可以分别设置RGB三颜色分量值），默认颜色为黑色<br>

### 3 三维变换
#### 3.1 绘制矩形
建立立方体的数据模型，选择此菜单项后，该立方体会在视图区中绘制出来（采用透视投影）
#### 3.2 沿x轴方向平移
选择此菜单项后，可以通过键盘按键“A”和“L”分别使立方体沿x轴正方向和负方向做指定步长的平移，每次平移后都要将平移后的立方体绘制在视图区中
#### 3.3 沿y轴方向平移
选择此菜单项后，可以通过键盘按键“A”和“L”分别使立方体沿y轴正方向和负方向做指定步长的平移，每次平移后都要将平移后的立方体绘制在视图区中
#### 3.4 沿z轴方向平移
选择此菜单项后，可以通过键盘按键“A”和“L”分别使立方体沿z轴正方向和负方向做指定步长的平移，每次平移后都要将平移后的立方体绘制在视图区中
#### 3.5 绕x轴旋转
选择此菜单项后，可以通过键盘按键“A”和“L”分别使立方体绕x轴做指定角度数的正向和反向旋转
#### 3.6 绕y轴旋转
选择此菜单项后，可以通过键盘按键“A”和“L”分别使立方体绕y轴做指定角度数的正向和反向旋转
#### 3.7 绕z轴旋转
选择此菜单项后，可以通过键盘按键“A”和“L”分别使立方体绕z轴做指定角度数的正向和反向旋转
#### 3.8 设置数据
选择此菜单项后，显示对话框，设置功能3.7至3.9的平移步长，默认步长为 1，以及设置功能3.10至3.12的每次旋转角度，默认角度为10度<br>

### 4 绘制曲线
#### 4.1 绘制Bezier曲线 
选择此菜单项后，可在视图区用鼠标左键单击的方式顺序输入控制点，控制点数量为4时绘制以鼠标输入的点为控制点的3次Bezier曲线