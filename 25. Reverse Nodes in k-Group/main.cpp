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

    ListNode *one = new ListNode(1);
    ListNode *one1 = new ListNode(2);
    ListNode *one2 = new ListNode(3);
    ListNode *one3 = new ListNode(4);
    ListNode *one4 = new ListNode(5);

    one->next = one1;
    one1->next = one2;
    one2->next = one3;
    one3->next = one4;

    ListNode *one11 = new ListNode(1);
    ListNode *one111 = new ListNode(6);
    ListNode *one12 = new ListNode(9);
    ListNode *one13 = new ListNode(11);
    ListNode *one14 = new ListNode(21);

    one11->next = one111;
    one111->next = one12;
    one12->next = one13;
    one13->next = one14;

    ListNode *one212 = new ListNode(10);
    ListNode *one213 = new ListNode(18);
    ListNode *one214 = new ListNode(29);

    one212->next = one213;
    one213->next = one214;


    Solution* solution = new Solution();
    ListNode *ew = solution->reverseKGroup(one,4);

//
//    vector<ListNode *> container;
//    container.push_back(one);
//    container.push_back(one11);
//    container.push_back(one212);
//    solution->mergeKLists(container);
    return 0;
}


