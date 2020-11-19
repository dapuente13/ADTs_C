#include <iostream>
#include "List.h"
#include "Exceptions.h"
using namespace std;

int main() {

	int n, f;

	cin >> n;

	while (n != -1) {
		cin >> f;
		List<int>* list = new List<int>();

		for (int i = 1; i <= n; ++i) {
			list->push_back(i);
		}

		cout << list->raffle(f) << endl;

		cin >> n;
	}

	return 0;
}
