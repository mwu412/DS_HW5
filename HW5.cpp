#include <iostream>
using namespace std;

#define MAX 1000000	//resucsent: infinity

class Graph {
private:
	int n;	//number of vertices
	int **a; //array of cost
	int **suc; //array of successor
	void PrintPath(int i, int j) {
		int successor = i;
		cout << i;
		while (successor != j) {
			successor = suc[successor][j];
			cout << "->" <<successor;
		}
		cout << endl;
	}
public:
	void MakeMatrix() {
		cin >> n;
		a = new int *[n];
		for (int i = 0; i < n; i++)
			a[i] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 0) a[i][j] = MAX;
			}
		}
		suc = new int *[n];
		for (int i = 0; i < n; i++)
			suc[i] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == MAX) suc[i][j] = -1;
				else suc[i][j] = j;
			}
		}
	}
	void Floyd() {
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i != j) {
						if ((a[i][k] + a[k][j]) < a[i][j]) {
							a[i][j] = a[i][k] + a[k][j];
							suc[i][j] = suc[i][k];
						}
						else if ((a[i][k] + a[k][j]) == a[i][j]) {
							if (suc[i][k] < suc[i][j]) suc[i][j] = suc[i][k];
						}
					}
				}
			}
		}
	}
	void PrintResult() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] != MAX && i != j) {
					cout << "Path(" << i << ',' << j << "):";
					PrintPath(i, j);
					cout << "Cost:" << a[i][j] << endl;
				}
			}
		}
	}
};

int main() {
	Graph g;
	g.MakeMatrix();
	g.Floyd();
	g.PrintResult();
	system("pause");
	return 0;
}
