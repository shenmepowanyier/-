//关于在我心里学生和老师应该分开来弄这件事
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<windows.h>
#include<stdlib.h>

using namespace std;

int stu = 2;

struct student {
	char name[20] = { 0 };
	char id[20] = { 0 };
	double chinese, math, english;
};

struct Node {
	struct student st;
	struct Node* next;
};

Node* headNode = NULL;

void credit(char id[20], char mima[20]);//老师身份验证查询 
void credits(char name[20], char id[20]);//学生查询 
void show4(char name[20], char id[20], int chinese, int math, int english);//学生成绩展示
void out(struct Node* list);//输出
void show();//主欢迎
void show1();//老师界面
void show2();//学生界面
void show3();//验证老师身份
void welcome();//教师登录界面 
void input();//录入 
void save();//
void income();//
void find();//查询 
void delevet();//删除 
void change();//修改 

int main()
{

	show();
	input();

	return 0;
}
//登录页面
void show()
{
	string sf;
	int count = 0;
	printf("学分系统诚挚为您服务！！！\n");
	printf("请问您是老师还是学生？（老师/学生）\n");
	cout << "(ps:如需退出请手动点右上角的叉叉)" << endl;
	printf("(请不要输入其它，不然系统君会哭哭的)\n");
jump:
	cin >> sf;
	if (sf == "老师") {
		system("cls");
		show1();
	}
	else if (sf == "学生") {
		system("cls");
		show2();
	}
	else {
		printf("嘤嘤嘤\n");
		count++;
		if (count == 3) printf("请不要调戏系统君\n");
		if (count == 5) {
			printf("系统觉得不能与你愉快玩耍，于是选择拒绝同你交流，并把你踢出程序\n");
			Sleep(3000);
			exit(1);
		}
		goto jump;
	}
}
//教师页面解锁
void show1()
{
	char id2[20], mima[20];
	cout << "请输入您的教师码：";
	cin >> id2;
	cout << "请输入您的密码：";
	cin >> mima;
	credit(id2, mima);
}

//教师登录密码输入 
void credit(char id[20], char mima[20])
{
	int flog = 0;
	FILE* fp = fopen("C:\\Users\\蝈蝈\\Desktop\\教师登录.txt", "r");
	char id2[20] = { 0 }, mima2[20] = { 0 };
	if (fp == NULL) {
		printf("文件读取失败，系统君将在三秒后强制退出\n");
		for (int i = 3; i > 0; i--) {
			printf("倒计时开始：%ds", i);
			Sleep(1000);
		}
		exit(1);
	}
	else {
		while (1) {
			fscanf(fp, "%s %s", &id2, &mima2);
			if (strcmp(id, id2) == 0) {
				if (strcmp(mima, mima2) != 0) {
					printf("密码输入错误，请重新输入哦~\n");
					Sleep(2000);
					system("cls");
					show1();
				}
				else {
					system("cls");
					welcome();
					break;
				}
			}
			flog++;
			if (flog > stu) {
				printf("未能找到您的存在，请联系管理员（不存在滴~）将您录入。\n");
				Sleep(2000);
				system("cls");
				show();
			}
		}
	}
	fclose(fp);
}
//解锁后的教师页面
void welcome()
{
	while (1) {
		char n;

		cout << "--------------------------" << endl;
		cout << "欢迎来到成绩查询系统,请问您需要什么服务？" << endl;
		cout << "1.录入学生信息" << endl;
		cout << "2.打印全部学生信息" << endl;
		cout << "3.删除学生信息" << endl;
		cout << "4.修改学生信息" << endl;
		cout << "5.查找单个学生信息" << endl;
		cout << "6.退出系统（伤心，难受，系统君舍不得您）" << endl;
		cout << "--------------------------" << endl;
		cin >> n;
		switch (n) {
		case '1': input(); break;
		case '2': income(); break;
		case '3': delevet(); break;
		case '4': change(); break;
		case '5': find(); break;
		case '6': system("cls"); show(); break;
		default: printf("系统君生气地告诉您：我没这个功能！！！并把你踢出系统\n"), Sleep(2000), system("cls"), show();
		}
	}

}
//正确输入后的界面
void show4(char name[20], char id[20], double chinese, double math, double english)
{
	string a;
	printf("姓名：%s\t\t\n", name);
	printf("学号：%s\t\t\n", id);
	printf("语文：%.2lf\t\t\n", chinese);
	printf("数学：%.2lf\t\t\n", math);
	printf("英语：%.2lf\t\t\n", english);
	printf("（系统君提示：如需退出请按1，如需回到主页面请输入：艾因我的娇娇老婆！）\n");
	cin >> a;
	if (a == "1") exit(1);
	else if (a == "艾因我的娇娇老婆！") {
		system("cls");
		show2();
	}
	else {
		printf("你这人咋个一身反骨。系统君陷入思考，并愉快地决定把你踢出系统\n");
		Sleep(3000);
		system("cls");
		printf("欸嘿，开个玩笑。系统君如是说，但还是把你踢了\n");
		Sleep(4000);
		show();
	}
}


