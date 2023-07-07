#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stack<int> stk;
	int cnt, a, size = 0, sum = 0; cin >> cnt;
	if (cnt < 1 || cnt > 100000) return 0;
	for (int i = 0; i < cnt; i++) {
		cin >> a;
		if (a != 0) { stk.push(a); sum += a;  }
		else if (a == 0) { sum -= stk.top(); stk.pop(); }
	}
	cout << sum << "\n";
	return 0;
}