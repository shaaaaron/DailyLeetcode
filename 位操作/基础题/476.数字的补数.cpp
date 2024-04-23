/*
 * @lc app=leetcode.cn id=476 lang=cpp
 * @lcpr version=30122
 *
 * [476] 数字的补数
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
    int findComplement(int num) {
        int ans=0, bit=0;
        while(num){
            ans+= ( !(num&1))<<bit;
            
            num=num>>1;
            bit++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

