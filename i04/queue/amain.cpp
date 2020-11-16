#include "Exceptions.h"
#include "Queue.h"
#include <iostream>
using namespace std;

int main() {

	int cases, n, num, pos;
	cin >> cases;

	for (int i = 0; i < cases; ++i) {
		Queue<int>* q = new Queue<int>();
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >> num;
			q->push(num);
		}
		cin >> pos;
		q->penalizeElement(pos);

		for (int j = 0; j < n; ++j) {
			cout << q->front() << " ";
			q->pop();
		}
		cout << endl;
	}

	return 0;
}
