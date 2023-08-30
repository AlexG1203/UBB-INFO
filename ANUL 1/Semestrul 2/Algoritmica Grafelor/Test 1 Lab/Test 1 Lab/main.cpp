#include <iostream>
#include <fstream>
using namespace std;

int n, mat_a[100][100];
ifstream fin("in.txt");

int main() {
	int n, mat[100][100];
	fin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fin >> mat[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (mat[i][j] != 0) {
				cout << i << " " << j;
				cout << endl;
			}
		}
	}
}