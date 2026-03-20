#include <iostream>
#include <string>
using namespace std;

bool isNumber(string s) {
    bool num = false;
    bool dot = false;
    bool exp = false;

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            num = true;
        }
        else if (s[i] == '+' || s[i] == '-') {
            if (i != 0 && s[i-1] != 'e' && s[i-1] != 'E')
                return false;
        }
        else if (s[i] == '.') {
            if (dot || exp)
                return false;
            dot = true;
        }
        else if (s[i] == 'e' || s[i] == 'E') {
            if (exp || !num)
                return false;
            exp = true;
            num = false;
        }
        else {
            return false;
        }
    }

    return num;
}

int main() {
    string s;
    cin >> s;

    if (isNumber(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}
