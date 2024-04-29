/*
 * @lc app=leetcode.cn id=2411 lang=cpp
 * @lcpr version=30122
 *
 * [2411] 按位或最大的最小子数组长度
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
    vector<int> smallestSubarrays(vector<int>& nums) {
        unordered_map<int, int >memo;

        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            int remo_idx=i;
            for(int bit=0;bit<31;bit++){
                if( (1<<bit & nums[i])==0 && memo.find(bit)!=memo.end()){//
                    remo_idx=max(remo_idx, memo[bit]);
                }else if((1<<bit & nums[i])!=0){
                    memo[bit]=i;
                }
            }

            ans.push_back(remo_idx-i+1);
        }

        reverse(ans.begin(),  ans.end());
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

