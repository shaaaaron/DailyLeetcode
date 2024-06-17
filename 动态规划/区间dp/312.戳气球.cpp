/*
 * @lc app=leetcode.cn id=312 lang=cpp
 * @lcpr version=30121
 *
 * [312] 戳气球
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
    // 考虑哪个气球是最后戳破的
    // dp[i][j] 表示开区间(i,j)戳破其中的所有气球（不包括边界），能取得的最大硬币数
    // 给左边右边分别添加一个虚拟气球
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n,0));

        for(int d_ij=2;d_ij<=n-1;d_ij++){
            for(int i=0,j=i+d_ij;j<n;i++,j++){
                for(int tmp=i+1;tmp<j;tmp++){
                    // tmp是最后炸爆的
                    dp[i][j]=max(dp[i][j], dp[i][tmp]+ dp[tmp][j]+nums[i]*nums[j]*nums[tmp]);
                }
            }
        }

        return dp[0][n-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,5,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,5]\n
// @lcpr case=end

 */

