/*
 * @lc app=leetcode.cn id=334 lang=cpp
 * @lcpr version=30121
 *
 * [334] 递增的三元子序列
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
    bool increasingTriplet(vector<int>& nums) {
        int min1=INT_MAX, min2=INT_MAX;// 子序列，解题思路是遍历到字符i时，只需要维护最小的i和ij候选。
        for(int i=0;i<nums.size();i++){
            if(nums[i]>min2) return true; // 注意下面三行代码的顺序不能乱，否则如果本题求的是非严格递增子序列，可能出现[1]中，遍历到1直接把min1、min2、returntrue 分别执行了。应该像01背包一样，反过来执行。
            if(nums[i]>min1 && nums[i]<min2) min2=nums[i];
            if(nums[i]<min1) min1=nums[i];  
        }

        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,5,0,4,6]\n
// @lcpr case=end

 */

