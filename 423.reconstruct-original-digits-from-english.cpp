/*
 * @lc app=leetcode.cn id=423 lang=cpp
 * @lcpr version=30122
 *
 * [423] 从英文中重建数字
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string originalDigits(string s) {// 手动拓扑排序
        unordered_map<char,int> chr2num; //根据单个字符找数字
        chr2num['z']=0;
        chr2num['x']=6;
        chr2num['s']=7;
        chr2num['v']=5;
        chr2num['f']=4;
        chr2num['w']=2;
        chr2num['o']=1;
        chr2num['g']=8;
        chr2num['n']=9;
        chr2num['t']=3;
        vector<string> num2str{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; // 根据数字找完整数字

        unordered_map<char,int> chr_cnt; // 记录字母出现的次数
        for(int i=0;i<s.size();i++){
            chr_cnt[s[i]]++;
        }

        vector<int> ans;
        
        for(auto chr:vector<char>{'z','x','s','v','f','w','o','g','n','t'}){
            int num=chr2num[chr]; //对应的数字
            if(chr_cnt.find(chr)!=chr_cnt.end() && chr_cnt[chr]!=0){
                // int chr_num=chr_cnt[chr]; // 数字出现的次数
                while(chr_cnt[chr]>0){ // 可能有重复数字！
                    for(int i=0;i<num2str[num].size();i++){
                        chr_cnt[num2str[num][i]]--; // 用对应的字符串，而不是s
                    }
                    ans.push_back(num);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        string ans_str="";
        for(int num:ans){
            ans_str+=string(1, num+'0');
        }
        return ans_str;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "nnei"\n
// @lcpr case=end
// @lcpr case=start
// "owoztneoer"\n
// @lcpr case=end

// @lcpr case=start
// "fviefuro"\n
// @lcpr case=end

 */

