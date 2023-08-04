#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int n;
    int result;
    string wear_name;                                            // ex) hat, mask
    string wear_category;                                        // ex) headgear, face
    int wear_count;                                              // count wear_name
    map<string, int> wearing;

    cin>>test_case;

    for(int i=0; i<test_case; i++){
        wearing.clear();                                         // reset map each test_case 
        result = 0;
        cin>>n;
        for (int j=0; j<n; j++){
            cin>>wear_name>>wear_category;
            if (wearing.find(wear_category) != wearing.end()){   // If wear_category is already exist, increase wear_count
                //cout<<"found"<<endl;
                wearing[wear_category]++;
            }
            else {                                               // If not, insert new pair 
                //cout<<"not found"<<endl;
                wearing.insert(make_pair(wear_category, 1));
            }
        }
        
        /*
        for (const auto& entry : wearing){
            cout<<entry.first<<" "<<entry.second<<endl;
        }
        */
    }



    return 0;
}