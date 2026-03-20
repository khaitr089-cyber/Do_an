#include <iostream>
#include <vector>
#include <set>
using namespace std;

int distributeCandies(vector<int>& candyType) {

    set<int> types;

    for(int x : candyType)
        types.insert(x);

    int uniqueTypes = types.size();
    int n = candyType.size();

    return min(uniqueTypes, n / 2);
}

int main() {

    vector<int> candyType = {1,1,2,2,3,3};

    cout << distributeCandies(candyType);

    return 0;
}
