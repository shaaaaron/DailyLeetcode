/*
 * @lc app=leetcode.cn id=2897 lang=cpp
 * @lcpr version=30122
 *
 * [2897] 对数组执行操作使平方和最大
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
// 很巧妙，题型和2939类似
// 题目给定了不变量，在不变量的前提下调整使结果最大
    int maxSum(vector<int>& nums, int k) {
        int PRIME=1000*1000*1000+7;

        vector<int> memo(31);
        for(int num:nums){
            for(int bit=0;bit<31;bit++){
                if(num&1<<bit)
                    memo[bit]++;
            }
        }

        long long ans=0, cur=0;
        for(int i=1;i<=k;i++){
            cur=0;
            for(int bit=0;bit<31;bit++){
                if(memo[bit]){
                    memo[bit]--;
                    cur|=1<<bit;
                }
            }
            ans+=(cur*cur)%PRIME;
            ans%=PRIME;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,6,5,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,5,4,7]\n3\n
// @lcpr case=end

 */

