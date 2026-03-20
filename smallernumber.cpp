#include <iostream>
#include <vector>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

    int n = nums.size();
    vector<int> result(n);

    for(int i = 0; i < n; i++) {

        int count = 0;

        for(int j = 0; j < n; j++) {

            if(i != j && nums[j] < nums[i]) {
                count++;
            }

        }

        result[i] = count;
    }

    return result;
}

int main() {

    vector<int> nums = {8,1,2,2,3};

    vector<int> ans = smallerNumbersThanCurrent(nums);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}
