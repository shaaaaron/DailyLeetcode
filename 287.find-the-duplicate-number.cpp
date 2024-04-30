/*
 * @lc app=leetcode.cn id=287 lang=cpp
 * @lcpr version=30122
 *
 * [287] 寻找重复数
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
    int findDuplicate(vector<int>& nums) {
        // 注意是一共n+1个元素，但是指向1到n。可以把第一个看作0，一定是在基环树的树上
        // 内向基环树，每个节点的出度都为1
        // 内向外向基环树的顶点树和边的数量都相等
        int sl=0, ft=0;
        sl=nums[sl], ft=nums[nums[ft]];
        while(sl != ft){
            sl=nums[sl], ft=nums[nums[ft]];
        }
        ft=0;
        
        while(sl!=ft){
            sl=nums[sl];
            ft=nums[ft];
        }
        return sl;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,3,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,3,3]\n
// @lcpr case=end

 */

