#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    int n;                // the number of input
    int input;            // each input value 
    int heap_index;       // the last index of heap 
    int j, temp;          
    int parent, child;
    int *heap;

    cin>>n;
    heap = new int[n+1];
    heap_index = 0;

    for (int i=0; i<n; i++){
        cin>>input;
        // If 0 is entered, print first element of heap
        if (input == 0) {
            // Haep is emtpy -> print 0
            if (heap_index == 0){
                cout<<0<<'\n';
            }
            else {
                cout<<heap[1]<<'\n';
                temp = heap[heap_index--];
                parent = 1;
                child = 2;

                while (child <= heap_index){
                    if ((child < heap_index) && (heap[child] > heap[child+1])){
                        child++;
                    }
                    if (temp <= heap[child]){
                        break;
                    }
                    heap[parent] = heap[child];
                    parent = child;
                    child = child * 2;
                }
                heap[parent] = temp;

                
            }
        }
        else {
            // J is next index to put input value
            // If input value is smaller than parent node of j, change parent node and child node until j is 1 
            j = ++heap_index;  
            while((j != 1) && (input < heap[j/2])){
                heap[j] = heap[j/2];
                j /= 2;
            }
            heap[j] = input;
        }
    }

    return 0;
}