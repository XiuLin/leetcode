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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.size() == 0) {
            return NULL;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        if (lists.size() == 2) {
            return mergeTwoKLists(lists[0],lists[1]);
        }

        ListNode *tmp = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            tmp = mergeTwoKLists(tmp,lists[i]);
        }

        return tmp;

    }

    ListNode* mergeTwoKLists(ListNode *first,ListNode *second){

        ListNode * tmp = NULL;
        ListNode * start = NULL;
        while (first && second) {
            if (first->val < second->val) {
                if (!tmp) {
                    tmp = first;
                    start = first;
                    first = first->next;
                }else {
                    tmp->next = first;
                    tmp = tmp->next;
                    first = first->next;
                }
            }else if(first->val > second->val) {
                if (!tmp) {
                    tmp = second;
                    start = second;
                    second = second->next;
                }else{
                    tmp->next = second;
                    tmp = tmp->next;
                    second = second->next;
                }
            }else if (first->val == second->val) {
                if (!tmp) {
                    tmp = first;
                    start = first;
                    first = first->next;
                }else{
                    tmp->next = first;
                    tmp = tmp->next;
                    first = first->next;
                }
            }
        }
        if (first) {
            if(tmp)
                tmp->next = first;
            else
                start = first;
        }
        if (second) {
            if (tmp)
                tmp->next = second;
            else
                start = second;
        }
        return start;
    }
};



int main() {

    ListNode *one = new ListNode(1);
    ListNode *one1 = new ListNode(4);
    ListNode *one2 = new ListNode(5);
    ListNode *one3 = new ListNode(9);
    ListNode *one4 = new ListNode(15);

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

    vector<ListNode *> container;
    container.push_back(one);
    container.push_back(one11);
    container.push_back(one212);
    solution->mergeKLists(container);
    return 0;
}


