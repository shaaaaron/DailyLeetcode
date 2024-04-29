/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=30122
 *
 * [238] 除自身以外数组的乘积
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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1)
                ans[i]=1;
            else
                ans[i]=nums[i+1]*ans[i+1];
        }

        int bef_prod=1;
        for(int i=0;i<nums.size();i++){
            ans[i]*=bef_prod;
            bef_prod*=nums[i];
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */

