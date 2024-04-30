/*
 * @lc app=leetcode.cn id=201 lang=cpp
 * @lcpr version=30122
 *
 * [201] 数字范围按位与
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
// 必须严格缩减，只mask没法判断
    int rangeBitwiseAnd(int left, int right) {
        int ans=0, base=1;
        while(left>0 || right>0){
            if(left==right && left&1==1){
                ans+=base;
            }
            base=base<<1;
            left=left>>1;
            right=right>>1;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n7\n
// @lcpr case=end

// @lcpr case=start
// 0\n0\n
// @lcpr case=end

// @lcpr case=start
// 1\n2147483647\n
// @lcpr case=end

 */

