/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=30121
 *
 * [279] 完全平方数
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
    int numSquares(int n) {
        
        // // for(int i=0;i<=n;i++)a[0][i]=1;
        // // a[0][0]=1;
        // vector<vector<int>> a(n+1, vector<int>(n+1, -1));
        // int tmpI;
        // for(int i=1;i*i<=n;i++){ // 不超过n的完全平方数，从1开始枚举
        //     for(int j=0;j<=n;j++){
        //         if(j==i*i)  a[i][j]=1;
        //         else{
        //                 a[i][j] = a[i-1][j];
        //             for(int k=0;j-k*i*i>=0;k++){
        //                 if(a[i][j-k*i*i]!=-1 && (a[i][j-k*i*i]+1<a[i][j] || a[i][j]==-1))
        //                     a[i][j] =a[i][j-k*i*i]+k;
        //             }   
        //         }
        //     }
        //     tmpI=i;
        // }

        // for(int i=0;i<=n;i++)a[0][i]=1;
        // a[0][0]=1;
        vector<int> a(n+1, -1); // 内存mle
        int tmpI;
        for(int i=1;i*i<=n;i++){ // 不超过n的完全平方数，从1开始枚举
            for(int j=0;j<=n;j++){
                if(j==i*i){
                    a[j]=1;
                }  
                else if(j-i*i>=0 && (a[j-i*i]+1<a[j] || a[j]==-1)){ //时间tle
                    a[j] =a[j-i*i]+1;
                }
                
            }
            tmpI=i;
        }

        return a[n];

        // std::vector<int> dp(n + 1, INT_MAX);
        // dp[0] = 0; // 0由0个完全平方数构成
        // for (int i = 1; i * i <= n; ++i) {
        //     int square = i * i;
        //     for (int j = square; j <= n; ++j) {
        //         if (dp[j - square] != INT_MAX) { // 保证j-square是有效的
        //             dp[j] = std::min(dp[j], dp[j - square] + 1);
        //         }
        //     }
        // }
        // return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7927\n
// @lcpr case=end
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */

