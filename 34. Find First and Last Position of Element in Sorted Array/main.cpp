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

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1,-1};
        if (nums.size() == 0) {
            return ret;
        }
        return internal_search_range(nums,ret,target,0,nums.size()-1);

    }

    vector<int> internal_search_range(vector<int>& nums, vector<int>&bad_ret ,const int &target,int begin,int end) {

        if (begin >= end && target != nums[begin]) {
            return bad_ret;
        }

        if (nums[begin] == target) {
            return find_range(target,nums,begin,0,nums.size()-1);
        }

        int mid = (end-begin)/2 + begin;
        if (mid == begin && nums[end] == target) {
            return {end,end};
        }

        if (mid == begin && nums[end] != target) {
            return bad_ret;
        }

        if (nums[mid] == target) {
            return find_range(target,nums,mid,0,nums.size()-1);
        }else if (nums[mid] > target){
            return internal_search_range(nums,bad_ret,target,0,mid-1);
        }else if (nums[mid] < target){
            return internal_search_range(nums,bad_ret,target,mid+1,end);
        }

        return bad_ret;
    }

    vector<int> find_range(const int &target,vector<int>& nums,int target_index,int begin,int end){

        int b_index = find_begin_range(target,nums,begin,target_index,target_index);
        int e_index = find_end_range(target,nums,target_index,end,target_index);

        return {b_index,e_index};
    }

    int find_begin_range(const int &target,vector<int>& nums,int begin,int end,int last_right_pos){


        if (begin >= end ) {
            if (target != nums[end])
                return last_right_pos;
            else
                return end;
        }

        if (nums[begin] == target) {
            return begin;
        }

        int mid = (end-begin)/2 + begin;
        if (mid == begin && nums[end] == target) {
            return end;
        }

        if (nums[mid] == target) {
            return find_begin_range(target,nums,0,mid,mid);
        }else if (nums[mid] < target) {
            return find_begin_range(target,nums,mid+1,end,last_right_pos);
        }

        return last_right_pos;
    }

    int find_end_range(const int &target,vector<int>& nums,int begin,int end,int last_right_pos) {

        if (begin >= end ) {
            if (target != nums[end])
                return last_right_pos;
            else
                return end;
        }

        if (nums[begin] == target) {
            return find_end_range(target,nums,begin+1,end,begin);
        }

        int mid = (end-begin)/2+begin;
        if (mid == begin && nums[end] == target) {
            return end;
        }

        if (nums[mid] == target) {
            return find_end_range(target,nums,mid+1,end,mid);
        }else if (nums[mid] > target) {
            return find_end_range(target,nums,mid+1,end,last_right_pos);
        }

        return last_right_pos;
    }

};



int main() {


    clock_t begin = clock();


    Solution* solution = new Solution();

    vector<int> array = {1,2,4};
    int target = 2;
    solution->searchRange(array,target);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<time_spent<<endl;

    return 0;
}


