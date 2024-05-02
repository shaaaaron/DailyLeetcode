/*
 * @lc app=leetcode.cn id=2749 lang=cpp
 * @lcpr version=30122
 *
 * [2749] 得到整数零需要执行的最少操作数
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
// 解决问题的关键是把大问题规约为小问题，转为遍历小问题
// 40是因为位数的关系
    int makeTheIntegerZero(int num1, int num2) {
        if(num1==0) return 0;
        long long cur;
        for(int i=0;i<40;i++){ //不需要num1/num2，最多只需要位数次
            cur=num1-(long long)num2*i;//防止越界
            // if(cur<0) return -1; // 由于num2可能负数，所以这里不直接退出
            if(__builtin_popcountll(cur)<=i && i<=cur){
                // __builtin_popcount对7135848540不能正确bitcount，因为只能对32位bitcount
                // 64位需要使用__builtin_popcountll
                // cout<<i<<","<<cur<<","<<__builtin_popcount(cur)<<endl;
                // 负数会被i<=cur滤掉
                // 负数会被bitcount正确计数
                return i;
            }
        }

        return -1; //__builtin_popcount(cur)<=i由于位数，所以不会进入最后的return -2
    }
};
// __builtin_popcount() 系列函数设计用于无符号整数。如果用于符号整数，其行为取决于整数的具体二进制表示（即补码形式）。这意味着，如果传递一个负数，它会根据负数的补码形式来计算 1 的位数。例如，-1 在补码中所有位都是 1，因此 __builtin_popcount() 将返回 32（对于 32 位整数）或 64（对于 64 位整数），具体取决于你使用的是哪一个函数版本。
// @lc code=end



/*
// @lcpr case=start
// 112577768\n-501662198\n
// @lcpr case=end
// @lcpr case=start
// 3\n-2\n
// @lcpr case=end

// @lcpr case=start
// 5\n7\n
// @lcpr case=end

 */

