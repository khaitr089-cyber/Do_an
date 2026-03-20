#include <iostream>
#include <string>
using namespace std;

string toLowerCase(string s) {

    for(int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }

    return s;
}

int main() {

    string s;
    getline(cin, s);

    cout << toLowerCase(s);

    return 0;
}
