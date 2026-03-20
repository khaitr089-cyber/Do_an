#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string thousandSeparator(int n) {

    string s = to_string(n);
    string result = "";
    int count = 0;

    for(int i = s.length()-1; i >= 0; i--) {

        result += s[i];
        count++;

        if(count == 3 && i != 0) {
            result += '.';
            count = 0;
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {

    int n = 1234567;

    cout << thousandSeparator(n);

    return 0;
}
