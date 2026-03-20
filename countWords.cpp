#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countWords(vector<string>& words1, vector<string>& words2)
{
    unordered_map<string,int> count1;
    unordered_map<string,int> count2;

    for(string w : words1)
        count1[w]++;

    for(string w : words2)
        count2[w]++;

    int result = 0;

    for(auto &p : count1)
    {
        if(p.second == 1 && count2[p.first] == 1)
            result++;
    }

    return result;
}

int main()
{
    vector<string> words1 = {"leetcode","is","amazing","as","is"};
    vector<string> words2 = {"amazing","leetcode","is"};

    cout << countWords(words1, words2);

    return 0;
}
