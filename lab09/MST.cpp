#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Node {
	int id;
	int key;
	Node *pi;
};

int size = 0;
Node Q[100];

int parent(int i) {
	return i/2;
}

void DecreaseKey(Node n, int size) {
	if (n.key < Q[size].key) {
		Q[size] = n;
		int j = size;
		Node temp;
		while (j > 0 && Q[parent(j)].key > Q[j].key) {
			temp = Q[j];
			Q[j] = Q[parent(j)];
			Q[parent(j)] = temp;
			j = parent(j);
		}
	}
}

void Insert(Node in) {
	size++;
	Q[size-1].key = INT_MAX;
	DecreaseKey(in, size-1);
}

void minHeapify(int input) {
	int x;
	int y = 2*input + 1;
	int z = 2*input + 2;
	Node temp;
	if (y < size && Q[y].key < Q[input].key) {
		x = y;
	}
	else
		x = input;
	if (z < size && Q[z].key < Q[x].key) {
		x = z;
	}
	if (x != input) {
		temp = Q[input];
		Q[input] = Q[x];
		Q[x] = temp;
		minHeapify(x);
	}
}

Node ExtractMin() {
	Node min = Q[0];
	Q[0] = Q[size-1];
	size--;
	minHeapify(0);
	return min;
}

int main() {
	int vertices;
	int edges;
	int x, y, w;
	Node input;
	Node current;
	input.key = INT_MAX;
	input.pi = NULL;
	cin >> vertices;
	int graph[vertices][vertices];
	for (int i = 0; i < vertices; i++) {
		graph[i][i] = 0;
		Q[i].id = i;
		Q[i].key = MAX_INT;
		Q[i].pi = NULL;
	}
	Q[0].key = 0;
	cin >> edges;
	for (int j = 0; j < edges; j++) {
		cin >> x;
		cin >> y;
		cin >> w;
		graphs[x][y] = w;
	}
	while (size > 0) {
		current = ExtractMin();
		for (int k = 0; k < size; k++) {
			if (graph[current.id][k] != 0 && graph[current.id][k] < Q[k].key) {
				Q[k].pi = current;
				Q[k].key = graph[current][k];
			}
		}
	}
}
