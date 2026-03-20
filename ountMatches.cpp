#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int index;

    if(ruleKey == "type") index = 0;
    else if(ruleKey == "color") index = 1;
    else index = 2;

    int count = 0;

    for(int i = 0; i < items.size(); i++)
    {
        if(items[i][index] == ruleValue)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    vector<vector<string>> items = {
        {"phone","blue","pixel"},
        {"computer","silver","lenovo"},
        {"phone","gold","iphone"}
    };

    string ruleKey = "color";
    string ruleValue = "silver";

    cout << countMatches(items, ruleKey, ruleValue);

    return 0;
}
