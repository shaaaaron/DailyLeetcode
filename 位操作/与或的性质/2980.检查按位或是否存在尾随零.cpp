/*
 * @lc app=leetcode.cn id=2980 lang=cpp
 * @lcpr version=30122
 *
 * [2980] 检查按位或是否存在尾随零
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
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt=0;
        for(int num:nums){
            if( (num&1)==0)cnt++; // 需要加括号，位移、比较、按位操作 运算符依次降低
        }

        return cnt>=2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,8,16]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,7,9]\n
// @lcpr case=end

 */

