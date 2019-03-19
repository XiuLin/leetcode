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

    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1){
            return;
        }
        vector<int> v;
        factorial(0,v,nums);
    }

    void factorial(int j,vector<int> numsout,vector<int>nums) {
        if (j == nums.size()){
            for (int i = 0; i < numsout.size(); ++i) {
                cout<<numsout[i]<<" ";
            }
            cout<<endl;
            return;
        }
        for (int i = j; i < nums.size(); ++i) {
            numsout.push_back(nums[i]);
            swap(nums[j],nums[i]);
            factorial(j+1,numsout,nums);
            swap(nums[j],nums[i]);
            numsout.pop_back();
        }
    }

    void swap(int &x,int &y) {
        if (x == y)
            return;
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
};



int main() {


    clock_t begin = clock();


    Solution* solution = new Solution();

    vector<string> works = {"a","b","a"};
    string s = "abababab";

    //string tt = s.substr(2,10);

    //vector<int> ret = solution->findSubstring(s,works);

    vector<int> array = {1,3,2};
    solution->nextPermutation(array);
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


