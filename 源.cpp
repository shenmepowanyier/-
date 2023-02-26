#pragma warning(disable : 4996)//关闭已弃用函数警告

#include<conio.h>
#include<iostream>
#include<string>
#include<graphics.h>
#include"DrawTransparent.h"

using namespace std;

//函数
void picture();//图片加载
void welcome();//欢迎界面
void showt();//老师密码输入界面
void shows();//学生登录界面
void facet();//老师成功登录界面
void faces(char name[20], char id[20], int chinese, int math, int engilsh);//学生成功登录界面
void save();//将链表的内容存入文件
void input();//向链表内录入内容
void found();//查询
void deve();//删除
void chang();//修改
void found1(char name[20], char id[20], char chinese[20], char math[20], char engilsh[20]);//查询录入正确后界面
int zhuanhuan(char num[20]);//将char类型转化为int类型

//图片
IMAGE teacher;
IMAGE student;
IMAGE bk;
IMAGE student1;
IMAGE live;
IMAGE yi;
IMAGE chaxun;
IMAGE change;
IMAGE shanchu;
IMAGE puton;
IMAGE live1;
IMAGE yi1;

//鼠标
MOUSEMSG msg;

//老师人数与学生人数
int m = 2;
int stu = 0;

//浅浅开一个链表
struct student {
	char name[20] = { 0 };
	char id[20] = { 0 };
	int chinese, math, english;
};

struct Node {
	struct student st;
	struct Node* next;
};

Node* headNode = NULL;

int main()
{
	//设置窗口与背景
	initgraph(1000, 600);
	setbkcolor(WHITE);
	cleardevice();
	welcome();

	getchar();
	closegraph();

	return 0;
}

//加载图片
void picture()
{
	loadimage(&bk, "./主页面.png", 1000, 600);
	loadimage(&teacher, "./老师.png");
	loadimage(&student, "./学生.png");
	loadimage(&student1, "./学生成绩界面.png");
	loadimage(&live, "./退出.png");
	loadimage(&yi, "./首页.png");
	loadimage(&change, "./修改.png");
	loadimage(&shanchu, "./删除.png");
	loadimage(&chaxun, "./查询.png");
	loadimage(&puton, "./录入.png");
	loadimage(&live1, "./退出t.png");
	loadimage(&yi1, "./首页t.png");
}

//欢迎界面（暂无问题）
void welcome()
{
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	settextstyle(48, 0, "楷体");
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	outtextxy(86, 41, "欢迎来到学管系统");
	outtextxy(86, 121, "请选择您的身份：");
	DrawImg(135, 213, &student);
	DrawImg(135, 380, &teacher);
	//鼠标操作
	while (1) {
		if (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.x >= 135 && msg.x <= 380 && msg.y >= 213 && msg.y <= 309 && msg.uMsg == WM_LBUTTONDOWN) {
				shows();
				break;
			}
			else if (msg.x >= 135 && msg.x <= 380 && msg.y >= 380 && msg.y <= 476 && msg.uMsg == WM_LBUTTONDOWN) {
				showt();
				break;
			}	
		}
	}
}

