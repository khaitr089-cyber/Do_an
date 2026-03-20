#include <iostream>
#include <string>

using namespace std;

string replaceDigits(string s)
{
    for(int i = 1; i < s.length(); i += 2)
    {
        int x = s[i] - '0';       // chuy?n ký t? s? sang s?
        s[i] = s[i-1] + x;        // th?c hi?n shift
    }

    return s;
}

int main()
{
    string s = "a1c1e1";

    cout << replaceDigits(s);

    return 0;
}
