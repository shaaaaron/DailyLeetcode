/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 * @lcpr version=30201
 *
 * [1493] 删掉一个元素以后全为1的最长子数组
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
// 问题转化：如果存在零，含有一个零的最长数组
// 如果全为1，则是数组的长度-1

// 换言之，就是含有至多一个零的最长数组长度，减去1
    int longestSubarray(vector<int>& nums) {
        int lt=0,rt=0;
        int zero_cnt=0;
        int ans=0;
        while(rt<nums.size()){
            if(nums[rt]==0){
                zero_cnt++;
                while(zero_cnt>1){
                    if(nums[lt]==0){
                        zero_cnt--;
                    }
                    lt++;
                }
            }
            ans=max(rt-lt+1, ans); // 左闭右闭
            rt++;
        }
        return ans-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,0,1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

 */

