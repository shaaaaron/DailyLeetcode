/*
 * @lc app=leetcode.cn id=974 lang=cpp
 * @lcpr version=30122
 *
 * [974] 和可被 K 整除的子数组
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
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0, sum=0;
        vector<int> memo(k, 0);
        memo[0]=1;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            // sum可能是负数，((sum%k)+k)%k得到的是正余数
            int rem = ((sum%k)+k)%k;
            int comple =  k-rem!=k ? k-rem:0;
            ans+= memo[rem];

            memo[rem]++;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,0,-2,-3,1]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5]\n9\n
// @lcpr case=end

 */

