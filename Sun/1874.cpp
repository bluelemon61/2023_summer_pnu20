#include <iostream>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::stack;

int main(void){
    
    stack<int> s_sequence; // ������ ����� ���� stack
    char *result;          // ��°��� ������ char �迭
    int result_index=0;    // �Է��� result�� index 
    int result_true=1;     // ������ �������� �˷��ִ� ��
    int number;            // ù �� �Է°�
    int input_sequence;    // pop �ؾ��� ������ ��
    int stack_number=1;    // ������ ����� ���ؼ� stack�� push�� ��

    cin>>number;
    result = new char[number*2 + 1]; 

    for (int i=0; i<number; i++){
        cin>>input_sequence;
        //cout<<"input number is "<<input_sequence<<endl;
        
        while(1){

            if (result_true == 0 ) break;
            if (s_sequence.empty() == 1){                        // stack�� ������� ���
                //cout<<"stack is empty"<<endl;
                //cout<<"push "<<stack_number<<endl;
                s_sequence.push(stack_number);                   // stack_number�� push�ϰ� 
                stack_number++;                                
                result[result_index] = '+';                      // result�� + ����
                result_index++;
            }

            if (s_sequence.top() == input_sequence){             // �Է°��� stack�� top�� ������ ���  
                //cout<<"pop"<<endl;
                s_sequence.pop();                                // pop�� �ϰ� 
                result[result_index] = '-';                      // result�� - ����
                result_index++;
                break;
            }
            else {
                if (s_sequence.top() < input_sequence){          // �Է°��� top���� ū ��� 
                    //cout<<"push "<<stack_number<<endl;
                    s_sequence.push(stack_number);               // stack_number�� push�ϰ� 
                    stack_number++;
                    result[result_index] = '+';                  // result�� + ����
                    result_index++;
                }
                else if (s_sequence.top() > input_sequence){     // �Է°��� top���� ���� ���� ������ ���� �� ����.
                    result_true = 0;                             // result_true�� ���� 0���� ����
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