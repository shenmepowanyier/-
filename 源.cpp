//������������ѧ������ʦӦ�÷ֿ���Ū�����
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

void credit(char id[20], char mima[20]);//��ʦ�����֤��ѯ 
void credits(char name[20], char id[20]);//ѧ����ѯ 
void show4(char name[20], char id[20], int chinese, int math, int english);//ѧ���ɼ�չʾ
void out(struct Node* list);//���
void show();//����ӭ
void show1();//��ʦ����
void show2();//ѧ������
void show3();//��֤��ʦ���
void welcome();//��ʦ��¼���� 
void input();//¼�� 
void save();//
void income();//
void find();//��ѯ 
void delevet();//ɾ�� 
void change();//�޸� 

int main()
{

	show();
	input();

	return 0;
}
//��¼ҳ��
void show()
{
	string sf;
	int count = 0;
	printf("ѧ��ϵͳ��ֿΪ�����񣡣���\n");
	printf("����������ʦ����ѧ��������ʦ/ѧ����\n");
	cout << "(ps:�����˳����ֶ������ϽǵĲ��)" << endl;
	printf("(�벻Ҫ������������Ȼϵͳ����޿޵�)\n");
jump:
	cin >> sf;
	if (sf == "��ʦ") {
		system("cls");
		show1();
	}
	else if (sf == "ѧ��") {
		system("cls");
		show2();
	}
	else {
		printf("������\n");
		count++;
		if (count == 3) printf("�벻Ҫ��Ϸϵͳ��\n");
		if (count == 5) {
			printf("ϵͳ���ò������������ˣ������ѡ��ܾ�ͬ�㽻�����������߳�����\n");
			Sleep(3000);
			exit(1);
		}
		goto jump;
	}
}
//��ʦҳ�����
void show1()
{
	char id2[20], mima[20];
	cout << "���������Ľ�ʦ�룺";
	cin >> id2;
	cout << "�������������룺";
	cin >> mima;
	credit(id2, mima);
}

