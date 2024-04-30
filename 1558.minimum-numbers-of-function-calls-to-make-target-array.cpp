/*
 * @lc app=leetcode.cn id=1558 lang=cpp
 * @lcpr version=30122
 *
 * [1558] 得到目标数组的最少函数调用次数
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
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=30;i>=0;i--){
            int mask=1<<i;
            int bit_cnt=0;
            for(int num:nums){
                if(mask&num)
                    bit_cnt++;
            }
            if(ans==0 && bit_cnt){
                ans+=i;
            }
            ans+=bit_cnt;
        }

        return ans;
    }
};
// @lc code=end
// 情况一：mat = [0] * n
// 在这种情况下，您创建了一个包含 n 个 0 的列表。这里的 0 是一个不可变的整数类型，在 Python 中，不可变对象不会因为被复制而引入引用问题。列表中的每个 0 虽然指向同一个对象，但由于整数是不可变的，这里不会有副作用或意外的行为。因此，您可以认为这是一种安全的操作。
// 情况二：mat = [[0] * n] * m
// 这里的情况就复杂很多了。首先，[0] * n 创建了一个包含 n 个 0 的列表，和上面类似，这部分是没有问题的。然而，接下来的 * m 是将这个列表复制了 m 次，创建一个新的列表。关键在于，复制的是列表的引用，而不是列表的内容（深拷贝）

/*
// @lcpr case=start
// [1,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,8,16]\n
// @lcpr case=end

 */

