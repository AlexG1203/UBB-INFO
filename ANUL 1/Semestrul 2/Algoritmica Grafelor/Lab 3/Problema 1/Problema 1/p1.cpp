#include<iostream>
#include<fstream>
#include <climits>
using namespace std;

int n, m, x;
int mat[1001][1001], dist[1001];
bool sptSet[1001];

int minDistance()
{
	int min = INT_MAX, min_index = 0;

	for (int i = 0; i < n; i++)
		if (!sptSet[i] && dist[i] < min)
		{
			min = dist[i];
			min_index = i;
		}
	return min_index;
}

void dijkstra(int src)
{
	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int u = minDistance();

		sptSet[u] = true;
		for (int v = 0; v < n; v++)
			if (!sptSet[v] && mat[u][v] && dist[u] != INT_MAX
				&& dist[u] + mat[u][v] < dist[v])
				dist[v] = dist[u] + mat[u][v];
	}

}

int main(int argc, char** argv)
{
	ifstream f(argv[1]);
	ofstream g(argv[2]);

	f >> n >> m >> x;

	int a, b, s;
	while (f >> a >> b >> s)
	{
		mat[a][b] = s;
	}


	dijkstra(x);

	for (int i = 0; i < n; i++)
	{
		cout << dist[i] << " ";
		g << dist[i] << " ";
	}
	cout << endl;


	f.close();
	g.close();
	return 0;
}