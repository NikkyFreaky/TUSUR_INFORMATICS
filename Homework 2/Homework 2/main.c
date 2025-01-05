#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system("chcp 1251");
	printf("Программу выполнил студент гр.421-1 Злобин Никита Сергеевич\n");
	int n, i, sum=0;
    printf("Введите число n = ");
    scanf("%d", &n);
    
    int temp_sum[n];
    
    for(i=0; i<n; i++)
    {
        temp_sum[i]=1;
    }
    
    int k;
    for(i=1; i<=n; i++)
    {
        for(k=i; k<=2*i; k++)
        {
            temp_sum[i-1] *= k;
        }
    }
    
    for(i=0; i<n; i++)
    {
        sum+=temp_sum[i];
    }
    
    printf("Результат вычислений = %d", sum);
	return 0;
}
