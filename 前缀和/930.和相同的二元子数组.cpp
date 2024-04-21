/*
 * @lc app=leetcode.cn id=930 lang=cpp
 * @lcpr version=30122
 *
 * [930] 和相同的二元子数组
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
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> memo;

        int sum=0, ans=0;
        memo[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(memo.find(sum-goal)!=memo.end()){
                ans+=memo.at(sum-goal);
            }

            memo[sum]++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,1,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0,0]\n0\n
// @lcpr case=end

 */

