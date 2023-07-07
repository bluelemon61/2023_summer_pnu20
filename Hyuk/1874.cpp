#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt, a = 1; cin >> cnt;
	stack<int> stk; vector<char> result;
	for (int i = 0; i < cnt; i++) {
		int x; cin >> x;
		for (a; a <= x;) {
			stk.push(a);
			a += 1;
			result.push_back('+');
		}
		if (stk.top() == x) {
			stk.pop();
			result.push_back('-');
		}
		else { cout << "NO"; return 0; }
		
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}
