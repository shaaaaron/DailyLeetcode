/*
 * @lc app=leetcode.cn id=3097 lang=cpp
 * @lcpr version=30122
 *
 * [3097] 或值至少为K的最短子数组 II
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
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=INT_MAX;
        unordered_map<int,int> memo, memo_pre;
        for(int i=0;i<nums.size();i++){
            memo.clear();
            for(auto &pr : memo_pre){
                // 保证留下的时下表大的
                if(memo.find(pr.first | nums[i]) == memo.end())
                    memo[pr.first | nums[i]]=pr.second;
                else
                    memo[pr.first | nums[i]]=max(memo[pr.first | nums[i]], pr.second);
                if((pr.first | nums[i])>=k) ans=min(ans, i-pr.second+1);
            }// 如果有重复，后面覆盖前面。由于无序，覆盖是错误的
            memo[nums[i]]=i;
            if(nums[i]>=k) ans=min(ans, 1);

            memo_pre=memo;
        }

        return ans==INT_MAX?-1: ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,29,50,1,32,96,1]\n126\n
// @lcpr case=end
// @lcpr case=start
// [1,2,32,21]\n55\n
// @lcpr case=end
// @lcpr case=start
// [1,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,1,8]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */

