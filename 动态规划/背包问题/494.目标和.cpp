/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=30121
 *
 * [494] 目标和
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
    int findTargetSumWays(vector<int>& nums, int target) {
        // T=A-S => 2S=A+S-T 
        int total=-target;
        for(auto &num: nums) total+=num; // 注意下面使用total

        if(total<0) return false; // total至少非负！否则会出现
        // Line 1037: Char 9: runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
        // 表示数组访问出界

        vector<int> dp(total+1, 0); //总表达式的数目，初始化为0!
        dp[0]=1;

        for(auto &num:nums){
            for(int j=total;j>=2*num;j--){
                dp[j]=dp[j]+dp[j- 2*num];
            }
        }

        return dp[total];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

