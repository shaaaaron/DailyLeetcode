/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30121
 *
 * [53] 最大子数组和
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
    int maxSubArray(vector<int>& nums) {
        int frontier = 0; // 当前子数组前面的最大连续子数组
        int ansTmp = nums[0];
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(frontier+nums[i]>ansTmp) ansTmp = frontier+nums[i];
            if(frontier+nums[i]>0){
                frontier = frontier+nums[i];
            }else{
                frontier = 0;
            }
        }

        return ansTmp;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

