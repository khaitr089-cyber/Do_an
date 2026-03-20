#include <iostream>
#include <vector>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {

    if(timeSeries.size() == 0)
        return 0;

    int total = 0;

    for(int i = 1; i < timeSeries.size(); i++) {
        total += min(duration, timeSeries[i] - timeSeries[i-1]);
    }

    total += duration;

    return total;
}

int main() {

    vector<int> timeSeries = {1,4};
    int duration = 2;

    cout << findPoisonedDuration(timeSeries, duration);

    return 0;
}
