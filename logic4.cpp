#include<iostream>
using namespace std;


bool NUM[10];

void DFS(int v,int* G[], int n) {

	NUM[v] = true;
	cout << v;
	for (int i = 0; i < n; i++) {
		if ((G[v][i] == 1) && (NUM[i] == false)) {
			DFS(i,G,n);
		}
	}
}

int main() {

	setlocale(LC_ALL, "rus");
	int** G;
	int n;
	cout << "Введите размер матрицы: ";
	cin >> n;
	int m = n;
	G = (int**)malloc(m * sizeof(int*));


	for (int i = 0; i < n; i++) {
		G[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		G[i][i] = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				G[i][j] = rand() % 2;
				G[j][i] = G[i][j];
			}
		}
	}
	cout << "Матрица: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << G[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		NUM[i] = false;
	}

	cout << "Результат обхода матрицы: \n";
	for (int i = 0; i < n; i++) {
		if (NUM[i] == false) {
			DFS(i,G,n);
		}
	}
}
