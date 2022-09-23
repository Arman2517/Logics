#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
const int N = 1000;
int a[N][N], b[N][N], c[N][N], elem_c;
int main(void)
{
	setlocale(LC_ALL, "rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения
	start = clock();
	int i = 0, j = 0, r;

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < N)
	{
		while (j < N)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < N)
	{
		while (j < N)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			elem_c = 0;
			for (r = 0; r < N; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}

	end = clock();
	cout << "Время выполнения программы: " << (end - start) / CLOCKS_PER_SEC;
	return(0);
}
