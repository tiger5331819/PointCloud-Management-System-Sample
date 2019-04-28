#include"数据库头.h"
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
		printf("乘客的姓名: %s\n", p->name);
		printf("乘客的出生日期: %d\n", p->date);
		printf("乘客的性别:"); if (p->sex) printf("男\n"); else printf("女\n");
		cout << "乘客的联系方式："; cout << p->dianhua << endl;
		cout << "密码："; cout << p->mima << endl;
		yonghupiaochakan1(p);
	}
	else printf("没有找到\n");
}
void update(struct part *p)
{
	int flag, flag2 = 1;
	if (p != NULL)
	{
		while (flag2)
		{
			printf("-----------------\n");
			printf("想要改变什么呢?\n");
			printf("1.改变名字\n");
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
void yonghu()
{
	bool go = true; int mi,xuanze,flag = 0; char ch; struct part *p=NULL; char mima[20]; long long d;
	while (go)
	{
		cout << "输入身份证号码："; cin >> d; p = find_student(d); if (p == NULL) { cout << "用户不存在！" << endl; continue; }
		cout << "输入密码："; cin >> mima; mi = strcmp(mima, p->mima); if (mi != 0) { cout << "密码错误！" << endl; continue; }
		else go = false;
	}
	go = true;
	while (go)
	{
		while (go) {
			printf("-------------------------------------\n");
			printf("1. 查看。\n");
			printf("2. 更新。\n");
			cout << "3. 订票" << endl;
			printf("4. 浏览航班信息。\n");
			printf("5. 退票。\n");
			printf("0. 结束。\n");
			printf("-------------------------------------\n");
			cin >>xuanze; ch = getchar();
			switch (xuanze)
			{
			case 1:chazhao(p); break;
			case 2:update(p); break;
			case 3:dingpiaoUI(p); break;
			case 4:Dliulan(); break;
			case 5:Dsell(p); cout << "退票成功！" << endl; break;
			case 0:go = false; system("cls"); break;
			default:printf("错误代码\n");
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
