/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=30121
 *
 * [198] 打家劫舍
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
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        // int dp1=nums[0], dp2=nums[1];
        int dp1=nums[0], dp2=max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            int dp3 = max(dp1+nums[i], dp2);
            dp1=dp2;
            dp2=dp3;
        }

        return dp2;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */

