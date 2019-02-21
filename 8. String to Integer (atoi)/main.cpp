#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;

int myAtoi(string str) {
    long long ret =0;
    int i= 0;
    while (str[i] == ' ')++i;
    int na = 1;
    if (str[i] == '-'){
        na =-1;
        ++i;
    }else if (str[i] == '+'){
        na = 1;
        ++i;
    }

    for (int j = i; j < str.size(); ++j) {
        if (str[j] > '9' || str[j] <'0'){
            break;
        }
        ret = ret*10 +(str[j]-'0');
        if(ret > INT_MAX){
            break;
        }
    }

    if (na < 0){
        if (ret + INT_MIN > 0)
            return INT_MIN;
    }else if(na > 0) {
        if (ret > INT_MAX)
            return INT_MAX;
    }

    return ret*na;
}

int main() {

    string i;
    std::cin>>i;
    int r = myAtoi(i);

    std::cout<<r<<endl;
    return 0;
}


