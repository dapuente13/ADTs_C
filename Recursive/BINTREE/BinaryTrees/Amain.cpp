#include "Bintree.h"
#include <iostream>
#include <string>
using namespace std;


Bintree<int> rellenarTree() {
	char c;
	cin >> c;

	if (c == '(') {
		Bintree<int> left, right;
		
		left = rellenarTree(); 
		int root;
		cin >> root;
		right = rellenarTree();
		cin >> c;

		return Bintree<int>(left, root, right);
	}
	else if (c == '[') {
		int num;
		cin >> num;
		cin >> c;
		return Bintree<int>(num);
	}
	else if (c == '#') {
		return Bintree<int>();
	}
	else {
		return Bintree<int>();
	}
}

int special_product(Bintree<int> tree, int &special, int up_product) {
	
	if (tree.empty()) {
		return 1;
	}

	int product_leftchild = special_product(tree.leftChild(), special, up_product * tree.root());
	int product_rightchild = special_product(tree.rightChild(), special, up_product * tree.root());
	int totalproduct = product_leftchild * product_rightchild;
	
	if (up_product == totalproduct) {
		special++;
	}

	return totalproduct * tree.root();
}

int main() {
	int n, special = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		Bintree<int> tree;
		tree = rellenarTree();
		special_product(tree, special, 1);
		cout << special;
		if (i < n - 1) {
			cout << endl;
		}
		special = 0;
	}

	return 0;
}
