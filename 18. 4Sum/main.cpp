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
    
    for (int i = 0; i < nums.size()-3; ++i) {
        
        if (i >0 && nums[i] == nums[i-1]) continue;
        
        int tar = target - nums[i];
        for (int k = i +1; k < nums.size()-2; ++k) {
            
            if (k >i+1 && nums[k] == nums[k-1]) continue;
            
            int begin = k +1;
            int end = nums.size()-1;
            while (begin < end) {
                
                if (begin < end && tar == nums[k]+nums[begin]+nums[end]) {
                    ret.push_back({nums[i],nums[k],nums[begin],nums[end]});
                    while (begin < end && begin > k +1 && nums[begin] == nums[begin-1]) {
                        ++begin;
                    }
                    while (begin < end && nums[end] == nums[end-1]) {
                        --end;
                    }
                    ++begin;--end;
                }
                else if (begin < end && tar > nums[k]+nums[begin]+nums[end]) {
                    ++begin;
                }else if (begin < end && tar < nums[k]+nums[begin]+nums[end]) {
                    --end;
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
    
    
    vector<int>num = {-1,2,2,-5,0,-1,4};
    vector< vector<int> > ret = fourSum(num,3);
    int j =0;
    cout<<j<<endl;
    
    return 0;
}


