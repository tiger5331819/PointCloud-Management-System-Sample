#include"���ݿ�ͷ.h"
#include"�ļ����Ӻ���.h"
list<Hangban>hangban;
list<Yonghu>yonghupiao;

void yonghupiaochakan1(struct part *q)
{
	int flag=0;
	for (list<Yonghu>::iterator p = yonghupiao.begin(); p != yonghupiao.end(); p++)
	{
		if (!strcmp(q->name, p->name))
		{
			cout << "��Ʊ��Ϣ���£�" << endl;
			cout << "��������"<<p->hangban_m << endl;
			cout << "��λΪ��  ";
			cout << "��: " << p->h;
			cout <<"�У�"<< p->l << endl;
			flag = 1;
		}
	}
	if(!flag)cout<<"û�ж�Ʊ��"<<endl;
}


void Dbuy(struct part *q, list<Hangban>::iterator p)
{
	int i, j;
	cout << "������:"; cout << p->hangban_m << endl;
	cout << "�۸�"; cout << p->hangbanp_price << endl;
	cout << "��λ�ţ�" << "����"; cin >> i; cout << "������"; cin >> j;
	if (p->hangbanp_ding[i][j] == 1)
	{
		cout << "����λ�ѱ�����������ѡ��" << endl;
		system("pause");
		return;
	}
	cout << "�Ƿ�ȷ��������Ϊ1����Ϊ0��"; cin >> p->hangbanp_ding[i][j];
	Yonghu one;
	strcpy(one.name, q->name);
	strcpy(one.hangban_m,p->hangban_m);
	one.h = i; one.l = j;
	cout << "��Ʊ�ɹ����������� " << p->hangban_m <<" ��"<<p->hangban_b<<" ����"<<p->hangban_e
		<<" ��λΪ���У� " << one.h << "�У�" << one.l <<"  ����ʱ��Ϊ��  "<<p->hangban_t<< endl;
	yonghupiao.push_back(one);
	system("pause");
}
void Dchazhao1(struct part *q)
{
	char name[50]; bool flag;
	cout << "���뺽������"; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_m))
		{
			cout << "������:"; cout << p->hangban_m << endl;
			cout << "���վ��"; cout << p->hangban_b << endl;
			cout << "�յ�վ��"; cout << p->hangban_e << endl;
			cout << "����ʱ�䣺"; cout << p->hangban_t << endl;
			for (int i = 1; i < hang; i++)
				for (int j = 1; j < lie; j++)
				{
					p->hangban_w[i][j] = j;
					printf(" %d %d", p->hangban_w[i][j], p->hangbanp_ding[i][j]);
					if (j == 4)printf("\n");
				}
			cout << "�Ƿ�Ʊ��(��Ϊ1����Ϊ0)" << endl; cin >> flag;
			if (flag) { Dbuy(q, p); }
			system("cls");
			return;
		}
	}
	cout << "û���ҵ���" << endl;
}
void Dchazhao2(struct part *q)
{
	char name[50]; bool flag;
	cout << "���վ��"; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_b))
		{
			cout << "������:"; cout << p->hangban_m << endl;
			cout << "���վ��"; cout << p->hangban_b << endl;
			cout << "�յ�վ��"; cout << p->hangban_e << endl;
			cout << "����ʱ�䣺"; cout << p->hangban_t << endl;
			for (int i = 1; i < hang; i++)
				for (int j = 1; j < lie; j++)
				{
					p->hangban_w[i][j] = j;
					printf(" %d %d", p->hangban_w[i][j], p->hangbanp_ding[i][j]);
					if (j == 4)printf("\n");
				}
			cout << "�Ƿ�Ʊ��(��Ϊ1����Ϊ0)" << endl; cin >> flag;
			if (flag) { Dbuy(q, p); }
			system("cls");
			return;
		}
	}
	cout << "û���ҵ���" << endl;
}
void Dchazhao3()
{
	char name[50];
	cout << "���վ��"; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_b))
		{
			cout << "������:"; cout << p->hangban_m << endl;
			cout << "���վ��"; cout << p->hangban_b << endl;
			cout << "�յ�վ��"; cout << p->hangban_e << endl;
			cout << "����ʱ�䣺"; cout << p->hangban_t << endl;
			for (int i = 1; i < hang; i++)
				for (int j = 1; j < lie; j++)
				{
					p->hangban_w[i][j] = j;
					printf(" %d %d", p->hangban_w[i][j], p->hangbanp_ding[i][j]);
					if (j == 4)printf("\n");
				}
		}
	}
}
void Dsell(struct part *p)
{
	int i;
	for (list<Yonghu>::iterator q = yonghupiao.begin(); q!= yonghupiao.end(); q++)
	{
		if (!strcmp(p->name, q->name))
		{
        cout << "�Ѷ���������" << q->hangban_m << endl;
		cout << "�Ѷ���λ��" << "�� " << q->h << "�� " << q->l << endl;
		cout << "�Ƿ�ȷ����Ʊ������Ϊ1����Ϊ0��" << endl; cin >> i;
	    if (i)
	       {
		for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
		{
			if (!strcmp(q->hangban_m, p->hangban_m))
				p->hangbanp_ding[q->h][q->l] = 0;
		}
        strcpy(q->name, "01");
		q->h = 0; q->l = 0;
		system("cls");
		return;
		    }
	}
	}
}
void dingpiaoUI(struct part *p)
{
	bool go = true; int xuanze; char ch;
	while (go) {
		printf("-------------------------------------\n");
		printf("1. �Ժ��������ҡ�\n");
		printf("2. �����վ���ҡ�\n");
		printf("0. ������\n");
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:Dchazhao1(p); break;
		case 2:Dchazhao2(p); break;
		case 0:go = false; system("cls"); break;
		default:printf("�������\n");
		}
	}
}
void Dliulan()
{
	bool go = true; int xuanze; char ch;
	void Hshuchu3();
	void Hchazhao();
	while (go) {
		printf("-------------------------------------\n");
		printf("1. �Ժ��������ҡ�\n");
		printf("2. �����վ���ҡ�\n");
		printf("3. �鿴ȫ�����ࡣ\n");
		printf("0. ������\n");
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:Hchazhao(); break;
		case 2:Dchazhao3(); break;
		case 3:Hshuchu3(); break;
		case 0:go = false; system("cls"); break;
		default:printf("�������\n");
		}
	}
}

