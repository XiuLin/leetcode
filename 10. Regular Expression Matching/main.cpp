#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;

//bool isMatch(string s, string p) {
//
//    vector<char> stack;
//    vector<char> tmp;
//    for (int k = s.size()-1; k >=0 ; --k) {
//        stack.push_back(s[k]);
//    }
//    tmp = stack;
//
//    int stack_top_index_of_s = 0;
//    int tmpindex;
//    for (int index_of_p = 0; index_of_p < s.size(); ++index_of_p) {
//        tmpindex = index_of_p;
//        while (tmp.size()) {
//            char top = tmp.at(tmp.size()-1);
//            if (top == p[index_of_p] || p[index_of_p] == '.' ) {
//                tmp.pop_back();
//                ++index_of_p;
//                continue;
//            }
//            if ( p[index_of_p] == '*') {
//                while (tmp.size()){
//                    char t = tmp.at(tmp.size()-1);
//                    if (t != top){
//                        break;
//                    }
//                    tmp.pop_back();
//                }
//                ++index_of_p;
//                continue;
//            }
//            break;
//        }
//        if (!tmp.size()){
//            return true;
//        }
//        tmp = stack;
//        index_of_p = tmpindex;
//    }
//    return false;
//}


bool isMatch(string s, string p) {

    int stack_top_index_of_s = 0;
    int tmpindex;
    for (int index_of_p = 0; index_of_p < s.size(); ++index_of_p) {
        tmpindex = index_of_p;
        while (stack_top_index_of_s <s.size() && index_of_p < s.size()) {
            char top = s.at(stack_top_index_of_s);
            if (top == p[index_of_p] || p[index_of_p] == '.' ) {

                ++stack_top_index_of_s;
                ++index_of_p;
                continue;
            }
            if ( p[index_of_p] == '*') {
                if (index_of_p == 0 ){
                    break;
                }
                if (p[index_of_p -1] != s.at(stack_top_index_of_s)){
                    break;
                }
                while (stack_top_index_of_s < s.size()){
                    char t = s.at(stack_top_index_of_s);
                    if (t != top){
                        break;
                    }
                    ++stack_top_index_of_s;
                }
                ++index_of_p;
                continue;
            }
            break;
        }
        if (stack_top_index_of_s == s.size()-1){
            return true;
        }

        stack_top_index_of_s = 0;
        index_of_p = tmpindex;
    }
    return false;
}

int main() {

//    string s;
//    string p;

    string s = "acaabbaccbbacaabbbb";
    string p = "a*.*b*.*a*aa*a*";

    //std::cin>>s>>p;
    bool r = isMatch(s,p);

    std::cout<<r<<endl;
    return 0;
}


