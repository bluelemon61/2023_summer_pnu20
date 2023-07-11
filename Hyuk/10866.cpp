#include <iostream>
#include <string>

using namespace std;

void push_front(int*, int, int);
void pop_front(int*, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt, a; cin >> cnt;
	int size = 0;
	if (cnt < 1 || cnt > 10000) return 0;
	int* deque = new int[cnt];
	for (int i = 0; i < cnt; i++) {
		string cmd; cin >> cmd;
		if (cmd == "push_front") { cin >> a; push_front(deque, a, size);  size++; }
		else if (cmd == "push_back") { cin >> a; deque[size] = a; size++; }
		else if (cmd == "pop_front") { cout << (size == 0 ? -1 : deque[0]) << "\n"; pop_front(deque, size); size == 0 ? size = 0 : size--; }
		else if (cmd == "pop_back") { cout << (size == 0 ? -1 : deque[size - 1]) << "\n";  size == 0 ? size = 0 : size--;}
		else if (cmd == "size") { cout << size << "\n";}
		else if (cmd == "empty") { cout << (size == 0) << "\n";}
		else if (cmd == "front") { cout << (size == 0 ? -1 : deque[0]) << "\n";}
		else if (cmd == "back") { cout << (size == 0 ? -1 : deque[size - 1]) << "\n";}
	}
	
	return 0;
}

void push_front(int* a ,int b, int size) {
	for (int i = 0; i < size; i++) { a[i + 1] = a[i]; }
	a[0] = b;
}

void pop_front(int* a, int size) {
	for (int i = 0; i < size - 1; i++) a[i] = a[i + 1];
}
