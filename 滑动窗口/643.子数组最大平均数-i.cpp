/*
 * @lc app=leetcode.cn id=643 lang=cpp
 * @lcpr version=30122
 *
 * [643] 子数组最大平均数-i
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
    double findMaxAverage(vector<int>& nums, int k) {
        int lt=0, rt=0;
        // 下面记录总和，最后才计算平均值
        int ans, sum=0;
        while(rt<k){
            sum+=nums[rt];
            rt++;
        }
        ans=sum;

        while(rt<nums.size()){
            sum+=nums[rt];
            sum-=nums[lt];
            rt++;
            lt++;
            ans=max(ans, sum);
        }
        return double(ans)/k;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,12,-5,-6,50,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n
// @lcpr case=end

 */

