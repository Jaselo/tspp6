#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000000; // бесконечность
const int n = 9; // количество вершин
bool used[100] = { 0 }; // массив для пометок
int g[8][9] = {               // матрица смежности
//1  2  3  4  5  6  7  8  9
{ 0, 5, 6, 0, 0, 0, 0, 0, 0 }, //1
{ 0, 0, 3, 8, 0, 0, 0, 0, 0 }, //2
{ 0, 0, 0, 0, 9, 7, 0, 8, 0 }, //3
{ 0, 0, 3, 0, 2, 0, 6, 0, 0 }, //4
{ 0, 0, 0, 0, 0, 0, 5, 0, 0 }, //5
{ 0, 0, 0, 0, 7, 0, 10, 0, 0}, //6
{ 0, 0, 0, 0, 0, 0, 0, 0, 4 }, //7
{ 0, 0, 0, 0, 0, 0, 0, 0, 3 }, //8
};

int solve() {
	int i, j, v, to;
	vector <int> min_e(n, INF), sel_e(n, -1);
	min_e[0] = 0;
	for (i = 0; i < n; i++) {
		v = -1;
		for (j = 0; j < n; j++)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		if (min_e[v] == INF) {
			cout << "No MST!";
			exit(0);
		}
		used[v] = true;
		if (sel_e[v] != -1)
			cout << v << " " << sel_e[v] << endl;
		for (to = 0; to < n; to++)
			if (g[v][to] < min_e[to]) {
				min_e[to] = g[v][to];
				sel_e[to] = v;
			}
	}
	return 0;
}

int main() {
	solve();
	return 0;
}
