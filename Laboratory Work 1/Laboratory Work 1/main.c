#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system("chcp 1251");
	printf("Программу выполнил Злобин Никита\n");
	double b,x,a,z,p,d,c;
	a=10;
	c=7.3;
	printf("Введите b=\n");
	scanf("%lf",&b);
	p=(b+sqrt(b*b+4*a*c))/(2*a);
	d=pow(a,3)*c+pow(b,-2);
	z=p-d;
	printf("Значение z=%.3lf\n",z);
	return 0;
}
