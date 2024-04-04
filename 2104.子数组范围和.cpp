/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 * @lcpr version=30121
 *
 * [2104] 子数组范围和
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
// python好像没有int表示范围问题
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();

        stack<int> s;
        vector<long long> dp(nums.size(),0); // return longlong这里longlong

        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<nums[i]){

                s.pop();
            }
            if(s.empty()){
                dp[i]= (long long)(i+1)*nums[i];
            }else{
                dp[i]= (long long)(i-s.top())*nums[i]+dp[s.top()];
            }
            ans+=dp[i];
            s.push(i);
            // cout<<nums[i]<<","<<dp[i]<<","<<ans<<endl;
        }

        s=stack<int>{};
        // cout<<(s.size());
        // ans=0;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>nums[i]){

                s.pop();
            }
            if(s.empty()){
                dp[i]= (long long)(i+1)*nums[i]; // 看数据范围
            }else{
                dp[i]= (long long)(i-s.top())*nums[i]+dp[s.top()];
            }
            ans-=dp[i];
            s.push(i);
            // cout<<nums[i]<<","<<dp[i]<<","<<ans<<endl;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,-3,1]\n
// @lcpr case=end
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,3]\n
// @lcpr case=end



 */

