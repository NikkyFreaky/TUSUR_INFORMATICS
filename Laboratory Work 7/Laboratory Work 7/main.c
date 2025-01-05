#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    system("chcp 1251");
    system("cls");

    printf(" ��������� �������� ������� ��.421-1 ������ ������ ���������, ������� 9\n");

    unsigned n, m;

    printf("\n ������� ���������� ������: ");
    scanf("%d", &n);

    printf(" ������� ���������� �����: ");
    scanf("%d", &m);

    printf("\n");

    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < m; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));

    printf(" ");
    for (unsigned check = 0; check < n; check++)
        printf("%3d", check + 1);

    printf("\n");

    for (unsigned i = 0; i < m; i++)
    {
        printf("%d", i + 1);

        for (unsigned j = 0; j < n; j++)
        {
            matrix[i][j] = 0; // i - ����� (������), j - ������� (�������)
            printf("%3d", 0);
        }
        printf("\n");
    }
    printf("\n");


    for (unsigned i = 0; i < m; i++)
    {
        unsigned start, finish;

        printf(" ������� ������ ����� (�� 1 �� %d): ", n);
        scanf("%d", &start);

        printf(" ������� ����� ����� (�� 1 �� %d): ", n);
        scanf("%d", &finish);


        if (start == finish)
        {
            matrix[i][start - 1] = 2; //����
        }
        else
        {
            matrix[i][start - 1] = 1; //������ �����
            matrix[i][finish - 1] = -1; //����� �����
        }
        printf("\n");

        /*  system("cls");  */

        printf(" ");
        for (unsigned check = 0; check < n; check++)
        {
            printf("%3d", check + 1);
        }
        printf("\n");

        for (unsigned i = 0; i < m; i++)
        {
            printf("%d", i + 1);
            for (unsigned j = 0; j < n; j++)
            {
                printf("%3d", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf(" ������� �����, ������� ������� ����������� ������:"); //������� ����������� ������ - ��� ������� ��������� ������ �� ����� ��� ������
    for (unsigned j = 0; j < n; j++)
    {
        bool flag = true; //����� ��� ������� ������
        for (unsigned i = 0; i < m; i++) //��������� ������� ������ ����
        {
            int elem = matrix[i][j];
            if (elem == 2 || elem == -1)
            {
                flag = false;
                break;
            }
        }

        if (flag) //������� ������� 
        {
            printf("%2d;", j + 1);
        }
    }
    printf("\n");

    return 0;
}