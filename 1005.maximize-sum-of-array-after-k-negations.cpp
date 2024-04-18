/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 * @lcpr version=30122
 *
 * [1005] K 次取反后最大化的数组和
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
    int sum(vector<int> &nums){
        int ans=0; 
        for(auto&num:nums){
            ans+=num;
        }
        return ans;
    }
    // 下面是一个初步做法，一个更好的做法如下
    // 按大小排序，将负数取反
    // 如果还有剩余次数，选出最小的颠倒 

    int largestSumAfterKNegations(vector<int>& nums, int k) { // k至少为1
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){ // 遇到了正数
                if(i==0){   // 如果前面没有负数，简单处理
                    if(k%2) nums[i]=-nums[i];
                }else{
                    if(k%2){// 如果前面有负数，选择小的颠倒
                        // 注意到这里，所有负数已经颠倒了一次变成了正数
                        if(nums[i-1]> nums[i]){
                            nums[i]=-nums[i];
                        }else{
                            nums[i-1]=-nums[i-1];
                        }
                    }
                }
                return sum(nums);
            }

            nums[i]=-nums[i]; // 尽可能将小的负数颠倒过来
            k--;
            if(k==0){ // 次数用完了，return
                return sum(nums);
            }
        }

        // 都是负数
        int n=nums.size();
        if(k%2==1)nums[n-1]=-nums[n-1];
        return sum(nums);
    }
};
// @lc code=end



/*

// @lcpr case=start
// [-4,-2,-3]\n1\n
// @lcpr case=end
// @lcpr case=start
// [4,2,3]\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,-1,0,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,-3,-1,5,-4]\n2\n
// @lcpr case=end

 */

