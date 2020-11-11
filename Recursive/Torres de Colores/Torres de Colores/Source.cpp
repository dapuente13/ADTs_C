#include <iostream>
#include <vector>
#include <fstream>
using namespace std; 

typedef enum{A, R, V};

void imprimir(const vector<int>& torre, int altura) {
	for (int i = 0; i < altura; ++i) {
		if (torre[i] == A) {
			cout << "azul ";
		}
		else if (torre[i] == R) {
			cout << "rojo ";
		}
		else {
			cout << "verde ";
		}
	}
	cout << endl;
}

bool esValida(const vector<int>& torre, vector<int>& marcas, int azul, int rojo, int verde, int color, int k, int altura) {

	
	if (color == A) {
		if (marcas[A] == azul) { return false; }
	}
	if (color == R) {
		if (marcas[R] == rojo) {return false;}
	}
	if (color == V) {
		if (marcas[V] == verde) { return false; }
	}
	if (k == 0 && color != R) { return false; }
	if (color == V && torre[k - 1] == V) { return false; }
	if (color == V && marcas[V] == marcas[A]) { return false; }
	if (k == (altura - 1)) {
		++marcas[color];
		if (marcas[R] <= (marcas[V] + marcas[A])) {
			--marcas[color];
			return false;
		}
		else {
			--marcas[color];
		}
	}
	return true;
}

void construir(vector<int>& torre, vector<int> &marcas, int altura, int azul, int rojo, int verde, bool &haytorre, int k) {
	for (int i = 0; i < 3; ++i) {
		torre[k] = i;
		if (esValida(torre, marcas, azul, rojo, verde, i, k, altura)) {
			++marcas[i];
			if (k == (altura-1)) {
				imprimir(torre, altura);
				haytorre = true;
			}
			else {
				construir(torre, marcas, altura, azul, rojo, verde, haytorre, k+1);
			}
			--marcas[i];
		}
	}
}

bool resuelveCaso() {
	vector<int> torre; //tupla
	int azul, rojo, verde, altura;
	vector<int> marcas; //cuenta de piezas colocadas
	bool haytorre = false;

	cin >> altura >> azul >> rojo >> verde;
	if ((altura + azul + rojo + verde) == 0) { return false; }
	torre.resize(altura);
	marcas.resize(3);

	construir(torre, marcas, altura, azul, rojo, verde, haytorre, 0);

	if (!haytorre) {
		cout << "SIN SOLUCION" << endl << endl;
	}
	else {
		cout << endl;
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