/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30121
 *
 * [84] 柱状图中最大的矩形
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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s; // 下一个严格更小的元素，使用大顶单调栈
        vector<int> ans1(n,0), ans2(n,0); //可以指使用一个

        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>heights[i]){ // 小则这里num小
                ans1[s.top()] = heights[s.top()] * (i-s.top());
                s.pop();
            }
            s.push(i);
        }

        // 如果栈中还存在元素，这些元素右边没有严格更小的元素
        // 可以求最左边元素的下标，或者到最左边元素的距离。前者可以统一初始化，不需要额外栈中所有元素出栈
        while(!s.empty()){
            ans1[s.top()] = heights[s.top()] * (n-s.top());
            s.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>heights[i]){
                ans2[s.top()] = heights[s.top()] * (s.top()-i);
                s.pop();
            }
            s.push(i);
        }

        while(!s.empty()){
            ans2[s.top()] = heights[s.top()] * (s.top()-(-1));
            s.pop();
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans, ans1[i]+ans2[i]-heights[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end
// @lcpr case=start
// [3,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,5,6,2,3,3,2,6,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,4,2]\n
// @lcpr case=end
// @lcpr case=start
// [3,2,2,3]\n
// @lcpr case=end
 */

