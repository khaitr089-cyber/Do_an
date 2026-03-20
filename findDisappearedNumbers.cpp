#include <iostream>
#include <vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();

    // dánh d?u
    for(int i = 0; i < n; i++) {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0)
            nums[index] = -nums[index];
    }

    vector<int> result;

    // tìm s? b? thi?u
    for(int i = 0; i < n; i++) {
        if(nums[i] > 0)
            result.push_back(i + 1);
    }

    return result;
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};

    vector<int> result = findDisappearedNumbers(nums);

    for(int x : result)
        cout << x << " ";

    return 0;
}
