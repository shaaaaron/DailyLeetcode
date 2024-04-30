/*
 * @lc app=leetcode.cn id=260 lang=cpp
 * @lcpr version=30122
 *
 * [260] 只出现一次的数字 III
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
// 注意结果可能越界
    vector<int> singleNumber(vector<int>& nums) {
        long long xors=0; // xor是保留字
        for(int num:nums){
            xors^=num;
        }

        int x=0, y=0;
        for(int num:nums){
            if(num&(xors&(-xors))){//加以区分, 两个都是与，想清楚不能写成异或
            // 中间结果可能越界
                x^=num;
            }
            else{
                y^=num;
            }

        }

        return {x, y}; // 不用显示构造，返回自动构造
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,0,-2147483648]\n
// @lcpr case=end
// @lcpr case=start
// [2,1,2,3,4,1]\n
// @lcpr case=end
// @lcpr case=start
// [1,2,1,3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

 */

