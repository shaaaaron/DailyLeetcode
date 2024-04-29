/*
 * @lc app=leetcode.cn id=1863 lang=cpp
 * @lcpr version=30122
 *
 * [1863] 找出所有子集的异或总和再求和
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
    // 数据范围，直接遍历
    int subsetXORSum(vector<int>& nums) {
        int ans=0, n=nums.size();
        for(int state=0;state< 1<<n;state++){
            int cur_xor=0;
            for(int i=0;i<n;i++){
                if(1<<i&state) cur_xor^=nums[i];
            }
            ans+=cur_xor;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,6]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,6,7,8]\n
// @lcpr case=end

 */

