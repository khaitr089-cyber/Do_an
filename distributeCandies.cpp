#include <iostream>
#include <vector>

using namespace std;

vector<int> distributeCandies(int candies, int num_people) {

    vector<int> ans(num_people, 0);
    int give = 1;

    while(candies > 0) {

        int index = (give - 1) % num_people;

        int current = min(give, candies);

        ans[index] += current;

        candies -= current;

        give++;
    }

    return ans;
}

int main() {

    int candies = 7;
    int num_people = 4;

    vector<int> result = distributeCandies(candies, num_people);

    for(int x : result)
        cout << x << " ";

    return 0;
}
