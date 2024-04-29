/*
 * @lc app=leetcode.cn id=477 lang=cpp
 * @lcpr version=30122
 *
 * [477] 汉明距离总和
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
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                ans+=__builtin_popcount(nums[i]|nums[j])-__builtin_popcount(nums[i]&nums[j]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,14,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,14,4]\n
// @lcpr case=end

 */

