#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(int costemin, int solucion, int local, int ciu, int k) {

	if ((local + (ciu - k) * costemin) >= solucion) { return false; }
	return true;
}

void viaje(vector<int> &tour, vector<bool> &marcas, const vector<vector<int>> &matriz, int ciu, int & solucion, int sol_parc, int costemin, int k) {
	int local;

	for (int i = 1; i < ciu; ++i) {
		if (!marcas[i]) {
			tour[k] = i;
			local = sol_parc + matriz[tour[k - 1]][i];
			if (esValida(costemin, solucion, local, ciu, k)) {
				marcas[i] = true;
				if (k == (ciu-1)) {
					local += matriz[0][i];
					if (local < solucion) {
						solucion = local;
					}
				}
				else {
					viaje(tour, marcas, matriz, ciu, solucion, local, costemin, k + 1);
				}
				marcas[i] = false;
			}
		}
	}
}

bool resuelveCaso() {
	vector<int> tour;
	vector<vector<int>> matriz;
	vector<int> aux;
	vector<bool> marcas;
	int ciu, sol, costemin = 500;

	cin >> ciu;
	if (ciu == 0) { return false; }
	tour.resize(ciu);
	marcas.resize(ciu);
	costemin = 500 * ciu;
	for (int i = 0; i < ciu; i++) {
		aux.resize(ciu);
		for (int j = 0; j < ciu; j++) {
			cin >> aux[j];
			if (aux[j] != 0 && aux[j] < costemin) {
				costemin = aux[j];
			}
		}
		matriz.push_back(aux);
	}
	sol = 0;
	for (int i = 1; i < ciu; i++) {
		sol += matriz[i][i - 1];
	}
	sol += matriz[0][ciu - 1];
	tour[0] = 0;
	marcas[0] = true;

	viaje(tour, marcas, matriz, ciu, sol, 0, costemin, 1);

	cout << sol << endl;

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