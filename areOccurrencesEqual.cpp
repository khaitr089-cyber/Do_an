#include <iostream>
#include <string>

using namespace std;

bool areOccurrencesEqual(string s)
{
    int count[26] = {0};

    // d?m s? l?n xu?t hi?n
    for(char c : s)
    {
        count[c - 'a']++;
    }

    int freq = 0;

    for(int i = 0; i < 26; i++)
    {
        if(count[i] != 0)
        {
            if(freq == 0)
                freq = count[i];
            else if(count[i] != freq)
                return false;
        }
    }

    return true;
}

int main()
{
    string s = "abacbc";

    if(areOccurrencesEqual(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}
