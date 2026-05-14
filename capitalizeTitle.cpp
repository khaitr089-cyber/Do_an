#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string word, result;

        while (ss >> word) {

        
            for (char &c : word) {
                c = tolower(c);
            }

          
            if (word.length() > 2) {
                word[0] = toupper(word[0]);
            }

            if (!result.empty()) result += " ";
            result += word;
        }

        return result;
    }
};
