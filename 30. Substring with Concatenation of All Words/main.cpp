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

    vector<int> findSubstring(string s, vector<string>& words) {

        unordered_map<string,int> wordsMap;
        vector<int> rets;
        if (s.length() ==0 || words.size() == 0 || s.length() < words.size()*words.begin()->length()){
            return rets;
        }

        string tmp;

        for (vector<string>::iterator iter = words.begin();iter != words.end();++iter) {
            pair<unordered_map<string,int>::iterator, bool> res =  wordsMap.insert(make_pair(*iter,1));
            if (!res.second){
                ++res.first->second;
            }
        }

        unordered_map<string,int> wordsMapCaches;

        for (int i = 0; i < s.length()-words.size()*(words.begin()->length())+1; ++i) {

            tmp = s.substr(i,words.begin()->length());
            unordered_map<string,int>::iterator res = wordsMap.find(tmp);

            int times = 0;
            if (res != wordsMap.end()){

                for (int j = i; j < i+words.size()*(words.begin()->length()); j+=words.begin()->length()) {
                    unordered_map<string,int>::iterator res = wordsMap.find(s.substr(j,words.begin()->length()));
                    if (res != wordsMap.end()){
                        if (wordsMapCaches.find(res->first) == wordsMapCaches.end()){
                            wordsMapCaches.insert(*res);
                        }
                        if(--res->second == 0) {
                            wordsMap.erase(res->first);
                        }
                        ++times;
                    }else{
                        break;
                    }
                }
            }

            if (wordsMapCaches.size()) {
                wordsMap.insert(wordsMapCaches.begin(),wordsMapCaches.end());
                for (unordered_map<string,int>::iterator iter = wordsMapCaches.begin(); iter != wordsMapCaches.end(); ++iter) {
                    if (wordsMap.find(iter->first) == wordsMap.end()) {
                        wordsMap.insert(*iter);
                    }else{
                        wordsMap.find(iter->first)->second = iter->second;
                    }
                }
                wordsMapCaches.clear();
            }

            if (times == words.size()){
                rets.push_back(i);
            }
        }
        return rets;
    }

};



int main() {


    clock_t begin = clock();


    Solution* solution = new Solution();

    vector<string> works = {"a","b","a"};
    string s = "abababab";

    //string tt = s.substr(2,10);

    vector<int> ret = solution->findSubstring(s,works);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<time_spent<<endl;
    //ListNode *ew = solution->reverseKGroup(one,4);
    //s = "barfoothefoobarman",
      //      words = ["foo","bar"]
//
//    vector<ListNode *> container;
//    container.push_back(one);
//    container.push_back(one11);
//    container.push_back(one212);
//    solution->mergeKLists(container);
    return 0;
}


