/*
 * @lc app=leetcode.cn id=523 lang=cpp
 * @lcpr version=30122
 *
 * [523] 连续的子数组和
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> memo;
        memo[0]=-1; // 认为下标是-1
        // 本题不是记录有几个，而是记录开始ide索引，所以0特殊处理为-1

        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k; //sum非负
            if(memo.find(rem)!=memo.end() && memo[rem]<i-1){ // 长度至少为2
                return true;
            }

            if(memo.find(rem)==memo.end()){
                memo[rem]=i;
            }
        }

        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [23,2,4,6,7]\n6\n
// @lcpr case=end
// @lcpr case=start
// [1000000000]\n1000000000\n
// @lcpr case=end

// @lcpr case=start
// [23,2,6,4,7]\n6\n
// @lcpr case=end

// @lcpr case=start
// [23,2,6,4,7]\n13\n
// @lcpr case=end

 */