//��ʦ��¼�������� 
void credit(char id[20], char mima[20])
{
	int flog = 0;
	FILE* fp = fopen("C:\\Users\\����\\Desktop\\��ʦ��¼.txt", "r");
	char id2[20] = { 0 }, mima2[20] = { 0 };
	if (fp == NULL) {
		printf("�ļ���ȡʧ�ܣ�ϵͳ�����������ǿ���˳�\n");
		for (int i = 3; i > 0; i--) {
			printf("����ʱ��ʼ��%ds", i);
			Sleep(1000);
		}
		exit(1);
	}
	else {
		while (1) {
			fscanf(fp, "%s %s", &id2, &mima2);
			if (strcmp(id, id2) == 0) {
				if (strcmp(mima, mima2) != 0) {
					printf("���������������������Ŷ~\n");
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
				printf("δ���ҵ����Ĵ��ڣ�����ϵ����Ա�������ڵ�~������¼�롣\n");
				Sleep(2000);
				system("cls");
				show();
			}
		}
	}
	fclose(fp);
}
//������Ľ�ʦҳ��
void welcome()
{
	while (1) {
		char n;

		cout << "--------------------------" << endl;
		cout << "��ӭ�����ɼ���ѯϵͳ,��������Ҫʲô����" << endl;
		cout << "1.¼��ѧ����Ϣ" << endl;
		cout << "2.��ӡȫ��ѧ����Ϣ" << endl;
		cout << "3.ɾ��ѧ����Ϣ" << endl;
		cout << "4.�޸�ѧ����Ϣ" << endl;
		cout << "5.���ҵ���ѧ����Ϣ" << endl;
		cout << "6.�˳�ϵͳ�����ģ����ܣ�ϵͳ���᲻������" << endl;
		cout << "--------------------------" << endl;
		cin >> n;
		switch (n) {
		case '1': input(); break;
		case '2': income(); break;
		case '3': delevet(); break;
		case '4': change(); break;
		case '5': find(); break;
		case '6': system("cls"); show(); break;
		default: printf("ϵͳ�������ظ���������û������ܣ������������߳�ϵͳ\n"), Sleep(2000), system("cls"), show();
		}
	}

}
//��ȷ�����Ľ���
void show4(char name[20], char id[20], double chinese, double math, double english)
{
	string a;
	printf("������%s\t\t\n", name);
	printf("ѧ�ţ�%s\t\t\n", id);
	printf("���ģ�%.2lf\t\t\n", chinese);
	printf("��ѧ��%.2lf\t\t\n", math);
	printf("Ӣ�%.2lf\t\t\n", english);
	printf("��ϵͳ����ʾ�������˳��밴1������ص���ҳ�������룺�����ҵĽ������ţ���\n");
	cin >> a;
	if (a == "1") exit(1);
	else if (a == "�����ҵĽ������ţ�") {
		system("cls");
		show2();
	}
	else {
		printf("������զ��һ���ǡ�ϵͳ������˼���������ؾ��������߳�ϵͳ\n");
		Sleep(3000);
		system("cls");
		printf("�G�٣�������Ц��ϵͳ������˵�������ǰ�������\n");
		Sleep(4000);
		show();
	}
}


//���������Ϣ�������ļ� 
void save()
{
	FILE* fp = fopen("C:\\Users\\����\\Desktop\\����.txt", "w+");
	Node* s = headNode;
	while (s != NULL) {
		fprintf(fp, "%s %s %lf %lf %lf\n", s->st.name, s->st.id, s->st.chinese, s->st.math, s->st.english);
		s = s->next;
	}
	fclose(fp);
}
//��������¼����Ϣ 
void input()
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	if (headNode == NULL) headNode = newNode;
	else {
		newNode->next = headNode;
		headNode = newNode;
	}
	cout << "������ѧ����Ϣ" << endl;

	cout << "����:";
	memset(newNode->st.name, 0, sizeof(newNode->st.name));
	scanf("%s", &newNode->st.name);
	cout << "ѧ��:";
	scanf("%s", &newNode->st.id);
	cout << "����:";
	scanf("%lf", &newNode->st.chinese);
	cout << "��ѧ:";
	scanf("%lf", &newNode->st.math);
	cout << "Ӣ��:";
	scanf("%lf", &newNode->st.english);
	cout << '\n';
	save();
	cout << "¼��ɹ�~" << endl;
	system("pause");
	system("cls");
}
//�����������Ϣ 
void income()
{
	Node* s = headNode;
	while (s != NULL) {
		printf("������%s\n", s->st.name);
		printf("ѧ�ţ�%s\n", s->st.id);
		printf("���ģ�%.2lf\n", s->st.chinese);
		printf("��ѧ��%.2lf\n", s->st.math);
		printf("Ӣ�%.2lf\n", s->st.english);
		printf("\n");
		s = s->next;
	}
	system("pause");
	system("cls");
}
//���ҵ���ѧ����Ϣ 
void find()
{
	char id2[20];
	cout << "������ѧ��ѧ�ţ�" << endl;
	cin >> id2;
	Node* s = headNode;
	while (1) {
		if (strcmp(id2, s->st.id) == 0) {
			printf("������%s\n", s->st.name);
			printf("ѧ�ţ�%s\n", s->st.id);
			printf("���ģ�%.2lf\n", s->st.chinese);
			printf("��ѧ��%.2lf\n", s->st.math);
			printf("Ӣ�%.2lf\n", s->st.english);
			system("pause");
			system("cls");
			break;
		}
		s = s->next;
		if (s == NULL) {
			printf("δ���ҵ���ϢQAQ\n");
			system("pause");
			system("cls");
			break;
		}
	}
}
//ɾ����Ϣ 
void delevet()
{
	char id2[20];
	cout << "������ѧ��ѧ�ţ�" << endl;
	cin >> id2;
	Node* s = headNode;
	//���ɾ��Ϊͷ��� 
	if (strcmp(id2, s->st.id) == 0) {
		headNode = headNode->next;
		free(s);
		save();
		printf("��ɾ��");
		system("pause");
		system("cls");
		return;
	}
	//�������ͷ���
	Node* s2 = headNode;
	while (s->next != NULL) {
		if (strcmp(s->next->st.id, id2) == 0) {
			s = s2->next;
			s2->next = s2->next->next;
			free(s);
			save();
			printf("��ɾ��");
			system("pause");
			system("cls");
			return;
		}
		s = s->next;
		if (s->next == NULL) break;
	}
	if (s->next == NULL) {
		cout << "û���ҵ����ˣ������ӡ�" << endl;
		system("cls");
		return;
	}
}
void change()
{
	Node* s = headNode;
	char id2[20], ch[20];
	cout << "������ѧ��ѧ�ţ�";
	cin >> id2;
	while (1) {
		if (strcmp(s->st.id, id2) == 0) break;
		else {
			s = s->next;
			if (s == NULL) {
				cout << "δ���ҵ�����,���������루�����˳����밴1����";
				cin >> id2;
				if (strcmp(id2, "1") == 0) return;
			}
		}
	}
	cout << "�����������޸����ݣ�";
	cin >> ch;
	while (1) {
		if (strcmp(ch, "����") != 0 && strcmp(ch, "��ѧ") != 0 && strcmp(ch, "Ӣ��") != 0) {
			cout << "�������޸�ѧ���أ����������룺";
			cin >> ch;
		}
		else break;
	}
	while (s != NULL) {
			if (strcmp(ch, "����")) {
				cout << "�������޸ĺ�ķ���:";
				cin >> s->st.chinese;
			}
			else if (strcmp(ch, "��ѧ")) {
				cout << "�������޸ĺ�ķ���:";
				cin >> s->st.math;
			}
			else if (strcmp(ch, "Ӣ��")) {
				cout << "�������޸ĺ�ķ���:";
					cin >> s->st.english;
				}
			cout << "�޸����" << endl;
			system("pause");
			system("cls");
			return;
	}
}
//ѧ��ҳ��
void show2()
{
	char name[20], id[20];

	cout << "����������������";
	cin >> name;
	cout << "����������ѧ�ţ�";
	cin >> id;

	credits(name, id);
}
//ѧ������ 
void credits(char name[20], char id[20])
{
	int flog = 0, count = 0;
	FILE* fp = fopen("C:\\Users\\����\\Desktop\\����.txt", "r");
	char id2[20], name2[20];
	double chinese, math, english;
	if (fp == NULL) {
		printf("�ļ���ȡʧ�ܣ�ϵͳ�����������ǿ���˳�\n");
		for (int i = 3; i > 0; i--) {
			printf("����ʱ��ʼ��%ds", i);
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
					cout << "ѧ�������������~����������" << endl;
					Sleep(2000);
					system("cls");
					show();
				}
			}
			flog++;
			if (flog > stu) {
				cout << "δ���ҵ����Ĵ��ڣ�������������δ¼�룬���Ժ���~" << endl;
				Sleep(2000);
				system("cls");
				show();
			}
		}
	}
	fclose(fp);
}
