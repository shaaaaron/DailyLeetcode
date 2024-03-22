/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(),0);
        for(int i=0;i<grid[0].size();i++){
            dp[i] = grid[0][i] + (i==0?0:dp[i-1]);
        }

        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                dp[j] = j==0?dp[j]:min(dp[j],dp[j-1]);  // 条件运算符优先级低，只比赋值高
                dp[j] = dp[j]+grid[i][j];
            }
        }
        return dp[grid[0].size()-1];
    }
};
// @lc code=end

