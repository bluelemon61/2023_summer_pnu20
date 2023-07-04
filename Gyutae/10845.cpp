#include <iostream>
#include <queue>
using namespace std;

int command();

int main() {
	queue<int> q;
	int max;
	cin >> max;
	for (int i = 0; i < max; i++) {
		switch (command()) {
		case 0: // push
		{
			int x;
			cin >> x;
			q.push(x);
			break;
		}
		case 1: // pop
			if (q.empty())
				cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
			break;
		case 2: // size
			cout << q.size() << endl;
			break;
		case 3: // empty
			cout << q.empty() << endl;
			break;
		case 4: // front
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.front() << endl;
			break;
		case 5: // back
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.back() << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}

int command() {
	string cmd;
	cin >> cmd;
	if (cmd.compare("push") == 0) {
		return 0;
	}
	else if (cmd.compare("pop") == 0) {
		return 1;
	}
	else if (cmd.compare("size") == 0) {
		return 2;
	}
	else if (cmd.compare("empty") == 0) {
		return 3;
	}
	else if (cmd.compare("front") == 0) {
		return 4;
	}
	else if (cmd.compare("back") == 0) {
		return 5;
	}
	else {
		return -1;
	}
}