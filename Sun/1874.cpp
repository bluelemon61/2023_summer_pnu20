#include <iostream>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::stack;

int main(void){
    
    stack<int> s_sequence; // 수열을 만들기 위한 stack
    char *result;          // 출력값을 저장할 char 배열
    int result_index=0;    // 입력할 result의 index 
    int result_true=1;     // 수열이 가능한지 알려주는 값
    int number;            // 첫 줄 입력값
    int input_sequence;    // pop 해야할 수열의 값
    int stack_number=1;    // 수열을 만들기 위해서 stack에 push할 값

    cin>>number;
    result = new char[number*2 + 1]; 

    for (int i=0; i<number; i++){
        cin>>input_sequence;
        //cout<<"input number is "<<input_sequence<<endl;
        
        while(1){

            if (result_true == 0 ) break;
            if (s_sequence.empty() == 1){                        // stack이 비어있을 경우
                //cout<<"stack is empty"<<endl;
                //cout<<"push "<<stack_number<<endl;
                s_sequence.push(stack_number);                   // stack_number를 push하고 
                stack_number++;                                
                result[result_index] = '+';                      // result에 + 저장
                result_index++;
            }

            if (s_sequence.top() == input_sequence){             // 입력값이 stack의 top과 동일한 경우  
                //cout<<"pop"<<endl;
                s_sequence.pop();                                // pop을 하고 
                result[result_index] = '-';                      // result에 - 저장
                result_index++;
                break;
            }
            else {
                if (s_sequence.top() < input_sequence){          // 입력값이 top보다 큰 경우 
                    //cout<<"push "<<stack_number<<endl;
                    s_sequence.push(stack_number);               // stack_number를 push하고 
                    stack_number++;
                    result[result_index] = '+';                  // result에 + 저장
                    result_index++;
                }
                else if (s_sequence.top() > input_sequence){     // 입력값이 top보다 작은 경우는 수열을 만들 수 없다.
                    result_true = 0;                             // result_true의 값을 0으로 변경
                    break;
                }
            }
        }
    }
    if (result_true == 0){
        cout<<"NO"<<'\n';
    }
    else {
        for (int i=0; i<number*2; i++){
            cout<<result[i]<<'\n';
        }
    }

    
    return 0;
}