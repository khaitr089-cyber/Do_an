#include <iostream>
using namespace std;

int largestAltitude(int gain[], int n) {

    int height = 0;
    int maxHeight = 0;

    for(int i = 0; i < n; i++) {
        height += gain[i];     // c?p nh?t d? cao
        if(height > maxHeight)
            maxHeight = height;
    }

    return maxHeight;
}

int main() {

    int gain[] = {-5,1,5,0,-7};
    int n = sizeof(gain)/sizeof(gain[0]);

    cout << largestAltitude(gain,n);

    return 0;
}
