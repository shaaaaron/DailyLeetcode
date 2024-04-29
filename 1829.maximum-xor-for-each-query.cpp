/*
 * @lc app=leetcode.cn id=1829 lang=cpp
 * @lcpr version=30122
 *
 * [1829] 每个查询的最大异或值
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
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int mask= (1<<maximumBit)-1;
        int res=0;
        for(int num:nums){
            res^=num;
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(~(res&mask)&mask); // 注意这里
            res^=nums[n-1-i];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,5,7]\n3\n
// @lcpr case=end

 */

