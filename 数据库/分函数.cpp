#include"���ݿ�ͷ.h"
#include"�ļ����Ӻ���.h"
void yonghupiaochakan1(struct part *q);


class Hangbang
{
public:
	char n[20];
	char mima[20];
}Hangbang1;
struct part *student = NULL;
struct part *find_student(long long number)
{
	struct part *p;
	for (p = student; p != NULL&&number>p->number; p = p->next);
	if (p != NULL&&number == p->number) return p;
	return NULL;
};
void duqu(FILE *fp)
{
	struct part *i, *o; bool flag = true; struct part *new_p;  int mmm=1; char name[100];
	while (flag)
	{
		new_p = (struct part*)malloc(sizeof(struct part));
		if (new_p == NULL) { printf("data is full\n"); return; }
		fscanf(fp, "%lld", &new_p->number);
		if (new_p->number < 11) {  free(new_p); return; }
		for (i = student, o = NULL; i != NULL&&new_p->number > i->number; o = i, i = i->next);
		if (i != NULL&&new_p->number == i->number) { printf("�����Ѿ�����.\n"); free(new_p); return; }
		fscanf(fp, "%s", &new_p->name);
		fscanf(fp, "%d",&new_p->date);
		fscanf(fp, "%d", &new_p->sex);
		fscanf(fp, "%lld",&new_p->dianhua);
		fscanf(fp, "%s", &new_p->mima);
		new_p->next = i;
		if (o == NULL) {
			student = new_p;
		}
		else o->next = new_p;

	}
}

