#include <iostream>
using namespace std;

#define MAX 10	//represent: infinity

class Graph {
private:
	int n;	//number of vertices
	int **a; //array of cost
	int **pre; //array of predecessor
public:
	void MakeMatrix() {
		cin >> n;
		*a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 0) a[i][j] = MAX;
			}
		}
		*pre = new int[n];
		for (int i = 0; i < n; i++)
			pre[i] = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(a[i][j] == MAX) pre[i][j] = -1;
				else a[i][j] = i;
			}
		}
	}
	void Floyd() {
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (a[i][j] != MAX && a[i][k] + a[k][j] < a[i][j]) {
						a[i][j] = a[i][k] + a[k][j];
						pre[i][j] = k;
					}
				}
			}
		}
	}
	void PrintResult() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == MAX) cout << "Path(" << i << ',' << j << "):";
				cout << i;
				while(pre[i])
					
			}
		}
	}
};
