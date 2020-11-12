#include "Poli.h"
#include <iostream>
using namespace std;

int main() {

	int n, grade, x;
	int* vector;
	
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> grade;
		vector = new int[grade + 1];
		for (int i = 0; i < grade + 1; ++i) {
			cin >> vector[i];
		}

		Polynomial<int> pol1 = Polynomial<int>(vector, grade);

		cin >> grade;
		vector = new int[grade + 1];
		for (int i = 0; i < grade + 1; ++i) {
			cin >> vector[i];
		}

		Polynomial<int> pol2 = Polynomial<int>(vector, grade);
		cin >> x;

		Polynomial<int> res = pol2 + pol1;

		cout << res.evaluate(x) << endl;
	}
	return 0;
}
