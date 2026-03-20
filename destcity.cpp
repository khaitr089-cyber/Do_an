#include <iostream>
#include <vector>
#include <set>

using namespace std;

string destCity(vector<vector<string>>& paths) {

    set<string> start;

    for(auto p : paths) {
        start.insert(p[0]);
    }

    for(auto p : paths) {
        if(start.count(p[1]) == 0) {
            return p[1];
        }
    }

    return "";
}

int main() {

    vector<vector<string>> paths = {
        {"London","New York"},
        {"New York","Lima"},
        {"Lima","Sao Paulo"}
    };

    cout << destCity(paths);

    return 0;
}
