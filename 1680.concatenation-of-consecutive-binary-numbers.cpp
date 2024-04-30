/*
 * @lc app=leetcode.cn id=1680 lang=cpp
 * @lcpr version=30122
 *
 * [1680] 连接连续二进制数字
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
// 注意时间复杂度，可以过
    int concatenatedBinary(int n) {
        long long ans=0;
        long long base=1; // ans/base防止越界
        int PRIME=1000*1000*1000+7;
        // 遍历可以向后可以从后向前，思考之后应该后向前

        for(int num=n;num>=1;num--){// 反向连接
            for(int i=0;i<32-__builtin_clz(num);i++){
                ans+=((num&1<<i)>>i)*base;
                ans%=PRIME;
                base*=2;
                base%=PRIME;
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 12\n
// @lcpr case=end

 */