//将输入的信息保存入文件 
void save()
{
	FILE* fp = fopen("C:\\Users\\蝈蝈\\Desktop\\测试.txt", "w+");
	Node* s = headNode;
	while (s != NULL) {
		fprintf(fp, "%s %s %lf %lf %lf\n", s->st.name, s->st.id, s->st.chinese, s->st.math, s->st.english);
		s = s->next;
	}
	fclose(fp);
}
//向链表内录入信息 
void input()
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	if (headNode == NULL) headNode = newNode;
	else {
		newNode->next = headNode;
		headNode = newNode;
	}
	cout << "请输入学生信息" << endl;

	cout << "姓名:";
	memset(newNode->st.name, 0, sizeof(newNode->st.name));
	scanf("%s", &newNode->st.name);
	cout << "学号:";
	scanf("%s", &newNode->st.id);
	cout << "语文:";
	scanf("%lf", &newNode->st.chinese);
	cout << "数学:";
	scanf("%lf", &newNode->st.math);
	cout << "英语:";
	scanf("%lf", &newNode->st.english);
	cout << '\n';
	save();
	cout << "录入成功~" << endl;
	system("pause");
	system("cls");
}
//输出所有人信息 
void income()
{
	Node* s = headNode;
	while (s != NULL) {
		printf("姓名：%s\n", s->st.name);
		printf("学号：%s\n", s->st.id);
		printf("语文：%.2lf\n", s->st.chinese);
		printf("数学：%.2lf\n", s->st.math);
		printf("英语：%.2lf\n", s->st.english);
		printf("\n");
		s = s->next;
	}
	system("pause");
	system("cls");
}
//查找单个学生信息 
void find()
{
	char id2[20];
	cout << "请输入学生学号：" << endl;
	cin >> id2;
	Node* s = headNode;
	while (1) {
		if (strcmp(id2, s->st.id) == 0) {
			printf("姓名：%s\n", s->st.name);
			printf("学号：%s\n", s->st.id);
			printf("语文：%.2lf\n", s->st.chinese);
			printf("数学：%.2lf\n", s->st.math);
			printf("英语：%.2lf\n", s->st.english);
			system("pause");
			system("cls");
			break;
		}
		s = s->next;
		if (s == NULL) {
			printf("未能找到信息QAQ\n");
			system("pause");
			system("cls");
			break;
		}
	}
}
//删除信息 
void delevet()
{
	char id2[20];
	cout << "请输入学生学号：" << endl;
	cin >> id2;
	Node* s = headNode;
	//如果删除为头结点 
	if (strcmp(id2, s->st.id) == 0) {
		headNode = headNode->next;
		free(s);
		save();
		printf("已删除");
		system("pause");
		system("cls");
		return;
	}
	//如果不是头结点
	Node* s2 = headNode;
	while (s->next != NULL) {
		if (strcmp(s->next->st.id, id2) == 0) {
			s = s2->next;
			s2->next = s2->next->next;
			free(s);
			save();
			printf("已删除");
			system("pause");
			system("cls");
			return;
		}
		s = s->next;
		if (s->next == NULL) break;
	}
	if (s->next == NULL) {
		cout << "没有找到此人，嘤嘤嘤。" << endl;
		system("cls");
		return;
	}
}
void change()
{
	Node* s = headNode;
	char id2[20], ch[20];
	cout << "请输入学生学号：";
	cin >> id2;
	while (1) {
		if (strcmp(s->st.id, id2) == 0) break;
		else {
			s = s->next;
			if (s == NULL) {
				cout << "未能找到此人,请重新输入（如需退出，请按1）：";
				cin >> id2;
				if (strcmp(id2, "1") == 0) return;
			}
		}
	}
	cout << "请输入所需修改内容：";
	cin >> ch;
	while (1) {
		if (strcmp(ch, "语文") != 0 && strcmp(ch, "数学") != 0 && strcmp(ch, "英语") != 0) {
			cout << "不存在修改学科呢，请重新输入：";
			cin >> ch;
		}
		else break;
	}
	while (s != NULL) {
			if (strcmp(ch, "语文")) {
				cout << "请输入修改后的分数:";
				cin >> s->st.chinese;
			}
			else if (strcmp(ch, "数学")) {
				cout << "请输入修改后的分数:";
				cin >> s->st.math;
			}
			else if (strcmp(ch, "英语")) {
				cout << "请输入修改后的分数:";
					cin >> s->st.english;
				}
			cout << "修改完成" << endl;
			system("pause");
			system("cls");
			return;
	}
}
//学生页面
void show2()
{
	char name[20], id[20];

	cout << "请输入您的姓名：";
	cin >> name;
	cout << "请输入您的学号：";
	cin >> id;

	credits(name, id);
}
//学生查找 
void credits(char name[20], char id[20])
{
	int flog = 0, count = 0;
	FILE* fp = fopen("C:\\Users\\蝈蝈\\Desktop\\测试.txt", "r");
	char id2[20], name2[20];
	double chinese, math, english;
	if (fp == NULL) {
		printf("文件读取失败，系统君将在三秒后强制退出\n");
		for (int i = 3; i > 0; i--) {
			printf("倒计时开始：%ds", i);
			Sleep(1000);
		}
		exit(1);
	}
	else {
		while (1) {
			fscanf(fp, "%s %s %lf %lf %lf", &name2, &id2, &chinese, &math, &english);
			if (strcmp(name, name2) == 0) {
				if (strcmp(id, id2) == 0) {
					show4(name, id, chinese, math, english);
					break;
				}
				count++;
				if (count > stu) {
					cout << "学号输入错误呢亲~请重新输入" << endl;
					Sleep(2000);
					system("cls");
					show();
				}
			}
			flog++;
			if (flog > stu) {
				cout << "未能找到您的存在，姓名输入出错或还未录入，请稍后尝试~" << endl;
				Sleep(2000);
				system("cls");
				show();
			}
		}
	}
	fclose(fp);
}
