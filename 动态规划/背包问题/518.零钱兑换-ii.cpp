/*
 * @lc app=leetcode.cn id=518 lang=cpp
 * @lcpr version=30121
 *
 * [518] 零钱兑换 II
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
    int change(int amount, vector<int>& coins) {

        vector<int> dp(amount+1, 0); // 方法数为0
        dp[0]=1;

        for(auto &coin: coins){
            for(int i=coin;i<=amount;i++){
                dp[i]=dp[i]+dp[i-coin];
            }
        }
        return dp[amount];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[1, 2, 5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */

