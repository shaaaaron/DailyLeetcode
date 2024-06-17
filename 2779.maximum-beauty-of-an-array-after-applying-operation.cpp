/*
 * @lc app=leetcode.cn id=2779 lang=cpp
 * @lcpr version=30203
 *
 * [2779] 数组的最大美丽值
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
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        deque<int> dq;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            dq.push_back(i);
            while(nums[i]-nums[dq.front()]>2*k){
                dq.pop_front();
            }
            ans=max(ans, (int)dq.size());
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,6,1,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n10\n
// @lcpr case=end

 */

