/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=30122
 *
 * [55] 跳跃游戏
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
    bool canJump(vector<int>& nums) {
        int max_loc=0, i=0;
        while(i<=max_loc){
            max_loc=max(max_loc, i+nums[i]);
            if(max_loc>=nums.size()-1) return true;
            i++;
        }
        // 如果maxloc没有达到（超过）重点时，继续前进
        // 如果达到（超过）重点，结束
        // 由于maxloc没有达到（超过）重点，所以i一定在nums下标范围内

        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0]\n
// @lcpr case=end
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */

