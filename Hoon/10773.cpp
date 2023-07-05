#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 0;
    cin >> n;

    stack<int> st;

    string inst;
    int number;
    for (int i = 0; i < n; i++) {
        cin >> number;
        if (number) st.push(number);
        else st.pop();
    }

    int sum = 0;
    while(!st.empty()) {
        sum += st.top();
        st.pop();
    }

    cout << sum << "\n";

    return 0;
}