void shuru(FILE *fp)
{
	bool flag = true; int number;
	while (flag) {
		printf("-----------------\n");
		printf("��Ҫ��������˿���Ϣ��\n");
		printf("1.˳������\n");
		printf("2.��������\n");
		printf("3.�������\n");
		printf("0.�˳�\n");
		cin >> number;
		switch (number)
		{
			void shuru1(FILE*); void shuru2(FILE*); void shuru3(FILE *);
		case 1:shuru1(fp); break;
		case 2:shuru2(fp); break;
		case 3:shuru3(fp); break;
		case 0:flag = false; system("cls"); break;
		default:printf("����Ĵ���\n");
		}
	}
}
void shuru3(FILE *fp)
{
	struct part *i, *o; bool flag = true; long long w; struct part *new_p;
	while (flag)
	{
		new_p = (struct part*)malloc(sizeof(struct part));
		if (new_p == NULL) { printf("data is full\n"); return; }
		printf("���������֤��:"); cin >> w;
		new_p->number = (long long)w;
		fprintf(fp,"%lld\n",new_p->number);
		for (i = student, o = NULL; i != NULL&&new_p->number > i->number; o = i, i = i->next);
		if (i != NULL&&new_p->number == i->number) { printf("�����Ѿ�����.\n"); free(new_p); return; }
		printf("��������:");
		cin >> new_p->name; fprintf(fp, "%s\n", new_p->name);
		printf("�����������:"); scanf_s("%d", &new_p->date); fprintf(fp,"%d\n",new_p->date);
		printf("�����Ա�:(������1,Ů���� 0)"); scanf_s("%d", &new_p->sex); fprintf(fp,"%d\n", new_p->sex);
		cout << "������ϵ��ʽ��"; cin >> new_p->dianhua; fprintf(fp, "%lld\n", new_p->dianhua);
		cout << "�������룺"; cin >> new_p->mima; fprintf(fp, "%s\n", new_p->mima);
		new_p->next = i;
		if (o == NULL) student = new_p;
		else o->next = new_p;
		printf("�Ƿ��������?(��Ϊ 1,��Ϊ 0)\n"); cin >> flag;
		printf("-----------------\n");
	}
}
void shuru2(FILE *fp)
{
	struct part *i, *o; long long number; struct part *p; printf("���������֤��\n"); cin >> number;
	p = find_student(number);
	if (p!=NULL) { printf("data is full\n"); return; }
	p = (struct part*)malloc(sizeof(struct part));
	if (p == NULL) { printf("data is full\n"); return; }
	p->number = number; fprintf(fp, "%lld\n", p->number);
	for (i = student, o = NULL; i != NULL&&p->number > i->number; o = i, i = i->next);
	printf("��������:");
	cin >> p->name; fprintf(fp, "%s\n", p->name);
	printf("�����������:"); scanf_s("%d", &p->date); fprintf(fp, "%d\n", p->date);
	printf("�����Ա�:(������1,Ů���� 0)"); cin>>p->sex; fprintf(fp, "%d\n", p->sex);
	cout << "������ϵ��ʽ��"; cin >> p->dianhua;; fprintf(fp, "%lld\n", p->dianhua);
	cout << "�������룺"; cin >> p->mima; fprintf(fp, "%s\n", p->mima);
	printf("-----------------\n");
	p->next = i;
	if (o == NULL) student = p;
	else o->next = p;
}
void shuru1(FILE *fp)
{
	struct part *i, *o; bool flag = true; long long w; struct part *new_p; printf("���������֤��\n"); cin >> w;
	while (flag)
	{
		new_p = (struct part*)malloc(sizeof(struct part));
		if (new_p == NULL) { printf("data is full\n"); return; }//����һ���µĿռ䲢�ж��Ƿ����ɹ�

		new_p->number=(long long)w; fprintf(fp, "%lld\n", new_p->number);
		for (i = student, o = NULL; i != NULL&&new_p->number > i->number; o = i, i = i->next);
		if (i != NULL&&new_p->number == i->number)
		{ printf("�����Ѿ�����.\n"); free(new_p); return; }//��ָ��ָ����������һ�����жϼ���������³�Ա�Ƿ�;ɳ�Ա�ظ�������ظ����ͷſռ�
		printf("�������֤���룺"); cout << w << endl; w++;
		printf("��������:");
		cin >> new_p->name; fprintf(fp, "%s\n", new_p->name);
		printf("�����������:"); scanf_s("%d", &new_p->date); fprintf(fp, "%d\n", new_p->date);
		printf("�����Ա�:(������1,Ů���� 0)"); cin>>new_p->dianhua; fprintf(fp, "%d\n", new_p->dianhua);
		cout << "������ϵ��ʽ��"; cin >> new_p->dianhua;; fprintf(fp, "%lld\n", new_p->dianhua);
		cout << "�������룺"; cin >> new_p->mima; fprintf(fp, "%s\n", new_p->mima);
		new_p->next = i;//���³�Ա��nextָ��ָ��i->next
		if (o == NULL) student = new_p;
		else o->next = new_p;//�ж��³�Ա�Ƿ����ӳɹ������ӳɹ��ͼ���������һ���³�Ա
		printf("�Ƿ��������?(��Ϊ 1,��Ϊ 0)\n");cin>>flag;
		printf("-----------------\n");
	}
}
void chazhao()
{
	long long number; struct part *p;
	printf("�������֤����:");
	scanf_s("%lld", &number);
	p = find_student(number);
	if (p != NULL)
	{
		printf("�˿͵�����: %s\n", p->name);
		printf("�˿͵ĳ�������: %d\n", p->date);
		printf("�˿͵��Ա�:"); if (p->sex) printf("��\n"); else printf("Ů\n");
		cout << "�˿͵���ϵ��ʽ��"; cout<< p->dianhua<<endl;
		cout << "���룺"; cout << p->mima<<endl;
		 yonghupiaochakan1(p);
	}
	else printf("û���ҵ�\n");
}
void update2()
{
	FILE *fp; struct part *p;
	if ((fp = fopen("shuju.txt", "w+")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		exit(1);
	}
	for (p = student; p != NULL; p = p->next)
	{
		fprintf(fp, "%lld\n", p->number);
		 fprintf(fp, "%s\n", p->name);
			fprintf(fp, "%d\n", p->date);
		fprintf(fp, "%d\n", p->sex);
		fprintf(fp, "%lld\n", p->dianhua);
		fprintf(fp, "%s\n", p->mima);
	}
	fclose(fp);
}
void update(FILE *fp)
{
	int flag, flag2 = 1; struct part *p; long long number;
	printf("�������֤����:"); scanf_s("%lld", &number);
	p = find_student(number);
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
void shuchu(struct part *p)
{
	void shuchu1(struct part*);
	void shuchu2(struct part*);
	void shuchu3(struct part*);
	int  flag = 1;
	while (flag) {
		printf("-----------------\n");
		printf("��Ҫ��������˿���Ϣ��?\n");
		printf("1.�������\n");
		printf("2.�������\n");
		printf("3.ȫ�����\n");
		printf("0.����\n");
		printf("-----------------\n");
		scanf_s("%d", &flag);
		switch (flag)
		{
		case 1:shuchu1((struct part *)p); break;
		case 2:shuchu2((struct part *)p); break;
		case 3:shuchu3((struct part *)p); break;
		case 0:flag = 0; system("cls"); break;
		default:printf("����Ĵ���.\n");
		}
	}

}
void shuchu1(struct part *p)
{
	 int flag = 1;
	p = student; int i = 1;
	while (p != NULL&&flag)
	{
		printf("�˿͵����֤���룺"); cout << p->number<< endl;
		printf("�˿͵�����: %s\n", p->name);
		printf("�˿͵ĳ�������: %d\n", p->date);
		printf("�˿͵��Ա�:"); if (p->sex) printf("��\n"); else printf("Ů\n");
		cout << "�˿͵���ϵ��ʽ��"; cout<< p->dianhua<<endl;
		cout << "����Ϊ��"; cout << p->mima << endl;
		yonghupiaochakan1(p);
		p = p->next; i++;
		printf("�Ƿ���һ��?(��Ϊ 1,��Ϊ 0)\n"); scanf_s("%d", &flag);
		cout << endl;
	}
	if (p = NULL) printf("������\n");
}
void shuchu3(struct part *p)
{
	for (p = student; p != NULL; p = p->next)
	{
		printf("�˿͵����֤���룺"); cout << p->number << endl;
		printf("�˿͵�����: %s\n", p->name);
		printf("�˿͵ĳ�������: %d\n", p->date);
		printf("�˿͵��Ա�:"); if (p->sex) printf("��\n"); else printf("Ů\n");
		cout << "�˿͵���ϵ��ʽ��"; cout << p->dianhua<<endl;
		cout << "����Ϊ��"; cout << p->mima << endl;
		yonghupiaochakan1(p);
		cout << endl;
	}
}
void shuchu2(struct part *p)
{
	long long number;
	printf("�������֤����:"); scanf_s("%lld", &number);
	p = find_student(number);
	if (p != NULL)
	{
		printf("�˿͵�����: %s\n", p->name);
		printf("�˿͵ĳ�������: %d\n", p->date);
		printf("�˿͵��Ա�:"); if (p->dianhua) printf("��\n"); else printf("Ů\n");
		cout << "�˿͵���ϵ��ʽ��"; cout<< p->dianhua<<endl;
		cout << "����Ϊ��"; cout << p->mima << endl;
		yonghupiaochakan1(p);
		cout << endl;
	}
	else printf("������.\n");
}
void Hangband(FILE *fp,FILE *fp2)
{
	strcpy(Hangbang1.n, "00000");
	strcpy(Hangbang1.mima, "00000");
	bool go = true; int mi, n, flag = 0; char ch;  char mima[20], d[20]; int xuanze;
	while (go)
	{
		cout << "�����˺ţ�"; cin >> d; n = strcmp(d, Hangbang1.n); if (n != 0) { cout << "�û������ڣ�" << endl; }
		else go = false;
	}
	go = true;
	while (go)
	{
	cout << "�������룺"; cin >> mima; mi = strcmp(mima, Hangbang1.mima); if (mi != 0) { cout << "�������" << endl; }
	else go = false;
}
	go = true;
	while (go)
	{
		printf("-------------------------------------\n");
		cout << "1.�û�����" << endl;
		cout << "2.���չ���" << endl;
		cout << "0.�˳�" << endl;
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
			void Hangband1(FILE *);
			void Hangbanx(FILE *);
		case 1:Hangband1(fp); break;
		case 2:Hangbanx(fp2); break;
		case 0:go = 0; system("cls"); break;
		default:printf("�������\n");
		}
	}
}
void Hangband1(FILE *fp)
{
	bool go = true; int xuanze; char ch;
	while (go) {
		printf("-------------------------------------\n");
		printf("1. ���ҡ�\n");
		printf("2. ������Ϣ��\n");
		printf("3. ���¡�\n");
		printf("4. �����Ϣ��\n");
		//printf("5. ��ȡ���ݡ�\n");
		printf("0. ������\n");
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:chazhao(); break;
		case 2:shuru(fp); break;
		case 3:update(fp); break;
		case 4:shuchu((struct part *)fp); break;
		//case 5:duqu(fp); printf("��ȡ���\n"); break;
		case 0:go = false; system("cls"); break;
		default:printf("�������\n");
		}
	}
}
