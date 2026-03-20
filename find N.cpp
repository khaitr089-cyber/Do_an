#include <iostream>
#include <vector>

using namespace std;

vector<int> sumZero(int n) {

    vector<int> result;

    for(int i = 1; i <= n/2; i++) {
        result.push_back(i);
        result.push_back(-i);
    }

    if(n % 2 == 1) {
        result.push_back(0);
    }

    return result;
}

int main() {

    int n = 5;

    vector<int> ans = sumZero(n);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}
