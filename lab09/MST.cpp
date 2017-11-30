#include <iostream>
#include <climits>
#include <vector>

using namespace std;
int vertices;

int extractMin(vector<int> valid, vector<int> key) {
	int index = vertices - 1;
	int minimum = INT_MAX;
	for (int k = 0; k < vertices; k++) {
		if (valid[k] == 0 && key[k] < minimum) {
			//cout << "ping6 index: " << index << endl;
			minimum = key[k];
			index = k;
		}
	}
	//cout << "ping7 index: " << index << endl;
	return index;
}

void MST(vector< vector<int> > graph) {
	//cout << "pingMST1" << "vertices: " << vertices << endl;
	int min;
	//cout << "pingMST2" << endl;
	vector<int> pi (vertices, 0);
	//cout << "pingMST3" << endl;
	vector<int> key (vertices, 0);
	//cout << "pingMST4" << endl;
	vector<int> valid (vertices, 0);
	//cout << "pingMST5" << endl;
	for (int i = 0; i < vertices; i++) {
		//cout << "ping1" << endl;
		key[i] = INT_MAX;
		valid[i] = 0;
	}
	pi[0] = -1;
	key[0] = 0;
	for (int j = 0; j < vertices-1; j++) {
		//cout << "ping2 j= " << j << endl;
		min = extractMin(valid, key);
		valid[min] = 1;
		for (int k = 0; k < vertices; k++) {
			//cout << "ping3 min= " << min << " k = " << k << endl;
			if (graph[min][k] != 0 && valid[k] == 0 && graph[min][k] < key[k]) {
				//cout << "ping4" << endl;
				pi[k] = min;
				key[k] = graph[min][k];
			}
		}
	}
	for (int m = 1; m < vertices; m++) {
		//cout << "ping5" << endl;
		cout << pi[m] << endl;
	}
}

int main() {
	int edges;
	int x, y, w;
	cin >> vertices;
	vector< vector<int> > graph;
	graph.resize(vertices, vector<int>(vertices, 0));
	for (int i = 0; i < vertices; i++) {
		graph[i][i] = 0;
	}
	//for (int k = 0; k < vertices; k++) {
	//	for (int n = 0; n < vertices; n++) {
	//		cout << graph[k][n]  << " ";
	//	}
	//	cout << endl;
	//}
	cin >> edges;
	for (int j = 0; j < edges; j++) {
		//cout << "pingSeg" << endl;
		cin >> x;
		cin >> y;
		cin >> w;
		graph[x][y] = w;
		//for (int k = 0; k < vertices; k++) {
        		//for (int n = 0; n < vertices; n++) {
                		//cout << graph[k][n]  << " ";
        		//}
        		//cout << endl;
		//}
	}
	MST(graph);
}
