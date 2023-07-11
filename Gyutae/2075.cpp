#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int ni;
		cin >> ni;
		pq.push(ni);
		if (pq.size() > n) {
			pq.pop();
		}
	}

	cout << pq.top() << "\n";
	return 0;
}