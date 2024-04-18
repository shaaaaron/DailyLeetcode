/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30122
 *
 * [78] 子集
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
    vector<int> nums;

    vector<int> now;

    vector<vector<int>> ans;

    void bt(int k){
        if(k==nums.size()){ // 这里检查
            ans.push_back(now);
            return;
        }

        now.push_back(nums[k]);
        bt(k+1);
        now.pop_back();
        bt(k+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums=nums;
        bt(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

