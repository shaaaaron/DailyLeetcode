/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=30122
 *
 * [560] 和为 K 的子数组
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
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        vector<int> sum(nums.size()+1);
        unordered_map<int,int> memo;

        for(int i=0;i<nums.size();i++){
            sum[i+1]=sum[i]+nums[i];
        }
        
        memo[0]=1; // memo更新但是ans不更新
        for(int i=0;i<nums.size();i++){ // 区间是 ...,i]
            if(memo.find(sum[i+1]-k)!=memo.end()){
                ans+=memo.at(sum[i+1]-k);
            }
            memo[sum[i+1]]++;
        }
        return ans;
        
        // 目前的思路是，根据 索引 查找 前缀和
        // 一个优化的思路是，根据 前缀和 查找 索引，并且只需要记录前面指定前缀和的索引有多少个

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */

