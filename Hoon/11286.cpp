#include <iostream>
#include <cstdlib>

using namespace std;

bool abs_big(int parent, int child) {
    // cout << parent << " > " << child << "\n";
    if (abs(parent) > abs(child)) {
        return true;
    }
    if (parent + child == 0 && parent > 0) {
        return true;
    }
    // cout << "false" << "\n";
    return false;
}

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
        cout << "Heap: ";
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

    while (parent) {
        if (abs_big(arr[parent], arr[target])) {
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
    // cout << "Pop" << "\n";
    if(len==0) {
        return 0;
    }
    int result = arr[1];
    arr[1] = arr[len--];

    int num = arr[1];
    int target = 1;
    int child = target*2;
    
    while(child <= len){
        // this->Show();
        if (child < len && abs_big(arr[child], arr[child+1]))
            child++;
        
        if (abs_big(arr[target] , arr[child])) {
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
        // cout << "input: " << num << "\n";
        if(num){
            hp->Push(num);
        } else {
            cout << hp->Pop() << "\n";
        }
        // hp->Show();
    }

    return 0;
}