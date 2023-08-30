//Transformare din lista de muchii in matrice de adiacenta
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, mat[100][100] = { 0 };
	cin >> n;
	int x, y;
	while(cin>>x>>y) {
		mat[x][y] = 1;
		mat[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
*/

//Transformare din lista de muchii in lista de adiacenta
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, mat[100][100] = { 0 }, la[100][100] = {0};
	cin >> n;
	int x, y;
	while(cin>>x>>y) {
		cin >> x >> y;
		mat[x][y] = 1;
		mat[y][x] = 1;
	}
	int grad;
	for (int i = 1; i <= n; i++) {
		grad = 0;
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == 1)
				la[i][++grad] = j;
		}
		la[i][0] = grad;
	}

	for (int i = 1; i <= n; i++) {
		cout << i << ":";
		for (int j = 1; j <= n; j++) {
			cout << la[i][j] << " ";
		}
		cout << endl;
	}
}*/


//Transformare din lista de muchii in matrice de incidenta
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, m, mat[100][100] = { 0 };
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		mat[x][i] = 1;
		mat[y][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
*/


//Transformare din matrice de adiacenta in lista de muchii
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, mat[100][100];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
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
*/

//Transformare din matrice de adiacenta in lista de adiacenta
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, mat[100][100], la[100][100] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	int grad;
	for (int i = 1; i <= n; i++) {
		grad = 0;
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == 1)
				la[i][++grad] = j;
		}
		la[i][0] = grad;
	}

	for (int i = 1; i <= n; i++) {
		cout << i << ":";
		for (int j = 1; j <= n; j++) {
			cout << la[i][j] << " ";
		}
		cout << endl;
	}
}
*/

//Transformare din matrice de adiacenta in matrice de incidenta
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, mat[100][100], mati[100][100] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	int m = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (mat[i][j] != 0) {
				m++;
				mati[i][m] = 1;
				mati[j][m] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << mati[i][j] << " ";
		}
		cout << endl;
	}
}*/

//Transformare din lista de adiacenta in matrice de adiacenta
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, la[100][100] = { 0 }, mat[100][100] = {0};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> la[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (la[i][j] != 0)
				mat[i][la[i][j]] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
*/

//Transformare din matrice de incidenta in lista de muchii
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, m, mat[100][100] = { 0 }, mata[100][100] = { 0 }, la[100][100] = { 0 };
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		int x = -1, y = -1;
		for (int j = 1; j <= n; j++) {
			if (mat[j][i] == 1) {
				if (x == -1)
					x = j;
				else {
					y = j;
					mata[x][y] = 1;
					mata[y][x] = 1;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (mata[i][j] != 0) {
				cout << i << " " << j;
				cout << endl;
			}
		}
	}
}
*/

//Transformare din matrice de incidenta in matrice de adiacenta
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, m, mat[100][100] = { 0 }, mata[100][100] = { 0 };
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		int x = -1, y = -1;
		for (int j = 1; j <= n; j++) {
			if (mat[j][i] == 1) {
				if (x == -1)
					x = j;
				else {
					y = j;
					mata[x][y] = 1;
					mata[y][x] = 1;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << mata[i][j] << " ";
		}
		cout << endl;
	}
}
*/

//Transformare din matrice de incidenta in lista de adiacenta
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, m, mat[100][100] = { 0 }, mata[100][100] = { 0 }, la[100][100] = { 0 };
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		int x = -1, y = -1;
		for (int j = 1; j <= n; j++) {
			if (mat[j][i] == 1) {
				if (x == -1)
					x = j;
				else {
					y = j;
					mata[x][y] = 1;
					mata[y][x] = 1;
					break;
				}
			}
		}
	}
	int grad;
	for (int i = 1; i <= n; i++) {
		grad = 0;
		for (int j = 1; j <= n; j++) {
			if (mata[i][j] == 1)
				la[i][++grad] = j;
		}
		la[i][0] = grad;
	}

	for (int i = 1; i <= n; i++) {
		cout << i << ":";
		for (int j = 1; j <= n; j++) {
			cout << la[i][j] << " ";
		}
		cout << endl;
	}
}
*/


//Sa se determine nodurile izolate dintr-un graf
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, ok, mat[100][100] = { 0 };
	cin >> n;
	int x, y;
	while (cin >> x >> y) {
		mat[x][y] = 1;
		mat[y][x] = 1;
	}
	cout << "Nodurile Izolate: ";
	int global_ok = 1;
	for (int i = 1; i <= n; i++) {
		ok = 0;
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == 1) {
				ok = 1;
			}
		}
		if (ok == 0) {
			cout << i  << " ";
			global_ok = 0;
		}
	}
	if (global_ok) {
		cout << "Nu are noduri izolate!\n";
	}
}
*/

//Sa se determine daca graful este regular (toate nodurile au acelasi grad)
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, mat[100][100] = { 0 };
	cin >> n;
	int x, y;
	while (cin >> x >> y) {
		mat[x][y] = 1;
		mat[y][x] = 1;
	}
	int grad = 0;
	for (int j = 1; j <= n; j++) {
		if (mat[1][j] == 1) {
			grad++;
		}
	}
	int ok = 0;
	for (int i = 1; i <= n; i++) {
		int g_curent = 0;
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == 1) {
				g_curent++;
			}
		}
		if (g_curent != grad)
			ok = 1;
	}
	if (ok == 0)
		cout << "Graful este regular!";
	else
		cout << "Graful nu este regular!";
}
*/

//Sa se determine matricea distantelor minime pentru distantele intre oricare 2 varfuri din graf
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n, mat[100][100], matd[100][100] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (mat[i][j] == 0 && i != j)
				matd[i][j] = INT_MAX;
			else 
				matd[i][j] = mat[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (matd[i][k] != INT_MAX && matd[k][j] != INT_MAX) {
					if (matd[i][j] > matd[i][k] + matd[k][j]) {
						matd[i][j] = matd[i][k] + matd[k][j];
					}
				}
			}
		}
	}
	cout << "\nMatricea drumurilor este :\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (matd[i][j] != INT_MAX)
				cout << matd[i][j] << ' ';
			else 
				cout << "x ";
		}
		cout << endl;
	}
}
*/

//Sa se determine daca graful este conex (exista un lant pentru oricare 2 noduri)
/*
#include <iostream>
#include <fstream>
using namespace std;

int mat[100][100], visited[100];

void dfs(int start, int n) {
	visited[start] = 1;
	for (int j = 1; j <= n; j++) {
		if (mat[start][j] == 1 && visited[j] == 0)
		{
			dfs(j, n);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}
	dfs(1, n);
	bool conex = 1;
	for (int i = 1; i <= n; i++) {
		cout << visited[i] << ' ';
		if (visited[i] == 0) 
			conex = 0;
	}
	if (conex == 1)
		cout << "\nGraful este conex\n";
	else 
		cout << "\nGraful nu este conex\n";
}
*/