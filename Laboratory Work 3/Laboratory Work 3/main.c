#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system ("chcp 1251");
	printf("��������� �������� ������ ������\n");
	float x,y;
	printf("������� �������� x � y:");
	int m = scanf("%f%f", &x,&y);
	if (m!=2) {printf("������� �� �����\n");
			   system("pause");
			   exit(0);}
	if((y<=-x+2)&&(y<=x+2)&&(y>=x-2)&&(y>=-x-2) || ((x-1)*(x-1))+((y-1)*(y-1))<=(1*1) ) {
		printf("������ ����� ����������� �������� �������������� �������\n");
		}
	else {
		printf("������ ����� �� ����������� �������� �������������� �������\n");
		}
	return 0;
}
