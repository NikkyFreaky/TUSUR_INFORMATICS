#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	system(" chcp 1251");
	printf(" ��������� �������� ������� ��.421-1 ������ ������ ���������\n ������� ����������� �������: ");
	int n;
	scanf("%d", &n); 
	//��������� ������ ��� ������
	int **arr = (int**)malloc(sizeof(int*) *n);
	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(sizeof(int) *n);
	//���������� ������� ��������� �������
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = rand() % 100 - rand() % 100;
	//����� ��������� ������� � �������
	printf("\n ������� A: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%5d ", arr[i][j]);
			printf("\n");
	}
	//����� ������������� �������� � �������
	int db=0;
	int max_i = 0, max_j = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > arr[max_i][max_j]) {
				max_i = i;
				max_j = j;
				db = 0;
			} else if (arr[max_i][max_j] == arr[i][j]) {
				db++;
			}
		}
	}
	printf("\n ������������ �������� �������: %d; ������: %d; �������: %d;\n", arr[max_i][max_j], max_i+1, max_j+1);
	if (db != 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == arr[max_i][max_j]) {
					printf(" ���������� �������� %d � �������. ������: %d; �������: %d;", arr[max_i][max_j], i, j);
				}
			}
		}
	}
	//���������� ������� ������� ������;
	int* temp;
	for (int i = 0; i < n-1; i++) {
		int k = i;
		for (int j = i+1; j < n; j++) {
			if (arr[k][n - 1] > arr[j][n - 1])
				k = j;
			{
				temp = arr[k];
				arr[k] = arr[i];
				arr[i] = temp;
			}
		}
	}
	//����� ���������������� �������
	printf("\n ��������������� ������: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d ", arr[i][j]);
		}
		printf("\n");
	}
	//������������ ������
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
	return 0;
}

