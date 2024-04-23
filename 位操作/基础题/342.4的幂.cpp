/*
 * @lc app=leetcode.cn id=342 lang=cpp
 * @lcpr version=30122
 *
 * [342] 4的幂
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
    bool isPowerOfFour(int n) {
        if(n<=0) return false;// 非常重要，不仅是因为负数难以处理，而且INT_MIN-1会越界

        while(n%4==0){
            n/=4;
        }
        if(n==1) return true;
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// -2147483648\n
// @lcpr case=end
// @lcpr case=start
// -2\n
// @lcpr case=end
// @lcpr case=start
// -4\n
// @lcpr case=end
// @lcpr case=start
// -99\n
// @lcpr case=end
// @lcpr case=start
// 16\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

