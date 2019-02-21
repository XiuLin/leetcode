#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    string newstring;

    int *indexstring = new int[s.size()];
    int step = numRows -1;
    //如果行数为1或者行数大于字符串总个数那就直接返回
    if (step == 0 || numRows >s.size()){
        return s;
    }

    //解题思路，所有拐点的索引都是numRows-1的整数倍。所以以拐点为分割点 每个拐点即是起点也是终点
    // 待解析的字符串中每个字符转换成目标字符串后每个字符都是分布在 0~numRows-1的每一行中，转换后
    // 在每一行中字母的先后顺序与在s中一样。拐点分成奇数拐点和偶数拐点，所有字符都分布在从偶数拐点
    //到奇数拐点 奇数拐点到偶数拐点之间，一个字符如果是拐点从偶数拐点到奇数拐点那么它所在的行就是其
    // 在原字符串中索引对numRows-1取模(see //33)，一个字符如果是拐点从偶数拐点到奇数拐点那么它所在的行就是其
    // 在原字符串中索引对numRows-1取模后被numRows-1减一下(see //34)

    vector<string> vs(numRows);

    for (int i = 0; i < s.size(); ++i) {
        int row = i/step;
        int c = i%step;
        if (c == 0 && row%2 == 0){
            //上拐点
            indexstring[i] = 0;
        }else if (c == 0 && row%2 == 1){
            //下拐点
            indexstring[i] = step;
        }else {
            int line = i - row *(step);
            if (row%2 == 0){
                //33
                indexstring[i] = line;
            }else {
                //34
                indexstring[i] = step - line;;
            }
        }

        //将计算好的点扔到指定的行中
        int pos = indexstring[i];
        vs.at(pos) = vs.at(pos) + s[i];
    }

    //将所有行拼接
    for (int l = 0; l < numRows; ++l) {
        newstring = newstring + vs.at(l);
    }
    delete []indexstring;
    return newstring;
}


int main() {

    string s = "zmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkg";

    string snew = convert(s,87);

    std::cout<<snew<<endl;
    return 0;
}


