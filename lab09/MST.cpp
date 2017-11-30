#include <iostream>
#include <climits>
#include <vector>

using namespace std;
int vertices = 0;

int extractMin(int pi[], int key[]) {
	int index;
	int min = INT_MAX;
	for (int k = 0; k < vertices; k++) {
		if (valid[j] == 0 && key[j] < min) {
			min = key[j];
			index = j;
		}
	}
	return j;
}

void MST(vector< vector<int> > graph) {
	int min;
	vector<int> pi;
	vector<int> key;
	vector<int> valid;
	for (int i = 0; i < vertices; i++) {
		key[i] = INT_MAX;
		valid[i] = 0;
	}
	pi[0] = -1;
	key[0] = 0;
	for (int j = 0; j < vertices - 1; j++) {
		min = extractMin(pi, key);
	}
	valid[min] = 1;
	for (int k = 0; k < vertices; k++) {
		if (graph[min][k] != 0 && valid[k] == 0 && graph[min][k] < key[k]) {
			pi[k] = min;
			key[k] = graph[min][k]
		}
	}
}

int main() {
	int vertices;
	int edges;
	int x, y, w;
	cin >> vertices;
	vector< vector<int> > graph(vertices, vector< int >(vertices, 0));
	for (int i = 0; i < vertices; i++) {
		graph[i][i] = 0;
	}
	cin >> edges;
	for (int j = 0; j < edges; j++) {
		cin >> x;
		cin >> y;
		cin >> w;
		graph[x][y] = w;
	}
	MST(graph);
	for (int m = 1; m < vertices; m++) {
		cout << pi[m] << endl;
	}
}
