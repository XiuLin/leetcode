#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits>
#include <limits.h>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* removeNTH(ListNode *head,int cn,int &n) {
    if (!head) {
        --n;
        return head;
    }
    ListNode *h = head->next;
    h = removeNTH(h,cn,n);
    if (n == 0) {
        --n;
        return head->next;
    }
    if (n > 0 && n <cn) {
        --n;
    }
    if (-1 == n) {
        --n;
        head->next = h;
        return head;
    }
    return head;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {

    int cn = n;
    return removeNTH(head,cn,n);
}



int main() {

//    string s;
//    string p;

    //string s = "acaabbaccbbacaabbbb";
    //string p = "a*.*b*.*a*aa*a*";

    string s = "";
    string p = "*";
    //std::cin>>s>>p;

    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four = new ListNode(4);
    ListNode *five = new ListNode(5);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    vector<int>num = {-1,2,2,-5,0,-1,4};

    int j =0;
    cout<<j<<endl;

    ListNode * newone = removeNthFromEnd(one,6);

    return 0;
}


