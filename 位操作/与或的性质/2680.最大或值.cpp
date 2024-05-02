/*
 * @lc app=leetcode.cn id=2680 lang=cpp
 * @lcpr version=30122
 *
 * [2680] 最大或值
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
    long long maximumOr(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(nums.size()), post(nums.size());

        for(int i=0;i<n;i++){
            if(i==0)
                pre[i]=0; //  初始化不能为1
            else
                pre[i]=nums[i-1]|pre[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1)
                post[i]=0;
            else
                post[i]=nums[i+1]|post[i+1];
        }

        for(int i=0;i<n;i++){
            cout<<pre[i]<<","<<post[i]<<endl;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long tmp= ((long long)nums[i]<<k) | pre[i]  | post[i];
            ans=max(ans, tmp);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [12,9]\n1\n
// @lcpr case=end

// @lcpr case=start
// [8,1,2]\n2\n
// @lcpr case=end

 */

