#include <iostream>
#include <vector>
using namespace std;

bool areOccurrencesEqual(string s) {

    vector<int> freq(26,0);

    for(char c : s) {
        freq[c - 'a']++;
    }

    int count = 0;

    for(int f : freq) {

        if(f != 0) {

            if(count == 0)
                count = f;

            else if(count != f)
                return false;
        }
    }

    return true;
}

int main() {

    string s = "abacbc";

    if(areOccurrencesEqual(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}
