/*
 * @lc app=leetcode.cn id=2275 lang=cpp
 * @lcpr version=30122
 *
 * [2275] 按位与结果大于零的最长组合
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
// 思路有点绕，用了抽屉原理，想一下写出来
    int largestCombination(vector<int>& candidates) {
        vector<int> memo(31); // 利用最多31位（除去符号位）
        for(int num:candidates){
            for(int bit=0;bit<31;bit++){
                if((num&1<<bit)==0){
                    memo[bit]++;
                }
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<31;i++){
            ans=min(ans, memo[i]);
        }

        return candidates.size()-ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [16,17,71,62,12,24,14]\n
// @lcpr case=end

// @lcpr case=start
// [8,8]\n
// @lcpr case=end

 */

