/*
 * @lc app=leetcode.cn id=856 lang=cpp
 * @lcpr version=30121
 *
 * [856] 括号的分数
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
    int scoreOfParentheses(string s) {
        stack<int> st; //分数和括号，0表示括号

        for(auto ch:s){
            if(ch=='('){
                st.push(0);
            }else{
                int score;
                // 默认栈中不空，有左括号
                if(st.top()!=0){
                    score=st.top();
                    st.pop();
                    st.pop();
                    score*=2;
                }else{
                    st.pop();
                    score=1;                    
                }
                if(!st.empty() && st.top()!=0){ // s和st不能混淆
                    score+=st.top();
                    st.pop();
                }
                
                st.push(score);
            }
        }

        return st.top(); // 由于合并，保证只有一个元素

    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "(())"\n
// @lcpr case=end

// @lcpr case=start
// "()()"\n
// @lcpr case=end

// @lcpr case=start
// "(()(()))"\n
// @lcpr case=end

 */

