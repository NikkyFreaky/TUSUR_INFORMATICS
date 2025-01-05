#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system ("chcp 1251");
	printf("Программу выполнил Злобин Никита\n");
	float x,y;
	printf("Введите значение x и y:");
	int m = scanf("%f%f", &x,&y);
	if (m!=2) {printf("Введены не числа\n");
			   system("pause");
			   exit(0);}
	if((y<=-x+2)&&(y<=x+2)&&(y>=x-2)&&(y>=-x-2) || ((x-1)*(x-1))+((y-1)*(y-1))<=(1*1) ) {
		printf("Данная точка принадлежит заданной заштрихованной области\n");
		}
	else {
		printf("Данная точка не принадлежит заданной заштрихованной области\n");
		}
	return 0;
}
