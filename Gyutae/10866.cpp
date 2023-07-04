#include <iostream>
using namespace std;

void push_front(int, int*, int&);
void push_back(int, int*, int&);
int pop_front(int*, int&);
int pop_back(int*, int&);

int command() {
	string cmd;
	cin >> cmd;
	if (cmd.compare( "push_front") == 0) {
		return 0;
	}
	else if (cmd.compare("push_back") == 0) {
		return 1;
	}
	else if (cmd.compare("pop_front") == 0) {
		return 2;
	}
	else if (cmd.compare("pop_back") == 0) {
		return 3;
	}
	else if (cmd.compare("size") == 0) {
		return 4;
	}
	else if (cmd.compare("empty") == 0) {
		return 5;
	}
	else if (cmd.compare("front") == 0) {
		return 6;
	}
	else if (cmd.compare("back") == 0) {
		return 7;
	}
	else {
		return -1;
	}
}

int main() {
	int max_size; // max deque size must be less than the number of instructions.
	int size = 0;
	cin >> max_size;
	int x;
	int* deque = new int[max_size];

	for (int i = 0; i < max_size; i++) {
		switch (command()) {
		case 0:
			cin >> x;
			push_front(x, deque, size);
			break;
		case 1:
			cin >> x;
			push_back(x, deque, size);
			break;
		case 2:
			cout << pop_front(deque, size) << endl;
			break;
		case 3:
			cout << pop_back(deque, size) << endl;
			break;
		case 4:
			cout << size << endl;
			break;
		case 5:
			cout << (size == 0) << endl;
			break;
		case 6:
			if (size) {
				cout << deque[0] << endl;
			}
			else {
				cout << -1 << endl;
			}
			break;
		case 7:
			if (size) {
				cout << deque[size - 1] << endl;
			}
			else {
				cout << -1 << endl;
			}
			break;
		default:
			break;
		}
	}
	return 0;
}

void push_front(int x, int* deq, int& size) {
	for (int i = size - 1; i >= 0; i--) {
		deq[i + 1] = deq[i];
	}
	deq[0] = x;
	size++;
}

void push_back(int x, int* deq, int& size) {
	deq[size] = x;
	size++;
}

int pop_front(int* deque, int& size) {
	if (size == 0) {
		return -1;
	}
	int popped = deque[0];
	for (int i = 0; i < size - 1; i++) {
		deque[i] = deque[i + 1];
	}
	size--;
	return popped;
}

int pop_back(int* deque, int& size) {
	if (size == 0) {
		return -1;
	}
	int popped = deque[size - 1];
	size--;
	return popped;
}