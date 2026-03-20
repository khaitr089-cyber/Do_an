#include <iostream>
using namespace std;

int sumOfUnique(int nums[], int n)
{
    int count[101] = {0};

    // d?m s? l?n xu?t hi?n
    for(int i = 0; i < n; i++)
    {
        count[nums[i]]++;
    }

    int sum = 0;

    // tính t?ng ph?n t? duy nh?t
    for(int i = 0; i < n; i++)
    {
        if(count[nums[i]] == 1)
        {
            sum += nums[i];
        }
    }

    return sum;
}

int main()
{
    int nums[] = {1,2,3,2};
    int n = sizeof(nums)/sizeof(nums[0]);

    cout << sumOfUnique(nums,n);

    return 0;
}
