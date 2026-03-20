#include <iostream>
using namespace std;

int smallestEqual(int nums[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i % 10 == nums[i])
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int nums[] = {4,3,2,1};
    int n = sizeof(nums)/sizeof(nums[0]);

    cout << smallestEqual(nums,n);

    return 0;
}
