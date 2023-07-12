#include <iostream>
#include <queue>
using namespace std;

int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<int> file;              // file�� ����
    queue<int> importance_list;   // �� file�� �߿䵵�� ������� ����
    priority_queue<int> pq;
    
    int test_case;                // test case�� ��
    int total_file;               // test case���� ��ü file�� ���� 
    int file_no;                  // test case���� �˰� ���� file�� ��ȣ
    int input_importance;
    int most_important;           // ���� file�� �߿䵵 �� ���� ���� ��
    int result;                   // �� test case������ ���
    int *result_list;             // ��� test case�� ���


    cin>>test_case;
    result_list = new int[test_case];

    for (int i=0; i<test_case; i++){
        cin>>total_file>>file_no;
        for (int j=0; j<total_file; j++){             
            cin>>input_importance;                            // �߿䵵�� �Է¹����� ���ÿ� 
            file.push(j);                                     // file�� ��ȣ�� �����ϰ�
            importance_list.push(input_importance);     
            pq.push(input_importance);                        // �߿䵵�� �켱����ť�� ����
            //cout<<"file : "<<file.front()<<" importance : "<<importance_list.front()<<endl;
        }
        result = 0;
        most_important = pq.top();                            // �� �ݺ� ���� �켱���� ť�� ����� �߿䵵�� ������
        pq.pop();
        //cout<<"most important : "<<most_important<<endl;
        while (file.empty() == 0){
            if (importance_list.front() == most_important){   // ���� ���� �߿䵵�� importance_list�� front�� ������ ���(pop)
                if (file.front() == file_no){                 // ��� ������ �˰� ���� file�� ���
                    result++;
                    //cout<<"result : "<<result<<endl;
                    break;
                }
                file.pop();                                   // 3���� queue ���� pop
                importance_list.pop();
                most_important = pq.top();
                pq.pop();
                result++;
                //cout<<"most important : "<<most_important<<endl;
            }
            else {                                  
                //cout<<"file.front : "<<file.front()<<" important.front : "<<importance_list.front()<<endl; 
                file.push(file.front());
                importance_list.push(importance_list.front());
                file.pop();
                importance_list.pop();
            }
        }
        
        result_list[i] = result;                              // result�� result list�� ����

        file = queue<int>();
        importance_list = queue<int>();
        pq = priority_queue<int>();
    }

    for (int i=0; i<test_case; i++){
        cout<<result_list[i]<<'\n';
    }


    return 0;
}