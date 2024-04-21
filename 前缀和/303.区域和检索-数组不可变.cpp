/*
 * @lc app=leetcode.cn id=303 lang=cpp
 * @lcpr version=30122
 *
 * [303] 区域和检索 - 数组不可变
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
class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        sums.resize(nums.size()+1); //多一个元素

        sums[0]=0;
        for(int i=1;i<sums.size();i++){
            sums[i]=sums[i-1]+nums[i-1]; //s[i+1]=s[i]+a[i]，右边都是i
            // a[i]+...+a[j]=s[j+1]-s[i] 恰好是左开右闭
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right+1]-sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumArray", "sumRange", "sumRange", "sumRange"][[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]\n
// @lcpr case=end

 */

