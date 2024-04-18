/*
 * @lc app=leetcode.cn id=376 lang=cpp
 * @lcpr version=30122
 *
 * [376] 摆动序列
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
// n^2的dp不难想到，但是n的贪心比较难
// 核心是摆动序列的最大长度，是nums（不严格）单调串的长度+1
// 先思考什么时候nums本身就是摆动序列，然后退化到nums钟找摆动序列
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;

        bool fisrt=true;
        bool up=true;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            if(fisrt){
                fisrt=false;
                if(nums[i]>nums[i-1]) up=true;
                else up=false;
                ans++;
            }else{
                if(nums[i]>nums[i-1] && !up){
                    up=!up;
                    ans++;
                }else if(nums[i]<nums[i-1] && up){
                    up=!up;
                    ans++;
                }

            }
        }

        // if(fisrt) return 1;
        return ans+1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,4,9,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,17,5,10,13,15,10,5,16,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7,8,9]\n
// @lcpr case=end

 */

