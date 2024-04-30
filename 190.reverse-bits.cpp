/*
 * @lc app=leetcode.cn id=190 lang=cpp
 * @lcpr version=30122
 *
 * [190] 颠倒二进制位
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
    uint32_t reverseBits(uint32_t n) {
        for(int i=0;i<31-i;i++){
           int a=(n&1<<i)>>i; 
           int b=(n&1<<(31-i))>>(31-i); // 先把对应数取出来
           a=a^b; // 用异或结果进行i swap
           n=n^(a<<i);
           n=n^(a<<(31-i));
        }
        return n;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 00000010100101000001111010011100\n
// @lcpr case=end

// @lcpr case=start
// 11111111111111111111111111111101\n
// @lcpr case=end

 */

