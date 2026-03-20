#include <iostream>
#include <vector>
using namespace std;

int mostWordsFound(vector<string>& sentences)
{
    int maxWords = 0;

    for(string s : sentences)
    {
        int count = 1;   // ít nh?t 1 t?

        for(char c : s)
        {
            if(c == ' ')
                count++;
        }

        maxWords = max(maxWords, count);
    }

    return maxWords;
}

int main()
{
    vector<string> sentences = {
        "alice and bob love leetcode",
        "i think so too",
        "this is great thanks very much"
    };

    cout << mostWordsFound(sentences);

    return 0;
}
