#include"数据库头.h"
#include"文件链接函数.h"
list<Hangban>hangban;
list<Yonghu>yonghupiao;

void yonghupiaochakan1(struct part *q)
{
	int flag=0;
	for (list<Yonghu>::iterator p = yonghupiao.begin(); p != yonghupiao.end(); p++)
	{
		if (!strcmp(q->name, p->name))
		{
			cout << "订票信息如下：" << endl;
			cout << "航班名："<<p->hangban_m << endl;
			cout << "座位为：  ";
			cout << "行: " << p->h;
			cout <<"列："<< p->l << endl;
			flag = 1;
		}
	}
	if(!flag)cout<<"没有订票。"<<endl;
}


void Dbuy(struct part *q, list<Hangban>::iterator p)
{
	int i, j;
	cout << "航班名:"; cout << p->hangban_m << endl;
	cout << "价格："; cout << p->hangbanp_price << endl;
	cout << "座位号：" << "行数"; cin >> i; cout << "列数："; cin >> j;
	if (p->hangbanp_ding[i][j] == 1)
	{
		cout << "此座位已被购买，请重新选择！" << endl;
		system("pause");
		return;
	}
	cout << "是否确定？（是为1，否为0）"; cin >> p->hangbanp_ding[i][j];
	Yonghu one;
	strcpy(one.name, q->name);
	strcpy(one.hangban_m,p->hangban_m);
	one.h = i; one.l = j;
	cout << "订票成功！航班名： " << p->hangban_m <<" 从"<<p->hangban_b<<" 飞往"<<p->hangban_e
		<<" 座位为：行： " << one.h << "列：" << one.l <<"  飞行时间为：  "<<p->hangban_t<< endl;
	yonghupiao.push_back(one);
	system("pause");
}
void Dchazhao1(struct part *q)
{
	char name[50]; bool flag;
	cout << "输入航班名："; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_m))
		{
			cout << "航班名:"; cout << p->hangban_m << endl;
			cout << "起飞站："; cout << p->hangban_b << endl;
			cout << "终点站："; cout << p->hangban_e << endl;
			cout << "飞行时间："; cout << p->hangban_t << endl;
			for (int i = 1; i < hang; i++)
				for (int j = 1; j < lie; j++)
				{
					p->hangban_w[i][j] = j;
					printf(" %d %d", p->hangban_w[i][j], p->hangbanp_ding[i][j]);
					if (j == 4)printf("\n");
				}
			cout << "是否订票？(是为1，否为0)" << endl; cin >> flag;
			if (flag) { Dbuy(q, p); }
			system("cls");
			return;
		}
	}
	cout << "没有找到！" << endl;
}
void Dchazhao2(struct part *q)
{
	char name[50]; bool flag;
	cout << "起飞站："; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_b))
		{
			cout << "航班名:"; cout << p->hangban_m << endl;
			cout << "起飞站："; cout << p->hangban_b << endl;
			cout << "终点站："; cout << p->hangban_e << endl;
			cout << "飞行时间："; cout << p->hangban_t << endl;
			for (int i = 1; i < hang; i++)
				for (int j = 1; j < lie; j++)
				{
					p->hangban_w[i][j] = j;
					printf(" %d %d", p->hangban_w[i][j], p->hangbanp_ding[i][j]);
					if (j == 4)printf("\n");
				}
			cout << "是否订票？(是为1，否为0)" << endl; cin >> flag;
			if (flag) { Dbuy(q, p); }
			system("cls");
			return;
		}
	}
	cout << "没有找到！" << endl;
}
void Dchazhao3()
{
	char name[50];
	cout << "起飞站："; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_b))
		{
			cout << "航班名:"; cout << p->hangban_m << endl;
			cout << "起飞站："; cout << p->hangban_b << endl;
			cout << "终点站："; cout << p->hangban_e << endl;
			cout << "飞行时间："; cout << p->hangban_t << endl;
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
        cout << "已定航班名：" << q->hangban_m << endl;
		cout << "已定座位：" << "行 " << q->h << "列 " << q->l << endl;
		cout << "是否确定退票？（是为1，否为0）" << endl; cin >> i;
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
		printf("1. 以航班名查找。\n");
		printf("2. 以起飞站查找。\n");
		printf("0. 结束。\n");
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:Dchazhao1(p); break;
		case 2:Dchazhao2(p); break;
		case 0:go = false; system("cls"); break;
		default:printf("错误代码\n");
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
		printf("1. 以航班名查找。\n");
		printf("2. 以起飞站查找。\n");
		printf("3. 查看全部航班。\n");
		printf("0. 结束。\n");
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:Hchazhao(); break;
		case 2:Dchazhao3(); break;
		case 3:Hshuchu3(); break;
		case 0:go = false; system("cls"); break;
		default:printf("错误代码\n");
		}
	}
}

