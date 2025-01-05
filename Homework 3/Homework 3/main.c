#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	system(" chcp 1251");
	printf(" Программу выполнил студент гр.421-1 Злобин Никита Сергеевич\n\n Введите размер массива: ");
	int n;
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int) *n);
	//заполнение массива случайным образом и вывод его элементов в консоль
	srand((unsigned int)time(NULL));
	printf(" Одномерный массив:");
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
		printf(" %d ", arr[i]);
	}
	//сортировка массива методом выбора
	int min_i, temp;
	int s = 0;
	for (int i = 0; i < n; i++) {
		min_i = i;
		for (int j = i + 1; j < n; j++) {
			s++;
			if (arr[j] < arr[min_i])
				min_i = j;
			if (min_i != i) {
				temp = arr[min_i];
				arr[min_i] = arr[i];
				arr[i] = temp;
			}
		}
	}
	printf("\n Отсортированный массив: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
		printf("\n Количество сравнений элементов массива: %d", s);
		printf("\n");
	return 0;
}

