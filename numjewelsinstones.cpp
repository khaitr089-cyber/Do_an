#include <iostream>
#include <set>
using namespace std;

int numJewelsInStones(string jewels, string stones) {

    set<char> jewelSet;

    for(char c : jewels)
        jewelSet.insert(c);

    int count = 0;

    for(char c : stones) {
        if(jewelSet.count(c))
            count++;
    }

    return count;
}

int main() {

    string jewels = "aA";
    string stones = "aAAbbbb";

    cout << numJewelsInStones(jewels, stones);

    return 0;
}