void Hshuru1(FILE *fp)
{
	Hangban one;
	cout << "���뺽����:"; cin >> one.hangban_m; fprintf(fp, "%s\n", one.hangban_m);
	cout << "�������վ��"; cin >> one.hangban_b; fprintf(fp, "%s\n", one.hangban_b);
	cout << "�����յ�վ��"; cin >> one.hangban_e; fprintf(fp, "%s\n", one.hangban_e);
	cout << "�������ʱ�䣺"; cin >> one.hangban_t; fprintf(fp, "%s\n", one.hangban_t);
	for (int i = 1; i < hang; i++)
		for (int j = 1; j < lie; j++)
		{
			one.hangban_w[i][j] = j;
		}
	hangban.push_back(one);
}
void Hshuru2(FILE *fp)
{
	bool flag=true; Hangban one;
	while (flag)
	{
		cout << "���뺽����:"; cin >> one.hangban_m; fprintf(fp, "%s\n", one.hangban_m);
		cout << "�������վ��"; cin >> one.hangban_b; fprintf(fp, "%s\n", one.hangban_b);
		cout << "�����յ�վ��"; cin >> one.hangban_e; fprintf(fp, "%s\n", one.hangban_e);
		cout << "�������ʱ�䣺"; cin >> one.hangban_t; fprintf(fp, "%s\n", one.hangban_t);
		for (int i = 1; i < hang; i++)
			for (int j = 1; j < lie; j++)
			{
				one.hangban_w[i][j] = j;
			}
		int i; hangban.push_back(one);
		cout << "�Ƿ�������루��Ϊ1����Ϊ0��" << endl; cin >> i;
		if (!i) flag = false;
	}
}
void Hshuru(FILE *fp)
{
	void Hshuru1(FILE*);
	void Hshuru2(FILE*);
	int  flag = 1;
	while (flag) {
		printf("-----------------\n");
		printf("��Ҫ�������뺽����Ϣ��?\n");
		printf("1.��������\n");
		printf("2.������\n");
		printf("0.����\n");
		printf("-----------------\n");
		scanf_s("%d", &flag);
		switch (flag)
		{
		case 1:Hshuru1(fp); break;
		case 2:Hshuru2(fp); break;
		case 0:flag = 0; system("cls"); break;
		default:printf("����Ĵ���.\n");
		}
	}
}
void Hchazhao()
{
	char name[50];
	cout << "���뺽������"; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_m))
		{
			cout << "������:"; cout << p->hangban_m << endl;
			cout << "���վ��"; cout << p->hangban_b << endl;
			cout << "�յ�վ��"; cout << p->hangban_e << endl;
			cout << "����ʱ�䣺"; cout << p->hangban_t << endl;
			return;
		}
	}
	cout << "û���ҵ���" << endl;
}


