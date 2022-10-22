#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void BFS(int v, int *G[], int n, bool NUM[]) {
	queue<int> Q = {};
	Q.push(v);
	NUM[v] = true;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		cout << v+1;
		for (int i = 0; i < 5; i++) {
			if ((G[v][i] == 1) && (NUM[i] == false)) {
				Q.push(i);
				NUM[i] = true;
			}
		}
	}
}

int main() {

	setlocale(LC_ALL, "rus");
	int** G;
	bool* NUM;
	int n;
	cout << "Введите размер матрицы: ";
	cin >> n;
	int m = n;
	G = (int**)malloc(m * sizeof(int*));
	NUM = (bool*)malloc(m * sizeof(bool));
	
	for (int i = 0; i < n; i++) {
		G[i] = (int*)malloc(m * sizeof(int));
		G[i][i] = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				G[i][j] = rand() % 2;
			}
		}
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
			BFS(i,G,n,NUM);
		}
	}
}