void Hshuru1(FILE *fp)
{
	Hangban one;
	cout << "输入航班名:"; cin >> one.hangban_m; fprintf(fp, "%s\n", one.hangban_m);
	cout << "输入起飞站："; cin >> one.hangban_b; fprintf(fp, "%s\n", one.hangban_b);
	cout << "输入终点站："; cin >> one.hangban_e; fprintf(fp, "%s\n", one.hangban_e);
	cout << "输入飞行时间："; cin >> one.hangban_t; fprintf(fp, "%s\n", one.hangban_t);
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
		cout << "输入航班名:"; cin >> one.hangban_m; fprintf(fp, "%s\n", one.hangban_m);
		cout << "输入起飞站："; cin >> one.hangban_b; fprintf(fp, "%s\n", one.hangban_b);
		cout << "输入终点站："; cin >> one.hangban_e; fprintf(fp, "%s\n", one.hangban_e);
		cout << "输入飞行时间："; cin >> one.hangban_t; fprintf(fp, "%s\n", one.hangban_t);
		for (int i = 1; i < hang; i++)
			for (int j = 1; j < lie; j++)
			{
				one.hangban_w[i][j] = j;
			}
		int i; hangban.push_back(one);
		cout << "是否继续输入（是为1，否为0）" << endl; cin >> i;
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
		printf("想要怎样输入航班信息呢?\n");
		printf("1.单个输入\n");
		printf("2.逐步输入\n");
		printf("0.结束\n");
		printf("-----------------\n");
		scanf_s("%d", &flag);
		switch (flag)
		{
		case 1:Hshuru1(fp); break;
		case 2:Hshuru2(fp); break;
		case 0:flag = 0; system("cls"); break;
		default:printf("错误的代码.\n");
		}
	}
}
void Hchazhao()
{
	char name[50];
	cout << "输入航班名："; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_m))
		{
			cout << "航班名:"; cout << p->hangban_m << endl;
			cout << "起飞站："; cout << p->hangban_b << endl;
			cout << "终点站："; cout << p->hangban_e << endl;
			cout << "飞行时间："; cout << p->hangban_t << endl;
			return;
		}
	}
	cout << "没有找到！" << endl;
}


