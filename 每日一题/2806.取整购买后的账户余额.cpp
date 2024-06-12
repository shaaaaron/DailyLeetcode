/*
 * @lc app=leetcode.cn id=2806 lang=cpp
 * @lcpr version=30203
 *
 * [2806] 取整购买后的账户余额
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
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int x=purchaseAmount/10*10, y=x+10;
        int money= y-purchaseAmount<=purchaseAmount-x?y:x;
        return 100-money;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 9\n
// @lcpr case=end

// @lcpr case=start
// 15\n
// @lcpr case=end

 */

