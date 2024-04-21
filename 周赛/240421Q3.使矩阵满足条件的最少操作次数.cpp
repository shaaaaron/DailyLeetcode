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

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> nums(n, vector<int>(10));
        vector<vector<int>> dp(n+1, vector<int>(10, INT_MAX));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int tmp=grid[i][j];
                nums[j][tmp]++; //第j列的数字数量
            }
        }
        
        for(int i=0;i<=9;i++) dp[0][i]=0; // 初始化
        
        for(int i=1;i<=n;i++){
            // i=0，默认初始化
            // i-1是nums索引
            for(int j=0;j<=9;j++){
                for(int before_j=0;before_j<=9;before_j++){
                    if(before_j==j) continue;
                    
                    dp[i][j]=min(dp[i][j], dp[i-1][before_j]+ m-nums[i-1][j]);
                }
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<=9;i++){
            ans=min(ans, dp[n][i]);
        }
        return ans;
    }
};