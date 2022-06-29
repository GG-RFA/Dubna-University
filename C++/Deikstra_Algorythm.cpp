#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 6

int main()
{
	system("chcp 1251");
	system("cls");
	//int a[SIZE][SIZE]; // матрица связей 
	int a[SIZE][SIZE] = { {0,8,7,3,5,1},
						{7,0,4,4,10,7},
						{4,3,0,5,10,7},
						{7,7,9,0,5,2},
						{10,10,5,1,0,2},
						{9,4,1,6,0,0} }; // матрица связей
	int d[SIZE]; // минимальное расстояние 
	int v[SIZE]; // посещенные вершины 
	int temp, minindex, min;
	int begin_index = 0; // начальная вершина------!!!!!
	// Инициализация матрицы связей 
	for (int i = 0; i < SIZE; i++)
	{
		a[i][i] = 0;
		for (int j = i + 1; j < SIZE; j++) {
			printf("Введите расстояние %d - %d: ", i + 1, j + 1);
			scanf("%d", &temp);
			a[i][j] = temp;
			a[j][i] = temp;
		}
	}
	// Вывод матрицы связей 
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%5d ", a[i][j]);
		printf("\n");
	}
	//Инициализация вершин и расстояний 
	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 10000;//Примем 10000 как бесконечное расстояние 
		v[i] = 1;
	}
	d[begin_index] = 0; // Шаг алгоритма 
	do
	{
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < SIZE; i++)
		{ // Если вершину ещё не обошли и вес меньше min
			if ((v[i] == 1) && (d[i] < min))
			{ // Переприсваиваем значения
				min = d[i];
				minindex = i;
			}
		}
		// Добавляем найденый минимальный вес
		// к текущему весу вершины
		// и сравниваем с текущим минимальным весом вершины
		if (minindex != 10000)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (a[minindex][i] > 0)
				{
					temp = min + a[minindex][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);
	// Вывод кратчайших расстояний до вершин 
	printf("\nКратчайшие расстояния до вершин: \n");
	for (int i = 0; i < SIZE; i++)
		printf("%5d ", d[i]);

	// Восстановление пути
	int ver[SIZE]; // массив посещенных вершин 
	int end = 5; // индекс конечной вершины 5-1 - !!!!!!!!!!!
	ver[0] = end + 1; // начальный элемент - конечная вершина 
	int k = 1; // индекс предыдущей вершины 
	int weight = d[end]; //вес конечной вершины

	while (end != begin_index)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (a[i][end] != 0)
			{
				int temp = weight - a[i][end];
				if (temp == d[i])
				{
					weight = temp;
					end = i;
					ver[k] = i + 1;
					k++;
				}
			}
		}
	}
	// Вывод пути (начальная вершина оказалась в конце массива из k элементов)
	printf("\nВывод кратчайшего пути\n");
	for (int i = k - 1; i >= 0; i--)
		printf("%3d", ver[i]);
	getchar(); getchar();
	return 0;
}