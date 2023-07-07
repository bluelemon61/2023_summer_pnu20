#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	queue<int> q;
	int cnt, a, size = 0; cin >> cnt;
	if (cnt < 1 || cnt > 10000) return 0;
	for (int i = 0; i < cnt; i++) {
		string cmd; cin >> cmd;
		if (cmd == "push") { cin >> a; q.push(a); size++; }
		else if (cmd == "pop") { cout << (size == 0 ? -1 : q.front()) << "\n"; if (size > 0) { q.pop(); size--; } }
		else if (cmd == "size") { cout << q.size() << "\n"; }
		else if (cmd == "empty") { cout << q.empty() << "\n"; }
		else if (cmd == "front") { cout << (size == 0 ? -1 : q.front()) << "\n"; }
		else if (cmd == "back") { cout << (size == 0 ? -1 : q.back()) << "\n"; }
	}

	return 0;
}