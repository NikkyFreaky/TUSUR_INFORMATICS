#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	system(" chcp 1251");
	printf(" ��������� �������� ������� ��.421-1 ������ ������ ���������, ������� 9\n\n ������� ������ �������: ");

	int n;
	scanf("%d", &n);

	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(sizeof(int) * n);

	int number = 1;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = number++;
			}
		}
		else
		{
			for (int j = n - 1; j >= 0; j--)
			{
				arr[i][j] = number++;
			}
		}
	}

	printf(" �������� �������: \n");
	for (size_t i = 0; i < n; i++, printf("\n"))
		for (size_t j = 0; j < n; j++)
			printf("%5d", arr[i][j]);

	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}