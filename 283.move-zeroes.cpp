/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30122
 *
 * [283] 移动零
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
    void moveZeroes(vector<int>& nums) {
        // 方法1，双指针法没有办法维持数组顺序不变
        // int i=0,j=nums.size()-1;
        // while(i<j){
        //     while(i<nums.size() && nums[i]!=0){
        //         i++;
        //     }
        //     while(j>=0 && nums[j]==0){
        //         j--;
        //     }
        //     if(i<j){
        //         swap(nums[i], nums[j]);
        //     }
        //     i++;
        //     j--;
        // }

        // 方法2，两个指针从前向后
        int i=0,j=0;
        for(int i=0;i<nums.size();i++){ // 还挺巧妙地
            if(nums[i]!=0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        // 还是很奇怪，后面直接都为0更简单
        return;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

