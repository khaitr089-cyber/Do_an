#include <iostream>
#include <vector>
using namespace std;

int maxDistance(vector<int>& colors)
{
    int n = colors.size();
    int maxDist = 0;

    for(int i = 0; i < n; i++)
    {
        if(colors[i] != colors[0])
            maxDist = max(maxDist, i);

        if(colors[i] != colors[n-1])
            maxDist = max(maxDist, n - 1 - i);
    }

    return maxDist;
}

int main()
{
    vector<int> colors = {1,1,1,6,1,1,1};

    cout << maxDistance(colors);

    return 0;
}
