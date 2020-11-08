#include <iostream>
using namespace std;

int fractal(int num) {
	
	if (num == 1) {
		return 4;
	}
	else {
		return 4 * num + 4*fractal(num/2);
	}
}

bool resuelveCaso() {
	int num;

	cin >> num;
	if (!cin) {
		return false;
	}
	else {
		cout << fractal(num) << endl;
	}

	return true;
}

int main() {
	while (resuelveCaso()) {}
	return 0;
}