//教师登录验证(暂无问题)
void showt()
{
	int flog = 0, j = 0, x = 0;//j判断是否退出,flog判断人数，x跳转位置
	char ch1[50], ch2[50];
	HWND hWind = GetHWnd();//获得窗口句柄
	//背景板
	cleardevice();
	picture();
	putimage(0, 0, &bk);

	FILE* fp = fopen("C:\\Users\\蝈蝈\\Desktop\\教师登录.txt", "r");
	char id[20] = { 0 }, mima[20] = { 0 };
	if (fp == NULL) {
		printf("文件读取失败，系统君将在三秒后强制退出\n");
		Sleep(3000);
		exit(1);
	}
	else {
		InputBox(ch1, 50, "请输入id");
		while (1) {
			fscanf(fp, "%s %s", &id, &mima);
			if (strcmp(ch1, id) == 0) {
				InputBox(ch2, 50, "请输入密码");
				while (1) {
					if (strcmp(ch2, mima) == 0) {
						MessageBox(hWind, "输入正确", NULL, MB_OK);
						facet();
						j = 1;
					}
					else {
						int a = MessageBox(hWind, "密码错误，是否重新输入？", NULL, MB_OKCANCEL);
						if (a == 2) {
							j = 1;
							welcome();
						}
						else InputBox(ch2, 50, "请输入密码");
					}
					if (j == 1) break;
				}
			}
			else {
				flog++;
				x = x + 11;
				fseek(fp, x, SEEK_SET);
			}
			if (flog > m) {
				int a = MessageBox(hWind, "未能找到您的存在(重新输入请选择‘确定’， 退出请选择‘取消’)", NULL, MB_OKCANCEL);
				if (a == 2) {
					j = 1;
					welcome();
				}
				else InputBox(ch1, 50, "请输入id", NULL, MB_OK);
			}
			if (j == 1) break;
		}
	}
}

//教师登录后页面（暂无大碍吧，欸嘿）
void facet()
{
	//底面载入
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	//按钮
	picture();
	DrawImg(86, 72, &puton);
	DrawImg(86, 186, &shanchu);
	DrawImg(86, 300, &change);
	DrawImg(86, 414, &chaxun);
	DrawImg(916, 501, &yi1);
	DrawImg(916, 548, &live1);
	//鼠标操作
	while (1) {
		if (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.x >= 86 && msg.x <= 437 && msg.y >= 72 && msg.y <= 159 && msg.uMsg == WM_LBUTTONDOWN) {
				input();
				break;
			}
			if (msg.x >= 86 && msg.x <= 437 && msg.y >= 186 && msg.y <= 273 && msg.uMsg == WM_LBUTTONDOWN) {
				deve();
				break;
			}
			if (msg.x >= 86 && msg.x <= 437 && msg.y >= 300 && msg.y <= 387 && msg.uMsg == WM_LBUTTONDOWN) {
				chang();
				break;
			}
			if (msg.x >= 86 && msg.x <= 437 && msg.y >= 414 && msg.y <= 501 && msg.uMsg == WM_LBUTTONDOWN) {
				found();
				break;
			}
			if (msg.x >= 916 && msg.x <= 990 && msg.y >= 501 && msg.y <= 530 && msg.uMsg == WM_LBUTTONDOWN) {
				welcome();
				break;
			}
			if (msg.x >= 916 && msg.x <= 990 && msg.y >= 548 && msg.y <= 577 && msg.uMsg == WM_LBUTTONDOWN) {
				exit(1);
			}
		}
	}
}

//向链表录入数据（暂无问题）
void input()
{
	char chin[20], ma[20], en[20];
	HWND hWind = GetHWnd();
	//背景板
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	//链表操作
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	if (headNode == NULL) headNode = newNode;
	else {
		newNode->next = headNode;
		headNode = newNode;
	}
	memset(newNode->st.name, 0, sizeof(newNode->st.name));
	InputBox(newNode->st.name, 20, "姓名");
	InputBox(newNode->st.id, 20, "学号");
	InputBox(chin, 20, "语文");
	InputBox(ma, 20, "数学");
	InputBox(en, 20, "英语");
	stu++;
	//将字符串转化为int类型
	newNode->st.chinese = zhuanhuan(chin);
	newNode->st.math = zhuanhuan(ma);
	newNode->st.english = zhuanhuan(en);
	MessageBox(hWind, "录入成功~", NULL, MB_OK);
	save();
	facet();
}

//存入文件（暂无问题）
void save()
{
	FILE* fp = fopen("C:\\Users\\蝈蝈\\Desktop\\测试.txt", "w+");
	Node* s = headNode;
	while (s != NULL) {
		fprintf(fp, "%s %s %d %d %d\n", s->st.name, s->st.id, s->st.chinese, s->st.math, s->st.english);
		s = s->next;
	}
	fclose(fp);
}