void Hshuchu1()
{
	int flag = 1;
		for (list<Hangban>::iterator p = hangban.begin(); flag&&p != hangban.end(); p++)
		{
			printf("��������"); cout << p->hangban_m << endl;
			printf("���վ: %s\n", p->hangban_b);
			printf("�յ�վ: %s\n", p->hangban_e);
			printf("����ʱ��:"); cout << p->hangban_t << endl;
			printf("Ʊ�ۣ�"); cout << p->hangbanp_price << endl;
			printf("�Ƿ���һ��?(��Ϊ 1,��Ϊ 0)\n"); scanf_s("%d", &flag);
		}
}
void Hshuchu2()
{
	char name[100];

	cout << "���뺽������"; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin();p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_m))
		{
		printf("��������"); cout << p->hangban_m << endl;
		printf("���վ: %s\n", p->hangban_b);
		printf("�յ�վ: %s\n", p->hangban_e);
		printf("����ʱ��:"); cout << p->hangban_t << endl;
		printf("Ʊ�ۣ�"); cout << p->hangbanp_price << endl;
		return;
	     }

	}
	cout << "û���ҵ���" << endl;
}
void Hshuchu3()
{
	for (list<Hangban>::iterator p = hangban.begin();p != hangban.end(); p++)
	{
		printf("��������"); cout << p->hangban_m << endl;
		printf("���վ: %s\n", p->hangban_b);
		printf("�յ�վ: %s\n", p->hangban_e);
		printf("����ʱ��:"); cout << p->hangban_t << endl;
		printf("Ʊ�ۣ�"); cout << p->hangbanp_price << endl;
		cout << endl;
	}
}
void Hshuchu(FILE *fp)
{
	int  flag = 1;
	while (flag) {
		printf("-----------------\n");
		printf("��Ҫ�������������Ϣ��?\n");
		printf("1.�������\n");
		printf("2.�������\n");
		printf("3.ȫ�����\n");
		printf("0.����\n");
		printf("-----------------\n");
		scanf_s("%d", &flag);
		switch (flag)
		{
		case 1:Hshuchu1(); break;
		case 2:Hshuchu2(); break;
		case 3:Hshuchu3(); break;
		case 0:flag = 0; system("cls"); break;
		default:printf("����Ĵ���.\n");
		}
	}
}
void Hduqu(FILE *fp,FILE *fp2)
{
	bool flag = true;
	while (flag)
	{
		Hangban one; int i;
		i = fscanf(fp, "%s", one.hangban_m); if (i == -1) return;
		for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
		{
			if (!strcmp(one.hangban_m, p->hangban_m)) { cout << "Data is full" << endl; fclose(fp2);return; }
		}
			fscanf(fp, "%s", &one.hangban_b); 
			fscanf(fp2, "%s", &one.hangban_m);
			fscanf(fp, "%s", &one.hangban_e);
			fscanf(fp, "%s", &one.hangban_t);
			fscanf(fp2, "%d", &one.hangbanp_price);
			for (int i = 1; i < hang; i++)
				for (int j = 1; j < lie; j++)
				{
					fscanf(fp2, " %d %d", &one.hangban_w[i][j], &one.hangbanp_ding[i][j]);
				}
			hangban.push_back(one);
		}
	fclose(fp2);
}
void Hupdate()
{
	bool flag2 = true, flag = true; int i, b=0;
	char name[50];
	while(flag)
	{
	cout << "���뺽������"; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_m))
		{
			while (flag2)
			{
				cout << "------------------------" << endl;
				cout << "����Ҫ����ʲô��" << endl;
				cout << "1.�ı亽����" << endl;
				cout << "2.�ı����վ" << endl;
				cout << "3.�ı��յ�վ" << endl;
				cout << "4.�ı����ʱ��" << endl;
				cout << "5.�ı�����" << endl;
				cout << "0.�˳�" << endl;
				cout << "------------------------" << endl;
				cin >> i; b = 1;
				switch (i)
				{
				case 1:cout << "�����º�����:"; cin >> p->hangban_m; break;
				case 2:cout << "���������վ:"; cin >> p->hangban_b; break;
				case 3:cout << "�������յ�վ:"; cin >> p->hangban_e; break;
				case 4:cout << "�����·���ʱ��:"; cin >> p->hangban_t; break;
				case 5:cout << "�����º�����:"; cin >> p->hangban_m; cout << "���������վ:"; cin >> p->hangban_b; cout << "�������յ�վ:"; cin >> p->hangban_e; cout << "�����·���ʱ��:"; cin >> p->hangban_t;
				case 0:flag2 = flag = false; system("cls"); break;
				default:cout << "�������" << endl;
				}
			}
		}

	}
	if(b==0)cout << "û���ҵ���" << endl;
    }
}
void Hupdate2()
{
	FILE  *fp;
	if ((fp = fopen("hangkongshuju.txt", "w+")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		exit(1);
	}
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		fprintf(fp,"%s\n", p->hangban_m);
		fprintf(fp,"%s\n", p->hangban_b);
		fprintf(fp,"%s\n", p->hangban_e);
		fprintf(fp,"%s\n",p->hangban_t);
	}
	fclose(fp);
}
//void Yupdate()
//{
//	ofstream file("yonghupiao.txt");
//	Yonghu one;
//	if (file.is_open())
//	{
//		for (list<Yonghu>::iterator p = yonghupiao.begin(); p != yonghupiao.end(); p++)
//		{
//			file << p->name << endl;
//			file << p->hangban_m << endl;
//			file << p->h << endl;
//			file << p->l << endl;
//		}
//		file.close();
//	}
//}

