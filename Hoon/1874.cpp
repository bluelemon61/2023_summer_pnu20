#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string result = "";

    int max = 0; // the max value in the past
    int before = 0; // before value
    bool* used = new bool[n+1];

    /* for index 0~n, [false,false, ...] */
    for (int i = 0; i < n+1; i++) {
        *(used+i) = false;
    }

    int number; // current input value
    bool no = false;
    for (int i = 1; i < n+1; i++) {
        cin >> number;

        if (number > max) { // 1. if number > max
            for (int _ = max; _ < number; _++) {
                result += "+\n";
            }
            result += "-\n";
            max = number;
        } else {            // 1. if number < max
            for (int _ = before-1; _ >= number; _--) {
                if (!*(used+_)) { // 2. if unused
                    if (_==number) { // 3. but same with current value
                        result += "-\n";
                    } else {        // 3. but not same
                        no = true;
                        break;
                    }
                }
            }
        }
        *(used+number) = true;

        before = number;
    }

    if (no) {
        result = "NO";
    }

    cout << result;

    return 0;
}