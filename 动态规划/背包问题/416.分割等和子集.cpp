/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30121
 *
 * [416] 分割等和子集
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
    // 零一背包
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++) total+=nums[i];
        if(total%2==1)return false;

        total=total/2;  
        vector<int> dp(total+1, 0); //表示是否可以
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=total;j>=nums[i];j--){ // 零一背反过来
                dp[j]=max(dp[j], dp[j-nums[i]]);  // 背包是不是需要大小是正？
            }
        }
        return dp[total];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */

