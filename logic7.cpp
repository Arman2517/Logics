#include<iostream>
#include<vector>
#include<queue>
using namespace std;



void BFSD(int v,int *G[],int n,int DIST[]) {
	queue<int> Q = {};
	Q.push(v);
	DIST[v] = 0;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		cout << v;
		for (int i = 0; i < 5; i++) {
			if ((G[v][i] > 0) && (DIST[i] > DIST[v]+G[v][i])) {
				Q.push(i);
				DIST[i] = DIST[v] + G[v][i];
			}
		}
	}
}

int main() {

	setlocale(LC_ALL, "rus");
	int** G;
	int* DIST;
	int n;
	cout << "Введите размер матрицы: ";
	cin >> n;
	int m = n;
	G = (int**)malloc(m * sizeof(int*));
	DIST = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < n; i++) {
		G[i] = (int*)malloc(m * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		G[i][i] = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				G[i][j] = rand() % 10;
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
		DIST[i] = 1000;
	}
	cout << "Введите начальную вершину: ";
	int v;
	cin >> v;
	cout << "Результат обхода матрицы: \n";
	BFSD(v,G,n, DIST);
	for (int i = 0; i < n; i++) {
		cout << "\nВершина:" << i << ", Расстояние:" << DIST[i] << "\n";
	}
}
