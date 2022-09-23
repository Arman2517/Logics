#include <iostream>
#include<string>
using namespace std;

int maxmin(int a[], int n) {
	int max=0, min=100;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)max = a[i];
		if (a[i] < min)min = a[i];
	}
	return max - min;
}

void initial(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
}

void printArray(int a[],int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i]<<" ";
	}
}

void createArray(int* a,int n) {
	for (int i = 0; i < n; i++) {
		int j;
		cin >> j;
		a[i] = j;
	}
}

void summStrings(int a[10][2]) {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = 0;
		for (int j = 0; j < 2; j++) {
			sum += a[i][j];
		}
		cout << sum<<"\n";
	}
}

void structStudents() {
setlocale(LC_ALL,"Russian");
	string name, surname, facul;
	int zach;
	int i;
	struct student {
		char famil[20];
		char name[20], facult[20];
		int Nomzach;
	}stud[3];

	for (i = 0; i < 3; i++) {
		cout << "Введите фамилию студента \n"; cin >> stud[i].famil;
		cout << "Введите имя студента " << stud[i].famil << endl; cin >> stud[i].name;
		cout << "Введите название факультета студента " << stud[i].famil <<" "<< stud[i].name << endl; cin >> stud[i].facult;
		cout << "Введите номер зачётной книжки студента " << stud[i].famil <<" "<< stud[i].name << endl; cin >> stud[i].Nomzach;
	}
	for (i = 0; i < 3; i++) {
		cout << "Студент "<<stud[i].famil<<stud[i].name<<"обучается на факультете"<<stud[i].facult<<"номер зачётной книжки"<<stud[i].Nomzach;
	}
	cout << "Поиск студента \n";
	cout << "1:По фамилии \n";
	cout << "2:По имени \n";
	cout << "3:По названию факультета \n";
	cout << "4:По номеру зачётной книжки \n";
	int print;
	cin >> print;
	switch (print)
	{
	case 1:
		cin >> surname;
		for (int i = 0; i < 3; i++) {
			if (surname==stud[i].famil)
	cout<<"По вашему запросу найден студент:\n"<< "Студент " << stud[i].famil << stud[i].name << "обучается на факультете" << stud[i].facult << "номер зачётной книжки" << stud[i].Nomzach;
		}
	case 2:
		cin >> name;
		for (int i = 0; i < 3; i++) {
			if (name == stud[i].name)
				cout << "По вашему запросу найден студент:\n" << "Студент " << stud[i].famil << stud[i].name << "обучается на факультете" << stud[i].facult << "номер зачётной книжки" << stud[i].Nomzach;
		}
	case 3:
		cin >> facul;
		for (int i = 0; i < 3; i++) {
			if (facul == stud[i].facult)
				cout << "По вашему запросу найден студент:\n" << "Студент " << stud[i].famil << stud[i].name << "обучается на факультете" << stud[i].facult << "номер зачётной книжки" << stud[i].Nomzach;
		}
	case 4:
		cin >> zach;
		for (int i = 0; i < 3; i++) {
			if (zach == stud[i].Nomzach)
				cout << "По вашему запросу найден студент:\n" << "Студент " << stud[i].famil << stud[i].name << "обучается на факультете" << stud[i].facult << "номер зачётной книжки" << stud[i].Nomzach;
		}
	default:
		break;
	}

}
int main(void) {
	setlocale(LC_ALL, "Russian");
//	int temp, n = 10, m = 6, k = 2;
	int a[10] = { 8,13,25,56,34,76,27,45,96,55 };
	int** p;
	int m ;
	cout << "Введите количество столбцов: ";
	cin >> m;
	int n;
	cout << "Введите количество строк: ";
	cin >> n;
	p = (int**)malloc(n*sizeof(int*));
	for (int i = 0; i < n; i++) {

		p[i] = (int*)malloc(m * sizeof(int));

		for (int j = 0; j < m; j++) {

			p[i][j] = rand() % 10;
		
		}
	}
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {
			cout<<p[i][j]<<" ";
		}
		cout << endl;
	}
	//structStudents();
	//summStrings(a);
	//printArray(a, n);
	//cout <<"\n"<< maxmin(a, n);

}
