#include <iostream>
#include <stack>
using std::cin;
using std::cout;
using std::stack;

int main(void){
    
    stack<int> s;
    int repeat_count;
    int input_value;
    int stack_size;
    int stack_sum;

    cin>>repeat_count;
    for (int i=0; i<repeat_count; i++){
        cin>>input_value;
        if (input_value == 0){
            s.pop();
        }
        else {
            s.push(input_value);
        }

    }

    stack_size = s.size();
    stack_sum = 0;

    for (int i=0; i<stack_size; i++){
        stack_sum += s.top();
        s.pop();
    }
    cout<<stack_sum;

    return 0;
}