#include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    int count[26] = {0};

    // d?m s? l?n xu?t hi?n
    for(int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
    }

    // tìm ký t? xu?t hi?n 1 l?n
    for(int i = 0; i < s.length(); i++) {
        if(count[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string s;
    cin >> s;

    cout << firstUniqChar(s);

    return 0;
}
