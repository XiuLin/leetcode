#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0){
        return false;
    }

    int tmp = x;
    long long ret =0;
    while (x) {
        ret = ret*10 + x%10;
        x /=10;
    }
    if (ret != tmp) {
        return false;
    }
    return true;
}

int main() {

    int i;
    std::cin>>i;
    bool r = isPalindrome(i);

    std::cout<<r<<endl;
    return 0;
}


