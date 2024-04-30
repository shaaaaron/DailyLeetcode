/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 * @lcpr version=30122
 *
 * [2044] 统计按位或能得到最大值的子集数目
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
// 子序列，可能是回溯
    int countMaxOrSubsets(vector<int>& nums) {
       // 排列直接2^n
        int tar=0;
        for(int num:nums) tar|=num;

        int ans=0;
        int n=nums.size();
        for(int state=0;state< 1<<n;state++){ // 比回溯写起来来清除
            int or_res=0;
            for(int bit=0;bit<n;bit++){
                if(state&1<<bit){
                    or_res|=nums[bit];
                }
            }
            if(or_res==tar) ans++;
        } 
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,5]\n
// @lcpr case=end
// @lcpr case=start
// [3,2,1,5,6,7,8,9,10,12,11,13,15,16,29,31]\n
// @lcpr case=end

 */

