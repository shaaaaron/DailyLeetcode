/*
 * @lc app=leetcode.cn id=801 lang=cpp
 * @lcpr version=30202
 *
 * [801] 使序列递增的最小交换次数
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
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int a=0, b=0; // a表示最后数字不变，b表示最后数字交换
        for(int i=0;i<nums1.size();i++){
            if(i==0){
                b=1; // 最开始要放在循环中，并且正确处理
                continue;
            } 
            int new_a=INT_MAX, new_b=INT_MAX;
            if(nums1[i-1]<nums1[i] && nums2[i-1]<nums2[i]) new_a=min(new_a, a);
            if(nums2[i-1]<nums1[i] && nums1[i-1]<nums2[i]) new_a=min(new_a, b);
            if(nums1[i-1]<nums2[i] && nums2[i-1]<nums1[i]) new_b=min(new_b, a+1);
            if(nums2[i-1]<nums2[i] && nums1[i-1]<nums1[i]) new_b=min(new_b, b+1);
            a=new_a, b=new_b;
        }
        return min(a,b);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,4]\n[1,2,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,5,8,9]\n[2,1,4,6,9]\n
// @lcpr case=end

 */

