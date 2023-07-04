#include <iostream>
#include <cstring>
#include <deque>
using std::cout;
using std::cin;
using std::endl;
using std::deque;

int main(void){

    deque<int> d;
    int repeat_count;
    char instruction[12];
    int push_value;
    int pop_value;

    cin>>repeat_count;
    for(int i=0; i<repeat_count; i++){
        cin>>instruction;
        if (strcmp(instruction, "push_front") == 0){
            cin>>push_value;
            d.push_front(push_value);
        }
        else if (strcmp(instruction, "push_back") == 0){
            cin>>push_value;
            d.push_back(push_value);
        }
        else if (strcmp(instruction, "pop_front") == 0){
            if (d.empty() == 1){
                cout<<-1<<endl;
            }
            else{
                cout<<d.front()<<endl;
                d.pop_front();
            }
        }
        else if (strcmp(instruction, "pop_back") == 0){
            if (d.empty() == 1){
                cout<<-1<<endl;
            }
            else {
                cout<<d.back()<<endl;
                d.pop_back();
            }
        }
        else if (strcmp(instruction, "size") == 0){
            cout<<d.size()<<endl;
        }
        else if (strcmp(instruction, "empty") == 0){
            cout<<d.empty()<<endl;
        }
        else if (strcmp(instruction, "front") == 0){
            if (d.empty() == 1){
                cout<<-1<<endl;
            }
            else {
                cout<<d.front()<<endl;
            }
        }
        else if (strcmp(instruction, "back") == 0){
            if (d.empty() == 1){
                cout<<-1<<endl;
            }
            else{
                cout<<d.back()<<endl;
            }
        }
        else {
            return 1;
        }
    }
    return 0;
}