#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits>
#include <limits.h>

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

    int divide(int dividend, int divisor) {

        long long tmp = 0;
        int bef = 0;

        if (dividend == INT_MIN && divisor == -1) {
            return 0;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        bool is_n;
        if (dividend > 0 && divisor >0 || dividend < 0 && divisor <0 ){
            is_n = false;
        }else{
            is_n = true;
        }

        long long tdd = dividend;
        long long td  = divisor;
        long long dividend_l = dividend > 0 ? tdd : -tdd;
        long long divisor_l  = divisor > 0 ? td: -td;

        int current = 0;
        for (int i = 0; i < INT_MAX; ++i) {
            tmp = divisor_l + tmp;

            bef = i;

            if (tmp > dividend_l) {
                break;
            }else if(tmp == dividend_l){
                bef = i+1;
                break;
            }
        }
        return is_n ? -bef:bef;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {


        if (NULL == head) {
            return NULL;
        }

        if (1 == k) {
            return head;
        }

        ListNode **array = (ListNode **)malloc(sizeof(ListNode*) *k);
        int current = 0;
        ListNode *start = head;

        int tmp = 0;
        while (head) {

            array[current%k] = head;

            if ((current+1)%k == 0) {
                swap(array,k);
            }

            head = head->next;
            ++current;
        }
        free(array);
        return start;
    }

    void swap(ListNode **array,int k) {

        int tmp=0;
        for (int i = 0,max = k-1; i < max; ++i,--max) {
            tmp = array[i]->val;
            array[i]->val = array[max]->val;
            array[max]->val = tmp;
        }
    }

};



int main() {


    clock_t begin = clock();


    Solution* solution = new Solution();
    //ListNode *ew = solution->reverseKGroup(one,4);

    cout<<solution->divide(INT_MIN,1)<<endl;
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<time_spent<<endl;
//
//    vector<ListNode *> container;
//    container.push_back(one);
//    container.push_back(one11);
//    container.push_back(one212);
//    solution->mergeKLists(container);
    return 0;
}


