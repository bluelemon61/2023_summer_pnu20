#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Heap { // Priority Queue
private:
    int* arr;
    int len = 0;
public:
    Heap(int size){
        arr = new int[size+1];
    }
    ~Heap(){
        delete[] arr;
    }
    void Push(vector<stack<int>>& data, int num);
    int Pop(vector<stack<int>>& data);
    void Show(){
        for (int i = 1; i<=len; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

void Heap::Push(vector<stack<int>>& data, int num) {
    arr[++len] = num;
    int target = len;
    int parent = len/2;

    while(parent){
        if (data[arr[parent]].top() < data[arr[target]].top()) {
            arr[target] = arr[parent];
            arr[parent] = num;
        } else {
            break;
        }
        target = parent;
        parent = target/2;
    }
}

int Heap::Pop(vector<stack<int>>& data) {
    int result = arr[1];
    arr[1] = arr[len--];

    int num = arr[1];
    int target = 1;
    int child = target*2;
    
    while(child <= len){
        if (child < len && data[arr[child]].top() < data[arr[child+1]].top())
            child++;
        
        if (data[arr[child]].top() > data[arr[target]].top()) {
            arr[target] = arr[child];
            arr[child] = num;
        } else {
            break;
        }

        target = child;
        child = target*2;
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int result;

    Heap* hp = new Heap(n); // Priority Queue

    // stack<int>* nn = new stack<int>[n];
    /*
    Note that using raw arrays (new stack<int>[n]) 
    in this case may lead to potential memory management issues
    */
    vector<stack<int>> nn(n); // n of stack nn[n]

    int num;
    for (int i = 0; i < n*n; i++) { // input
        cin >> num;
        nn[i%n].push(num);
    }
    // cout << "input clear\n";

    for(int i = 0; i < n; i++) { // initialize
        hp->Push(nn, i);
    }
    // cout << "initialize clear\n";

    /*
    Save the index of Stack Array("nn") to Heap and sort by nn[i].top()
    And for(n), Pop from Heap. Finally print the result.
    */

    int index;
    for(int i = 0; i < n; i++) {
        index = hp->Pop(nn);
        result = nn[index].top();
        // for (int j = 0; j < n; j++) {
        //     cout << nn[j].top() << " ";
        // }
        // cout << "\n";
        
        nn[index].pop();
        if (!nn[index].empty()) {
            hp->Push(nn, index);
        }
    }

    cout << result << "\n";

    delete hp;
    return 0;
}