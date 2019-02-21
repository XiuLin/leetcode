#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;

int reverse(int x) {

    long long ret = 0;

    while (x !=0) {
        int r = x % 10;
        x = x / 10;
        ret = ret *10 + r;
    }
    if (ret > INT_MAX || ret < INT_MIN || ret == 0) {
        return 0;
    }else {
        return ret;
    }
}

int main() {

    int i;
    std::cin>>i;
    int r = reverse(i);

    std::cout<<r<<endl;
    return 0;
}


