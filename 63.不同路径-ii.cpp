/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> dp(n,0);

        for(int i=0;i<n;i++){
            dp[i] = i==0? (1-obstacleGrid[0][i]): (obstacleGrid[0][i]? 0: dp[i-1]);
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[j]=0;
                }else{
                    dp[j]= j==0?dp[j]: dp[j]+dp[j-1];
                }
                // cout<<dp[j]<<endl;
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

