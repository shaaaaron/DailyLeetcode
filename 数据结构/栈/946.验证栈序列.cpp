/*
 * @lc app=leetcode.cn id=946 lang=cpp
 * @lcpr version=30121
 *
 * [946] 验证栈序列
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
// 因为数组中元素两两不同，直接枚举
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0,j=0, n=pushed.size();
        for(i=0;i<n;i++){
            s.push(pushed[i]);
            while(!s.empty() &&s.top()==popped[j]){
                s.pop(); // 出栈一个元素才j++，所以不可能越界
                j++;
            }
        }

        return s.empty(); // 也就是j==n刚好用完
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n[4,5,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n[4,3,5,1,2]\n
// @lcpr case=end

 */

