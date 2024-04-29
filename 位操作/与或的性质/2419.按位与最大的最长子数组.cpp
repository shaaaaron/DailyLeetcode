/*
 * @lc app=leetcode.cn id=2419 lang=cpp
 * @lcpr version=30122
 *
 * [2419] 按位与最大的最长子数组
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
#include <assert.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_num=0, len=0, ans=0;

        for(int num:nums){
            if(max_num == num ){
                len++;
            }else if( max_num < num){
                max_num=num;
                len=1;
                ans=0;
            }else{
                len=0;
            }

            ans=max(ans, len);
        }
        
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [311155,311155,311155,311155,311155,311155,311155,311155,201191,311155]\n
// @lcpr case=end
// @lcpr case=start
// [1,2,3,3,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

