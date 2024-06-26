/*
 * @lc app=leetcode.cn id=2220 lang=cpp
 * @lcpr version=30122
 *
 * [2220] 转换数字的最少位翻转次数
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
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^goal);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n4\n
// @lcpr case=end

 */

