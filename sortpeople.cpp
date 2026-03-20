#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

    vector<pair<int,string>> people;

    for(int i = 0; i < names.size(); i++) {
        people.push_back({heights[i], names[i]});
    }

    sort(people.begin(), people.end(), greater<pair<int,string>>());

    vector<string> result;

    for(auto p : people) {
        result.push_back(p.second);
    }

    return result;
}

int main() {

    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};

    vector<string> ans = sortPeople(names, heights);

    for(string s : ans) {
        cout << s << " ";
    }

    return 0;
}
