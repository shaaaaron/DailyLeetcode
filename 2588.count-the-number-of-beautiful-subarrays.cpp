/*
 * @lc app=leetcode.cn id=2588 lang=cpp
 * @lcpr version=30122
 *
 * [2588] 统计美丽子数组数目
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
// 操作的奇偶不变量
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int> memo;
        memo[0]=1;// 初始化，注意！

        long long ans=0;
        int pre_xors=0;
        for(int i=0;i<nums.size();i++){
            pre_xors^=nums[i];
            if(memo.find(pre_xors)!=memo.end()){
                ans+=memo[pre_xors];
            }

            // if(nums[i]==0) ans--;
            // 题目有点问题，看下讨论区，0是满足要求的子数组，因为操作了0次
            memo[pre_xors]++;
        }
        
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,0,1]\n
// @lcpr case=end
// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end
// @lcpr case=start
// [2,1,1]\n
// @lcpr case=end
// @lcpr case=start
// [4,3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,4]\n
// @lcpr case=end

 */

