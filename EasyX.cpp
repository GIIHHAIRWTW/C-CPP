#define _CRT_SECURE_NO_WARNINGS 1

#include<easyx.h>      //等价于 #include<graphics.h>
#include<stdio.h>
#include<mmsystem.h>   //mm-多媒体
#pragma comment(lib, "winmm.lib")   //库文件包含
int main()
{
	initgraph(960,540);                        //1.创建窗口


	//outtextxy(480,270, "帅");                 //2.输出文本


	cleardevice();                              //3.刷新


	RGB(34, 177, 76);                                   //4.颜色
	//常见颜色 WHITE  BLACK  RED  GREEN  BLUE  YELLOW
	//不常见颜色 RGB( , , )

	mciSendString( L"open 1.mp3", 0, 0, 0);           //5.音乐 
	mciSendString( L"play 1.mp3", 0, 0, 0);

	//mciSendString("pause Wake.mp3", 0, 0, 0);
	//mciSendString("close Wake.mp3", 0, 0, 0);
	//mci-media control interface  发送字符串

	settextcolor(RGB(34, 177, 76));                     //6.文字
	settextstyle(100, 0, L"FOT-MatisseEleganto Pro EB");   //高度:100  宽度:0(自适应)  字体
	outtextxy(200, 400, L"EVANGELION");

	//1.普通绘图                                        //7.图片
	IMAGE p;
	loadimage(&p, L"Asuka.jpg");
	//putimage(0, 0, &p);

	//2.批量绘图(缓冲绘图)
	BeginBatchDraw();         //开始将图片绘制到缓冲区

	putimage(0, 0, &p);
	outtextxy(200, 400, L"EVANGELION");

	EndBatchDraw();           //结束图片缓冲区绘制，将完整一帧图像输出到窗口中

	//3.透明绘图
	   //1.准备两张图片 黑底白面图 白底彩面图
	    
	   //2.两张图片绘制在同一坐标
	    
	   //3.分别使用二进制操作   SPCPAINT-按位或 SPCAND-按位与

	getchar();   //防止程序闪退
	return 0;
}