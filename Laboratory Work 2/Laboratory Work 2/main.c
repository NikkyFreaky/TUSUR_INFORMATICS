#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system ("chcp 1251");
	printf("��������� �������� ������ ������\n");
	double a,s;
	printf("������� ����� ������� ������������:");
	int m = scanf("%lf",&a);
	if (m!=1) {printf("������� �� �����\n");
			   system("pause");
			   exit(0);}
	if (a<=0) {printf("������� �� ����� ���� ������������� ���� ��������� ����\n");
	           system("pause");
	           exit(0);}
	else{	s=(sqrt(3)*a*a)/4;
			printf("������� ������������=%.2lf\n",s);
	}
	return 0;
}
