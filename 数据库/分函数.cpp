#include"数据库头.h"
#include"文件链接函数.h"
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
		if (i != NULL&&new_p->number == i->number) { printf("数据已经有了.\n"); free(new_p); return; }
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
		printf("想要怎样输入乘客信息？\n");
		printf("1.顺序输入\n");
		printf("2.单个输入\n");
		printf("3.逐个输入\n");
		printf("0.退出\n");
		cin >> number;
		switch (number)
		{
			void shuru1(FILE*); void shuru2(FILE*); void shuru3(FILE *);
		case 1:shuru1(fp); break;
		case 2:shuru2(fp); break;
		case 3:shuru3(fp); break;
		case 0:flag = false; system("cls"); break;
		default:printf("错误的代码\n");
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
		printf("请输入身份证号:"); cin >> w;
		new_p->number = (long long)w;
		fprintf(fp,"%lld\n",new_p->number);
		for (i = student, o = NULL; i != NULL&&new_p->number > i->number; o = i, i = i->next);
		if (i != NULL&&new_p->number == i->number) { printf("数据已经有了.\n"); free(new_p); return; }
		printf("输入名字:");
		cin >> new_p->name; fprintf(fp, "%s\n", new_p->name);
		printf("输入出生日期:"); scanf_s("%d", &new_p->date); fprintf(fp,"%d\n",new_p->date);
		printf("输入性别:(男生是1,女生是 0)"); scanf_s("%d", &new_p->sex); fprintf(fp,"%d\n", new_p->sex);
		cout << "输入联系方式："; cin >> new_p->dianhua; fprintf(fp, "%lld\n", new_p->dianhua);
		cout << "输入密码："; cin >> new_p->mima; fprintf(fp, "%s\n", new_p->mima);
		new_p->next = i;
		if (o == NULL) student = new_p;
		else o->next = new_p;
		printf("是否继续输入?(是为 1,否为 0)\n"); cin >> flag;
		printf("-----------------\n");
	}
}
void shuru2(FILE *fp)
{
	struct part *i, *o; long long number; struct part *p; printf("请输入身份证号\n"); cin >> number;
	p = find_student(number);
	if (p!=NULL) { printf("data is full\n"); return; }
	p = (struct part*)malloc(sizeof(struct part));
	if (p == NULL) { printf("data is full\n"); return; }
	p->number = number; fprintf(fp, "%lld\n", p->number);
	for (i = student, o = NULL; i != NULL&&p->number > i->number; o = i, i = i->next);
	printf("输入名字:");
	cin >> p->name; fprintf(fp, "%s\n", p->name);
	printf("输入出生日期:"); scanf_s("%d", &p->date); fprintf(fp, "%d\n", p->date);
	printf("输入性别:(男生是1,女生是 0)"); cin>>p->sex; fprintf(fp, "%d\n", p->sex);
	cout << "输入联系方式："; cin >> p->dianhua;; fprintf(fp, "%lld\n", p->dianhua);
	cout << "输入密码："; cin >> p->mima; fprintf(fp, "%s\n", p->mima);
	printf("-----------------\n");
	p->next = i;
	if (o == NULL) student = p;
	else o->next = p;
}
void shuru1(FILE *fp)
{
	struct part *i, *o; bool flag = true; long long w; struct part *new_p; printf("请输入身份证号\n"); cin >> w;
	while (flag)
	{
		new_p = (struct part*)malloc(sizeof(struct part));
		if (new_p == NULL) { printf("data is full\n"); return; }//建立一个新的空间并判断是否建立成功

		new_p->number=(long long)w; fprintf(fp, "%lld\n", new_p->number);
		for (i = student, o = NULL; i != NULL&&new_p->number > i->number; o = i, i = i->next);
		if (i != NULL&&new_p->number == i->number)
		{ printf("数据已经有了.\n"); free(new_p); return; }//将指针指向链表的最后一个并判断即将加入的新成员是否和旧成员重复，如果重复就释放空间
		printf("输入身份证号码："); cout << w << endl; w++;
		printf("输入名字:");
		cin >> new_p->name; fprintf(fp, "%s\n", new_p->name);
		printf("输入出生日期:"); scanf_s("%d", &new_p->date); fprintf(fp, "%d\n", new_p->date);
		printf("输入性别:(男生是1,女生是 0)"); cin>>new_p->dianhua; fprintf(fp, "%d\n", new_p->dianhua);
		cout << "输入联系方式："; cin >> new_p->dianhua;; fprintf(fp, "%lld\n", new_p->dianhua);
		cout << "输入密码："; cin >> new_p->mima; fprintf(fp, "%s\n", new_p->mima);
		new_p->next = i;//让新成员的next指针指向i->next
		if (o == NULL) student = new_p;
		else o->next = new_p;//判断新成员是否连接成功，连接成功就继续连接下一个新成员
		printf("是否继续输入?(是为 1,否为 0)\n");cin>>flag;
		printf("-----------------\n");
	}
}
void chazhao()
{
	long long number; struct part *p;
	printf("输入身份证号码:");
	scanf_s("%lld", &number);
	p = find_student(number);
	if (p != NULL)
	{
		printf("乘客的名字: %s\n", p->name);
		printf("乘客的出生日期: %d\n", p->date);
		printf("乘客的性别:"); if (p->sex) printf("男\n"); else printf("女\n");
		cout << "乘客的联系方式："; cout<< p->dianhua<<endl;
		cout << "密码："; cout << p->mima<<endl;
		 yonghupiaochakan1(p);
	}
	else printf("没有找到\n");
}
void update2()
{
	FILE *fp; struct part *p;
	if ((fp = fopen("shuju.txt", "w+")) == NULL)
	{
		printf("不能打开文件\n");
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
	printf("输入身份证号码:"); scanf_s("%lld", &number);
	p = find_student(number);
	if (p != NULL)
	{
		while (flag2)
		{
			printf("-----------------\n");
			printf("想要改变什么呢?\n");
			printf("1.改变姓名\n");
			printf("2.改变出生日期\n");
			printf("3.改变性别\n");
			printf("4.改变联系方式\n");
			printf("5.改变密码\n");
			printf("6.改变所有\n");
			printf("0.结束\n");
			printf("-----------------\n");
			scanf_s("%d", &flag);
			switch (flag)
			{
			case 1:printf("输入新的姓名:"); cin >> p->name; break;
			case 2:printf("输入新的出生日期:"); cin >> p->date; break;
			case 3:printf("输入新的性别:"); cin >> p->sex; break;
			case 4:cout << "输入新的联系方式："; cin >> p->dianhua; break;
			case 5:cout << "输入新的密码："; cin >> p->mima; break;
			case 6:printf("输入新的姓名:"); cin >> p->name; printf("输入新的出生日期:"); cin >> p->date; printf("输入新的性别:");
				cin >> p->sex; cout << "输入新的联系方式："; cin >> p->dianhua; cout << "输入新的密码："; cin >> p->mima; break;
			case 0:flag2 = 0; system("cls"); break;
			default:printf("错误的代码\n");
			}
		}
	}
	else printf("没有找到.\n");

}
void shuchu(struct part *p)
{
	void shuchu1(struct part*);
	void shuchu2(struct part*);
	void shuchu3(struct part*);
	int  flag = 1;
	while (flag) {
		printf("-----------------\n");
		printf("想要怎样输出乘客信息呢?\n");
		printf("1.单个输出\n");
		printf("2.查找输出\n");
		printf("3.全部输出\n");
		printf("0.结束\n");
		printf("-----------------\n");
		scanf_s("%d", &flag);
		switch (flag)
		{
		case 1:shuchu1((struct part *)p); break;
		case 2:shuchu2((struct part *)p); break;
		case 3:shuchu3((struct part *)p); break;
		case 0:flag = 0; system("cls"); break;
		default:printf("错误的代码.\n");
		}
	}

}
void shuchu1(struct part *p)
{
	 int flag = 1;
	p = student; int i = 1;
	while (p != NULL&&flag)
	{
		printf("乘客的身份证号码："); cout << p->number<< endl;
		printf("乘客的姓名: %s\n", p->name);
		printf("乘客的出生日期: %d\n", p->date);
		printf("乘客的性别:"); if (p->sex) printf("男\n"); else printf("女\n");
		cout << "乘客的联系方式："; cout<< p->dianhua<<endl;
		cout << "密码为："; cout << p->mima << endl;
		yonghupiaochakan1(p);
		p = p->next; i++;
		printf("是否下一个?(是为 1,否为 0)\n"); scanf_s("%d", &flag);
		cout << endl;
	}
	if (p = NULL) printf("不存在\n");
}
void shuchu3(struct part *p)
{
	for (p = student; p != NULL; p = p->next)
	{
		printf("乘客的身份证号码："); cout << p->number << endl;
		printf("乘客的姓名: %s\n", p->name);
		printf("乘客的出生日期: %d\n", p->date);
		printf("乘客的性别:"); if (p->sex) printf("男\n"); else printf("女\n");
		cout << "乘客的联系方式："; cout << p->dianhua<<endl;
		cout << "密码为："; cout << p->mima << endl;
		yonghupiaochakan1(p);
		cout << endl;
	}
}
void shuchu2(struct part *p)
{
	long long number;
	printf("输入身份证号码:"); scanf_s("%lld", &number);
	p = find_student(number);
	if (p != NULL)
	{
		printf("乘客的姓名: %s\n", p->name);
		printf("乘客的出生日期: %d\n", p->date);
		printf("乘客的性别:"); if (p->dianhua) printf("男\n"); else printf("女\n");
		cout << "乘客的联系方式："; cout<< p->dianhua<<endl;
		cout << "密码为："; cout << p->mima << endl;
		yonghupiaochakan1(p);
		cout << endl;
	}
	else printf("不存在.\n");
}
void Hangband(FILE *fp,FILE *fp2)
{
	strcpy(Hangbang1.n, "00000");
	strcpy(Hangbang1.mima, "00000");
	bool go = true; int mi, n, flag = 0; char ch;  char mima[20], d[20]; int xuanze;
	while (go)
	{
		cout << "输入账号："; cin >> d; n = strcmp(d, Hangbang1.n); if (n != 0) { cout << "用户不存在！" << endl; }
		else go = false;
	}
	go = true;
	while (go)
	{
	cout << "输入密码："; cin >> mima; mi = strcmp(mima, Hangbang1.mima); if (mi != 0) { cout << "密码错误！" << endl; }
	else go = false;
}
	go = true;
	while (go)
	{
		printf("-------------------------------------\n");
		cout << "1.用户管理" << endl;
		cout << "2.航空管理" << endl;
		cout << "0.退出" << endl;
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
			void Hangband1(FILE *);
			void Hangbanx(FILE *);
		case 1:Hangband1(fp); break;
		case 2:Hangbanx(fp2); break;
		case 0:go = 0; system("cls"); break;
		default:printf("错误代码\n");
		}
	}
}
void Hangband1(FILE *fp)
{
	bool go = true; int xuanze; char ch;
	while (go) {
		printf("-------------------------------------\n");
		printf("1. 查找。\n");
		printf("2. 输入信息。\n");
		printf("3. 更新。\n");
		printf("4. 输出信息。\n");
		//printf("5. 读取数据。\n");
		printf("0. 结束。\n");
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:chazhao(); break;
		case 2:shuru(fp); break;
		case 3:update(fp); break;
		case 4:shuchu((struct part *)fp); break;
		//case 5:duqu(fp); printf("读取完成\n"); break;
		case 0:go = false; system("cls"); break;
		default:printf("错误代码\n");
		}
	}
}
