/*
 * @lc app=leetcode.cn id=1463 lang=cpp
 * @lcpr version=30122
 *
 * [1463] 摘樱桃 II
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
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n+2, INT_MIN));
        int dp[80][80][80]={0};
        fill(&dp[0][0][0], &dp[0][0][0] + 80*80*80, INT_MIN);

        // 行数不变，列数+1
        dp[0][1][n]=grid[0][0] + (n-1!=0?grid[0][n-1]:0);
        for(int i=1;i<m;i++){ // 从第二行开始
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){ // 似乎不能对称，不能只计算j<=k的部分
                    vector<int> tmp={
                        dp[i-1][j-1][k-1], dp[i-1][j-1][k], dp[i-1][j-1][k+1],
                        dp[i-1][j  ][k-1], dp[i-1][j  ][k], dp[i-1][j  ][k+1],
                        dp[i-1][j+1][k-1], dp[i-1][j+1][k], dp[i-1][j+1][k+1]};
                    dp[i][j][k]=*max_element(tmp.begin(), tmp.end())+grid[i][j-1] + (j!=k?grid[i][k-1]:0);
                }
            }
        }

        int ans=INT_MIN;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                ans=max(ans, dp[m-1][j][k]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1]]\n
// @lcpr case=end

 */

