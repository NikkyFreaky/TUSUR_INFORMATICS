#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system ("chcp 1251");
	printf("��������� �������� ������� ��.421-1 ������ ������ ���������\n");
	int m, overflow = 0, n = 1;
  	float x, e;
  	double S=0;
  	printf("������� �������� x � �������� e = ");
  	m = scanf("%f%f", &x, &e);
  	if (m!=2 || e>1 || e<0) {
    printf("������������ ����");
    exit(0);
  	}
  	double q=pow(x,5)/48;
 	while (q>e) {
    if (isinf(q) || isinf(S)){
      overflow = 1;
      break;
    }
    if ((n+1)%2==0) S+=q;
    else S-=q;
    q= (q*(x*x))/((n+1)*(n+4));
    n+=1;
  	}
  	if (overflow==1) printf("��������� �������� �� ����� ���� ���������� ��������� = %d", n-1);
 	else printf("���������� �������� = %d , �������� ����� = %.5lf", n-1, S);
	return 0;
}
