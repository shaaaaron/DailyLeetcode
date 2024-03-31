/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30121
 *
 * [322] 零钱兑换
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
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1, INT_MAX);
        dp[0]=0; // amount的特殊处理

        // i, a[j] 用到第i个硬币，总金额为j的方法数 注意是索引还是第i个
        // a[i][j] = min(a[i-1][j], a[i-1][j-coins[i]]+1)
        for(int i=0;i<n;i++){
            for(int j=coins[i]; j<=amount ;j++){ // 如果硬币数太大直接跳过，注意起止！
                if(dp[j-coins[i]] !=INT_MAX) // 先判断再加比！
                    dp[j] = min(dp[j], dp[j-coins[i]]+1);
                // cout<<dp[j]<<", ";
                // 如果有cout要注释，否则会超时！
            }
            
        }
        
        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [215,450,495,195,69,437]\n2605\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

