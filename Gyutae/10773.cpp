#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> transaction;
	int K;
	cin >> K;
	int num;

	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num) {
			transaction.push(num);
		}
		else { // wrong number!
			transaction.pop();
		}
	}

	int size = transaction.size();
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += transaction.top(); // add the top of stack
		transaction.pop(); // and pop
	}
	
	cout << sum << endl;
	return 0;
}