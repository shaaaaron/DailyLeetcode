/*
 * @lc app=leetcode.cn id=1785 lang=cpp
 * @lcpr version=30122
 *
 * [1785] 构成特定和需要添加的最少元素
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0;
        for(int num:nums)
            sum+=num;
        // accumulate(nums.begin(), nums.end(), 0);
        long long delta=goal-sum;
        if(delta==0) return 0;
        if(delta>=1) return (delta-1)/limit+1;
        return (-delta-1)/limit+1;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-1,1]\n3\n-4\n
// @lcpr case=end

// @lcpr case=start
// [1,-10,9,1]\n100\n0\n
// @lcpr case=end

 */

