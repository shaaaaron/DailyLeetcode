/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30122
 *
 * [93] 复原 IP 地址
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

// 两种方法，单个字符，连续的字符。本题因为数量限制，后者更好写
class Solution {
public:
    bool check(const string &s){ // 完整功能抽离出来
        if(s.size()==1)return true;
        if(s.size()==2){
            if(s[0]=='0') return false;
            return true;
        }
        if(s.size()==3){
            if(s[0]=='0') return false;
            if(s[0]<='1' || s[0]=='2'&&s[1]<='4' ||s[0]=='2'&&s[1]=='5' &&s[2]<='5') return true;
        }
        return false;
    }

    string s;

    string now;
    int substr_num; // 需要记录当前的段数

    vector<string> ans; 
    
    void bt(int k){
        if(k==s.size()){
            if(substr_num==4){
                ans.push_back(now);
            }
            return;
        }
        if(substr_num>=4) return;
        for(int i=k; i<s.size() && i<k+3; i++){
            if(check(s.substr(k,i-k+1))){// ik的地位不能颠倒
                int len=0;
                if(now!=""){
                    now+=".";
                    len++;
                } 
                now+=s.substr(k,i-k+1);
                len+=i-k+1;
                substr_num++;

                bt(i+1);
                now.erase(now.size()-len);
                substr_num--;
            }
        }

    }
    vector<string> restoreIpAddresses(string s) {
        this->s=s;
        substr_num=0;

        bt(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */

