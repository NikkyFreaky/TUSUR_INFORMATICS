#define _CRT_SECURE_NO_WARNINGS //��������� �������������� ������ �� ������
#define GET_VARIABLE_NAME(Variable) (#Variable) //������ �������������� �������� ���������� � �����
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double answer = 0; //����� ���������� �����

//��������� ��������� ��������
int Random()
{
	srand(time(NULL) + rand());
	return rand() % 21 - 10;
}

//����� �������
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

//���������� ��������� ��� M4(y) > 4
void Function_X(double A9_x, int M5_x)
{
	double degree = pow(10, -3);
	double cosine = cos(A9_x);
	double sum = M5_x + degree * cosine;
	printf(" z = %.1f (��� M4(y) > 4)", sum);
}


//���������� ��������� ��� �4(�) <= 4
void Function_Y(double A9_y, int M5_y)
{
	double square_root = sqrt(A9_y + 1);
	double degree = pow(M5_y, 3);
	double sum = square_root + 2.5 * degree;
	printf(" z = %.1f (��� M4(y) <= 4)", sum);
}

//������� �������������� ��������
double Arithmetic_mean(int* array, unsigned int n)
{
	answer = 0;
	for (size_t i = 0; i < n; i++)
		answer += array[i];

	return answer / n;
}

//����� ������������� ��������� �������
int Sum_positive_elements(int* array, unsigned int n)
{
	answer = 0;
	for (size_t i = 0; i < n; i++)
		if (array[i] > 0)
			answer += array[i];

	return sqrt(answer);
}

//����� ���������� �������� ��������� �������
int Sum_absolute_elements(int* array, unsigned int n)
{
	answer = 0;
	for (size_t i = 0; i < n; i++)
		answer += abs(array[i]);

	return log(answer);
}

//���������� ��������� �������, �������� ������� ������ ��������
int Number_greater_elements(int* array, unsigned int n, double min)
{
	answer = 0;
	for (size_t i = 0; i < n; i++)
		if (array[i] > min)
			answer++;

	return (int)answer;
}

//���������� ��������� �������, �������� ������� ������ ��������
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
	printf(" ��������� �������� ������� ��.421-1 ������ ������ ���������, ������� 9\n\n");

	unsigned int n, m;

	printf(" ������� n: ");
	scanf("%u", &n);
	printf(" ������� m: ");
	scanf("%u", &m);
	printf("\n");

	int* X = (int*)malloc(sizeof(int) * n);
	char name_x[] = GET_VARIABLE_NAME(X); //���������� �������� ���������� � ������
	Fill_print(X, n, name_x);

	int* Y = (int*)malloc(sizeof(int) * m);
	char name_y[] = GET_VARIABLE_NAME(Y); //���������� �������� ���������� � ������
	Fill_print(Y, m, name_y);

	//�6(Y) - ������� �������������� �������� ��������� ������� Y;
	double A6_y = Arithmetic_mean(Y, m);
	//�8(�) - ������ ���������� �� ����� ������������� ��������� ������� �;
	double A8_x = Sum_positive_elements(X, n);
	//�8(Y) - ������ ���������� �� ����� ������������� ��������� ������� Y;
	double A8_y = Sum_positive_elements(Y, m);
	//�9(�) - ����������� �������� �� ����� ���������� �������� ��������� ������� �;
	double A9_x = Sum_absolute_elements(X, n);
	//�9(Y) - ����������� �������� �� ����� ���������� �������� ��������� ������� Y;
	double A9_y = Sum_absolute_elements(Y, m);
	//�4(Y) - ���������� ��������� ������� Y, �������� ������� ������ �6(y);
	int M4_y = Number_less_elements(Y, m, A6_y);
	//�5(�)- ���������� ��������� ������� �, �������� ������� ������ �8(x).
	int M5_x = Number_greater_elements(X, n, A8_x);
	//�5(Y)- ���������� ��������� ������� Y, �������� ������� ������ �8(y).
	int M5_y = Number_greater_elements(Y, m, A8_y);

	printf("\n A6(y) - ������� �������������� �������� ��������� ������� Y: %.1f", A6_y);
	printf("\n A8(x) - ������ ���������� �� ����� ������������� ��������� ������� X: %.1f", A8_x);
	printf("\n A8(y) - ������ ���������� �� ����� ������������� ��������� ������� Y: %.1f", A8_y);
	printf("\n A9(x) - ����������� �������� �� ����� ���������� �������� ��������� ������� X: %.1f", A9_x);
	printf("\n A9(y) - ����������� �������� �� ����� ���������� �������� ��������� ������� Y: %.1f", A9_y);
	printf("\n M4(y) - ���������� ��������� ������� Y, �������� ������� ������ �6(y): %d", M4_y);
	printf("\n M5(x) - ���������� ��������� ������� �, �������� ������� ������ �8(x): %d", M5_x);
	printf("\n M5(y) - ���������� ��������� ������� Y, �������� ������� ������ �8(y): %d", M5_y);

	printf("\n\n �����:");
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