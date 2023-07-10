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
    void Push(int num);
    int Pop();
    void Show(){
        for (int i = 1; i<=len; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

void Heap::Push(int num) {
    arr[++len] = num;
    int target = len;
    int parent = len/2;

    while(parent){
        if (arr[parent] > arr[target]) {
            arr[target] = arr[parent];
            arr[parent] = num;
        } else {
            break;
        }
        target = parent;
        parent = target/2;
    }
}

int Heap::Pop() {
    if(len==0) {
        return 0;
    }
    int result = arr[1];
    arr[1] = arr[len--];

    int num = arr[1];
    int target = 1;
    int child = target*2;
    
    while(child <= len){
        if (child < len && arr[child] > arr[child+1])
            child++;
        
        if (arr[child] < arr[target]) {
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    Heap* hp = new Heap(n);

    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(num){
            hp->Push(num);
        } else {
            cout << hp->Pop() << "\n";
        }
    }
}