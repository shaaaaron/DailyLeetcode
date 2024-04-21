/*
 * @lc app=leetcode.cn id=525 lang=cpp
 * @lcpr version=30122
 *
 * [525] 连续数组
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
// 这题很巧妙
    int findMaxLength(vector<int>& nums) {
        int sum=0; // 1比0多的数量
                    // 将区间转化为前缀和
        int ans=0;
        unordered_map<int,int> memo; // 相同sum最远的
        memo[0]=-1; // 索引-1

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                sum++;
            }else{
                sum--;
            }

            if(memo.find(sum)!=memo.end()){
                ans=max(ans, i-memo[sum]);
            }

            if(memo.find(sum)==memo.end()){
                memo[sum]=i;
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

 */

