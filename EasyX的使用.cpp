#define _CRT_SECURE_NO_WARNINGS 1

#include<easyx.h>      //�ȼ��� #include<graphics.h>
#include<stdio.h>
#include<mmsystem.h>   //mm-��ý��
#pragma comment(lib, "winmm.lib")   //���ļ�����
int main()
{
	initgraph(960,540);                        //1.��������


	//outtextxy(480,270, "˧");                 //2.����ı�


	cleardevice();                              //3.ˢ��


	RGB(34, 177, 76);                                   //4.��ɫ
	//������ɫ WHITE  BLACK  RED  GREEN  BLUE  YELLOW
	//��������ɫ RGB( , , )

	mciSendString( L"open 1.mp3", 0, 0, 0);           //5.���� 
	mciSendString( L"play 1.mp3", 0, 0, 0);

	//mciSendString("pause Wake.mp3", 0, 0, 0);
	//mciSendString("close Wake.mp3", 0, 0, 0);
	//mci-media control interface  �����ַ���

	settextcolor(RGB(34, 177, 76));                     //6.����
	settextstyle(100, 0, L"FOT-MatisseEleganto Pro EB");   //�߶�:100  ���:0(����Ӧ)  ����
	outtextxy(200, 400, L"EVANGELION");

	//1.��ͨ��ͼ                                        //7.ͼƬ
	IMAGE p;
	loadimage(&p, L"Asuka.jpg");
	//putimage(0, 0, &p);

	//2.������ͼ(�����ͼ)
	BeginBatchDraw();         //��ʼ��ͼƬ���Ƶ�������

	putimage(0, 0, &p);
	outtextxy(200, 400, L"EVANGELION");

	EndBatchDraw();           //����ͼƬ���������ƣ�������һ֡ͼ�������������

	//3.͸����ͼ
	   //1.׼������ͼƬ �ڵװ���ͼ �׵ײ���ͼ
	    
	   //2.����ͼƬ������ͬһ����
	    
	   //3.�ֱ�ʹ�ö����Ʋ���   SPCPAINT-��λ�� SPCAND-��λ��

	getchar();   //��ֹ��������
	return 0;
}