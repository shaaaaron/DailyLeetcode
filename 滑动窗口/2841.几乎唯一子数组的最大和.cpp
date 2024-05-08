/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 * @lcpr version=30201
 *
 * [2841] 几乎唯一子数组的最大和
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
    long long maxSum(vector<int>& nums, int m, int k) {
        long long sum=0, unq=0; // 滑动窗口的区间和与不同元素的个数
        unordered_map<int,int> memo;
        long long ans=0;

        int lt=0, rt=0;
        while(rt<k){
            memo[nums[rt]]++;
            if(memo[nums[rt]]==1) unq++;
            sum+=nums[rt];

            rt++;
        }
        if(unq>=m) ans=max(sum, ans);

        while(rt<nums.size()){
            memo[nums[rt]]++;
            if(memo[nums[rt]]==1) unq++;
            memo[nums[lt]]--;
            if(memo[nums[lt]]==0) unq--; // 没改完
            sum+=nums[rt];
            sum-=nums[lt];
            if(unq>=m) ans=max(sum, ans);

            rt++;
            lt++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,3]\n2\n2\n
// @lcpr case=end
// @lcpr case=start
// [2,6,7,3,1,7]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [5,9,9,2,4,5,4]\n1\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,1]\n3\n3\n
// @lcpr case=end

 */

