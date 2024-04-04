/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30121
 *
 * [20] 有效的括号
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
// 用数学归纳发证明一下
    bool isValid(string s) {
        stack<char> stc;
        for(auto &t:s){
            if(t=='('||t=='['||t=='{'){
                stc.push(t);
            }else {
                if(stc.empty()||stc.top()=='('&&t!=')'||stc.top()=='{'&&t!='}'||stc.top()=='['&&t!=']')return 0;
                stc.pop();
            }
        }
        if(stc.empty())return 1;
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */

