#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	stack<int> s; // indexes that don't have nge
	int n;
	cin >> n;
	int* A = new int[n];
	int* NGE = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		NGE[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		while (!s.empty() && A[i] > A[s.top()]) {
			NGE[s.top()] = A[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n - 1; i++) {
		cout << NGE[i] << " ";
	}
	cout << "-1\n";
	return 0;
}