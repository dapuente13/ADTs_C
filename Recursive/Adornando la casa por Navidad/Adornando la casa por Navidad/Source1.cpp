#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

typedef struct {
	int coste, area;
}figura;


void belen(const vector <figura>& escaparate, vector<bool>& marcas, int objetos, int presupuesto, figura &solucion, figura parc_solucion, int k) {
	figura mi_sol;

	mi_sol = parc_solucion;
	mi_sol.area += escaparate[k].area;
	mi_sol.coste += escaparate[k].coste;
	marcas[k] = true;

	if (mi_sol.coste <= presupuesto){
		if (k == (objetos - 1)) {
			if (mi_sol.area > solucion.area) {
				solucion = mi_sol;
			}
		}
		else {
			belen(escaparate, marcas, objetos, presupuesto, solucion, mi_sol, k + 1);
		}
	}
	marcas[k] = false;
	if (k == (objetos - 1)) {
		if (parc_solucion.area > solucion.area) {
			solucion = parc_solucion;
		}
	}
	else {
		belen(escaparate, marcas, objetos, presupuesto, solucion, parc_solucion, k + 1);
	}
}

bool resuelveCaso() {
	int n, coste;
	vector <figura> escaparate;
	figura sol, parcial;
	vector <bool> marcas;
	cin >> n >> coste;

	if (!cin) { return false; }

	escaparate.resize(n);
	marcas.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> escaparate[i].coste >> escaparate[i].area;
	}

	parcial.area = 0;
	parcial.coste = 0;
	sol.area = 0;
	sol.coste = 0;

	belen(escaparate, marcas, n, coste, sol, parcial, 0);

	cout << sol.area << endl;

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