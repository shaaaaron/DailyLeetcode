/*
 * @lc app=leetcode.cn id=456 lang=cpp
 * @lcpr version=30121
 *
 * [456] 132 模式
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
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
// 注意和山形三元组的区别，有第一个元素和第三个元素大小关系的限制
    bool find132pattern(vector<int>& nums) {
        vector<int> minList(nums.size(), INT_MAX); // 表示第i个元素及之前，最小的元素
        // minlist是单调递减的
        minList[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            minList[i]=min(nums[i], minList[i-1]);
        }

        stack<int> s;
        for(int i=nums.size()-1;i>=1;i--){ // 只需到1因为有ij两个元素
            while(!s.empty() && s.top()<=minList[i]){
                s.pop();
            }
            if(!s.empty() && s.top()<nums[i] && nums[i]>minList[i])return true;
            s.push(nums[i]);    // 根据i维护k，但是考虑j
                                // 根据j没法维护k，因为i是单调的
        }


        return false;
    }
};
// @lc code=end

// 单调栈访问栈底元素用vector实现
// back pushback popback

/*
// @lcpr case=start
// [1,0,1,-4,-3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,5,0,3,4]\n
// @lcpr case=end

 */

