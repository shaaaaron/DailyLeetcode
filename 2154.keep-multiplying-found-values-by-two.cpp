/*
 * @lc app=leetcode.cn id=2154 lang=cpp
 * @lcpr version=30122
 *
 * [2154] 将找到的值乘以 2
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
// 想清楚，二分可以
// 但是不同次数之间有关联，直接一次性搜索
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for(int num:nums){
            if(num==original)
                original*=2; 
        }
        return original;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,6,1,12]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9]\n4\n
// @lcpr case=end

 */

