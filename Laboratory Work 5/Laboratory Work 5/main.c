#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system("chcp 1251");
	printf("��������� �������� ������� ��.421-1 ������ ������ ���������\n");
	
    int *arr,i,n;
    //��������� ������
    printf("������� ����������� �������: ");
	scanf("%d",&n);
	arr=(int*)calloc(n, sizeof(int));
	printf("������� �������� �������: ");
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
    printf("\n");
    //���������� ������������ ������ ��������� �������
    int product = 1;
    for(i = 0; i < n; i++)
    {
        if( (i+1) % 2 == 0 )
            product *= arr[i];
    }
    printf("������������ ������ ��������� ������� = %d\n",product);
    
    int firstNull = -1, lastNull = -1, summa = 0;
    //���������� ������� �������� ��������
    for(i = 0; i < n; i++)
    {
        if(arr[i] == 0){
            firstNull = i;
            break;
        }
    }
    //���������� ���������� �������� ��������
    for(i = n-1; i >= 0; i--)
    {
        if(arr[i] == 0){
            lastNull = i;
            break;
        }
    }
    //���������� ����� ���������
    if(firstNull == -1 || lastNull == -1)
        printf("��� ������� ���������\n");
    else{
    	for(i = firstNull+1; i < lastNull; i++)
    	{
        	summa+=arr[i];
    	}
    	printf("����� ���������, ������������� ����� ������ � ��������� �������� ���������� = %d\n", summa);
	} 
    //���������� ������� ������������ �������� �������
    int imin = 0;
    for(i=1;i<n;i++){             
    	if((arr[i]+imin)>(arr[i]+i)) imin = i;              
    }
	//�������� ��������� � ����� �������     
	for(i = 0; i < (n - imin); i++){
		arr[i] = arr[i + imin];
	}
	arr = (int*)realloc(arr, (n - imin) * sizeof(int));
	printf("����� ������: ");
	for(i = 0; i < (n - imin); i++){
		printf("%d ", arr[i]);
	}
    
	return 0;
}