//查询（需要在有链表的情况下才能输出）
void found() {
	//底面
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	//查询实现
	char id2[20];
	HWND hWind = GetHWnd();
	char chin[20], ma[20], en[20], name[20], id[20];

	InputBox(id2, 20, "请输入学号：");
	Node* s = headNode;
	while (1) {
		if (strcmp(id2, s->st.id) == 0) {
			char chin[20], ma[20], en[20];
			sprintf(chin, "%d",s->st.chinese);
			sprintf(ma, "%d", s->st.math);
			sprintf(en, "%d", s->st.english);
			settextstyle(36, 0, "楷体");
			found1(s->st.name, s->st.id, chin, ma, en);
			cout << 6;
			break;
		}
		s = s->next;
		if (s == NULL) {
			int a = MessageBox(hWind, "未能找到，是否重新输入？", NULL, MB_OKCANCEL);
			if (a == 1) {
				InputBox(id2, 20, "请输入学号：");
				s = headNode;
			}
			if (a == 2) {
				facet();
				break;
			}
		}
	}
}

//后(暂无问题)
void found1(char name[20], char id[20], char chinese[20], char math[20], char engilsh[20])
{
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	DrawImg(86, 64, &student1);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	outtextxy(286, 76, name);
	outtextxy(286, 131,id);
	outtextxy(286, 186, chinese);
	outtextxy(286, 241, math);
	outtextxy(286, 296, engilsh);
	//按钮（偷个懒）
	DrawImg(79, 422, &yi);
	DrawImg(259, 422, &live);
	//鼠标操控
	while (1) {
		if (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.x >= 79 && msg.x <= 212 && msg.y >= 422 && msg.y <= 477 && msg.uMsg == WM_LBUTTONDOWN) {
				facet();
				break;
			}
			if (msg.x >= 259 && msg.x <= 428 && msg.y >= 422 && msg.y <= 477 && msg.uMsg == WM_LBUTTONDOWN) {
				welcome();
				break;
			}
		}
	}
}

//删除（感觉还好）
void deve()
{
	//背景板
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	char id2[20];
	HWND hWind = GetHWnd();
	InputBox(id2, 20, "请输入学号");
	Node* s = headNode;
	//如果删除为头结点 
	if (strcmp(id2, s->st.id) == 0) {
		headNode = headNode->next;
		free(s);
		save();
		MessageBox(hWind, "删除成功", NULL, MB_OK);
		facet();
	}
	//如果不是头结点
	Node* s2 = headNode;
	while (s->next != NULL) {
		if (strcmp(s->next->st.id, id2) == 0) {
			s = s2->next;
			s2->next = s2->next->next;
			free(s);
			save();
			MessageBox(hWind, "删除成功", NULL, MB_OK);
			facet();
		}
		s = s->next;
		if (s->next == NULL) break;
	}
	if (s->next == NULL) {
		MessageBox(hWind, "没有找到此人，嘤嘤嘤", NULL, MB_OK);
		facet();
	}
}

//修改
void chang()
{
	//背景板
	cleardevice();
	picture();
	putimage(0, 0, &bk);

	HWND hWind = GetHWnd();
	Node* s = headNode;
	char id2[20], ch[20], chengji[20];
	InputBox(id2, 20, "请输入学号");
	while (1) {
		if (strcmp(s->st.id, id2) == 0) break;
		else {
			s = s->next;
			if (s == NULL) {
				int a = MessageBox(hWind, "未能找到，是否重新输入？", NULL, MB_OKCANCEL);
				if (a == 1) {
					s = headNode;
					InputBox(id2, 20, "请输入学号");
				}
				if (a == 2) {
					facet();
					break;
				}
			}
		}
	}
	InputBox(ch, 20, "请输入学科：");
	while (1) {
		if (strcmp(ch, "语文") != 0 && strcmp(ch, "数学") != 0 && strcmp(ch, "英语") != 0) {
			MessageBox(hWind, "该学科不存在，请重新输入", NULL, MB_OK);
			InputBox(ch, 20, "请输入学科");
		}
		else break;
	}
	if (s != NULL) {
		if (strcmp(ch, "语文") == 0) {
			InputBox(chengji, 20, "成绩");
			s->st.chinese = zhuanhuan(chengji);
		}
		else if (strcmp(ch, "数学") == 0) {
			InputBox(chengji, 20, "成绩");
			s->st.math = zhuanhuan(chengji);
		}
		else if (strcmp(ch, "英语") == 0) {
			InputBox(chengji, 20, "成绩");
			s->st.english = zhuanhuan(chengji);
		}
		MessageBox(hWind, "修改完成", NULL, MB_OK);
		facet();
	}
}

//学生登录(暂无问题)
void shows()
{
	char name[20], id[20], ch1[20], id1[20];
	int chinese, english, math;
	int i = 0, j = 0, x = 0;
	HWND hWind = GetHWnd();//获得窗口句柄

	//背景板
	cleardevice();
	picture();
	putimage(0, 0, &bk);

	//文件操作
	FILE *fp = fopen("C:\\Users\\蝈蝈\\Desktop\\测试.txt", "r");
	if (fp == NULL) {
		MessageBox(hWind, "文件打开失败", NULL, MB_OK);
		exit(1);
	}
	InputBox(ch1, 20, "请输入你名字：");
	while (1) {
		fscanf(fp, "%s %s %d %d %d", &name, &id, &chinese, &english, &math);
		if (strcmp(ch1, name) == 0) {
			InputBox(id1, 20, "请输入你的学号");
			while (1) {
				if (strcmp(id1, id) == 0) {
					faces(name, id, chinese, english, math);
					j = 1;
				}
				else {
					int b = MessageBox(hWind, "学号输入错误，是否重新输入", NULL, MB_OKCANCEL);
					if (b == 1) InputBox(id1, 20, "请输入你的学号：");
					else {
						welcome();
						j = 1;
					}
				}
				if (j == 1) break;
			}
		}
		else { 
			if (strlen(name) - 4 > 0) x += strlen(name) - 4;
			if (chinese > 10) x ++;
			if (math > 10) x ++;
			if (english > 10) x ++;
			x += 16;
			fseek(fp, x, SEEK_SET);
			i++;
		}
		if (i == stu) {
			int a = MessageBox(hWind, "未能找到您，是否重新输入", NULL, MB_OKCANCEL);
			if (a == 1) InputBox(ch1, 20, "请输入你的名字：");
			if (a == 2) {
				welcome();
				j = 1;
			}
			i = 0;
		}
		if (j == 1 ) break;
	}
}

//登录后界面（暂无问题）
void faces(char name[20], char id[20], int chinese, int math, int engilsh)
{
	//int转char
	char chin[20], ma[20], en[20];
	sprintf(chin, "%d", chinese);
	sprintf(ma, "%d", math);
	sprintf(en, "%d", engilsh);
	//界面图形
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	DrawImg(86, 64, &student1);
	//输出字符
	settextstyle(36, 0, "楷体");
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	outtextxy(286, 76, name);
	outtextxy(286, 131, id);
	outtextxy(286, 186, chin);
	outtextxy(286, 241, ma);
	outtextxy(286, 296, en);
	//按钮
	DrawImg(79, 422, &yi);
	DrawImg(259, 422, &live);
	//鼠标操控
	while (1) {
		if (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.x >= 79 && msg.x <= 212 && msg.y >= 422 && msg.y <= 477 && msg.uMsg == WM_LBUTTONDOWN) {
				welcome();
				break;
			}
			if (msg.x >= 259 && msg.x <= 428 && msg.y >= 422 && msg.y <= 477 && msg.uMsg == WM_LBUTTONDOWN) {
				exit(1);
			}
		}
	}

}

//转化（暂无问题）
int zhuanhuan(char num[20])
{
	int i = 0;
	int n = 0, m = 0;
	while (num[i] != '\0') {
		n = num[i] - '0';
		m = m * 10 + n;
		i++;
	}
	return m;
}
