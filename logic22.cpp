#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
const int N = 100000;
int arr[N];

int compare(const void* x1, const void* x2) {
    return(*(int*)x1 - *(int*)x2);
}
void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;

    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}
int main(void)
{
	setlocale(LC_ALL, "rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
    
    for (int i = 0; i < N; i++) {
     //   arr[i] = rand();// случайная
     
     //   arr[i] = i;// возрастающая

     //   arr[i] = 1000 - i;// убывающая

 /*       if (i < (N / 2)) {
            arr[i] = i;         //сначала возрастающая,затем убывающая
        }
        else {
            arr[i] = 1000 - i;
        }*/
    }

	clock_t start, end; // объявляем переменные для определения времени выполнения
    start = clock();
    qsort(arr, N,sizeof(int),compare);
    end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Время выполнения qsort() при сначала возрастающей, затем убывающей последовательности значений массива: " << seconds << endl;
	/*
    start = clock();
    shell(arr,N);
    end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Время выполнения сортировки Шелла: "  << seconds << endl;

    start = clock();
    qs(arr,0,N-1);
	end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Время выполнения быстрой сортировки: " << seconds;
    */
	return(0);
}
