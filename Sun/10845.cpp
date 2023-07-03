#include <iostream>
#include <cstring>
#include <queue>
using std::queue;
using std::cin;
using std::cout;
using std::endl;

int main(void){

    queue<int> q;
    int instruction_number;
    char instruction[7];
    int push_value; 
    int pop_value;

    cin>>instruction_number;
    
    for (int i=0; i<instruction_number; i++){
        cin>>instruction;
        if (strcmp(instruction, "push") == 0){
            cin>>push_value;
            q.push(push_value);
        }
        else if (strcmp(instruction, "pop") == 0){
            if (q.empty() == 1){
                cout<<-1<<endl;
            }
            else {
                cout<<q.front()<<endl;
                q.pop();
            }
        }
        else if (strcmp(instruction, "size") == 0){
            cout<<q.size()<<endl;
        }
        else if (strcmp(instruction, "empty") == 0){
            cout<<q.empty()<<endl;
        }
        else if (strcmp(instruction, "front") == 0){
            if (q.empty() == 1){
                cout<<-1<<endl;
            }
            else {
                cout<<q.front()<<endl;
            }
        }
        else if (strcmp(instruction, "back") == 0){
            if (q.empty() == 1){
                cout<<-1<<endl;
            }
            else {
                cout<<q.back()<<endl;
            }
        }
        else {
            return 1;
        }
    }

    return 0;
}