void shengcheng()
{
	FILE  *fp;
	if ((fp = fopen("piao.txt", "w+")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		exit(1);
	}
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		fprintf(fp, "%s\n", p->hangban_m);
		fprintf(fp, "%d\n", p->hangbanp_price);
		for (int i = 1; i < hang; i++)
			for (int j = 1; j < lie; j++)
			{
				fprintf(fp, " %d %d", p->hangban_w[i][j], p->hangbanp_ding[i][j]);
				if (j == 4)fprintf(fp, "\n");
			}
	}
	fclose(fp);
}
void chaxun()
{
	char name[50];
	cout << "���뺽������"; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_m))
		{
			cout << "������:"; cout << p->hangban_m << endl;
			cout << "�۸�"; cout << p->hangbanp_price << endl;
			for (int i = 1; i < hang; i++)
				for (int j = 1; j < lie; j++)
				{
					printf(" %d %d", p->hangban_w[i][j], p->hangbanp_ding[i][j]);
					if (j == 4)printf( "\n");
				}
			return;
		}
	}
	cout << "û���ҵ���" << endl;
}
void Hwrite()
{
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (p->hangbanp_price > 1) continue;

			p->hangbanp_price = 1;
			for (int i = 1; i < hang; i++)
				for (int j = 1; j < lie; j++)
				{
					p->hangbanp_ding[i][j] = 0;
				}

	}
}
void xiugaizuowei(list<Hangban>::iterator p)
{
	cout << "��ӡ��λ��Ϣ" << endl; int i, j;
	for ( i = 1; i < hang; i++)
		for ( j = 1; j < lie; j++)
		{
			printf( " %d %d", p->hangban_w[i][j], p->hangbanp_ding[i][j]);
			if (j == 4)printf( "\n");
		}
	cout << "�޸���λ�ţ�" << "����"; cin >> i; cout << "������"; cin >> j;
	cout << "�Ƿ��Ѷ�����Ϊ1����Ϊ0��"; cin >> p->hangbanp_ding[i][j];
	cout << "�޸����"<<endl;
}
void Hxiugai()
{
	bool flag2 = true, flag = true; int i, b = 0;
	char name[50];
	while (flag)
	{
		cout << "���뺽������"; cin >> name;
		for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
		{
			if (!strcmp(name, p->hangban_m))
			{
				while (flag2)
				{
					cout << "------------------------" << endl;
					cout << "����Ҫ����ʲô��" << endl;
					cout << "1.�ı�Ʊ��" << endl;
					cout << "2.�޸���λ��Ϣ" << endl;
					cout << "3.�ı�����" << endl;
					cout << "0.�˳�" << endl;
					cout << "------------------------" << endl;
					cin >> i; b = 1;
					switch (i)
					{
					case 1:cout << "�����¼۸�:"; cin >> p->hangbanp_price; break;
					case 2:xiugaizuowei(p); break;
					case 3:cout << "�����¼۸�"; cin >> p->hangbanp_price; xiugaizuowei(p); break;
					case 0:flag2 = flag = false; system("cls"); break;
					default:cout << "�������" << endl;
					}
				}
			}

		}
		if (b == 0)cout << "û���ҵ���" << endl;
	}
}
void Hyonghupiaowrite()
{
	FILE *fp;
	if ((fp = fopen("yonghupiao.txt", "w+")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		exit(1);
	}
	for (list<Yonghu>::iterator p = yonghupiao.begin(); p != yonghupiao.end(); p++)
	{
		if (!strcmp(p->name, "01")) continue;
		fprintf(fp, "%s\n", p->name); //cout << p->name;
		fprintf(fp, "%s\n", p->hangban_m);
		fprintf(fp, "%d\n", p->h);
		fprintf(fp, "%d\n", p->l);
		
	}
	fclose(fp);
}
void Hyonghupiaoduqu(FILE *fp)
{
	bool flag = true;
	while (flag)
	{
		Yonghu one; int i;
		i = fscanf(fp, "%s", one.name);  if (i == -1) return;
		//system("pause");
		for (list<Yonghu>::iterator p = yonghupiao.begin(); p != yonghupiao.end(); p++)
		{
			if (!strcmp(one.name, p->name)) { cout << "Data is full" << endl; fclose(fp); return; }
		}
		fscanf(fp, "%s", &one.hangban_m);
		fscanf(fp, "%d", &one.h);
		fscanf(fp, "%d", &one.l);
		yonghupiao.push_back(one);
	}
	fclose(fp);
}
void Hyonghupiaochakan()
{
	int i=0;
	for (list<Yonghu>::iterator p = yonghupiao.begin(); p != yonghupiao.end(); p++)
	{
		cout << "�û�����" << p->name << endl;
		cout << "��������" << p->hangban_m << endl;
		cout << "��λ �У� " << p->h;
		cout << " �У�  " << p->l << endl;
		cout << endl;
		i = 1; 
	}
	if(!i){ cout << "û������" << endl; }
}

void guanli()
{
	Hwrite();
	bool go = true; int xuanze, flag = 0; char ch;
	while (go)
	{
		cout << "--------------------------------------" << endl;
		cout << "1.���һ�Ʊ" << endl;
		cout << "2.�޸Ļ�Ʊ��Ϣ" << endl;
		cout << "3.�鿴��Ʊ�û���Ϣ" << endl;
		cout << "0.�˳�" << endl;
		cout << "--------------------------------------" << endl;
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:chaxun(); break;
		case 2:Hxiugai(); break;
		case 3:Hyonghupiaochakan(); break;
		case 0:go = false; system("cls"); break;
		default:cout << "�������" << endl;
		}
	}
}
void Hding()
{
	bool go = true; int xuanze, flag = 0; char ch;
	while (go)
	{
		cout << "--------------------------------------" << endl;
		cout << "1.���ɻ�Ʊ���ļ���" << endl;
		cout << "2.��Ʊ����" << endl;
		cout << "0.�˳�" << endl;
		cout << "--------------------------------------" << endl;
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:shengcheng(); cout << "���ɳɹ���" << endl; break;
		case 2:guanli(); break;
		case 0:go = false; shengcheng(); system("cls"); break;
		default:cout << "�������" << endl;
		}
	}
}

void Hangbanx(FILE *fp)
{
	bool go = true; int xuanze, flag = 0; char ch;
	while (go) {
		printf("-------------------------------------\n");
		printf("1. ���ҡ�\n");
		printf("2. ������Ϣ��\n");
		printf("3. ���¡�\n");
		printf("4. �����Ϣ��\n");
		//printf("5. ��ȡ���ݡ�\n");
		cout << "6. ��Ʊ��Ϣ����" << endl;
		printf("0. ������\n");
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:Hchazhao(); break;
		case 2:Hshuru(fp); break;
		case 3:Hupdate(); break;
		case 4:Hshuchu(fp); break;
		//case 5:Hduqu(fp); printf("��ȡ���\n"); break;
		case 6:Hding(); break;
		case 0:go = false; system("cls"); break;
		default:printf("�������\n");
		}
	}
}
