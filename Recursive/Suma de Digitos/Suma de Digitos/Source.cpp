#include <iostream>
#include <vector>
using namespace std;

int suma(const vector <int> &v, int tam, int k) {
	int res;

	if (k == tam) {
		res = v[k];
		cout << v[k] << " ";
	}
	else {
		res = suma(v, tam, k + 1);
		res += v[k];
		cout << "+ " << v[k] << " ";

	}
	return res;
}

bool resuelveCaso() {
	long long int num;
	int tam, res;
	vector<int> v;

	cin >> num;
	if (num < 0) {return false;}
	if (num != 0) {
		while (num > 0) {
			v.push_back(num % 10);
			num /= 10;
		}
	}
	else {
		v.push_back(0);
	}
	tam = v.size()-1;
	res = suma(v, tam, 0);

	cout << "= " << res << endl;

	return true;
}

int main() {
	while (resuelveCaso()) {	}
	return 0;
}
