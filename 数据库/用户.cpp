#include"���ݿ�ͷ.h"
struct part *find_student(long long number);
void dingpiaoUI(struct part *p);
void Dsell(struct part *q);
void Dliulan();
void shuru2(FILE *fp);
void yonghupiaochakan1(struct part *q);

void chazhao(struct part *p)
{
	if (p != NULL)
	{
		printf("�˿͵�����: %s\n", p->name);
		printf("�˿͵ĳ�������: %d\n", p->date);
		printf("�˿͵��Ա�:"); if (p->sex) printf("��\n"); else printf("Ů\n");
		cout << "�˿͵���ϵ��ʽ��"; cout << p->dianhua << endl;
		cout << "���룺"; cout << p->mima << endl;
		yonghupiaochakan1(p);
	}
	else printf("û���ҵ�\n");
}
void update(struct part *p)
{
	int flag, flag2 = 1;
	if (p != NULL)
	{
		while (flag2)
		{
			printf("-----------------\n");
			printf("��Ҫ�ı�ʲô��?\n");
			printf("1.�ı�����\n");
			printf("2.�ı��������\n");
			printf("3.�ı��Ա�\n");
			printf("4.�ı���ϵ��ʽ\n");
			printf("5.�ı�����\n");
			printf("6.�ı�����\n");
			printf("0.����\n");
			printf("-----------------\n");
			scanf_s("%d", &flag);
			switch (flag)
			{
			case 1:printf("�����µ�����:"); cin >> p->name; break;
			case 2:printf("�����µĳ�������:"); cin >> p->date; break;
			case 3:printf("�����µ��Ա�:"); cin >> p->sex; break;
			case 4:cout << "�����µ���ϵ��ʽ��"; cin >> p->dianhua; break;
			case 5:cout << "�����µ����룺"; cin >> p->mima; break;
			case 6:printf("�����µ�����:"); cin >> p->name; printf("�����µĳ�������:"); cin >> p->date; printf("�����µ��Ա�:");
				cin >> p->sex; cout << "�����µ���ϵ��ʽ��"; cin >> p->dianhua; cout << "�����µ����룺"; cin >> p->mima; break;
			case 0:flag2 = 0; system("cls"); break;
			default:printf("����Ĵ���\n");
			}
		}
	}
	else printf("û���ҵ�.\n");
}
void yonghu()
{
	bool go = true; int mi,xuanze,flag = 0; char ch; struct part *p=NULL; char mima[20]; long long d;
	while (go)
	{
		cout << "�������֤���룺"; cin >> d; p = find_student(d); if (p == NULL) { cout << "�û������ڣ�" << endl; continue; }
		cout << "�������룺"; cin >> mima; mi = strcmp(mima, p->mima); if (mi != 0) { cout << "�������" << endl; continue; }
		else go = false;
	}
	go = true;
	while (go)
	{
		while (go) {
			printf("-------------------------------------\n");
			printf("1. �鿴��\n");
			printf("2. ���¡�\n");
			cout << "3. ��Ʊ" << endl;
			printf("4. ���������Ϣ��\n");
			printf("5. ��Ʊ��\n");
			printf("0. ������\n");
			printf("-------------------------------------\n");
			cin >>xuanze; ch = getchar();
			switch (xuanze)
			{
			case 1:chazhao(p); break;
			case 2:update(p); break;
			case 3:dingpiaoUI(p); break;
			case 4:Dliulan(); break;
			case 5:Dsell(p); cout << "��Ʊ�ɹ���" << endl; break;
			case 0:go = false; system("cls"); break;
			default:printf("�������\n");
			}
		}
	}
}

void yonghuzhuce(FILE *fp)
{
	cout << "--------------------" << endl;
   shuru2(fp);
   cout << "-----------------------" << endl;
}
