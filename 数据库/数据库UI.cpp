#include"数据库头.h"
#include"文件链接函数.h"
FILE *fp,*fp1;
void yonghu();
void Hangband(FILE *fp,FILE *fp1);
void duqu(FILE *fp);
void Hduqu(FILE *fp,FILE *);
void Hupdate2();
void update2();
void shengcheng();
void yonghuzhuce(FILE *fp);
void Hyonghupiaoduqu(FILE *);
void Hyonghupiaowrite();
int main()
{
	bool go = true; int xuanze, flag = 0; char ch; 
	if ((fp= fopen("shuju.txt", "a+")) == NULL)
	{
		printf("不能打开文件\n");
		exit(1);
	}
	if ((fp1 = fopen("hangkongshuju.txt", "a+")) == NULL)
	{
		printf("不能打开文件\n");
		exit(1);
	}
	FILE *fp2,*fp3;
	if ((fp2 = fopen("yonghupiao.txt", "a+")) == NULL)
	{
		printf("不能打开文件\n");
		exit(1);
	}duqu(fp);
	if ((fp3 = fopen("piao.txt", "a+")) == NULL)
	{
		printf("不能打开文件\n");
		exit(1);
	}
	  Hduqu(fp1,fp3); Hyonghupiaoduqu(fp2);
	cout << "更新完成";
	system("cls");
	while (go) {
		printf("-------------------------------------\n");
		cout << "欢迎来到航空管理系统" << endl;
		printf("1.用户登陆\n");
		cout << "2.机场管理员登陆" << endl;
		cout << "3.用户注册" << endl;
		printf("0. 结束。\n");
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar(); 
		
		switch (xuanze)
		{
		case 1:yonghu(); break;
		case 2:Hangband(fp,fp1); go = false; break;
		case 3:yonghuzhuce(fp); cout << "注册成功！" << endl; break;
		case 0:go = false; break;
		default:printf("错误代码\n");
		}
	}
	 Hupdate2();
	 update2();
	 shengcheng();
	 Hyonghupiaowrite();
		fclose(fp);
		fclose(fp1);
	return 0;
}