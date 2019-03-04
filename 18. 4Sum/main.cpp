#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits>
#include <limits.h>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector< vector<int> > ret;
    if (nums.size() < 4) {
        return {};
    }

    std::sort(nums.begin(),nums.begin()+nums.size());

    for (int i = 0; i < nums.size(); ++i) {

        if (i >0 && nums[i] == nums[i-1]) continue;

        int begin = i +1;
        int end = nums.size()-1;
        while (begin < end) {

            while (begin < end && nums[begin] == nums[begin+1]) {
                ++begin;
            }
            while (begin < end && nums[end] == nums[end-1]) {
                --end;
            }

            int tmp = target - (nums[i]+nums[begin]+nums[end]);
            if (tmp < nums[begin] ){
                --end;
                continue;
            } else if (tmp > nums[end]) {
                ++begin;
                continue;
            }
            for (int j = begin+1; j < end; ++j) {
                if (tmp == nums[j]) {
                    ret.push_back({nums[i],nums[begin],nums[j],nums[end]});
                    ++begin;
                    --end;
                    break;
                }
            }
            if (begin + 1 >= end) {
                break;
            }
        }
    }
    return ret;
}
int main() {

//    string s;
//    string p;

    //string s = "acaabbaccbbacaabbbb";
    //string p = "a*.*b*.*a*aa*a*";

    string s = "";
    string p = "*";
    //std::cin>>s>>p;


    vector<int>num = {1, 0, -1, 0, -2, 2};
    vector< vector<int> > ret = fourSum(num,0);
    int j =0;
    cout<<j<<endl;

    return 0;
}


