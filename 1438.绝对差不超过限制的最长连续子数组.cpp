/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 * @lcpr version=30121
 *
 * [1438] 绝对差不超过限制的最长连续子数组
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
// 单调队列 从前到后变小
// 核心在于每一个可行的方法，都可以将长度表示为 最大元素左右能延申的最大边界
// 计算每一个元素作为最大元素，左右能延申的最大边界，都是一种可行方法
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> q;
        int n=nums.size();

        vector<int> right(n,n-1), left(n,0);
        // for(int i=0;i<n;i++) right[i]=i;
        // 最后还在队列中的元素，可以延申到n-1，就是实际边界

        for(int i=0;i<n;i++){
            while(!q.empty() && nums[q.front()]-limit>nums[i]){
                right[q.front()]=i-1;//
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()]<nums[i]){
                right[q.back()]=i-1;//
                q.pop_back();
            }
            q.push_back(i);
        }
        // for(int i=0;i<n;i++){ cout<<nums[right[i]]<<", ";}cout<<endl;

        q=deque<int>{}; // 初始化
        // for(int i=0;i<n;i++) left[i]=i;
        for(int i=n-1;i>=0;i--){ // 不能写错
            while(!q.empty() && nums[q.front()]-limit>nums[i]){
                left[q.front()]=i+1;//
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()]<nums[i]){
                left[q.back()]=i+1;
                q.pop_back();
            }
            q.push_back(i);
        }
        // for(int i=0;i<n;i++){ cout<<nums[left[i]]<<", ";}cout<<endl;

        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans, right[i]-left[i]+1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,2,4,7]\n4\n
// @lcpr case=end

// @lcpr case=start
// [10,1,2,4,7,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,2,4,4,2,2]\n0\n
// @lcpr case=end

 */

