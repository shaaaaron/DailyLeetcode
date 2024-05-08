/*
 * @lc app=leetcode.cn id=2134 lang=cpp
 * @lcpr version=30122
 *
 * [2134] 最少交换次数来组合所有的1-ii
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
    int minSwaps(vector<int>& nums) {
        int window_len=0;
        for(int num:nums){
            if(num==1)
                window_len++;
        }

        int ans, sum=0; //初始化
        int lt=0, rt=0;
        while(rt<window_len){
            sum+=nums[rt];
            rt++;
        }
        ans=sum;
        rt=rt%nums.size(); // 这里rt也需要模

        for(int i=0;i<nums.size();i++){
            sum+=nums[rt];
            sum-=nums[lt];
            rt++; rt=rt%nums.size();
            lt++; lt=lt%nums.size();
            ans=max(ans, sum);
        }
        
        return window_len-ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,1,1,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,0,0,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,0,1]\n
// @lcpr case=end

 */

