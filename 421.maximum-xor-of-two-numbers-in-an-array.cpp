/*
 * @lc app=leetcode.cn id=421 lang=cpp
 * @lcpr version=30122
 *
 * [421] 数组中两个数的最大异或值
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
// 很奇怪的做法，主要是贪心
// 记一下题型吧，题型很典型
// 试填法，什么是试填，不懂
    int findMaximumXOR(vector<int>& nums) {
        int mx=*max_element(nums.begin(), nums.end()); //求最大值和变量名
        if(mx==0) return 0;

        unordered_set<int> memo;
        int ans=0, mask=0;
        int bit_cnt=32-__builtin_clz(mx);
        for(int bit=bit_cnt-1;bit>=0;bit--){
            memo.clear();
            mask|=1<<bit;

            int new_ans=ans|1<<bit;
            for(int x:nums){
                x&=mask;
                if(memo.find(new_ans^x)!=memo.end()){// memo是find和insert
                    ans=new_ans;
                    break;
                }
                memo.insert(x);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,10,5,25,2,8]\n
// @lcpr case=end

// @lcpr case=start
// [14,70,53,83,49,91,36,80,92,51,66,70]\n
// @lcpr case=end

 */

