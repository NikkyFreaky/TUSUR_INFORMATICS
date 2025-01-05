#define _CRT_SECURE_NO_WARNINGS //Отключает дополнительную защиту от ошибок
#define GET_VARIABLE_NAME(Variable) (#Variable) //Макрос преобразования названия переменной в текст
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double answer = 0; //Общая переменная суммы

//Генератор рандомных значений
int Random()
{
	srand(time(NULL) + rand());
	return rand() % 21 - 10;
}

//Вывод массива
void Fill_print(int* array, unsigned int length, char* name)
{
	printf(" %s : [", name);
	for (size_t i = 0; i < length; i++) {
		if (i) printf(", ");
		array[i] = Random();
		printf("%d", array[i]);
	}
	printf("];\n");
}

//Вычисление выражения при M4(y) > 4
void Function_X(double A9_x, int M5_x)
{
	double degree = pow(10, -3);
	double cosine = cos(A9_x);
	double sum = M5_x + degree * cosine;
	printf(" z = %.1f (При M4(y) > 4)", sum);
}


//Вычисление выражения при М4(у) <= 4
void Function_Y(double A9_y, int M5_y)
{
	double square_root = sqrt(A9_y + 1);
	double degree = pow(M5_y, 3);
	double sum = square_root + 2.5 * degree;
	printf(" z = %.1f (При M4(y) <= 4)", sum);
}

//Среднее арифметическое значение
double Arithmetic_mean(int* array, unsigned int n)
{
	answer = 0;
	for (size_t i = 0; i < n; i++)
		answer += array[i];

	return answer / n;
}

//Сумма положительных элементов массива
int Sum_positive_elements(int* array, unsigned int n)
{
	answer = 0;
	for (size_t i = 0; i < n; i++)
		if (array[i] > 0)
			answer += array[i];

	return sqrt(answer);
}

//Сумма абсолютных значений элементов массива
int Sum_absolute_elements(int* array, unsigned int n)
{
	answer = 0;
	for (size_t i = 0; i < n; i++)
		answer += abs(array[i]);

	return log(answer);
}

//Количество элементов массива, значения которых больше заданных
int Number_greater_elements(int* array, unsigned int n, double min)
{
	answer = 0;
	for (size_t i = 0; i < n; i++)
		if (array[i] > min)
			answer++;

	return (int)answer;
}

//Количество элементов массива, значения которых меньше заданных
int Number_less_elements(int* array, unsigned int n, double min)
{
	int answer = 0;
	for (size_t i = 0; i < n; i++)
		if (array[i] < min)
			answer++;

	return (int)answer;
}

int main() {
	system(" chcp 1251");
	printf(" Программу выполнил студент гр.421-1 Злобин Никита Сергеевич, вариант 9\n\n");

	unsigned int n, m;

	printf(" Введите n: ");
	scanf("%u", &n);
	printf(" Введите m: ");
	scanf("%u", &m);
	printf("\n");

	int* X = (int*)malloc(sizeof(int) * n);
	char name_x[] = GET_VARIABLE_NAME(X); //Сохранение названия переменных в строку
	Fill_print(X, n, name_x);

	int* Y = (int*)malloc(sizeof(int) * m);
	char name_y[] = GET_VARIABLE_NAME(Y); //Сохранение названия переменных в строку
	Fill_print(Y, m, name_y);

	//А6(Y) - среднее арифметическое значение элементов массива Y;
	double A6_y = Arithmetic_mean(Y, m);
	//А8(Х) - корень квадратный из суммы положительных элементов массива Х;
	double A8_x = Sum_positive_elements(X, n);
	//А8(Y) - корень квадратный из суммы положительных элементов массива Y;
	double A8_y = Sum_positive_elements(Y, m);
	//А9(Х) - натуральный логарифм из суммы абсолютных значений элементов массива Х;
	double A9_x = Sum_absolute_elements(X, n);
	//А9(Y) - натуральный логарифм из суммы абсолютных значений элементов массива Y;
	double A9_y = Sum_absolute_elements(Y, m);
	//М4(Y) - количество элементов массива Y, значения которых меньше А6(y);
	int M4_y = Number_less_elements(Y, m, A6_y);
	//М5(Х)- количество элементов массива Х, значения которых больше А8(x).
	int M5_x = Number_greater_elements(X, n, A8_x);
	//М5(Y)- количество элементов массива Y, значения которых больше А8(y).
	int M5_y = Number_greater_elements(Y, m, A8_y);

	printf("\n A6(y) - Среднее арифметическое значение элементов массива Y: %.1f", A6_y);
	printf("\n A8(x) - Корень квадратный из суммы положительных элементов массива X: %.1f", A8_x);
	printf("\n A8(y) - Корень квадратный из суммы положительных элементов массива Y: %.1f", A8_y);
	printf("\n A9(x) - Натуральный логарифм из суммы абсолютных значений элементов массива X: %.1f", A9_x);
	printf("\n A9(y) - Натуральный логарифм из суммы абсолютных значений элементов массива Y: %.1f", A9_y);
	printf("\n M4(y) - Количество элементов массива Y, значения которых меньше А6(y): %d", M4_y);
	printf("\n M5(x) - Количество элементов массива Х, значения которых больше А8(x): %d", M5_x);
	printf("\n M5(y) - Количество элементов массива Y, значения которых больше А8(y): %d", M5_y);

	printf("\n\n Ответ:");
	if (M4_y > 4)
	{
		Function_X(A9_x, M5_x);
	}
	else
	{
		Function_Y(A9_y, M5_y);
	}

	printf("\n");

	return 0;
}