#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;

/*
 *
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
 */

string count_roman(string s,int x ,string sp);
string intToRoman(int num) {
    int x = 0;
    string s ;
    //1-9 10-99 100-1000 1000
    vector<string> spc = {"IVX","XLC","CDM","M"};
    int i = 0;
    while (num >0) {
        x = num % 10;
        num = num / 10;
        s = count_roman(s,x,spc[i]);
        ++i;
    }

    return s;
}

string count_roman(string s,int x ,string sp) {

    if (x < 4 && x >0) {
        for (int i = 0; i < x; ++i) {
            s = sp[0]+s;
        }
    } else if (x == 5) {
        s = sp[1] + s;
    } else if (x ==  4){
        s =  sp.substr(0,2) + s;
    } else if (x >5 && x <9){
        string ts = sp.substr(1,1);
        for (int i = 0; i < x-5; ++i) {
            ts = ts +sp[0];
        }
        s = ts +s;
    } else if (x == 9) {
        s = sp.substr(0,1) + sp.substr(2,1) +s;
    }
    return s;
}


int main() {

    int i;
    cin>>i;
    std::cout<<intToRoman(i)<<endl;
    return 0;
}


