/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 * @lcpr version=30122
 *
 * [1518] 换水问题
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
// 好推，记一下
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles+(numBottles-1)/(numExchange-1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 9\n3\n
// @lcpr case=end

// @lcpr case=start
// 15\n4\n
// @lcpr case=end

 */

