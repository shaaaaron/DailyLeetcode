/*
 * @lc app=leetcode.cn id=2935 lang=cpp
 * @lcpr version=30122
 *
 * [2935] 找出强数对的最大异或值 II
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
// 马马虎虎懂了，勉强对着写的。关键是如何用上大小的条件
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> memo;

        int bit_cnt=32-__builtin_clz(nums.back());
        int ans=0, mask=0;
        for(int i=bit_cnt-1;i>=0;i--){
            memo.clear();
            mask|=1<<i;
            int new_ans=ans|1<<i;

            for(int num:nums){
                int masked_num=mask&num;
                if(memo.find(new_ans^masked_num)!=memo.end() && memo[new_ans^masked_num]*2>=num){
                    ans=new_ans;
                    break;
                }
                memo[masked_num]=num;
            }

        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [10,100]\n
// @lcpr case=end

// @lcpr case=start
// [500,520,2500,3000]\n
// @lcpr case=end

 */

