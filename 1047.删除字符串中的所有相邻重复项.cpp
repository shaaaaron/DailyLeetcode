/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=30121
 *
 * [1047] 删除字符串中的所有相邻重复项
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
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto & ch :s){ // 只需要进栈的时候检查pop一次，不会影响到前面的
            if(st.empty()||st.top()!=ch){
                st.push(ch);
            }else{
                st.pop();
            }
        }
        string ans="";
        while(st.size()>=1){//是1不是0！！犯了好几次同样的问题
            // ans+=string(1, st.top());
            ans+= st.top(); // 字符在和字符串加减的时候会直接转换
            st.pop();
        }
        reverse(ans.begin(), ans.end()); // stack没有迭代器，reverse不需要复制
        // python reversed_str = str[::-1]
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

 */

