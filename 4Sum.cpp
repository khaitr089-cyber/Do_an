#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2,
                 vector<int>& nums3, vector<int>& nums4) {

    unordered_map<int,int> mp;

    int n = nums1.size();

    // luu t?ng nums1 + nums2
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mp[nums1[i] + nums2[j]]++;
        }
    }

    int count = 0;

    // tìm t?ng bù
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sum = -(nums3[i] + nums4[j]);

            if(mp.count(sum))
                count += mp[sum];
        }
    }

    return count;
}

int main() {

    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};

    cout << fourSumCount(nums1, nums2, nums3, nums4);

    return 0;
}
