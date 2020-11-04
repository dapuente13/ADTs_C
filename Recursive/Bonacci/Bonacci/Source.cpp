#include <iostream>
using namespace std;

const long long int TOP = 1000000007;


int fibo(long long int n, long long int x, long long int y, long long int &var) {
	long long int res, aux;

	if (n == 0) {
		res = x % TOP;
	}
	else if (n == 1) {
		var = x;
		res = y;
	}
	else {
		aux = fibo(n - 1, x, y, var);
		res = aux + var;
		var = aux;
	}
	return res % TOP;
}


bool resuelveCaso() {
	long long int n, x, y, var = 0;

	cin >> n;

	if (!cin) {
		return false;
	}
	cin >> x >> y;
	cout << fibo(n, x, y, var) << endl;

	return true;
}

int main() {
	while (resuelveCaso()) {	}
	return 0;
}
