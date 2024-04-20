/*
 * @lc app=leetcode.cn id=2602 lang=cpp
 * @lcpr version=30122
 *
 * [2602] 使数组元素全部相等的最少操作次数
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
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        // int n=nums.size();
        long long n=nums.size(); // 注意n和idx可能参与乘法运算，由于优先级比加法高，所以即使ans是longlong的，乘法时也可能越界。
        // 即使n和idx都应该long long

        vector<long long> ops(nums.size());
        for(int i=0;i<nums.size();i++){
            ops[0]+=nums[i]-nums[0];
        }

        for(int i=1;i<nums.size();i++){
            ops[i]=ops[i-1]+(long long)(2*i-n)*(nums[i]-nums[i-1]);
            //+i*(nums[i]-num[i-1])-(n-i)*(nums[i]-num[i-1])
        }

        vector<long long> ans;
        for(auto &q:queries){
            auto it=upper_bound(nums.begin(), nums.end(), q);
            // int idx=it-nums.begin(); 
            long long idx=it-nums.begin(); 
            
            // 前有idx个，后有n-idx个
            if(idx==0){
                ans.push_back(ops[idx]+n*(nums[0]-q));
            }else if(idx==n){//可以和下面的情况合并
                ans.push_back(ops[idx-1]+idx*(q-nums[idx-1]));
            }else{
                ans.push_back(ops[idx-1]+idx*(q-nums[idx-1])-(n-idx)*(q-nums[idx-1]));
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,3,3,3,6,8]\n[1,2,3,4,5,6,7,8,9]\n
// @lcpr case=end
// @lcpr case=start
// [3,1,6,8]\n[1,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,9,6,3]\n[10]\n
// @lcpr case=end

 */

