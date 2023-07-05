#include<iostream>
#include<deque>

int main(void){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int repeat;
    std::cin >> repeat;

    for (int _ = 0; _ < repeat; _++) {
        int n;
        int document;   // target document
        int input;      // importance
        int document_importance;    //target document's importance
        std::cin >> n >> document;
        std::deque<int> print;

        for (int __ = 0; __ < n; __++) {
            std::cin >> input;
            if (__ == document) { // if input is target document
                print.push_back(-1);    // save -1 instead of importance
                document_importance = input; // save importance in another var
            } else {
                print.push_back(input);
            }
        } // eg) print = [1, 2, -1, 4], document_importance = 3

        int print_count = 0;
        while (true) {
            // Separate case by whether front is target or not
            if (print.front() < 0) { // 1. if front is target
                bool print_front = true;
                for (int i = 1; i < print.size(); i++){  // 2. check front is most important or not
                    if (document_importance < print[i]) {
                        print.push_back(-1);
                        print.pop_front();
                        print_front = false;
                        break;
                    }
                }
                if (print_front) { // 3. if front is most important document
                    print.pop_front();
                    print_count++;
                    break;
                }
            } else {                // 1. if front is not target
                bool print_front = true;
                for (int i = 1; i < print.size(); i++) { // 2. check front is most important or not
                    if (print.front() < print[i] || print.front() < document_importance) {
                        print.push_back(print.front());
                        print.pop_front();
                        print_front = false;
                        break;
                    }
                }
                if (print_front) { // 3. if front is most important document
                    print.pop_front();
                    print_count++;
                }
            }
        }

        std::cout << print_count << "\n";
    }
}