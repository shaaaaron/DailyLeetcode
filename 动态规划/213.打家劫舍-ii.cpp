/*
 * @lc app=leetcode.cn id=213 lang=cpp
 * @lcpr version=30121
 *
 * [213] 打家劫舍 II
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0], nums[1]);

        // 偷第一个房子
        int dp1=nums[0], dp2=max(nums[0], nums[1]);
        for(int i=2;i<n - 1;i++){//不透最后一个
            int dp3 = max(dp1+nums[i], dp2);
            dp1=dp2;
            dp2=dp3;
        }
        int ansTmp = dp2;

        // 偷最后一个房子
        // int dp1=nums[n-1], dp2=max(nums[n-1], nums[n-2]);
        dp1=nums[n-1];
        dp2=max(nums[n-1], nums[n-2]);
        for(int i=n-3;i>=1;i--){ // 不偷第一个
            int dp3= max(dp1+nums[i],dp2);
            dp1=dp2;
            dp2=dp3;
        }

        return max(ansTmp, dp2);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

