#include <iostream>
#include <stack>
using namespace std;

int command();

int main() {
	stack<int> s;
	int max;
	cin >> max;
	for (int i = 0; i < max; i++) {
		switch (command()) {
		case 0: // push
		{
			int x;
			cin >> x;
			s.push(x);
			break;
		}
		case 1: // pop
			if (s.empty())
				cout << -1 << endl;
			else {
				cout << s.top() << endl;
				s.pop();
			}
			break;
		case 2: // size
			cout << s.size() << endl;
			break;
		case 3: // empty
			cout << s.empty() << endl;
			break;
		case 4: // top
			if (s.empty())
				cout << -1 << endl;
			else
				cout << s.top() << endl;
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
	else if (cmd.compare("top") == 0) {
		return 4;
	}
	else {
		return -1;
	}
}