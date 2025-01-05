#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system("chcp 1251");
	printf("Программу выполнил студент гр.421-1 Злобин Никита Сергеевич\n");
	
    int *arr,i,n;
    //заполняем массив
    printf("Введите размерность массива: ");
	scanf("%d",&n);
	arr=(int*)calloc(n, sizeof(int));
	printf("Введите элементы массива: ");
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
    printf("\n");
    //вычисление произведения четных элементов массива
    int product = 1;
    for(i = 0; i < n; i++)
    {
        if( (i+1) % 2 == 0 )
            product *= arr[i];
    }
    printf("Произведение четных элементов массива = %d\n",product);
    
    int firstNull = -1, lastNull = -1, summa = 0;
    //нахождение первого нулевого элемента
    for(i = 0; i < n; i++)
    {
        if(arr[i] == 0){
            firstNull = i;
            break;
        }
    }
    //нахождение последнего нулевого элементы
    for(i = n-1; i >= 0; i--)
    {
        if(arr[i] == 0){
            lastNull = i;
            break;
        }
    }
    //нахождение суммы элементов
    if(firstNull == -1 || lastNull == -1)
        printf("Нет нулевых элементов\n");
    else{
    	for(i = firstNull+1; i < lastNull; i++)
    	{
        	summa+=arr[i];
    	}
    	printf("Сумма элементов, расположенных между первым и последним нулевыми элементами = %d\n", summa);
	} 
    //нахождение первого минимального элемента массива
    int imin = 0;
    for(i=1;i<n;i++){             
    	if((arr[i]+imin)>(arr[i]+i)) imin = i;              
    }
	//удаление элементов и вывод массива     
	for(i = 0; i < (n - imin); i++){
		arr[i] = arr[i + imin];
	}
	arr = (int*)realloc(arr, (n - imin) * sizeof(int));
	printf("Новый массив: ");
	for(i = 0; i < (n - imin); i++){
		printf("%d ", arr[i]);
	}
    
	return 0;
}
