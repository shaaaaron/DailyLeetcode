/*
 * @lc app=leetcode.cn id=2810 lang=cpp
 * @lcpr version=30121
 *
 * [2810] 故障键盘
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
// 使用双端队列
    string reverse(string str){
        string ans=str;
        char ch;
        for(int i=0,j=ans.size()-1; i<j;i++, j--){
            ch = ans[j];
            ans[j] = ans[i];
            ans[i]= ch;
        }
        return ans;
    }
    string finalString(string s) {
        string ans="";
        int INum=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='i'){
                INum++;
            }else if(s[i]!='i'){
                if(INum%2==1){
                    ans=reverse(ans); // 
                }
                INum=0;
                ans=ans+string(1,s[i]);
            }
            
        }

        if(INum){ // 核心在最后的特殊处理，体会max和inverse在特殊处理上的区别
            if(INum%2==1){
                ans=reverse(ans); // 
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "string"\n
// @lcpr case=end

// @lcpr case=start
// "poiinter"\n
// @lcpr case=end

 */

