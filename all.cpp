#include <bits/stdc++.h>
using namespace std;
 
// -----------------------------------------------
// 125. Valid Palindrome
// -----------------------------------------------
bool isPalindrome(string s) {
    int l = 0, r = s.size()-1;
    while (l < r) {
        while (l < r && !isalnum(s[l])) l++;
        while (l < r && !isalnum(s[r])) r--;
        if (tolower(s[l]) != tolower(s[r])) return false;
        l++; r--;
    }
    return true;
}
 
// -----------------------------------------------
// 15. 3Sum
// -----------------------------------------------
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < (int)nums.size()-2; i++) {
        if (i && nums[i]==nums[i-1]) continue;
        int l = i+1, r = nums.size()-1;
        while (l < r) {
            int s = nums[i]+nums[l]+nums[r];
            if (s==0) { res.push_back({nums[i],nums[l],nums[r]}); while(l<r&&nums[l]==nums[l+1])l++; while(l<r&&nums[r]==nums[r-1])r--; l++;r--; }
            else if (s<0) l++;
            else r--;
        }
    }
    return res;
}
 
// -----------------------------------------------
// 11. Container With Most Water
// -----------------------------------------------
int maxArea(vector<int>& height) {
    int l = 0, r = height.size()-1, mx = 0;
    while (l < r) {
        mx = max(mx, min(height[l],height[r])*(r-l));
        if (height[l] < height[r]) l++;
        else r--;
    }
    return mx;
}
 
// -----------------------------------------------
// 26. Remove Duplicates From Sorted Array
// -----------------------------------------------
int removeDuplicates(vector<int>& nums) {
    int k = 0;
    for (int x : nums) if (!k || nums[k-1] != x) nums[k++] = x;
    return k;
}
 
// -----------------------------------------------
// 881. Boats to Save People
// -----------------------------------------------
int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int l = 0, r = people.size()-1, boats = 0;
    while (l <= r) {
        if (people[l]+people[r] <= limit) l++;
        r--; boats++;
    }
    return boats;
}
 
// -----------------------------------------------
// 2000. Reverse Prefix of Word
// -----------------------------------------------
string reversePrefix(string word, char ch) {
    int i = word.find(ch);
    if (i != (int)string::npos) reverse(word.begin(), word.begin()+i+1);
    return word;
}
 
// -----------------------------------------------
// 27. Remove Element
// -----------------------------------------------
int removeElement(vector<int>& nums, int val) {
    int k = 0;
    for (int x : nums) if (x != val) nums[k++] = x;
    return k;
}
 
// -----------------------------------------------
// 88. Merge Sorted Array
// -----------------------------------------------
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1, j = n-1, k = m+n-1;
    while (i >= 0 && j >= 0)
        nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    while (j >= 0) nums1[k--] = nums2[j--];
}
 
// -----------------------------------------------
// 344. Reverse String
// -----------------------------------------------
void reverseString(vector<char>& s) {
    int l = 0, r = s.size()-1;
    while (l < r) swap(s[l++], s[r--]);
}
 
// -----------------------------------------------
// 283. Move Zeroes
// -----------------------------------------------
void moveZeroes(vector<int>& nums) {
    int k = 0;
    for (int x : nums) if (x) nums[k++] = x;
    while (k < (int)nums.size()) nums[k++] = 0;
}
 
// -----------------------------------------------
// 16. 3Sum Closest
// -----------------------------------------------
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int best = nums[0]+nums[1]+nums[2];
    for (int i = 0; i < (int)nums.size()-2; i++) {
        int l = i+1, r = nums.size()-1;
        while (l < r) {
            int s = nums[i]+nums[l]+nums[r];
            if (abs(s-target) < abs(best-target)) best = s;
            if (s < target) l++;
            else if (s > target) r--;
            else return s;
        }
    }
    return best;
}
 
// -----------------------------------------------
// 18. 4Sum
// -----------------------------------------------
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n-3; i++) {
        if (i && nums[i]==nums[i-1]) continue;
        for (int j = i+1; j < n-2; j++) {
            if (j>i+1 && nums[j]==nums[j-1]) continue;
            int l = j+1, r = n-1;
            while (l < r) {
                long long s = (long long)nums[i]+nums[j]+nums[l]+nums[r];
                if (s==target) {
                    res.push_back({nums[i],nums[j],nums[l],nums[r]});
                    while(l<r&&nums[l]==nums[l+1])l++;
                    while(l<r&&nums[r]==nums[r-1])r--;
                    l++; r--;
                } else if (s < target) l++;
                else r--;
            }
        }
    }
    return res;
}
 
// -----------------------------------------------
// 167. Two Sum II - Input Array Is Sorted
// -----------------------------------------------
vector<int> twoSumII(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l < r) {
        int s = nums[l]+nums[r];
        if (s==target) return {l+1,r+1};
        else if (s < target) l++;
        else r--;
    }
    return {};
}
 
// ============================================================
// TOPIC 3: STACK
// ============================================================
 
// -----------------------------------------------
// 1047. Remove All Adjacent Duplicates In String
// -----------------------------------------------
string removeDuplicates(string s) {
    string stack;
    for (char c : s) {
        if (!stack.empty() && stack.back()==c) stack.pop_back();
        else stack += c;
    }
    return stack;
}
 
// -----------------------------------------------
// 20. Valid Parentheses
// -----------------------------------------------
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c=='(' || c=='[' || c=='{') st.push(c);
        else {
            if (st.empty()) return false;
            if ((c==')' && st.top()!='(') || (c==']' && st.top()!='[') || (c=='}' && st.top()!='{')) return false;
            st.pop();
        }
    }
    return st.empty();
}
 
// -----------------------------------------------
// 739. Daily Temperatures
// -----------------------------------------------
vector<int> dailyTemperatures(vector<int>& t) {
    int n = t.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && t[i] > t[st.top()]) {
            res[st.top()] = i - st.top(); st.pop();
        }
        st.push(i);
    }
    return res;
}
 
// -----------------------------------------------
// 155. Min Stack
// -----------------------------------------------
class MinStack {
    stack<pair<int,int>> st; // {val, curMin}
public:
    void push(int val) {
        int mn = st.empty() ? val : min(val, st.top().second);
        st.push({val, mn});
    }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};
 
// ============================================================
// TOPIC 4: BINARY SEARCH
// ============================================================
 
// -----------------------------------------------
// 704. Binary Search
// -----------------------------------------------
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (nums[m]==target) return m;
        else if (nums[m]<target) l = m+1;
        else r = m-1;
    }
    return -1;
}
 
// -----------------------------------------------
// 374. Guess Number Higher or Lower
// -----------------------------------------------
// API: int guess(int num); returns -1,0,1
int guessNumber(int n) {
    int l = 1, r = n;
    while (l <= r) {
        int m = l + (r-l)/2;
        // int g = guess(m);
        // if (g==0) return m;
        // else if (g<0) r = m-1;
        // else l = m+1;
        (void)m; // placeholder
    }
    return -1;
}
 
// -----------------------------------------------
// 35. Search Insert Position
// -----------------------------------------------
int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int m = (l+r)/2;
        if (nums[m] < target) l = m+1;
        else r = m;
    }
    return l;
}
 
// -----------------------------------------------
// 153. Find Minimum In Rotated Sorted Array
// -----------------------------------------------
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    while (l < r) {
        int m = (l+r)/2;
        if (nums[m] > nums[r]) l = m+1;
        else r = m;
    }
    return nums[l];
}
 
// -----------------------------------------------
// 33. Search In Rotated Sorted Array
// -----------------------------------------------
int searchRotated(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (nums[m]==target) return m;
        if (nums[l] <= nums[m]) {
            if (nums[l] <= target && target < nums[m]) r = m-1;
            else l = m+1;
        } else {
            if (nums[m] < target && target <= nums[r]) l = m+1;
            else r = m-1;
        }
    }
    return -1;
}
 
// -----------------------------------------------
// 658. Find K Closest Elements
// -----------------------------------------------
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l = 0, r = arr.size()-k;
    while (l < r) {
        int m = (l+r)/2;
        if (x - arr[m] > arr[m+k] - x) l = m+1;
        else r = m;
    }
    return vector<int>(arr.begin()+l, arr.begin()+l+k);
}
 
// -----------------------------------------------
// 69. Sqrt(x)
// -----------------------------------------------
int mySqrt(int x) {
    if (x < 2) return x;
    long long l = 1, r = x/2;
    while (l <= r) {
        long long m = (l+r)/2;
        if (m*m == x) return m;
        else if (m*m < x) l = m+1;
        else r = m-1;
    }
    return r;
}
 
// -----------------------------------------------
// 278. First Bad Version
// -----------------------------------------------
// API: bool isBadVersion(int v);
int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l < r) {
        int m = l + (r-l)/2;
        // if (isBadVersion(m)) r = m;
        // else l = m+1;
        (void)m; // placeholder
    }
    return l;
}
 
// -----------------------------------------------
// 441. Arranging Coins
// -----------------------------------------------
int arrangeCoins(int n) {
    long long l = 1, r = n;
    while (l <= r) {
        long long m = (l+r)/2;
        if (m*(m+1)/2 <= n) l = m+1;
        else r = m-1;
    }
    return r;
}
 
// -----------------------------------------------
// 1346. Check If N and Its Double Exist
// -----------------------------------------------
bool checkIfExist(vector<int>& arr) {
    unordered_set<int> s;
    for (int x : arr) {
        if (s.count(x*2) || (x%2==0 && s.count(x/2))) return true;
        s.insert(x);
    }
    return false;
}
 
// -----------------------------------------------
// 2520. Count the Digits That Divide a Number
// (2571. Find the Pivot Integer)
// -----------------------------------------------
int pivotInteger(int n) {
    int total = n*(n+1)/2;
    int sq = (int)sqrt(total);
    return sq*sq == total ? sq : -1;
}
 
// ============================================================
// TOPIC 5: SLIDING WINDOW
// ============================================================
 
// -----------------------------------------------
// 219. Contains Duplicate II
// -----------------------------------------------
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (mp.count(nums[i]) && i - mp[nums[i]] <= k) return true;
        mp[nums[i]] = i;
    }
    return false;
}
 
// -----------------------------------------------
// 121. Best Time to Buy And Sell Stock
// -----------------------------------------------
int maxProfit(vector<int>& prices) {
    int minP = INT_MAX, maxP = 0;
    for (int p : prices) {
        minP = min(minP, p);
        maxP = max(maxP, p - minP);
    }
    return maxP;
}
 
// -----------------------------------------------
// 3. Longest Substring Without Repeating Characters
// -----------------------------------------------
int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> pos;
    int res = 0, l = 0;
    for (int r = 0; r < (int)s.size(); r++) {
        if (pos.count(s[r]) && pos[s[r]] >= l) l = pos[s[r]] + 1;
        pos[s[r]] = r;
        res = max(res, r - l + 1);
    }
    return res;
}
