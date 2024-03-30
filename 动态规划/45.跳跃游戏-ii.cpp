/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30121
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
    int jump(vector<int>& nums) {
        int n = nums.size();
        int stpeNums=0, maxLoc=0, nextStepLoc=0;
        // 已经跳跃的步数，当前能走到最远的地方，下一步能跳到最远的地方 
        
        for(int i=0;i<=n-1;i++){
            if(i > maxLoc){
                maxLoc = nextStepLoc;
                stpeNums++;
            }
            
            if(i+nums[i]> nextStepLoc){
                nextStepLoc = i+nums[i];
            }   
        }

        return stpeNums;

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

// @lcpr case=start
// [100]\n
// @lcpr case=end
 */

