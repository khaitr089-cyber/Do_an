#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> targetIndices(vector<int>& nums, int target)
{
    vector<int> result;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == target)
            result.push_back(i);
    }

    return result;
}

int main()
{
    vector<int> nums = {1,2,5,2,3};
    int target = 2;

    vector<int> ans = targetIndices(nums, target);

    for(int x : ans)
        cout << x << " ";

    return 0;
}
