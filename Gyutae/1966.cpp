#include <iostream>
using namespace std;

class Document {
private:
	int index;
	int priority;
public:
	Document(int index, int priority) : index(index), priority(priority) { }
	int getIndex() { return index; }
	int getPriority() { return priority; }
	friend struct cmp;
};;

class myPriorityQueue {
private:
	Document** pq;
	Document* queuePop();
	int size;
public:
	myPriorityQueue() { size = 0; pq = 0; }
	myPriorityQueue(int maxsize) : size(0) { pq = new Document* [maxsize]; }
	bool isEmpty() { return !size; }
	Document* pop();
	void push(Document*);
};

class printQueue {
private:
	myPriorityQueue* q;
	int numofDoc;
	int target;
public:
	printQueue(int numofDoc, int target);
	void printAnswer();
};

int main() {
	int n;
	cin >> n;
	printQueue** que = new printQueue*[n];

	for (int i = 0; i < n; i++) {
		int numofDoc, target;
		cin >> numofDoc;
		cin >> target;
		que[i] = new printQueue(numofDoc, target);
		que[i]->printAnswer();
	}
	return 0;
}

Document* myPriorityQueue::queuePop() {
	Document* result = pq[0];
	for (int i = 0; i < size - 1; i++) {
		pq[i] = pq[i + 1];
	}
	size--;
	return result;
}

Document* myPriorityQueue::pop() {
	for (int i = 1; i < size; i++) {
		if (pq[0]->getPriority() < pq[i]->getPriority()) {
			push(queuePop());
			i = 0;
		}
	}
	return queuePop();
}

void myPriorityQueue::push(Document* x) {
	pq[size] = x;
	size++;
}

printQueue::printQueue(int numofDoc, int target): numofDoc(numofDoc), target(target) {
	q = new myPriorityQueue(numofDoc);
	for (int i = 0; i < numofDoc; i++) {
		int priority;
		cin >> priority;
		Document* x = new Document(i, priority);
		q->push(x);
	}
}

void printQueue::printAnswer() {
	int i = 1;
	while (1) {
		Document* temp = q->pop();
		if (temp->getIndex() == target) {
			break;
		}
		i++;
	}
	cout << i << "\n";
}