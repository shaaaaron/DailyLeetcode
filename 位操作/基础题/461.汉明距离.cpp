/*
 * @lc app=leetcode.cn id=461 lang=cpp
 * @lcpr version=30122
 *
 * [461] 汉明距离
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
    int hammingDistance(int x, int y) {
        int tmp=x^y, ans=0;
        while(tmp){
            tmp&=(tmp-1);
            ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n4\n
// @lcpr case=end

// @lcpr case=start
// 3\n1\n
// @lcpr case=end

 */

