/*
 * @lc app=leetcode.cn id=2997 lang=cpp
 * @lcpr version=30122
 *
 * [2997] 使数组异或和等于 K 的最少操作次数
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
    int minOperations(vector<int>& nums, int k) {
        int res=0;
        for(int num:nums){
            res^=num;
        }
        return __builtin_popcount(res^k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3,4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,0,2,0]\n0\n
// @lcpr case=end

 */

