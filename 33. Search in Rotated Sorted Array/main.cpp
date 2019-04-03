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


class Solution {
public:

    int search(vector<int>& nums, int target) {

        if (nums.size() == 0){
            return -1;
        }

        return internal_search(nums,target,0,nums.size()-1);
    }

    int internal_search(vector<int>& nums, const int &target,int begin,int end) {
        int ret =-1;
        if (begin >= end && nums[begin] != target) {
            return ret;
        }

        if (nums[begin] == target) {
            return begin;
        }

        int mid = (end-begin)/2+begin;
        if (target == nums[mid]) {
            return mid;
        }

        if (begin == mid && target == nums[end]) {
            return end;
        }

        if (begin == mid && target != nums[end]) {
            return ret;
        }

        if (nums[begin] > target && nums[mid] > target) {
            ret = internal_search(nums,target,mid,end);
            if (-1 == ret) {
                return internal_search(nums,target,begin,mid);
            }else{
                return ret;
            }
        }

        if (nums[begin] > target && nums[mid] < target) {
            return internal_search(nums,target,mid,end);
        }

        if (nums[begin] < target && nums[mid] > target) {
            return internal_search(nums,target,begin,mid);
        }

        if (nums[begin] < target && nums[mid] < target) {
            ret = internal_search(nums,target,mid,end);
            if (-1 == ret){
                return internal_search(nums,target,begin,mid);
            }else{
                return ret;
            }
        }

        return ret;
    }

};



int main() {


    clock_t begin = clock();


    Solution* solution = new Solution();

    vector<int> array = {4,5,6,7,8,1,2,3};
    int target = 8;
    cout<<solution->search(array,target)<<endl;

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<time_spent<<endl;

    return 0;
}


