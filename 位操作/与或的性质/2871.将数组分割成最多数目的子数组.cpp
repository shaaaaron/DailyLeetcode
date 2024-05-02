/*
 * @lc app=leetcode.cn id=2871 lang=cpp
 * @lcpr version=30122
 *
 * [2871] 将数组分割成最多数目的子数组
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
    int maxSubarrays(vector<int>& nums) {
        int i=0,j;
        int ans=0;

        while(i< nums.size()){
            j=i;
            int tmp=-1; // 全1
            while(j<nums.size()){
                tmp&=nums[j];
                j++;

                if(tmp==0){
                    ans++;
                    break;
                }
            }
            i=j;
        }
        return ans==0 ? 1: ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,2,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,7,1,3]\n
// @lcpr case=end

 */

