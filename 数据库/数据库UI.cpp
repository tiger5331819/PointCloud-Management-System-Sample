#include"���ݿ�ͷ.h"
#include"�ļ����Ӻ���.h"
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
		printf("���ܴ��ļ�\n");
		exit(1);
	}
	if ((fp1 = fopen("hangkongshuju.txt", "a+")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		exit(1);
	}
	FILE *fp2,*fp3;
	if ((fp2 = fopen("yonghupiao.txt", "a+")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		exit(1);
	}duqu(fp);
	if ((fp3 = fopen("piao.txt", "a+")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		exit(1);
	}
	  Hduqu(fp1,fp3); Hyonghupiaoduqu(fp2);
	cout << "�������";
	system("cls");
	while (go) {
		printf("-------------------------------------\n");
		cout << "��ӭ�������չ���ϵͳ" << endl;
		printf("1.�û���½\n");
		cout << "2.��������Ա��½" << endl;
		cout << "3.�û�ע��" << endl;
		printf("0. ������\n");
		printf("-------------------------------------\n");
		cin >> xuanze; ch = getchar(); 
		
		switch (xuanze)
		{
		case 1:yonghu(); break;
		case 2:Hangband(fp,fp1); go = false; break;
		case 3:yonghuzhuce(fp); cout << "ע��ɹ���" << endl; break;
		case 0:go = false; break;
		default:printf("�������\n");
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