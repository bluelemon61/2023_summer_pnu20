#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

void push(queue<int>* q){
    // cout << q << endl;
    int x = 0;
    cin >> x;
    q->push(x);
}

void pop(queue<int>* q){
    if (q->empty()) cout << -1 << "\n";
    else {
        cout << q->front() << "\n";
        q->pop();
    }
}

void size(queue<int>* q){
    cout << q->size() << "\n";
}

void empty(queue<int>* q){
    cout << q->empty() << "\n";
}

void front(queue<int>* q){
    if (q->empty()) cout << -1 << "\n";
    else cout << q->front() << "\n";
}

void back(queue<int>* q){
    if (q->empty()) cout << -1 << "\n";
    else cout << q->back() << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 0;
    cin >> n;

    queue<int> q;
    // cout << &q << endl;
    map<string, void(*) (queue<int>*)> queue_func = {
        {"push", push},
        {"pop", pop},
        {"size", size},
        {"empty", empty},
        {"front", front},
        {"back", back}
    };

    string inst;
    for (int i = 0; i < n; i++) {
        cin >> inst;
        queue_func[inst](&q);
    }

    return 0;
}