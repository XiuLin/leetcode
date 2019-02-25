#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;

int maxArea(vector<int>& height) {
    int m =0,n = height.size()-1;

    int ret = 0;

    while (m < n) {
        ret = max((n - m)*(height[m] > height[n]?height[n]:height[m]) ,ret);
        height[m] > height[n] ? --n:++m;
    }
    return ret;
}


int main() {

    vector<int> height = {10,9,8,7,6,5,4,3,2,1};

    std::cout<<maxArea(height)<<endl;
    return 0;
}


