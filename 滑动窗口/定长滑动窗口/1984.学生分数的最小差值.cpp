/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 * @lcpr version=30122
 *
 * [1984] 学生分数的最小差值
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
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lf=0, rt=k-1;

        int ans=INT_MAX;
        while(rt<nums.size()){
            ans=min(ans, nums[rt]-nums[lf]);
            lf++;
            rt++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [90]\n1\n
// @lcpr case=end

// @lcpr case=start
// [9,4,1,7]\n2\n
// @lcpr case=end

 */

