/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 * @lcpr version=30121
 *
 * [1277] 统计全为 1 的正方形子矩阵
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
    // dp[i][j]=dp[i-1][j]!=dp[i][j-1]?min(dp[i-1][j], dp[i][j-1]):
        //                           (a[i-dp[i-1][j]][j-dp[i-1][j]]==1 ? dp[i-1][j]: dp[i-1][j])
    // a[i][j]表示以[i][j]为右下角的正方性数量
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;

        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]==0){
                    continue;
                } 

                if(dp[i-1][j]!=dp[i][j-1]){
                    dp[i][j]=min(dp[i-1][j], dp[i][j-1])+1;
                }else{
                    int len=dp[i-1][j];
                    if(matrix[i-len -1][j-len -1]==1){ // 访问原数组记得-1！！！
                        dp[i][j]=dp[i-1][j]+1;
                    }else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,1,1],[1,1,1,1],[0,1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,1],[1,1,0],[1,1,0]]\n
// @lcpr case=end

 */

