#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    system("chcp 1251");
    system("cls");

    printf(" Программу выполнил студент гр.421-1 Злобин Никита Сергеевич, вариант 9\n");

    unsigned n, m;

    printf("\n Введите количество вершин: ");
    scanf("%d", &n);

    printf(" Введите количество ребер: ");
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
            matrix[i][j] = 0; // i - ребро (строка), j - вершина (столбец)
            printf("%3d", 0);
        }
        printf("\n");
    }
    printf("\n");


    for (unsigned i = 0; i < m; i++)
    {
        unsigned start, finish;

        printf(" Введите начало ребра (от 1 до %d): ", n);
        scanf("%d", &start);

        printf(" Введите конец ребра (от 1 до %d): ", n);
        scanf("%d", &finish);


        if (start == finish)
        {
            matrix[i][start - 1] = 2; //дуга
        }
        else
        {
            matrix[i][start - 1] = 1; //начало ребра
            matrix[i][finish - 1] = -1; //конец ребра
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

    printf(" Вершины графа, имеющие нулевую полустепень захода:"); //нулевая полустепень захода - это вершина состоящая только из нулей или единиц
    for (unsigned j = 0; j < n; j++)
    {
        bool flag = true; //нужен для задания флагов
        for (unsigned i = 0; i < m; i++) //проверяет вершины сверху вниз
        {
            int elem = matrix[i][j];
            if (elem == 2 || elem == -1)
            {
                flag = false;
                break;
            }
        }

        if (flag) //выводит вершину 
        {
            printf("%2d;", j + 1);
        }
    }
    printf("\n");

    return 0;
}