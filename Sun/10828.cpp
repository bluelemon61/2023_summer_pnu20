#include <iostream>
#include <cstring>
#include <stack>
using std::cout;
using std::cin;
using std::endl;
using std::stack;

int main(void){
    
    stack<int> s;
    int insturction_count;
    char instruction[7];
    int push_value;
    int pop_value;

    cin>>insturction_count;

    for (int i=0; i<insturction_count; i++){
        cin>>instruction;
        if (strcmp(instruction, "push") == 0){
            cin>>push_value;
            s.push(push_value);
        }
        else if (strcmp(instruction, "pop") == 0){
            if (s.empty() == 1){
                cout<<-1<<endl;
            }
            else {
                cout<<s.top()<<endl;
                s.pop();
            }
        }
        else if (strcmp(instruction, "size") == 0){
            cout<<s.size()<<endl;
        }
        else if (strcmp(instruction, "empty") == 0){
            cout<<s.empty()<<endl;
        }
        else if (strcmp(instruction, "top") == 0){
            if (s.empty() == 1){
                cout<<-1<<endl;
            }
            else {
                cout<<s.top()<<endl;
            }
        }
        else {
            return 1;
        }
    }

    return 0;
}