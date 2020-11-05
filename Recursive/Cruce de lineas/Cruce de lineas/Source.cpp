#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

typedef struct {
	bool coincide;
	int punto;
	bool menor_v;
	bool cruzado;
}pack;

pack algo(const vector<int> &v, const vector<int> &w, int ini, int fin) {
	pack p1, p2;
	int m;

	if (ini == fin) {
		p1.punto = ini;
		p1.coincide = false;
		p1.cruzado = false;

		if (v[ini] == w[ini]) {
			p1.coincide = true;
		}
		else if (v[ini] < w[ini]) {
			p1.menor_v = true;
		}
		else {
			p1.menor_v = false;
		}
	}
	else {
		m = (fin + ini) / 2;
		p1 = algo(v, w, ini, m);
		p2 = algo(v, w, m + 1, fin);

		if (p2.coincide) {
		p1 = p2;
		}
		else if (!p1.coincide) {
			if (p2.cruzado) {
				p1 = p2;
			}
			else if (!p1.cruzado) {
				if (p1.menor_v && p2.menor_v) {
					p1.punto = fin;
				}
				else if (!p1.menor_v && !p2.menor_v) {
					p1.punto = ini;
				}
				else {
					p1.cruzado = true;
				}
			}
		}

	}
	return p1;
}

bool resuelveCaso() {
	int n;
	vector<int> v; //creciente
	vector<int> w; //decreciente
	pack res;

	cin >> n;
	if (n == 0) {
		return false;
	}

	v.resize(n);
	w.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}

	if (v[n-1] < w[n-1]) {
		cout << "NO " << n - 1 << " " << n << endl;;
	}
	else if (v[0] > w[0]) {
		cout << "NO -1 0" << endl;;
	}
	else {
		res = algo(v, w, 0, n-1);
		if (res.coincide) {
			cout << "SI " << res.punto << endl;
		}
		else {
			cout << "NO " << res.punto << " " << res.punto + 1 << endl;
		}
	}

	return true;
}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("datos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

		while (resuelveCaso()) {}

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
	#endif

	return 0;
}