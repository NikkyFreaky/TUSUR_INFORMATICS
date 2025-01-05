#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	system(" chcp 1251");
	printf(" Программу выполнил студент гр.421-1 Злобин Никита Сергеевич\n Введите размерность матрицы: ");
	int n;
	scanf("%d", &n); 
	//выделение памяти под массив
	int **arr = (int**)malloc(sizeof(int*) *n);
	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(sizeof(int) *n);
	//заполнение массива случайным образом
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = rand() % 100 - rand() % 100;
	//вывод элементов массива в консоль
	printf("\n Матрица A: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%5d ", arr[i][j]);
			printf("\n");
	}
	//поиск максимального элемента в массиве
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
	printf("\n Максимальный элементы матрицы: %d; Строка: %d; Столбец: %d;\n", arr[max_i][max_j], max_i+1, max_j+1);
	if (db != 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == arr[max_i][max_j]) {
					printf(" Повторение элемента %d в массиве. Строка: %d; Столбец: %d;", arr[max_i][max_j], i, j);
				}
			}
		}
	}
	//сортировка массива методом выбора;
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
	//вывод отсортированного массива
	printf("\n Отсортированный массив: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d ", arr[i][j]);
		}
		printf("\n");
	}
	//освобождение памяти
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
	return 0;
}

