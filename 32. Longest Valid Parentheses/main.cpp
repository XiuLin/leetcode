#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits>
#include <limits.h>
#include <map>
#include <unordered_map>

using namespace std;


/**
 * Definition for singly-linked list.
 * */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

    int longestValidParentheses(string s) {

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                return countLongestValidParentheses(s.substr(i));
            }
        }
        return 0;
    }

    //递归传入当前最大
    int countLongestValidParentheses(string s) {

        int left =0;
        int right = s.length();
        int c = 0;
        int cn = 0;
        int max = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                ++c;
            }else{
                for (int j = i; j < s.length(); ++j) {
                    if (s[j] == '(') {
                        ++c;
                    }else{
                        ++cn;
                    }
                    if (c >= cn){
                        max = cn*2;
                        break;
                    }
                }
            }
        }
        return max;
    }
};



int main() {


    clock_t begin = clock();


    Solution* solution = new Solution();

    vector<string> works = {"a","b","a"};
    string s = "abababab";

    //string tt = s.substr(2,10);

    //vector<int> ret = solution->findSubstring(s,works);

    vector<int> array = {3,2,1};
    solution->longestValidParentheses(s);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<time_spent<<endl;
    //ListNode *ew = solution->reverseKGroup(one,4);
    //s = "barfoothefoobarman",
      //      words = ["foo","bar"]
//
//    vector<ListNode *> container;
//    container.push_back(one);
//    container.push_back(one11);
//    container.push_back(one212);
//    solution->mergeKLists(container);
    return 0;
}


