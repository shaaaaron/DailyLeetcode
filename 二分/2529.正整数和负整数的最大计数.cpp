/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 * @lcpr version=30121
 *
 * [2529] 正整数和负整数的最大计数
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
    int maximumCount(vector<int>& nums) {
        int i=0,n=nums.size();
        int j=n-1;
        while(i<=j){
            int m=(i+j)/2;
            if(nums[m]<=0){
                i=m+1;
            }else{
                j=m-1;
            }
        }
        int ans=n-i;

        i=0;j=n-1;
        while(i<=j){
            int m=(i+j)/2;
            if(nums[m]<0){
                i=m+1;
            }else{
                j=m-1;
            }
        }

        return max(ans, i);
    }
};
// @lc code=end



/*
// @lcpr case=start
[-1,-1,-1]\n
// @lcpr case=end
// @lcpr case=start
[-1,-1,-1,0,0]\n
// @lcpr case=end
// @lcpr case=start
// [-2,-1,-1,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-3,-2,-1,0,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,20,66,1314]\n
// @lcpr case=end

 */

