/*
 * @lc app=leetcode.cn id=673 lang=cpp
 * @lcpr version=30121
 *
 * [673] 最长递增子序列的个数
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
    int findNumberOfLIS(vector<int>& nums) {
        int maxv=0,ans=0; // 最长子序列的长度，数量
        
        vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            if(dp[i]==maxv){
                ans+=dp[i];
            }else if(dp[i]>maxv){
                ans=dp[i];
                maxv=
            }
            for(int j=0;j<i;j++){
                if(dp)
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n
// @lcpr case=end

 */

