/*
 * @lc app=leetcode.cn id=2568 lang=cpp
 * @lcpr version=30122
 *
 * [2568] 最小无法得到的或值
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
// 有点巧妙，多想想
    int minImpossibleOR(vector<int>& nums) {
        vector<int> memo(31);
        for(int num:nums){
            for(int i=0;i<31;i++){
                // 注意bitcnt=1，因为找最小的，大了没意义
                if(__builtin_popcount(num)==1 &&num&1<<i) memo[i]=1;
            }
        }

        for(int i=0;i<31;i++){
            if(!memo[i]) return 1<<i;
        }

        return -1;// error code
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1]\n
// @lcpr case=end

// @lcpr case=start
// [5,3,2]\n
// @lcpr case=end

 */

