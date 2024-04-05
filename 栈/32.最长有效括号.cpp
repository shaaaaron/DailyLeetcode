/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30121
 *
 * [32] 最长有效括号
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
    int longestValidParentheses(string s) {
        stack<int> st; // 用0表示左括号，其他表示实际的封闭括号数量
        int ans=0; // tmp1表示已经封闭，tmp2表示还没有封闭，实际不能用有限个元素

        // 可以证明如果一段）比（多则不可
        // "(()(()(()" 关键在于如何有效存储其中的封闭括号书，使用变量不够，要放在栈中
        // 要看特殊情况会发生多少次
        for(char ch:s){
            if(ch=='('){
                st.push(0);
            }else if(ch==')'){
                // 成功闭合
                int tmp=0;
                if(!st.empty()&&st.top()!=0){ // 2(5的5
                    tmp=st.top();
                    st.pop();
                }
                
                if(!st.empty() && st.top()==0){
                    st.pop();
                    tmp+=2;

                    if(!st.empty()&&st.top()!=0){ // 2(5的2
                        tmp+=st.top();
                        st.pop();
                    }
                    st.push(tmp);
                    ans=max(ans,tmp);
                }else{
                    st=stack<int>{};
                }
            }
            // cout<<tmp1<<","<<tmp2<<endl;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(()(()(()"\n
// @lcpr case=end
// @lcpr case=start
// "(()()"\n
// @lcpr case=end
// @lcpr case=start
// "()(()"\n
// @lcpr case=end

// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */

