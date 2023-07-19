#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

void push(stack<int>* q){
    // cout << q << endl;
    int x = 0;
    cin >> x;
    q->push(x);
}

void pop(stack<int>* q){
    if (q->empty()) cout << -1 << "\n";
    else {
        cout << q->top() << "\n";
        q->pop();
    }
}

void size(stack<int>* q){
    cout << q->size() << "\n";
}

void empty(stack<int>* q){
    cout << q->empty() << "\n";
}

void top(stack<int>* q){
    if (q->empty()) cout << -1 << "\n";
    else cout << q->top() << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 0;
    cin >> n;

    stack<int> st;
    // cout << &q << endl;
    map<string, void(*) (stack<int>*)> stack_func = {
        {"push", push},
        {"pop", pop},
        {"size", size},
        {"empty", empty},
        {"top", top}
    };

    string inst;
    for (int i = 0; i < n; i++) {
        cin >> inst;
        stack_func[inst](&st);
    }

    return 0;
}