#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> ret;
    if (nums.size() <3) {
        return ret;
    }

    std::sort(nums.begin(),nums.begin()+nums.size());
    for (int j = 0; j < nums.size(); ++j) {
        if (nums[j] >0) break;

        int begin = j+1;
        int end   = nums.size()-1;
        if (j >= 1 && nums[j] == nums[j-1]) continue;

        while (begin < end){
            if (nums[j]+nums[begin]+nums[end] == 0) {
                ret.push_back({nums[j],nums[begin],nums[end]});
                while (begin<end && nums[begin] == nums[begin+1]) ++begin;
                while (begin<end && nums[end] == nums[end-1]) --end;
                ++begin;--end;

            }else if (nums[j]+nums[begin]+nums[end] >0) {
                while (begin < end && nums[j]+nums[begin]+nums[end] >0){
                    --end;
                }
            }else {
                while (begin < end && nums[j]+nums[begin]+nums[end] < 0){
                    ++begin;
                }
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


    vector<int>num = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    vector< vector<int> > ret = threeSum(num);

    return 0;
}


