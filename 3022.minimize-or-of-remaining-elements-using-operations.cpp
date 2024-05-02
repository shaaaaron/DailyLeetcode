/*
 * @lc app=leetcode.cn id=3022 lang=cpp
 * @lcpr version=30122
 *
 * [3022] 给定操作次数内使剩余元素的或值最小
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
// 下面做法有问题，需要从前向后每次考虑一位
// 如果不行则不需要考虑
// 类似于试填法，接着向后考虑
// 其中每一段连续的合并
    int minOrAfterOperations(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>> pq;
        // int min_val, cnt;
        // while(k){
        //     if(pq.empty()){
        //         min_val=INT_MAX, cnt=0; //初始化
        //         for(int num:nums){
        //             if(num<min_val){ //min element
        //                 min_val=num;
        //                 cnt=1;
        //             }else if(num==min_val){
        //                 cnt++;
        //             }
        //         }

        //         for(int num:nums)
        //             if(num!=min_val)
        //                 pq.push(num);

        //         nums=vector<int> (cnt, min_val);
        //     }
        //     int cur=pq.top();
        //     pq.pop();
        //     nums.push_back(nums[0]&cur);
        //     k--;
        // }

        // while(!pq.empty()){
        //     nums.push_back(pq.top());
        //     pq.pop();
        // }
        // int ans=0;
        // for(int num:nums){
        //     ans|=num;
        // }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,3,2,7]\n2\n
// @lcpr case=end

// @lcpr case=start
// [7,3,15,14,2,8]\n4\n
// @lcpr case=end

// @lcpr case=start
// [10,7,10,3,9,14,9,4]\n1\n
// @lcpr case=end

 */

