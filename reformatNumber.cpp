#include <iostream>
#include <string>

using namespace std;

string reformatNumber(string number) {

    string digits = "";

    // Bu?c 1: l?y các ch? s?
    for(char c : number) {
        if(isdigit(c))
            digits += c;
    }

    string result = "";
    int i = 0;
    int n = digits.length();

    // Bu?c 2: chia nhóm
    while(n - i > 4) {
        result += digits.substr(i,3) + "-";
        i += 3;
    }

    if(n - i == 4) {
        result += digits.substr(i,2) + "-";
        result += digits.substr(i+2,2);
    }
    else {
        result += digits.substr(i);
    }

    return result;
}

int main() {

    string number = "123 4-567";

    cout << reformatNumber(number);

    return 0;
}
