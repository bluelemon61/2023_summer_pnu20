#include <iostream>
#include <cstdlib>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int input;
    int abs_input;
    int i, j, temp;
    int heap_index;
    int parent, child;
    int *heap;

    cin>>n;
    heap = new int[n+1];
    heap_index = 0;

    for (i=0; i<n; i++){
        cin>>input;
        if (input == 0){
            if (heap_index == 0){
                cout<<"0\n";
            }
            else {
                cout<<heap[1]<<'\n';
                temp = heap[heap_index--];
                abs_input = abs(temp);
                parent = 1;
                child = 2;

                while (child <= heap_index){
                    if ((child < heap_index) && (abs(heap[child]) >= abs(heap[child+1]))){
                        if (abs(heap[child]) == abs(heap[child+1])){
                            if (heap[child] > heap[child+1])
                                child++;
                        }
                        else {
                            child++;
                        }
                    }
                    if (abs_input <= abs(heap[child])){
                        if (abs_input == abs(heap[j/2])){
                            if (temp <= heap[j/2]){
                                break;
                            }
                        }
                        else {
                            break;
                        }
                    }
                    heap[parent] = heap[child];
                    parent = child;
                    child *= 2;
                }
                heap[parent] = temp;
            } 
        }
        else {
            abs_input = abs(input);
            j = ++heap_index;
            while ((j != 1) && (abs_input <= abs(heap[j/2]))){
                if (abs_input == abs(heap[j/2])){
                    if (input > heap[j/2])
                        break;  
                }
                heap[j] = heap[j/2];
                j /= 2;
            }
            heap[j] = input;
        }
    }

    return 0;
}