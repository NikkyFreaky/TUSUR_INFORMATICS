#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system ("chcp 1251");
	printf("��������� �������� ������� ��.421-1 ������ ������ ���������\n");
	int n,x[4],i,s=0;
	printf("������� ����������� �������������� ����� n:");
	int m = scanf("%d",&n);
	if (m!=1) 
	{
		printf("������� �� �����\n");
		exit(0);
	}
	if (n<1000 || n>9999) 
	{
		printf ("������� �� �������������� �����\n");
		exit(0);
	}
	for (i=0;i<4;i++)
	{
		x[i]=n%10;
		n/=10;
		if (x[i]==x[i-1]) s=s+1;
	}
	if (((x[0]==x[1]&&x[0]==x[2]) || (x[0]==x[1]&&x[0]==x[3]) || (x[0]==x[3]&&x[0]==x[2]) || (x[3]==x[1]&&x[3]==x[2]))&&s!=3) printf("������ ����� �������� ����� 3 ���������� �����");
	else printf("������ ����� �� �������� ����� 3 ���������� �����");
	return 0;
}
