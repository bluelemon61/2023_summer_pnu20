#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}

	int result = 0;
	while (pq.size() != 1) {
		int temp = pq.top();
		pq.pop();
		temp += pq.top();
		pq.pop();
		result += temp;
		pq.push(temp);
	}

	cout << result << "\n";
	return 0;
}