#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {

    unordered_set<string> bannedSet(banned.begin(), banned.end());
    unordered_map<string, int> count;

    for(char &c : paragraph) {
        if(ispunct(c))
            c = ' ';
        else
            c = tolower(c);
    }

    stringstream ss(paragraph);
    string word;

    while(ss >> word) {
        if(bannedSet.count(word) == 0) {
            count[word]++;
        }
    }

    string result;
    int maxCount = 0;

    for(auto &p : count) {
        if(p.second > maxCount) {
            maxCount = p.second;
            result = p.first;
        }
    }

    return result;
}

int main() {

    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};

    cout << mostCommonWord(paragraph, banned);

    return 0;
}
