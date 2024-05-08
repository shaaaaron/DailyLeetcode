/*
 * @lc app=leetcode.cn id=2653 lang=cpp
 * @lcpr version=30122
 *
 * [2653] 滑动子数组的美丽值
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

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> memo(105);

        int lt=0, rt=0;
        vector<int> ans;
        while(rt<k){
            memo[nums[rt]+50]++;
            rt++;
        }   
        int rem=x; // 初始化窗口就要放一个值到ans
        for(int i=-50;i<=50;i++){
            if(rem<=memo[i+50]){
                ans.push_back(i<0 ? i: 0); // 修改了下面也要修改这里
                break;
            }

            rem-=memo[i+50];
        }    

        while(rt<nums.size()){
            memo[nums[rt]+50]++; // 需要偏移量防止越界
            memo[nums[lt]+50]--;
            lt++;
            rt++;

            rem=x;
            for(int i=-50;i<=50;i++){
                if(rem<=memo[i+50]){
                    ans.push_back(i<0 ? i: 0); // 注意题意，如果是正数则为0
                    break;
                }

                rem-=memo[i+50];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-1,-3,-2,3]\n3\n2\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2,-3,-4,-5]\n2\n2\n
// @lcpr case=end

// @lcpr case=start
// [-3,1,2,-3,0,-3]\n2\n1\n
// @lcpr case=end

 */

