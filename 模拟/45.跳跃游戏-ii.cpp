/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30122
 *
 * [45] 跳跃游戏 II
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
// 有点巧妙，可以多看看
    int jump(vector<int>& nums) {
        int loc=0,next_step_loc=0;
        int i=0,ans=0;
        while(i<=loc){
            if(i==nums.size()-1) return ans;

            next_step_loc=max(next_step_loc, i+nums[i]);
            if(i==loc){
                ans++;
                loc=next_step_loc;
            }

            i++;
        }
        return 0-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */

