#include <iostream>
#include <vector>
using namespace std;

class MyPriorityQueue {
	vector<int> heap;
public:
	MyPriorityQueue() { heap.push_back(0); } // 1 base
	void Push(int x);
	int Pop();
	int Top() { return heap[1]; }
	void showQueue() {
		cout << "| ";
		for (int i = 0; i < heap.size(); i++) {
			cout << heap[i] << " ";
		}
		cout << "|\n";
	}
};

void MyPriorityQueue::Push(int x) {
	heap.push_back(x);
	int i = heap.size() - 1;
	while (i > 1) {
		if (heap[i] < heap[i / 2]) {
			int temp = heap[i];
			heap[i] = heap[i / 2];
			heap[i / 2] = temp;
			i /= 2;
		}
		else {
			break;
		}
	}
}

int MyPriorityQueue::Pop() {
	if (heap.size() == 1) {
		return 0;
	}
	int result = heap[1];
	heap[1] = heap[heap.size() - 1];
	heap.pop_back();
	for (int i = 1; i * 2 < heap.size();) {
		if (i * 2 + 1 < heap.size() && heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1]) {
			if (heap[2 * i] < heap[2 * i + 1]) {
				int temp = heap[i];
				heap[i] = heap[i * 2];
				heap[i * 2] = temp;
				i = i * 2;
			}
			else {
				int temp = heap[i];
				heap[i] = heap[i * 2 + 1];
				heap[i * 2 + 1] = temp;
				i = i * 2 + 1;
			}
		}
		else if (heap[i] > heap[i * 2]) {
			int temp = heap[i];
			heap[i] = heap[i * 2];
			heap[i * 2] = temp;
			i = i * 2;
		}
		else if (i * 2 + 1 < heap.size() && heap[i] > heap[i * 2 + 1]) {
			int temp = heap[i];
			heap[i] = heap[i * 2 + 1];
			heap[i * 2 + 1] = temp;
			i = i * 2 + 1;
		}
		else {
			break;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int size;
	cin >> size;
	MyPriorityQueue pq;
	for (int i = 0; i < size; i++) {
		int x;
		cin >> x;
		if (x) {
			pq.Push(x);
		}
		else {
			cout << pq.Pop() << "\n";
		}
	}
	return 0;
}