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

    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> key_map;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                map<char,int>::iterator iter = key_map.find(board[i][j]);
                if (iter == key_map.end()){
                    key_map.insert(make_pair(board[i][j],1));
                }else{
                    return false;
                }
            }
            key_map.clear();
        }

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') {
                    continue;
                }
                map<char,int>::iterator iter = key_map.find(board[j][i]);
                if (iter == key_map.end()){
                    key_map.insert(make_pair(board[j][i],1));
                }else{
                    return false;
                }
            }
            key_map.clear();
        }

        return true;
    }


};



int main() {


    clock_t begin = clock();


    Solution* solution = new Solution();

    vector< vector<char> > array =
            {
                    {'5','3','.','.','7','.','.','.','.'},
                    {'6','.','.','1','9','5','.','.','.'},
                    {'.','9','8','.','.','.','.','6','.'},
                    {'8','.','.','.','6','.','.','.','3'},
                    {'4','.','.','8','.','3','.','.','1'},
                    {'7','.','.','.','2','.','.','.','6'},
                    {'.','6','.','.','.','.','2','8','.'},
                    {'.','.','.','4','1','9','.','.','5'},
                    {'.','.','.','.','8','.','.','7','9'}
            };


    cout<<solution->isValidSudoku(array)<<endl;

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<time_spent<<endl;

    return 0;
}


