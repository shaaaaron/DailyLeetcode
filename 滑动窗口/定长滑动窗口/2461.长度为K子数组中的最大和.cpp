/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 * @lcpr version=30201
 *
 * [2461] 长度为 K 子数组中的最大和
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
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int lt=0, rt=0;
        long long ans=0, sum=0;
        int unq=0;
        unordered_map<int,int> memo;

        while(rt<k){
            sum+=nums[rt];
            memo[nums[rt]]++;
            if(memo[nums[rt]]==1) unq++;
            rt++;
        }
        if(unq==k) ans=max(ans, sum);
        
        while(rt<nums.size()){
            sum+=nums[rt];
            sum-=nums[lt];
            
            memo[nums[rt]]++;
            if(memo[nums[rt]]==1) unq++;
            memo[nums[lt]]--;
            if(memo[nums[lt]]==0) unq--;
            // 上面的四行之间不能交换顺序，否则会导致出错
            if(unq==k) ans=max(ans, sum);
            
            rt++;
            lt++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [11,11,7,2,9,4,17,1]\n1\n
// @lcpr case=end
// @lcpr case=start
// [1,5,4,2,9,9,9]\n3\n
// @lcpr case=end

// @lcpr case=start
// [4,4,4]\n3\n
// @lcpr case=end

 */

