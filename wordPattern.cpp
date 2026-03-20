#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

bool wordPattern(string pattern, string s) {
    vector<string> words;
    stringstream ss(s);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    if (words.size() != pattern.size())
        return false;

    map<char, string> m1;
    map<string, char> m2;

    for (int i = 0; i < pattern.size(); i++) {

        if (m1.count(pattern[i]) && m1[pattern[i]] != words[i])
            return false;

        if (m2.count(words[i]) && m2[words[i]] != pattern[i])
            return false;

        m1[pattern[i]] = words[i];
        m2[words[i]] = pattern[i];
    }

    return true;
}

int main() {
    string pattern = "abba";
    string s = "dog cat cat dog";

    if(wordPattern(pattern, s))
        cout << "true";
    else
        cout << "false";

    return 0;
}
