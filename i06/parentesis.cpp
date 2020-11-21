#include <iostream>
#include "Exceptions.h"
#include "StackLL.h"
#include <string>
using namespace std;

int main() {

	int n, j = 0;
	string str;
	bool fin = false;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		StackLL<char>* stack = new StackLL<char>();

		while (j < str.length() && !fin) {
			
			if (str[j] == '(' || str[j] == '[' || str[j] == '{') {
				stack->push(str[j]);
			}
			else if (!stack->empty()) {
				if (str[j] == ')' && stack->top() == '(') {
					stack->pop();
				}
				else if (str[j] == ']' && stack->top() == '[') {
					stack->pop();
				}
				else if (str[j] == '}' && stack->top() == '{') {
					stack->pop();
				}

			}
			else {
				fin = true;
			}

			++j;
		}

		if (fin || !stack->empty()) {
			cout << "no" << endl;
		}
		else {
			cout << "yes" << endl;
		}

		fin = false;
		j = 0;
	}


	return 0;
}
