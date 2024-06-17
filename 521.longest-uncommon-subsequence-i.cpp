/*
 * @lc app=leetcode.cn id=521 lang=cpp
 * @lcpr version=30203
 *
 * [521] 最长特殊序列 Ⅰ
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
    int findLUSlength(string a, string b) {
        if(a.size()!=b.size()) return max(int(a.size()), int(b.size()));
        if(a==b) return -1;
        return a.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aba"\n"cdc"\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n"bbb"\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n"aaa"\n
// @lcpr case=end

 */

