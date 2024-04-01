/*
 * @lc app=leetcode.cn id=724 lang=cpp
 * @lcpr version=30121
 *
 * [724] 寻找数组的中心下标
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
    int pivotIndex(vector<int>& nums) {
        int ans=0;
        for(auto & num :nums) ans+=num;

        int tmp=0;
        int i;
        for(i=0;i<nums.size();i++){
            if(tmp==ans-tmp-nums[i])break; // 赋值和判断相等
            tmp+=nums[i];
        }

        return i!=nums.size()?i:-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 7, 3, 6, 5, 6]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3]\n
// @lcpr case=end

// @lcpr case=start
// [2, 1, -1]\n
// @lcpr case=end

 */

