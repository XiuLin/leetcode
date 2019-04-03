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


    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0){
            return;
        }

        int p = 0;
        for (int i = nums.size()-1; i >0 ; --i) {
            if (nums[i] > nums[i-1]){
                p = i;
                break;
            }
        }
        if (p == 0 ){
            sort(nums.begin(),nums.end());
            return;
        }

        for (int j = nums.size()-1; j >= p; --j) {
            if (nums[j] > nums[p-1]) {
                swap(nums[j],nums[p-1]);
                break;
            }
        }

        sort(nums.begin()+p,nums.end());
    }

};



int main() {


    clock_t begin = clock();


    Solution* solution = new Solution();

    vector<int> array = {3,2,1};
    solution->nextPermutation(array);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<time_spent<<endl;

    return 0;
}


