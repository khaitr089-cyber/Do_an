#include <iostream>
using namespace std;

int digitSum(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int countBalls(int lowLimit, int highLimit)
{
    int box[100] = {0};   // luu s? bóng m?i h?p
    int maxBall = 0;

    for(int i = lowLimit; i <= highLimit; i++)
    {
        int s = digitSum(i);
        box[s]++;

        if(box[s] > maxBall)
            maxBall = box[s];
    }

    return maxBall;
}

int main()
{
    int lowLimit = 1;
    int highLimit = 10;

    cout << countBalls(lowLimit, highLimit);

    return 0;
}
