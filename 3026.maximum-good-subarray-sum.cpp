/*
 * @lc app=leetcode.cn id=3026 lang=cpp
 * @lcpr version=30122
 *
 * [3026] 最大好子数组和
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
        unordered_map<int, int> memo; // 根据数找到保留的索引
        vector<long long> sums(nums.size()+1);
        long long ans=LONG_LONG_MIN; //
        for(int i=1;i<sums.size();i++){
            sums[i]=sums[i-1]+nums[i-1];
        }

        for(int i=0;i<nums.size();i++){
            if(memo.find(nums[i]-k) != memo.end()){
                ans=max(ans, sums[i+1]-sums[memo.at(nums[i]-k)] );
            }
            if(memo.find(nums[i]+k) != memo.end()){
                ans=max(ans, sums[i+1]-sums[memo.at(nums[i]+k)] );
            }

            if(memo.find(nums[i]) != memo.end()){
                if(sums[i+1]- sums[memo.at(nums[i])]<0){
                    memo[nums[i]]=i;
                }
            }else{
                memo[nums[i]]=i;
            }
        }
        if(ans==LONG_LONG_MIN) return 0;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6]\n1\n
// @lcpr case=end

// @lcpr case=start
// [-1,3,2,4,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2,-3,-4]\n2\n
// @lcpr case=end
// @lcpr case=start
// [1,5]\n2\n
// @lcpr case=end
 */

