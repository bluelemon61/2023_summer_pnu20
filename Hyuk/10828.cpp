#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stack<int> stk;
	int cnt, a, size = 0; cin >> cnt;
	if (cnt < 1 || cnt > 10000) return 0;
	for (int i = 0; i < cnt; i++) {
		string cmd; cin >> cmd;
		if (cmd == "push") { cin >> a; stk.push(a); size++; }
		else if (cmd == "pop") { cout << (size == 0 ? -1 : stk.top()) << "\n"; if (size > 0) { stk.pop(); size--; } }
		else if (cmd == "size") { cout << stk.size() << "\n"; }
		else if (cmd == "empty") { cout << stk.empty() << "\n"; }
		else if (cmd == "top") { cout << (size == 0 ? -1 : stk.top()) << "\n";}
	}

	return 0;
}