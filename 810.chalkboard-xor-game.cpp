/*
 * @lc app=leetcode.cn id=810 lang=cpp
 * @lcpr version=30122
 *
 * [810] 黑板异或游戏
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
// 如果xor结果位0，直接赢
// 否则，证明操作一次之后必然不为0，条件为长度为偶数
// 可以从后手必败倒退，前一次不为0，而且手操作前序列个数为偶数
// 利用操作的交换律
// https://leetcode.cn/problems/chalkboard-xor-game/solutions/789745/gong-shui-san-xie-noxiang-xin-ke-xue-xi-ges7k/
    bool xorGame(vector<int>& nums) {
        int xor_res=0;
        for(int num:nums)
            xor_res^=num;
        
        if(xor_res==0) return true;
        if(nums.size()%2==0) return true;
        return false;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

