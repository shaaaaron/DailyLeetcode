/*
 * @lc app=leetcode.cn id=2527 lang=cpp
 * @lcpr version=30122
 *
 * [2527] 查询数组异或美丽值
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
// 挺好一题，非常有意思，注意到组合是没有顺序的
    int xorBeauty(vector<int>& nums) {
        int ans=0;
        for(int num:nums){
            ans^=num;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4]\n
// @lcpr case=end

// @lcpr case=start
// [15,45,20,2,34,35,5,44,32,30]\n
// @lcpr case=end

 */

