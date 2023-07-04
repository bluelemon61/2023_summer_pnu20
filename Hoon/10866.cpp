#include <iostream>
#include <string>
#include <deque>
#include <map>

using namespace std;

void push_front(deque<int>* q){
    // cout << q << endl;
    int x = 0;
    cin >> x;
    q->push_front(x);
}

void push_back(deque<int>* q){
    // cout << q << endl;
    int x = 0;
    cin >> x;
    q->push_back(x);
}

void pop_front(deque<int>* q){
    if (q->empty()) cout << -1 << "\n";
    else {
        cout << q->front() << "\n";
        q->pop_front();
    }
}

void pop_back(deque<int>* q){
    if (q->empty()) cout << -1 << "\n";
    else {
        cout << q->back() << "\n";
        q->pop_back();
    }
}

void size(deque<int>* q){
    cout << q->size() << "\n";
}

void empty(deque<int>* q){
    cout << q->empty() << "\n";
}

void front(deque<int>* q){
    if (q->empty()) cout << -1 << "\n";
    else cout << q->front() << "\n";
}

void back(deque<int>* q){
    if (q->empty()) cout << -1 << "\n";
    else cout << q->back() << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 0;
    cin >> n;

    deque<int> dq;
    // cout << &q << endl;
    map<string, void(*) (deque<int>*)> deque_func = {
        {"push_front", push_front},
        {"push_back", push_back},
        {"pop_front", pop_front},
        {"pop_back", pop_back},
        {"size", size},
        {"empty", empty},
        {"front", front},
        {"back", back}
    };

    string inst;
    for (int i = 0; i < n; i++) {
        cin >> inst;
        deque_func[inst](&dq);
    }

    return 0;
}