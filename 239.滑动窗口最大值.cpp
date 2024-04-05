/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30121
 *
 * [239] 滑动窗口最大值
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
// 模板题目
// 先出栈后进栈，只当遍历了k个元素之后才进ans数组，但之前要维护单调队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // 队头到队尾单调变小
        int n =nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){//只存后面的元素
            if(!dq.empty() && dq.front()<i-k +1){//一次对头出至多一个元素
                dq.pop_front();
            }
            
            while(!dq.empty() && nums[dq.back()]<= nums[i]){// 分别是华东窗口的pop和push操作
                dq.pop_back();
            }
            dq.push_back(i);
            
            if(i>=k-1)ans.push_back(nums[dq.front()]);
            
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

