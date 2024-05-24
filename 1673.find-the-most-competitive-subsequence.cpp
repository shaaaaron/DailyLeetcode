/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 * @lcpr version=30202
 *
 * [1673] 找出最具竞争力的子序列
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
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int> st;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            // 注意对最后一个元素而言，越小反而后面越容易成功，所以只需要st.size()+n-1-i>=k
            // 并且不需要把每一次的结果记录到ans中进行比较，会超时
            // 单调栈容易想到，但不知道怎么增加条件
            while(st.size()>0 && st.back()>nums[i] && st.size()+n-1-i>=k){
                st.pop_back();
            }
            st.push_back(nums[i]);
        }
        
        // 最后的结果可能超过k，所以需要消减到k
        while(st.size()>k){
            st.pop_back();
        }
        return vector<int> (st.begin(), st.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,2,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3,3,5,4,9,6]\n4\n
// @lcpr case=end

 */

