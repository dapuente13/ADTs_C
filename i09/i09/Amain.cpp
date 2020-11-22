#include "Bintree.h"
#include <iostream>
#include <string>
using namespace std;

Bintree<char> rellenarTree() {
	char c;
	cin >> c;

	if (c == '(') {
		Bintree<char> left, right;

		left = rellenarTree();
		char root;
		cin >> root;
		right = rellenarTree();
		cin >> c;

		return Bintree<char>(left, root, right);
	}
	else if (c == '[') {
		char num;
		cin >> num;
		cin >> c;
		return Bintree<char>(num);
	}
	else if (c == '#') {
		return Bintree<char>();
	}
	else {
		return Bintree<char>();
	}
}

bool BrakeRule(Bintree<char> tree, int &brakerule) {

	if (tree.empty()) {
		return false;
	}

	bool left = BrakeRule(tree.leftChild(), brakerule);
	bool right = BrakeRule(tree.rightChild(), brakerule);

	if (tree.root() == 'P') {
		if (!left && !right) {
			brakerule++;
			return false;
		}
		else {
			return true;
		}
	}
	else if (tree.root() == 'S') {
		return true;
	}
	return false;
}

int main() {
	int n, brakerule = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		Bintree<char> tree = rellenarTree();
		BrakeRule(tree, brakerule);
		cout << brakerule << endl;
		brakerule = 0;
	}

	return 0;
}
