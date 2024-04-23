/*
 * @lc app=leetcode.cn id=693 lang=cpp
 * @lcpr version=30122
 *
 * [693] 交替位二进制数
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
    bool hasAlternatingBits(int n) {
        int flag=n%2;
        while(n){
            if(n%2!=flag) return false;
            flag=1-flag;
            n/=2;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 11\n
// @lcpr case=end

 */

