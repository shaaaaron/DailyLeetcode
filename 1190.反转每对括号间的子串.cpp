/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 * @lcpr version=30121
 *
 * [1190] 反转每对括号间的子串
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
// 最好的ON时间复杂度的方法，但是n2可以过
    string reverseParentheses(string s) {
        stack<int> st;// 记录indx
        int n=s.size();
        vector<int> idx_map(n,0); // 似乎初始值不重要
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                idx_map[i]=st.top();
                idx_map[st.top()]=i;
                st.pop();
            }
        }

        string ret;
        int index = 0, step = 1;
        // 把每个括号当成传送门。而一个括号内的子串从外面必然一进一出
        while (index < n) { // 很微妙，多看看
            if (s[index] == '(' || s[index] == ')') {
                index = idx_map[index];
                step = -step; // 记录步长而不是mv_right这样的bool，更方便
                                // 而且更新也方便
            } else {
                ret.push_back(s[index]);
            }
            index += step;
        }
        return ret;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "(ab(c)d)"\n
// @lcpr case=end
// @lcpr case=start
// "(abcd)"\n
// @lcpr case=end

// @lcpr case=start
// "(u(love)i)"\n
// @lcpr case=end

// @lcpr case=start
// "(ed(et(oc))el)"\n
// @lcpr case=end

// @lcpr case=start
// "a(bcdefghijkl(mno)p)q"\n
// @lcpr case=end

 */

