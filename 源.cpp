#pragma warning(disable : 4996)//�ر������ú�������

#include<conio.h>
#include<iostream>
#include<string>
#include<graphics.h>
#include"DrawTransparent.h"

using namespace std;

//����
void picture();//ͼƬ����
void welcome();//��ӭ����
void showt();//��ʦ�����������
void shows();//ѧ����¼����
void facet();//��ʦ�ɹ���¼����
void faces(char name[20], char id[20], int chinese, int math, int engilsh);//ѧ���ɹ���¼����
void save();//����������ݴ����ļ�
void input();//��������¼������
void found();//��ѯ
void deve();//ɾ��
void chang();//�޸�
void found1(char name[20], char id[20], char chinese[20], char math[20], char engilsh[20]);//��ѯ¼����ȷ�����
int zhuanhuan(char num[20]);//��char����ת��Ϊint����

//ͼƬ
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

//���
MOUSEMSG msg;

//��ʦ������ѧ������
int m = 2;
int stu = 0;

//ǳǳ��һ������
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
	//���ô����뱳��
	initgraph(1000, 600);
	setbkcolor(WHITE);
	cleardevice();
	welcome();

	getchar();
	closegraph();

	return 0;
}

//����ͼƬ
void picture()
{
	loadimage(&bk, "./��ҳ��.png", 1000, 600);
	loadimage(&teacher, "./��ʦ.png");
	loadimage(&student, "./ѧ��.png");
	loadimage(&student1, "./ѧ���ɼ�����.png");
	loadimage(&live, "./�˳�.png");
	loadimage(&yi, "./��ҳ.png");
	loadimage(&change, "./�޸�.png");
	loadimage(&shanchu, "./ɾ��.png");
	loadimage(&chaxun, "./��ѯ.png");
	loadimage(&puton, "./¼��.png");
	loadimage(&live1, "./�˳�t.png");
	loadimage(&yi1, "./��ҳt.png");
}

