#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

/******
 *
 * 3	Longest Substring Without Repeating Characters
 *
 *
 *  string str;
    std::cin>>str;

    Solution *solution = new Solution();
    //solution->lengthOfLongestSubstring(str);
    cout<<solution->lengthOfLongestSubstring(str)<<endl;

 *
class Solution {
    int libcount[256] = {};
    int left =0;
    int right =0;
    int max_length = 0;
public:

    void initLibCount() {
        for (int i = 0; i < 256; ++i) {
            libcount[i] = -1;
        }
    }
    int lengthOfLongestSubstring(string s) {

        initLibCount();

        if (s.size() == 0){
            return max_length;
        }

        for (int i = 0; i < s.size(); ++i) {
            if(libcount[s[i]] == -1) {
                libcount[s[i]] = i;
                right =i+1;
                if (max_length < right - left)
                    max_length = right - left;
            }else {

                if (left <= libcount[s[i]]) {
                    left = libcount[s[i]]+1;
                }
                libcount[s[i]] = i;
                right =i+1;
                if (max_length < right - left)
                    max_length = right - left;
            }
        }

        return max_length;

    }
};

 *******/

class Solution {
public:
    string longestPalindrome(string s) {
        s.length();
    }
};

void readToRight(int column,int start,int end,vector< vector<int> > &array) {
    for (int i = start; i < end; ++i) {
        cout<<array[column][i]<<" ";
    }
    cout<<endl;
}

void readToBottom(int line,int start,int end,vector< vector<int> > &array) {
    for (int i = start; i < end; ++i) {
        cout<<array[i][line]<<" ";
    }
    cout<<endl;
}

void readToLeft(int column,int start,int end,vector< vector<int> > &array) {
    for (int i = start-1; i >= end; --i) {
        cout<<array[column][i]<<" ";
    }
    cout<<endl;
}

void readToTop(int line,int start,int end,vector< vector<int> > &array) {
    for (int i = start-1; i >= end; --i) {
        cout<<array[i][line]<<" ";
    }
    cout<<endl;
}

void countArray(int m,int n,vector< vector<int> > &array) {

    int startM =0;
    int endM =m;

    int startN =0;
    int endN =n;

    do{
        readToRight(startM,startN,endN,array);
        if (++startM >= endM ){
            break;
        }
        readToBottom(endN-1,startM,endM,array);
        if (--endN<=startN){
            break;
        }
        readToLeft(endM-1,endN,startN,array);
        if (--endM <=startM) {
            break;
        }
        readToTop(startN,endM,startM,array);
        if (++startN >=endN){
            break;
        }
    }while (true);
}

int main() {

    vector< vector<int> > array = {{1,1,1,1,1,1},
                                   {2,2,2,2,2,2},
                                   {3,3,3,3,3,3},
                                   {4,4,4,4,4,4}};

    countArray(4,4,array);
    //std::cout << "Hello, World!" << std::endl;

//    string str;
//    std::cin>>str;
//
//    Solution *solution = new Solution();
//    //solution->lengthOfLongestSubstring(str);
//    cout<<solution->lengthOfLongestSubstring(str)<<endl;
    return 0;
}