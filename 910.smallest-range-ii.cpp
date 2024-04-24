/*
 * @lc app=leetcode.cn id=910 lang=cpp
 * @lcpr version=30122
 *
 * [910] 最小差值 II
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
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans=nums[n-1]-nums[0];

        for(int i=0;i+1<n;i++){ // 分成左右非空的两端
            ans=min(ans, max(nums[i]+k, nums[n-1]-k)-min(nums[0]+k, nums[i+1]-k));
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0,10]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,6]\n3\n
// @lcpr case=end

 */

