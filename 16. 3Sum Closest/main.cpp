#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits>
#include <limits.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {

    std::sort(nums.begin(),nums.begin()+nums.size());

    int array[3] = {nums[0],nums[1],nums[2]};
    int minSep = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {

        int begin = i +1;
        int end = nums.size() - 1;
        int tar = 0;
        int tmp = INT_MAX;
        while (begin < end) {
            tar = nums[i] + nums[begin] + nums[end];
            tmp = abs(tar-target);

            if (tmp < minSep) {
                minSep = tmp;
                array[0] = nums[i];
                array[1] = nums[begin];
                array[2] = nums[end];

            }
            if (nums[i] + nums[begin] + nums[end] < target) {
                ++begin;
            } else if(nums[i] + nums[begin] + nums[end] > target) {
                --end;
            } else{
                break;
            }
        }
    }
    return array[0] + array[1] +array[2];
}
int main() {

//    string s;
//    string p;

    //string s = "acaabbaccbbacaabbbb";
    //string p = "a*.*b*.*a*aa*a*";

    string s = "";
    string p = "*";
    //std::cin>>s>>p;


    vector<int>num = {0, 2, 1, -3};
    cout<<threeSumClosest(num,1);

    return 0;
}