void Hshuchu1()
{
	int flag = 1;
		for (list<Hangban>::iterator p = hangban.begin(); flag&&p != hangban.end(); p++)
		{
			printf("航班名："); cout << p->hangban_m << endl;
			printf("起飞站: %s\n", p->hangban_b);
			printf("终点站: %s\n", p->hangban_e);
			printf("飞行时间:"); cout << p->hangban_t << endl;
			printf("票价："); cout << p->hangbanp_price << endl;
			printf("是否下一个?(是为 1,否为 0)\n"); scanf_s("%d", &flag);
		}
}
void Hshuchu2()
{
	char name[100];

	cout << "输入航班名："; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin();p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_m))
		{
		printf("航班名："); cout << p->hangban_m << endl;
		printf("起飞站: %s\n", p->hangban_b);
		printf("终点站: %s\n", p->hangban_e);
		printf("飞行时间:"); cout << p->hangban_t << endl;
		printf("票价："); cout << p->hangbanp_price << endl;
		return;
	     }

	}
	cout << "没有找到！" << endl;
}
void Hshuchu3()
{
	for (list<Hangban>::iterator p = hangban.begin();p != hangban.end(); p++)
	{
		printf("航班名："); cout << p->hangban_m << endl;
		printf("起飞站: %s\n", p->hangban_b);
		printf("终点站: %s\n", p->hangban_e);
		printf("飞行时间:"); cout << p->hangban_t << endl;
		printf("票价："); cout << p->hangbanp_price << endl;
		cout << endl;
	}
}
void Hshuchu(FILE *fp)
{
	int  flag = 1;
	while (flag) {
		printf("-----------------\n");
		printf("想要怎样输出航班信息呢?\n");
		printf("1.单个输出\n");
		printf("2.查找输出\n");
		printf("3.全部输出\n");
		printf("0.结束\n");
		printf("-----------------\n");
		scanf_s("%d", &flag);
		switch (flag)
		{
		case 1:Hshuchu1(); break;
		case 2:Hshuchu2(); break;
		case 3:Hshuchu3(); break;
		case 0:flag = 0; system("cls"); break;
		default:printf("错误的代码.\n");
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
	cout << "输入航班名："; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_m))
		{
			while (flag2)
			{
				cout << "------------------------" << endl;
				cout << "你想要更改什么：" << endl;
				cout << "1.改变航班名" << endl;
				cout << "2.改变起飞站" << endl;
				cout << "3.改变终点站" << endl;
				cout << "4.改变飞行时间" << endl;
				cout << "5.改变所有" << endl;
				cout << "0.退出" << endl;
				cout << "------------------------" << endl;
				cin >> i; b = 1;
				switch (i)
				{
				case 1:cout << "输入新航班名:"; cin >> p->hangban_m; break;
				case 2:cout << "输入新起飞站:"; cin >> p->hangban_b; break;
				case 3:cout << "输入新终点站:"; cin >> p->hangban_e; break;
				case 4:cout << "输入新飞行时间:"; cin >> p->hangban_t; break;
				case 5:cout << "输入新航班名:"; cin >> p->hangban_m; cout << "输入新起飞站:"; cin >> p->hangban_b; cout << "输入新终点站:"; cin >> p->hangban_e; cout << "输入新飞行时间:"; cin >> p->hangban_t;
				case 0:flag2 = flag = false; system("cls"); break;
				default:cout << "错误代码" << endl;
				}
			}
		}

	}
	if(b==0)cout << "没有找到！" << endl;
    }
}
void Hupdate2()
{
	FILE  *fp;
	if ((fp = fopen("hangkongshuju.txt", "w+")) == NULL)
	{
		printf("不能打开文件\n");
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
		printf("不能打开文件\n");
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
	cout << "输入航班名："; cin >> name;
	for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
	{
		if (!strcmp(name, p->hangban_m))
		{
			cout << "航班名:"; cout << p->hangban_m << endl;
			cout << "价格："; cout << p->hangbanp_price << endl;
			for (int i = 1; i < hang; i++)
				for (int j = 1; j < lie; j++)
				{
					printf(" %d %d", p->hangban_w[i][j], p->hangbanp_ding[i][j]);
					if (j == 4)printf( "\n");
				}
			return;
		}
	}
	cout << "没有找到！" << endl;
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
	cout << "打印座位信息" << endl; int i, j;
	for ( i = 1; i < hang; i++)
		for ( j = 1; j < lie; j++)
		{
			printf( " %d %d", p->hangban_w[i][j], p->hangbanp_ding[i][j]);
			if (j == 4)printf( "\n");
		}
	cout << "修改座位号：" << "行数"; cin >> i; cout << "列数："; cin >> j;
	cout << "是否已定（是为1，否为0）"; cin >> p->hangbanp_ding[i][j];
	cout << "修改完成"<<endl;
}
void Hxiugai()
{
	bool flag2 = true, flag = true; int i, b = 0;
	char name[50];
	while (flag)
	{
		cout << "输入航班名："; cin >> name;
		for (list<Hangban>::iterator p = hangban.begin(); p != hangban.end(); p++)
		{
			if (!strcmp(name, p->hangban_m))
			{
				while (flag2)
				{
					cout << "------------------------" << endl;
					cout << "你想要更改什么：" << endl;
					cout << "1.改变票价" << endl;
					cout << "2.修改座位信息" << endl;
					cout << "3.改变所有" << endl;
					cout << "0.退出" << endl;
					cout << "------------------------" << endl;
					cin >> i; b = 1;
					switch (i)
					{
					case 1:cout << "输入新价格:"; cin >> p->hangbanp_price; break;
					case 2:xiugaizuowei(p); break;
					case 3:cout << "输入新价格："; cin >> p->hangbanp_price; xiugaizuowei(p); break;
					case 0:flag2 = flag = false; system("cls"); break;
					default:cout << "错误代码" << endl;
					}
				}
			}

		}
		if (b == 0)cout << "没有找到！" << endl;
	}
}
void Hyonghupiaowrite()
{
	FILE *fp;
	if ((fp = fopen("yonghupiao.txt", "w+")) == NULL)
	{
		printf("不能打开文件\n");
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
		cout << "用户名：" << p->name << endl;
		cout << "航班名：" << p->hangban_m << endl;
		cout << "座位 行： " << p->h;
		cout << " 列：  " << p->l << endl;
		cout << endl;
		i = 1; 
	}
	if(!i){ cout << "没有数据" << endl; }
}

void guanli()
{
	Hwrite();
	bool go = true; int xuanze, flag = 0; char ch;
	while (go)
	{
		cout << "--------------------------------------" << endl;
		cout << "1.查找机票" << endl;
		cout << "2.修改机票信息" << endl;
		cout << "3.查看订票用户信息" << endl;
		cout << "0.退出" << endl;
		cout << "--------------------------------------" << endl;
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:chaxun(); break;
		case 2:Hxiugai(); break;
		case 3:Hyonghupiaochakan(); break;
		case 0:go = false; system("cls"); break;
		default:cout << "错误代码" << endl;
		}
	}
}
void Hding()
{
	bool go = true; int xuanze, flag = 0; char ch;
	while (go)
	{
		cout << "--------------------------------------" << endl;
		cout << "1.生成机票于文件中" << endl;
		cout << "2.机票管理" << endl;
		cout << "0.退出" << endl;
		cout << "--------------------------------------" << endl;
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:shengcheng(); cout << "生成成功！" << endl; break;
		case 2:guanli(); break;
		case 0:go = false; shengcheng(); system("cls"); break;
		default:cout << "错误代码" << endl;
		}
	}
}

void Hangbanx(FILE *fp)
{
	bool go = true; int xuanze, flag = 0; char ch;
	while (go) {
		printf("-------------------------------------\n");
		printf("1. 查找。\n");
		printf("2. 输入信息。\n");
		printf("3. 更新。\n");
		printf("4. 输出信息。\n");
		//printf("5. 读取数据。\n");
		cout << "6. 机票信息管理" << endl;
		printf("0. 结束。\n");
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar();
		switch (xuanze)
		{
		case 1:Hchazhao(); break;
		case 2:Hshuru(fp); break;
		case 3:Hupdate(); break;
		case 4:Hshuchu(fp); break;
		//case 5:Hduqu(fp); printf("读取完成\n"); break;
		case 6:Hding(); break;
		case 0:go = false; system("cls"); break;
		default:printf("错误代码\n");
		}
	}
}
