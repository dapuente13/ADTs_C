#include <iostream>
#include "StackLL.h"
#include <string>
using namespace std;

int main() {
	int n, op1, op2;
	string str;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		StackLL<int> stack;
		cin >> str;
		while (str != "end") {
			if (str != "+" && str != "-" && str != "*") {
				stack.push(stoi(str));
			}
			else {
				op1 = stack.top();
				stack.pop();
				op2 = stack.top();
				stack.pop();
				if (str == "+") {
					stack.push(op2 + op1);
				}
				else if (str == "-") {
					stack.push(op2 - op1);
				}
				else if (str == "*") {
					stack.push(op2 * op1);
				}
			}
			cin >> str;
		}
		cout << stack.top() << endl;
	}


	return 0;
}
