/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30122
 *
 * [131] 分割回文串
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
    string s;

    vector<string> now;

    vector<vector<string>> ans;

    bool check(string &s){ // 如果剪纸，这里可以记忆化一下。不过看时间复杂度和数据范围，不需要
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }

    // 如果当前是回文的，则新建
    // 否则只能追加

    // 和组合的区别在于，只有在计算到最后才能ans，不能中途终止
    // 两种题型：划分；组合

    // 两种思路：我的是每个字符串能不能添加，另一种是找到连续的子串，如代码随想录的例题
    void bt(int k){
        if(k==s.size()){
            if(check(now[now.size()-1])){ // 当前是回文串的，前面的划分时就检查了
                ans.push_back(now);
            }
            return;
        }
        int last_substr_idx=now.size()-1;
        if(now.size()==0 || check(now[now.size()-1])){ // 当前是回文串的，新开一个
            now.push_back(string(1, s[k]));
            bt(k+1);
            now.pop_back();
        }

        last_substr_idx=now.size()-1; // 其实不需要，因为状态维护
        if(now.size()!=0){
            now[last_substr_idx]+=s[k]; // 可以string或者单个字符。append则只能string
            bt(k+1);
            int len=now[last_substr_idx].size();
            now[last_substr_idx].erase(len-1);
            // erase能删除从x开始的y个字符
            //std::string str = "Hello World";
            // str.erase(0, 6);  // 从索引0开始删除6个字符，即删除"Hello 
            //str.erase(5);  // 从索引5开始删除，删除" World" 
        }
    }

    vector<vector<string>> partition(string s) {
        this->s=s; // 不为空串
        bt(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