//��ӭ���棨�������⣩
void welcome()
{
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	settextstyle(48, 0, "����");
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	outtextxy(86, 41, "��ӭ����ѧ��ϵͳ");
	outtextxy(86, 121, "��ѡ��������ݣ�");
	DrawImg(135, 213, &student);
	DrawImg(135, 380, &teacher);
	//������
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

//��ʦ��¼��֤(��������)
void showt()
{
	int flog = 0, j = 0, x = 0;//j�ж��Ƿ��˳�,flog�ж�������x��תλ��
	char ch1[50], ch2[50];
	HWND hWind = GetHWnd();//��ô��ھ��
	//������
	cleardevice();
	picture();
	putimage(0, 0, &bk);

	FILE* fp = fopen("C:\\Users\\����\\Desktop\\��ʦ��¼.txt", "r");
	char id[20] = { 0 }, mima[20] = { 0 };
	if (fp == NULL) {
		printf("�ļ���ȡʧ�ܣ�ϵͳ�����������ǿ���˳�\n");
		Sleep(3000);
		exit(1);
	}
	else {
		InputBox(ch1, 50, "������id");
		while (1) {
			fscanf(fp, "%s %s", &id, &mima);
			if (strcmp(ch1, id) == 0) {
				InputBox(ch2, 50, "����������");
				while (1) {
					if (strcmp(ch2, mima) == 0) {
						MessageBox(hWind, "������ȷ", NULL, MB_OK);
						facet();
						j = 1;
					}
					else {
						int a = MessageBox(hWind, "��������Ƿ��������룿", NULL, MB_OKCANCEL);
						if (a == 2) {
							j = 1;
							welcome();
						}
						else InputBox(ch2, 50, "����������");
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
				int a = MessageBox(hWind, "δ���ҵ����Ĵ���(����������ѡ��ȷ������ �˳���ѡ��ȡ����)", NULL, MB_OKCANCEL);
				if (a == 2) {
					j = 1;
					welcome();
				}
				else InputBox(ch1, 50, "������id", NULL, MB_OK);
			}
			if (j == 1) break;
		}
	}
}

//��ʦ��¼��ҳ�棨���޴󰭰ɣ��G�٣�
void facet()
{
	//��������
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	//��ť
	picture();
	DrawImg(86, 72, &puton);
	DrawImg(86, 186, &shanchu);
	DrawImg(86, 300, &change);
	DrawImg(86, 414, &chaxun);
	DrawImg(916, 501, &yi1);
	DrawImg(916, 548, &live1);
	//������
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

//������¼�����ݣ��������⣩
void input()
{
	char chin[20], ma[20], en[20];
	HWND hWind = GetHWnd();
	//������
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	//�������
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	if (headNode == NULL) headNode = newNode;
	else {
		newNode->next = headNode;
		headNode = newNode;
	}
	memset(newNode->st.name, 0, sizeof(newNode->st.name));
	InputBox(newNode->st.name, 20, "����");
	InputBox(newNode->st.id, 20, "ѧ��");
	InputBox(chin, 20, "����");
	InputBox(ma, 20, "��ѧ");
	InputBox(en, 20, "Ӣ��");
	stu++;
	//���ַ���ת��Ϊint����
	newNode->st.chinese = zhuanhuan(chin);
	newNode->st.math = zhuanhuan(ma);
	newNode->st.english = zhuanhuan(en);
	MessageBox(hWind, "¼��ɹ�~", NULL, MB_OK);
	save();
	facet();
}

//�����ļ����������⣩
void save()
{
	FILE* fp = fopen("C:\\Users\\����\\Desktop\\����.txt", "w+");
	Node* s = headNode;
	while (s != NULL) {
		fprintf(fp, "%s %s %d %d %d\n", s->st.name, s->st.id, s->st.chinese, s->st.math, s->st.english);
		s = s->next;
	}
	fclose(fp);
}

//��ѯ����Ҫ�������������²��������
void found() {
	//����
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	//��ѯʵ��
	char id2[20];
	HWND hWind = GetHWnd();
	char chin[20], ma[20], en[20], name[20], id[20];

	InputBox(id2, 20, "������ѧ�ţ�");
	Node* s = headNode;
	while (1) {
		if (strcmp(id2, s->st.id) == 0) {
			char chin[20], ma[20], en[20];
			sprintf(chin, "%d",s->st.chinese);
			sprintf(ma, "%d", s->st.math);
			sprintf(en, "%d", s->st.english);
			settextstyle(36, 0, "����");
			found1(s->st.name, s->st.id, chin, ma, en);
			cout << 6;
			break;
		}
		s = s->next;
		if (s == NULL) {
			int a = MessageBox(hWind, "δ���ҵ����Ƿ��������룿", NULL, MB_OKCANCEL);
			if (a == 1) {
				InputBox(id2, 20, "������ѧ�ţ�");
				s = headNode;
			}
			if (a == 2) {
				facet();
				break;
			}
		}
	}
}

//��(��������)
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
	//��ť��͵������
	DrawImg(79, 422, &yi);
	DrawImg(259, 422, &live);
	//���ٿ�
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

//ɾ�����о����ã�
void deve()
{
	//������
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	char id2[20];
	HWND hWind = GetHWnd();
	InputBox(id2, 20, "������ѧ��");
	Node* s = headNode;
	//���ɾ��Ϊͷ��� 
	if (strcmp(id2, s->st.id) == 0) {
		headNode = headNode->next;
		free(s);
		save();
		MessageBox(hWind, "ɾ���ɹ�", NULL, MB_OK);
		facet();
	}
	//�������ͷ���
	Node* s2 = headNode;
	while (s->next != NULL) {
		if (strcmp(s->next->st.id, id2) == 0) {
			s = s2->next;
			s2->next = s2->next->next;
			free(s);
			save();
			MessageBox(hWind, "ɾ���ɹ�", NULL, MB_OK);
			facet();
		}
		s = s->next;
		if (s->next == NULL) break;
	}
	if (s->next == NULL) {
		MessageBox(hWind, "û���ҵ����ˣ�������", NULL, MB_OK);
		facet();
	}
}

//�޸�
void chang()
{
	//������
	cleardevice();
	picture();
	putimage(0, 0, &bk);

	HWND hWind = GetHWnd();
	Node* s = headNode;
	char id2[20], ch[20], chengji[20];
	InputBox(id2, 20, "������ѧ��");
	while (1) {
		if (strcmp(s->st.id, id2) == 0) break;
		else {
			s = s->next;
			if (s == NULL) {
				int a = MessageBox(hWind, "δ���ҵ����Ƿ��������룿", NULL, MB_OKCANCEL);
				if (a == 1) {
					s = headNode;
					InputBox(id2, 20, "������ѧ��");
				}
				if (a == 2) {
					facet();
					break;
				}
			}
		}
	}
	InputBox(ch, 20, "������ѧ�ƣ�");
	while (1) {
		if (strcmp(ch, "����") != 0 && strcmp(ch, "��ѧ") != 0 && strcmp(ch, "Ӣ��") != 0) {
			MessageBox(hWind, "��ѧ�Ʋ����ڣ�����������", NULL, MB_OK);
			InputBox(ch, 20, "������ѧ��");
		}
		else break;
	}
	if (s != NULL) {
		if (strcmp(ch, "����") == 0) {
			InputBox(chengji, 20, "�ɼ�");
			s->st.chinese = zhuanhuan(chengji);
		}
		else if (strcmp(ch, "��ѧ") == 0) {
			InputBox(chengji, 20, "�ɼ�");
			s->st.math = zhuanhuan(chengji);
		}
		else if (strcmp(ch, "Ӣ��") == 0) {
			InputBox(chengji, 20, "�ɼ�");
			s->st.english = zhuanhuan(chengji);
		}
		MessageBox(hWind, "�޸����", NULL, MB_OK);
		facet();
	}
}

//ѧ����¼(��������)
void shows()
{
	char name[20], id[20], ch1[20], id1[20];
	int chinese, english, math;
	int i = 0, j = 0, x = 0;
	HWND hWind = GetHWnd();//��ô��ھ��

	//������
	cleardevice();
	picture();
	putimage(0, 0, &bk);

	//�ļ�����
	FILE *fp = fopen("C:\\Users\\����\\Desktop\\����.txt", "r");
	if (fp == NULL) {
		MessageBox(hWind, "�ļ���ʧ��", NULL, MB_OK);
		exit(1);
	}
	InputBox(ch1, 20, "�����������֣�");
	while (1) {
		fscanf(fp, "%s %s %d %d %d", &name, &id, &chinese, &english, &math);
		if (strcmp(ch1, name) == 0) {
			InputBox(id1, 20, "���������ѧ��");
			while (1) {
				if (strcmp(id1, id) == 0) {
					faces(name, id, chinese, english, math);
					j = 1;
				}
				else {
					int b = MessageBox(hWind, "ѧ����������Ƿ���������", NULL, MB_OKCANCEL);
					if (b == 1) InputBox(id1, 20, "���������ѧ�ţ�");
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
			int a = MessageBox(hWind, "δ���ҵ������Ƿ���������", NULL, MB_OKCANCEL);
			if (a == 1) InputBox(ch1, 20, "������������֣�");
			if (a == 2) {
				welcome();
				j = 1;
			}
			i = 0;
		}
		if (j == 1 ) break;
	}
}

//��¼����棨�������⣩
void faces(char name[20], char id[20], int chinese, int math, int engilsh)
{
	//intתchar
	char chin[20], ma[20], en[20];
	sprintf(chin, "%d", chinese);
	sprintf(ma, "%d", math);
	sprintf(en, "%d", engilsh);
	//����ͼ��
	cleardevice();
	picture();
	putimage(0, 0, &bk);
	DrawImg(86, 64, &student1);
	//����ַ�
	settextstyle(36, 0, "����");
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	outtextxy(286, 76, name);
	outtextxy(286, 131, id);
	outtextxy(286, 186, chin);
	outtextxy(286, 241, ma);
	outtextxy(286, 296, en);
	//��ť
	DrawImg(79, 422, &yi);
	DrawImg(259, 422, &live);
	//���ٿ�
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

//ת�����������⣩
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
