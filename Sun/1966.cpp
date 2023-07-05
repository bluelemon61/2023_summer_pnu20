#include <iostream>
#include <queue>
using namespace std;

int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<int> file;              // file을 저장
    queue<int> importance_list;   // 각 file의 중요도를 순서대로 저장
    priority_queue<int> pq;
    
    int test_case;                // test case의 수
    int total_file;               // test case에서 전체 file의 개수 
    int file_no;                  // test case에서 알고 싶은 file의 번호
    int input_importance;
    int most_important;           // 남은 file의 중요도 중 가장 높은 값
    int result;                   // 각 test case에서의 결과
    int *result_list;             // 모든 test case의 결과


    cin>>test_case;
    result_list = new int[test_case];

    for (int i=0; i<test_case; i++){
        cin>>total_file>>file_no;
        for (int j=0; j<total_file; j++){             
            cin>>input_importance;                            // 중요도를 입력받음과 동시에 
            file.push(j);                                     // file의 번호를 저장하고
            importance_list.push(input_importance);     
            pq.push(input_importance);                        // 중요도를 우선순위큐에 저장
            //cout<<"file : "<<file.front()<<" importance : "<<importance_list.front()<<endl;
        }
        result = 0;
        most_important = pq.top();                            // 각 반복 마다 우선순위 큐에 저장된 중요도를 가져옴
        pq.pop();
        //cout<<"most important : "<<most_important<<endl;
        while (file.empty() == 0){
            if (importance_list.front() == most_important){   // 가장 높은 중요도가 importance_list의 front와 같으면 출력(pop)
                if (file.front() == file_no){                 // 출력 순서를 알고 싶은 file일 경우
                    result++;
                    //cout<<"result : "<<result<<endl;
                    break;
                }
                file.pop();                                   // 3개의 queue 전부 pop
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
        
        result_list[i] = result;                              // result를 result list에 저장

        file = queue<int>();
        importance_list = queue<int>();
        pq = priority_queue<int>();
    }

    for (int i=0; i<test_case; i++){
        cout<<result_list[i]<<'\n';
    }


    return 0;
}